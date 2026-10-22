#include "estados.h"
#include “driver.h”

estados_t estado = CERRADA;

main()
{
	init_mcu();
	enumerar_funciones();

	while(1)
	{
		estado = funciones_estado[estado]();
  	}
}
