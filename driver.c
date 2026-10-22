#include <avr/io.h>
#include "driver.h"

void init_mcu()
{
	GpioInitStructure_AVR sens;
	
	sens.port =	avr_GPIO_B;
	sens.modo = 	avr_GPIO_mode_Input;
	sens.pine s=	SENS_DER_PIN | SENS_DERC_PIN | SENS_CEN_PIN | SENS_IZQC_PIN | SENS_IZQ_PIN;
	init_gpio (sens);
	
  	DDRB |= (1 << MOTOR_ABRE);
	DDRB |= (1 << MOTOR_CIERRA); 
  	DDRD |= (1 << MOTOR_ACTIVADO);
  	f_parar();
}

int f_leer_boton()
{
    int lectura_boton;

    lectura_boton = (PINB & (1 << BOTON)) != 0;

   return lectura_boton;
}

int f_leer_presencia()
{
    int lectura_sensor;

    lectura_sensor =  (PINB & (1 << SENSOR_PRESENCIA)) != 0;

    return lectura_sensor;
}

int f_leer_fin_apertura()
{
    int lectura_final_carrera_1;

   lectura_final_carrera_1 =  (PINB & (1 << FINAL_CARRRERA_ABIERTO)) != 0;

   return lectura_final_carrera_1;
}

int f_leer_fin_cierre()
{
    int lectura_final_carrera_2;

   lectura_final_carrera_2 =  (PINB & (1 << FINAL_CARRRERA_CERRADO)) != 0; 

   return lectura_final_carrera_2;
}

void f_abrir()
{
    PORTD |= (1 << MOTOR_ACTIVADO); 
    PORTB |= (1 << MOTOR_ABRE);
    PORTB &= ~(1 << MOTOR_CIERRA);
}

void f_cerrar()
{
    PORTD |= (1 << MOTOR_ACTIVADO);
    PORTB |= (1 << MOTOR_CIERRA);
    PORTB &= ~(1 << MOTOR_ABRE);
}

void f_parar()
{
    PORTD &= ~(1 << MOTOR_ACTIVADO);
}
