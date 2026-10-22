#include <avr/io.h>
#include "driver.h"

void init_mcu()
{
  	DDRB |= (1 << PB4);
	DDRB |= (1 << PB5); 
  	DDRD |= (1 << PD7);
  	f_parar();
}

int f_leer_boton()
{
    int lectura_boton;

    lectura_boton = (PINB & (1 << PB0)) != 0;

   return lectura_boton;
}

int f_leer_presencia()
{
    int lectura_sensor;

    lectura_sensor =  (PINB & (1 << PB1)) != 0;

    return lectura_sensor;
}

int f_leer_fin_apertura()
{
    int lectura_final_carrera_1;

   lectura_final_carrera_1 =  (PINB & (1 << PB2)) != 0;

   return lectura_final_carrera_1;
}

int f_leer_fin_cierre()
{
    int lectura_final_carrera_2;

   lectura_final_carrera_2 =  (PINB & (1 << PB3)) != 0; 

   return lectura_final_carrera_2;
}

void f_abrir()
{
    PORTD |= (1 << PD7); 
    PORTB |= (1 << PB4);
    PORTB &= ~(1 << PB5);
}

void f_cerrar()
{
    PORTD |= (1 << PD7);
    PORTB |= (1 << PB5);
    PORTB &= ~(1 << PB4);
}

void f_parar()
{
    PORTD &= ~(1 << PD7);
}
