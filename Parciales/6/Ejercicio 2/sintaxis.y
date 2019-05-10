%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
int yystopparser = 0;
FILE *yyin;

/* ************************************************** */
/* ********************* RPN  *********************** */
/* ************************************************** */

int currentCell = 1;

// Celda RPN
struct cell {
  int index;
  char *value;
};
typedef struct cell cell;

// Pila RPN
struct rpn {
  struct cell *value;
  struct rpn *next;
  struct rpn *prev;
};
typedef struct rpn rpn;

// Pila Indices RPN
typedef struct{
    cell* stack[100];
    int top;
} t_stack;

rpn *rpnQueue = NULL;
rpn *rpnFirst = NULL;
t_stack *indexes;

void initPolaca();
void mostrarPolaca();
cell* insertarEnPolaca(char *);
void apilarIndice(struct cell *cell);
cell* desapilarIndice(int isElse);

/* ************************************************** */
/* ******************** FIN - RPN  ****************** */
/* ************************************************** */

char *aux;

int yylex();
int yyerror(char *);
%}

%union {
int intval;
char *str_val;
}

%token EXP1
%token EXP2
%token EXP3

%start S

%%
S : EXP1
| EXP2
| EXP3

%%

/* ************************************************** */
/* *********************** RPN ********************** */
/* ************************************************** */

void initPolaca() {
  indexes = (t_stack *) malloc(sizeof(t_stack));
  indexes->top = -1;
}

cell* insertarEnPolaca(char *value) {
  rpn *ptr = (rpn *) malloc (sizeof (rpn));
  cell *c = (cell *) malloc (sizeof (cell));
  c->value = (char *) malloc (strlen (value) + 1);
  strcpy (c->value, value);
  ptr->value = c;
  ptr->next = rpnQueue;
  if (rpnFirst == NULL) {
    rpnFirst = ptr;
  } else {
    rpnQueue->prev = ptr;
  }
  rpnQueue = ptr;
  currentCell++;
  return c;
}

void apilarIndice(cell *c) {
  indexes->top++;
  indexes->stack[indexes->top] = c;
}

cell* desapilarIndice(int isElse) {
  cell *c = indexes->stack[indexes->top];
  char str[10];
  sprintf(str, "%d", isElse ? currentCell : currentCell + 1);
  strcpy(c->value, str);
  indexes->top--;
  return c;
}

void mostrarPolaca() {
  rpn *ptr;
  for (ptr = rpnFirst; ptr != (rpn *) 0; ptr = (rpn *)ptr->prev) {
     printf("%s", ptr->value->value);
     printf("\n");
  }
}

/* ************************************************** */
/* ******************** FIN - RPN  ****************** */
/* ************************************************** */

int main(int argc,char *argv[]) {
  if ((yyin = fopen(argv[1], "rt")) == NULL) {
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  } else {
    printf("\n");
    initPolaca();
		yyparse();
    mostrarPolaca();
    printf("\n\n");
  }

  fclose(yyin);
  return 0;
}

int yyerror(char * err) {
	printf("\nSyntax Error. %s\n", err);
	exit(1);
}