/*
 * controlador_AGV.c
 *
 *  Created on: Feb 6, 2016
 *      Author: Jorge Armando
 */
#include "controlador_AGV.h"
#include "estados.h"

#define	Kp	10
//#define Kd	300
#define Kd	450
#define Ki	1

//#define Kp	0
//#define Kd	0
//#define Ki	0

long error;
long error_anterior;
long integral;
long derivativo;
long vel_der;
long vel_izq;

extern int der, izq;
extern bool actualizar_estado,leer_sensor;

int inicializar_motores(void){
	error = 0;
	error_anterior = 0;
	integral = 0;
	derivativo = 0;
	vel_der = FWD_SPEED_RIGHT;
	vel_izq = FWD_SPEED_LEFT;
	velocidad_der(vel_der);
	velocidad_izq(vel_izq);
	return 0;
}


int pid(int posicion){
	long correccion; 
	error = posicion;
	integral += error;
	derivativo = error - error_anterior;
	correccion = Kp*error + Kd*derivativo + Ki*integral;
	error_anterior = error;
	vel_der -= correccion;
	vel_izq += correccion;
	velocidad_der(vel_der);
	velocidad_izq(vel_izq);
	
	return 0;
}

bool girar_derecha(){	
	velocidad_der(-FWD_SPEED_RIGHT);
	velocidad_izq(FWD_SPEED_LEFT);
	
	while(izq > 0){
		while(!actualizar_estado){
			while(!leer_sensor);
			muestrear_sensores();
			leer_sensor = FALSE;
		}
		actualizar_estado = FALSE;
	}
	
	while(izq <= THRESH){
		while(!actualizar_estado){
			while(!leer_sensor);
			muestrear_sensores();
			leer_sensor = FALSE;
		}
		actualizar_estado = FALSE;
	}

	return 0;	
}

bool girar_izquierda(void){
	velocidad_der(FWD_SPEED_RIGHT);
	velocidad_izq(-FWD_SPEED_LEFT);
	
	while(der > 0){
		while(!actualizar_estado){
			while(!leer_sensor);
			muestrear_sensores();
			leer_sensor = FALSE;
		}
		actualizar_estado = FALSE;
	}
	
	while(der <= THRESH){
		while(!actualizar_estado){
			while(!leer_sensor);
			muestrear_sensores();
			leer_sensor = FALSE;
		}
		actualizar_estado = FALSE;
	}

	return 0;	
}

bool girar_180(void){
	return girar_derecha();
}

int detener(void){
	apagar_motores();
	return 0;
}
