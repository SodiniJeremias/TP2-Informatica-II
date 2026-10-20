#include "mylib.h"
#include <avr/io.h>

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

estados_t f_cerrada()
{
    if (f_leer_boton() == 1)
    {
        f_abrir();
        return ABRIENDO; 
    }

    return CERRADA;
}

estados_t f_abierta()
{
    if(f_leer_presencia() == 0)
	{
		f_cerrar();
		return CERRANDO;
	}

    return ABIERTA;
}

estados_t f_abriendo()
{
  if(f_leer_fin_apertura() == 1)
	{
		f_parar();
		return ABIERTA;
	}
	return ABRIENDO;
}

estados_t f_cerrando()
{
	if(f_leer_presencia() == 1)
	{
		f_abrir();
		return ABRIENDO;
	}
	else if(f_leer_fin_cierre() == 1)
	{
		f_parar();
		return CERRADA;
	}
	return CERRANDO;
}
