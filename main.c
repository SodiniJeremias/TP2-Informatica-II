#include "mylib.h"
#include <avr/io.h>
estados_t estado = CERRADA;

main()
{
  DDRB |= (1 << PB4);
	DDRB |= (1 << PB5); 
  DDRD |= (1 << PD7);

  funciones_estado[0] = f_cerrada;
  funciones_estado[1] = f_abriendo;
  funciones_estado[2] = f_abierta;
  funciones_estado[3] = f_cerrando;
	
  f_parar();

	while(1)
	{
		estado = funciones_estado[estado]();
  }
}
