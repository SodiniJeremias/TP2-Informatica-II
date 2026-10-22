#define BOTON  PB0
#define SENSOR_PRESENCIA  PB1
#define FINAL_CARRERA_ABIERTO  PB2
#define FINAL_CARRERA_CERRADO  PB3

#define MOTOR_ABRE  PB4
#define MOTOR_CIERRA  PB5
#define MOTOR_ACTIVADO  PB7

void init_mcu();
int f_leer_boton();
int f_leer_presencia();
int f_leer_fin_apertura();
int f_leer_fin_cierre();

void f_abrir();
void f_cerrar();
void f_parar();
