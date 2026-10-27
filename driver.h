#include "avr_api/avr_api.h"

#define PUERTO_B avr_GPIO_B
#define PUERTO_D avr_GPIO_D

#define BOTON  avr_GPIO_PIN_0
#define SENSOR_PRESENCIA  avr_GPIO_PIN_1
#define FINAL_CARRERA_ABIERTO  avr_GPIO_PIN_2
#define FINAL_CARRERA_CERRADO  avr_GPIO_PIN_3

#define BOTON_IN              avr_GPIOB_IN_0
#define SENSOR_PRESENCIA_IN   avr_GPIOB_IN_1
#define FIN_APERTURA_IN       avr_GPIOB_IN_2
#define FIN_CIERRE_IN         avr_GPIOB_IN_3

#define MOTOR_ABRE  avr_GPIO_PIN_4
#define MOTOR_CIERRA avr_GPIO_PIN_5
#define MOTOR_ACTIVADO  avr_GPIO_PIN_7

void init_mcu();
int f_leer_boton();
int f_leer_presencia();
int f_leer_fin_apertura();
int f_leer_fin_cierre();

void f_abrir();
void f_cerrar();
void f_parar();
