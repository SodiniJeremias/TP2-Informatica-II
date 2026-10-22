#include "avr_api/avr_api.h"

#define BOTON  PB0
#define SENSOR_PRESENCIA  PB1
#define FINAL_CARRERA_ABIERTO  PB2
#define FINAL_CARRERA_CERRADO  PB3

#define MOTOR_ABRE  PB4
#define MOTOR_CIERRA  PB5
#define MOTOR_ACTIVADO  PD7

#define POR1 avr_GPIO_B
#define PORT2 avr_GPIO_D

void init_mcu();
int f_leer_boton();
int f_leer_presencia();
int f_leer_fin_apertura();
int f_leer_fin_cierre();

void f_abrir();
void f_cerrar();
void f_parar();
