/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : IRRx_Watchdog.c
**     Project     : Controlador_AGV
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.223, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2016-03-29, 10:56, # CodeGen: 39
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TPM1
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**           Maximal time for capture register
**             Xtal ticks              : 85
**             microseconds            : 2604
**             milliseconds            : 3
**             seconds (real)          : 0.002604166667
**             Hz                      : 384
**           One tick of timer is
**             nanoseconds             : 40
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TPM1C0V   [$0046]
**              Counter                : TPM1CNT   [$0041]
**              Mode                   : TPM1SC    [$0040]
**              Run                    : TPM1SC    [$0040]
**              Prescaler              : TPM1SC    [$0040]
**
**         Signal edge/level           : rising
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         Reset - byte IRRx_Watchdog_Reset(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file IRRx_Watchdog.c
** @version 01.30
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup IRRx_Watchdog_module IRRx_Watchdog module documentation
**  @{
*/         

/* MODULE IRRx_Watchdog. */

#include "Events.h"
#include "IRRx_Watchdog.h"




/*
** ===================================================================
**     Method      :  IRRx_Watchdog_Reset (component Capture)
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte IRRx_Watchdog_Reset(word *Value)

**  This method is implemented as a macro. See IRRx_Watchdog.h file.  **
*/

/*
** ===================================================================
**     Method      :  IRRx_Watchdog_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void IRRx_Watchdog_Init(void)
{
  /* TPM1SC: TOF=0,TOIE=0,CPWMS=0,CLKSB=0,CLKSA=0,PS2=0,PS1=0,PS0=0 */
  setReg8(TPM1SC, 0x00U);              /* Stop HW */ 
  /* TPM1MOD: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM1MOD, 0x00U);            /* Disable modulo register */ 
  /* TPM1CNTH: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0 */
  setReg8(TPM1CNTH, 0x00U);            /* Reset counter */ 
  /* TPM1C0V: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM1C0V, 0x00U);            /* Clear capture register */ 
  /* TPM1SC: PS2=0,PS1=0,PS0=0 */
  clrReg8Bits(TPM1SC, 0x07U);          /* Set prescaler register */ 
  /* TPM1C0SC: CH0F=0,CH0IE=0,MS0B=0,MS0A=0,ELS0B=0,ELS0A=1,??=0,??=0 */
  setReg8(TPM1C0SC, 0x04U);            /* Enable capture function */ 
  /* TPM1SC: TOF=0 */
  clrReg8Bits(TPM1SC, 0x80U);          /* Reset overflow interrupt request flag */ 
  /* TPM1SC: TOIE=1 */
  setReg8Bits(TPM1SC, 0x40U);          /* Enable overflow interrupt */ 
  /* TPM1SC: CLKSB=0,CLKSA=1 */
  clrSetReg8Bits(TPM1SC, 0x10U, 0x08U); /* Run counter */ 
}


/*
** ===================================================================
**     Method      :  IntOverflow (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes of the component event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(IRRx_Watchdog_IntOverflow)
{
  (void)TPM1SC;
  /* TPM1SC: TOF=0 */
  clrReg8Bits(TPM1SC, 0x80U);          /* Reset overflow interrupt request flag */ 
  IRRx_Watchdog_OnOverflow();          /* Invoke user event */
}



/* END IRRx_Watchdog. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/