#ifndef tercetos_h
#define tercetos_h

#include "tabla_simbolos.h"

#define OFFSET TAMANIO_TABLA
#define MAX_TERCETOS 512

/* Operadores extra para usar con los tokens */
#define NOOP -1 /* Sin operador */
#define BLOQ 7  /* Operador que indica el orden de las sentencias */
#define CMP 21  /* Comparador de assembler */
#define BNE 2   /* = */
#define BGE 4   /* < */
#define BLT 6   /* >= */
#define BLE 10  /* > */
#define BEQ 14  /* != */
#define BGT 8   /* <= */
#define JMP 16  /* Branch Always o Salto Incondicional*/
#define INL 18  /* Un terceto con este operador representa el resultado del inlist.
                * Representa la comparacion de dos numeros iguales si dio verdadero
                * o de dos numeros distintos si dio falso.
                */
#define INOK 20 /* Compara dos numeros distintos para representar el falso del inlist. */
#define IOK 22  /* Compara dos numeros iguales para representar el verdadero del inlist. */

/* Posiciones dentro de un terceto */
#define OP1 2
#define OP2 3
#define OPERADOR 1

/* Funciones */
int crear_terceto(int operador, int op1, int op2);
void guardarTercetos();
void modificarTerceto(int indice, int posicion, int valor);

typedef struct{
  int operador;
  int op1;
  int op2;
} terceto;

/* Variables externas */
extern terceto lista_terceto[MAX_TERCETOS];
extern int ultimo_terceto; /* Apunta al ultimo terceto escrito. Incrementarlo para guardar el siguiente. */

#endif
