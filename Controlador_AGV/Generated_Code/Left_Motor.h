/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Left_Motor.h
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
**                       33            |  PTC1_TPM3CH1
**             ----------------------------------------------------
**
**         Timer name                  : TPM3 [16-bit]
**         Counter                     : TPM3CNT   [$0061]
**         Mode register               : TPM3SC    [$0060]
**         Run register                : TPM3SC    [$0060]
**         Prescaler                   : TPM3SC    [$0060]
**         Compare register            : TPM3C1V   [$0069]
**         Flip-flop register          : TPM3C1SC  [$0068]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTC
**         Bit number (in port)        : 1
**         Bit mask of the port        : $0002
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
**         SetRatio16 - byte Left_Motor_SetRatio16(word Ratio);
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
** @file Left_Motor.h
** @version 01.28
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup Left_Motor_module Left_Motor module documentation
**  @{
*/         

#ifndef __Left_Motor
#define __Left_Motor

/* MODULE Left_Motor. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#define Left_Motor_PERIOD_VALUE              0x624DU /* Initial period value in ticks of the timer in high speed mode */
#define Left_Motor_PERIOD_VALUE_HIGH         0x624DU /* Period value in ticks of the timer in high speed mode */


byte Left_Motor_SetRatio16(word Ratio);
/*
** ===================================================================
**     Method      :  Left_Motor_SetRatio16 (component PWM)
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

void Left_Motor_Init(void);
/*
** ===================================================================
**     Method      :  Left_Motor_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END Left_Motor. */

#endif /* ifndef __Left_Motor */
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
