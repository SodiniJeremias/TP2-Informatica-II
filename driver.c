#include "driver.h"

void init_mcu()
{
	GpioInitStructure_AVR puertos;
	
	puertos.port =	PUERTO_B;
	puertos.modo = 	avr_GPIO_mode_Input;
	puertos.pines =	BOTON | SENSOR_PRESENCIA | FINAL_CARRERA_ABIERTO | FINAL_CARRERA_CERRADO;
	init_gpio (puertos);

	puertos.port =	PUERTO_B;
	puertos.modo = 	avr_GPIO_mode_Output;
	puertos.pines =	MOTOR_ABRE | MOTOR_CIERRA;
	init_gpio (puertos);

	puertos.port =	PUERTO_D;
	puertos.modo = 	avr_GPIO_mode_Output;
	puertos.pines =	MOTOR_ACTIVADO;
	init_gpio (puertos);

  	f_parar();
}

int f_leer_boton()
{
	return avr_GPIOB_IN_0;
}

int f_leer_presencia()
{
    return avr_GPIOB_IN_1;
}

int f_leer_fin_apertura()
{
   return avr_GPIOB_IN_2;
}

int f_leer_fin_cierre()
{
     return avr_GPIOB_IN_3;
}

void f_abrir()
{
    set_pin(PUERTO_D, 7);
    set_pin(PUERTO_B, 4);
    clear_pin(PUERTO_B, 5);
}

void f_cerrar()
{
    set_pin(PUERTO_D, 7);
    clear_pin(PUERTO_B, 4);
    set_pin(PUERTO_B, 5);
}

void f_parar()
{
	clear_pin(PUERTO_D, 7);
	clear_pin(PUERTO_B, 4);
	clear_pin(PUERTO_B, 5);
}
