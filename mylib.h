#ifndef MY_LIB
#define MY_LIB

typedef enum {
	CERRADA,
	ABRIENDO,
	ABIERTA,
	CERRANDO
} estados_t;

estados_t (*funcion_estado[4])(); 

int f_leer_boton();
int f_leer_presencia();
int f_leer_fin_apertura();
int f_leer_fin_cierre();

void f_abrir();
void f_cerrar();
void f_parar();

estados_t f_cerrada();
estados_t f_abriendo();
estados_t f_abierta();
estados_t f_cerrando();


#endif
