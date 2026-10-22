#include "estados.h"
#include "driver.h"

main()
{
	estados_t estado = CERRADA;
	init_mcu();
	enumerar_funciones();

	while(1)
	{
		estado = funciones_estado[estado]();
  	}
}
