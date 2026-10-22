#include "driver.h"
#include "estados.h"

void enumerar_funciones()
{
  funciones_estado[0] = f_cerrada;
  funciones_estado[1] = f_abriendo;
  funciones_estado[2] = f_abierta;
  funciones_estado[3] = f_cerrando;
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
