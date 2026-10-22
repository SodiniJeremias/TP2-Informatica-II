#include <avr/io.h>
#include "driver.h"

void init_mcu()
{
	GpioInitStructure_AVR PUERTOS;
	
	PUERTOS.port =	avr_GPIO_B;
	PUERTOS.modo = 	avr_GPIO_mode_Input;
	PUERTOS.pines =	BOTON | SENSOR_PRESENCIA | FINAL_CARRRERA_ABIERTO | FINAL_CARRERA_CERRADO;
	init_gpio (PUERTOS);

	PUERTOS.port =	avr_GPIO_B;
	PUERTOS.modo = 	avr_GPIO_mode_Output;
	PUERTOS.pines =	MOTOR_ABRE | MOTOR_CIERRA;
	init_gpio (PUERTOS);

	PUERTOS.port =	avr_GPIO_D;
	PUERTOS.modo = 	avr_GPIO_mode_Output;
	PUERTOS.pines =	MOTOR_ACTIVADO;
	init_gpio (PUERTOS);

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
    set_pin(avr_GPIO_D, 7);
    set_pin(avr_GPIO_B, 4);
    clear_pin(avr_GPIO_B, 5);
}

void f_cerrar()
{
    set_pin(avr_GPIO_D, 7);
    clear_pin(avr_GPIO_B, 4);
    set_pin(avr_GPIO_B, 5);
}

void f_parar()
{
	clear_pin(avr_GPIO_B, 7);
	clear_pin(avr_GPIO_B, 4);
	clear_pin(avr_GPIO_B, 5);
}
