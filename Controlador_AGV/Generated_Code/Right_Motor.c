/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Right_Motor.c
**     Project     : Controlador_AGV
**     Processor   : MC9S08QE128CLK
**     Component   : PWM
**     Version     : Component 02.241, Driver 01.28, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2016-02-22, 15:19, # CodeGen: 12
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       34            |  PTC0_TPM3CH0
**             ----------------------------------------------------
**
**         Timer name                  : TPM3 [16-bit]
**         Counter                     : TPM3CNT   [$0061]
**         Mode register               : TPM3SC    [$0060]
**         Run register                : TPM3SC    [$0060]
**         Prescaler                   : TPM3SC    [$0060]
**         Compare register            : TPM3C0V   [$0066]
**         Flip-flop register          : TPM3C0SC  [$0065]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTC
**         Bit number (in port)        : 0
**         Bit mask of the port        : $0001
**         Port data register          : PTCD      [$0004]
**         Port control register       : PTCDD     [$0005]
**
**         Initialization:
**              Output level           : high
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 25165824 Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : 33         0
**             microseconds            : 1000       0
**             milliseconds            : 1          0
**             seconds (real)          : 0.001000006994 0.0
**
**     Contents    :
**         SetRatio16 - byte Right_Motor_SetRatio16(word Ratio);
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
** @file Right_Motor.c
** @version 01.28
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup Right_Motor_module Right_Motor module documentation
**  @{
*/         


/* MODULE Right_Motor. */

#include "PE_Error.h"
#include "Right_Motor.h"

#pragma MESSAGE DISABLE C5703          /* WARNING C5703: Parameter _ declared in function _ but not referenced */
#pragma MESSAGE DISABLE C2705          /* WARNING C2705: Possible loss of data */
#pragma MESSAGE DISABLE C5919          /* WARNING C5919: Conversion of floating to unsigned integral */


/*lint -save  -esym(960,18.4) Disable MISRA rule (18.4) checking. */
typedef union {
  uint16_t Value;
  struct {
    uint8_t Hi;
    uint8_t Lo;
  } BB;
} TRatioValue;
/*lint -restore  +esym(960,18.4) Enable MISRA rule (18.4) checking. */

static TRatioValue ActualRatio;        /* Ratio of L-level to H-level - 16-bit unsigned value */

/* Internal method prototypes */

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetReg method for duty 
**         value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void);

/* End of Internal methods declarations */

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetReg method for duty 
**         value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void)
{
  if (ActualRatio.Value == 0xFFFFU) {  /* Duty = 100%? */
    TPM3C0V = 0xFFFFU;                 /* Store new value to the compare reg. */
  } else {
    TRatioValue Tmp1, Tmp2;
    uint16_t Result;
    Result = (uint16_t)((uint16_t)ActualRatio.BB.Hi * 0x62U); /* HI * HI */
    Tmp1.Value = (uint16_t)((uint16_t)ActualRatio.BB.Hi * 0x4EU); /* HI * LO */
    Result += Tmp1.BB.Hi;
    Tmp2.Value = (uint16_t)((uint16_t)ActualRatio.BB.Lo * 0x62U); /* LO * HI */
    Result += Tmp2.BB.Hi;
    if ((Tmp2.BB.Lo += Tmp1.BB.Lo) < Tmp1.BB.Lo) {
      ++Result;                        /* carry to result */
    }
    Tmp1.Value = (uint16_t)((uint16_t)ActualRatio.BB.Lo * 0x4EU); /* LO * LO */
    if ((Tmp1.BB.Hi += Tmp2.BB.Lo) < Tmp2.BB.Lo) {
      ++Result;                        /* carry to result */
    }
    if (Tmp1.BB.Hi >= 0x80U) {
      ++Result;                        /* round */
    }
    TPM3C0V = Result;
  }
}

/*
** ===================================================================
**     Method      :  Right_Motor_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte Right_Motor_SetRatio16(word Ratio)
{
  ActualRatio.Value = Ratio;           /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Right_Motor_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Right_Motor_Init(void)
{
  /* TPM3SC: TOF=0,TOIE=0,CPWMS=0,CLKSB=0,CLKSA=0,PS2=0,PS1=0,PS0=0 */
  setReg8(TPM3SC, 0x00U);              /* Disable device */ 
  /* TPM3C0SC: CH0F=0,CH0IE=0,MS0B=1,MS0A=1,ELS0B=1,ELS0A=0,??=0,??=0 */
  setReg8(TPM3C0SC, 0x38U);            /* Set up PWM mode with output signal level high */ 
  ActualRatio.Value = 0x00U;           /* Store initial value of the ratio */
  /* TPM3MOD: BIT15=0,BIT14=1,BIT13=1,BIT12=0,BIT11=0,BIT10=0,BIT9=1,BIT8=0,BIT7=0,BIT6=1,BIT5=0,BIT4=0,BIT3=1,BIT2=1,BIT1=0,BIT0=1 */
  setReg16(TPM3MOD, 0x624DU);          /* Set modulo register */ 
  SetRatio();                          /* Calculate and set up new values of the compare according to the selected speed CPU mode */
}

/* END Right_Motor. */

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
