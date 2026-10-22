typedef enum {
    CERRADA,
    ABRIENDO,
    ABIERTA,
    CERRANDO
} estados_t;

estados_t (*funciones_estado[4])();

void enumerar_funciones(void);
estados_t f_cerrada();
estados_t f_abriendo();
estados_t f_abierta();
estados_t f_cerrando();
