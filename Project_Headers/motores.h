#ifndef MOTOR_H_
#define MOTOR_H_

#include "Cpu.h"
#include "Events.h"
#include "Right_Motor.h"
#include "Left_Motor.h"
#include "Right_Motor_Ref.h"
#include "Left_Motor_Ref.h"
#include "PE_Types.h"

#define		ONE_HUNDRED_PWM		65535	//100%
#define		MAX_DUTY_CYCLE		26214	//40%
#define		MIN_DUTY_CYCLE		6554	//10%
#define		FWD_SPEED_RIGHT		46429		//46.4% del rango reducido
#define		FWD_SPEED_LEFT		50000		//50% del rango reducido
#define		ONE_H_PCT			100000

int velocidad_der(long vel);
int velocidad_izq(long vel);
int apagar_motores(void);

#endif
