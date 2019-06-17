%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

FILE *yyin;
char *yytext;
extern int yylineno;
int yylex();

/**** INICIO VARIABLES ****/
char tipoActual[10]={""};
char listaVariables[10][20]={""};
int variableActual=0;
void reinicioVariables();
/**** FIN VARIABLES ****/


/**** INICIO TERCETOS ****/

int IndAsignacion;
int IndExpresion;
int IndTermino;
int IndFactor;
int IndTake;
int IndListaTake;
int IndLong;
int IndEntrada;
int IndSalida;
int IndSuma;
int Ind_take_comp;
int Ind_take_op;
int IndCompArit;
int IndResTake;
int IndCmpTake;
int IndId;

struct terceto {
	char *uno;
	char *dos;
	char *tres;
};
struct terceto tercetos[1000];
int terceto_index = 0;

int crearTerceto_ccc(char *uno, char *dos, char *tres);
int crearTerceto_cci(char *uno, char *dos, int tres);
int crearTerceto_cii(char *uno, int dos, int tres);
int crearTerceto_fcc(float uno, char *dos, char *tres);
int crearTerceto_icc(int uno, char *dos, char *tres);
int crearTerceto_cic(char *uno, int dos, char *tres);
int crearTerceto_iii(int uno, int dos, int tres);
void cadenaIndice(int indice, char* cadena);

void save_tercetos();
/**** FIN TERCETOS ****/

/**** INICIO TAKE Y LONG ****/
int take_indice_id;
int take_saltos_a_completar[15];
int take_cant_saltos;
int take_index;
int cant_lista_long;
int cant_rec;
int es_long = 0;
int posicion_numero_take = 0;
int take_numeros[15];
/**** FIN TAKE Y LONG ****/

/**** INICIO COMPARACION ****/
char valor_comparacion[3];
int IndComparacion;
int saltos_and_a_completar[6];
int and_index = 0;
void completar_salto_si_es_comparacion_AND(int pos);
int pos_a_completar_OR;
int es_negado = 0;
/**** FIN COMPARACION ****/

/**** INICIO IF ****/
int if_salto_a_completar;
int if_saltos[6];
int if_index = 0;
void if_guardar_salto(int pos);
void if_completar_ultimo_salto_guardado_con(int pos);
/**** FIN IF ****/

/**** INICIO WHILE ****/
int while_pos_inicio;
int while_salto_a_completar;
int while_pos_a_completar[11];
int while_index = 0;
void while_guardar_pos(int pos);
/**** FIN IF ****/

/**** INICIO PILA ****/
const int tamPila = 100;

typedef struct {
    int pila[100];
    int tope;
} Pila;

void crearPila( Pila *p);
int pilaLLena( Pila *p );
int pilaVacia( Pila *p);
int ponerEnPila(Pila *p, int dato);
int sacarDePila(Pila *p);

Pila pilaExpresion;
Pila pilaTermino;
/**** FIN PILA ****/

/**** INICIO EXP NUMERICA ****/

int buscarTipoTS(char* nombreVar);
void verificarTipoDato(int tipo);
void reiniciarTipoDato();
int tipoDatoActual = -1;

int Integer = 1;
int Float = 2;
int String = 3;


/**** FIN EXP NUMERICA ****/

/**** Inicio assembler ****/
char lista_operandos_assembler[100][100];
int cant_op = 0;

void genera_asm();
char* getNombreAsm(char *cte_o_id);
char* getCodOp(char*);
/**** Fin assembler ****/
%}

/* Tipo de estructura de datos, toma el valor SUMA grande*/
%union {
	int valor_int;
	float valor_float;
	char *valor_string;
}

%token START
%token END
%token DEFVAR ENDDEF
%token INT FLOAT STRING
%token WHILE ENDWHILE
%token IF THEN ELSE ENDIF
%token AND OR NOT
%token ASIG
%token SUMA RESTA
%token POR DIVIDIDO
%token MENOR  MAYOR MENOR_IGUAL MAYOR_IGUAL
%token IGUAL DISTINTO
%token PA PC
%token CA CC
%token COMA
%token PUNTO_COMA
%token DOS_PUNTOS
%token GET
%token DISPLAY
%token LONG
%token TAKE
%token <valor_string>ID
%token <valor_float>CTE_FLOAT
%token <valor_int>CTE_INT
%token <valor_string>CTE_STRING

%start start

%%

start: programa { printf("\nGenerando assembler...\n"); genera_asm(); printf("\n\n\tCOMPILACION EXITOSA!!\n\n\n"); }
	 |			{ printf("\n El archivo 'Prueba.Txt' no tiene un programa\n"); }
	 ;

programa: START seccion_declaracion bloque END
	     | START bloque END ;


/* Declaracion de variables */

seccion_declaracion: DEFVAR bloque_dec ENDDEF {printf("Regla 1: Seccion declaracion es DEFVAR bloque_dec ENDEC\n");};

bloque_dec: bloque_dec declaracion { guardarTipos(variableActual, listaVariables, tipoActual); reinicioVariables(); }
	     | declaracion ;

declaracion:
	t_dato DOS_PUNTOS lista_id				            {
															printf("Regla 4: declaracion es t_dato DOS_PUNTOS lista_id\n");
															guardarTipos(variableActual, listaVariables, tipoActual); reinicioVariables();
														};

t_dato:
	FLOAT		                                        {
															printf("Regla 5: t_dato es FLOAT\n");
															strcpy(tipoActual,"FLOAT");
														}
	| INT		                                        {
															printf("Regla 6: t_dato es INT\n");
															strcpy(tipoActual,"INT");;
														}
	| STRING	                                        {
															printf("Regla 7: t_dato es STRING\n");
															strcpy(tipoActual,"STRING");;
														};

lista_id:
	lista_id PUNTO_COMA ID	                            {
	                                                        printf("Regla 8: lista_id es lista_id PUNTO_COMA ID\n");
	                                                        strcpy(listaVariables[variableActual++],$3); insertar_id_en_ts($3);
                                                        }
	| ID				                                {
	                                                        printf("Regla 9: lista_id es ID\n");
	                                                        strcpy(listaVariables[variableActual++],$1); insertar_id_en_ts($1);
                                                        };

 /* Fin de Declaracion de variables */

/* Seccion de codigo */

bloque:                                                 /* No existen bloques sin sentencias */
	bloque sentencia	                                {printf("Regla 10: bloque es bloque sentencia\n");}
	| sentencia			                                {printf("Regla 11: bloque es sentencia\n");};
	
sentencia:
	asignacion			                    			{printf("Regla 12: sentencia es asignacion\n");}
	| bloque_if                                         {printf("Regla 13: sentencia es bloque_if\n");}
	| bloque_while                                      {printf("Regla 14: sentencia es bloque_while\n");}
	| lectura                                			{printf("Regla 15: sentencia es lectura\n");}
	| escritura                              			{printf("Regla 16: sentencia es escritura\n");};

/* ASIGNACION */

asignacion:
	ID ASIG {IndId = crearTerceto_ccc($1, "","");} expresion_aritmetica { 
									char cadenaExpresion[5], cadenaLong[5], cadenaId[5];
									if(es_long == 0)
									{
										
										cadenaIndice(IndExpresion,cadenaExpresion);
										cadenaIndice(IndId,cadenaId);
										IndAsignacion = crearTerceto_ccc("=", cadenaId, cadenaExpresion);
									}
									else
									{

										cadenaIndice(IndId,cadenaId);
										cadenaIndice(IndLong,cadenaLong);
										IndAsignacion = crearTerceto_ccc("=", cadenaId , cadenaLong); 
										es_long = 0;
									}
									int tipo = buscarTipoTS($1);
									verificarTipoDato(tipo);
									reiniciarTipoDato();
								 };

/* WHILE */

bloque_while:
    WHILE { while_guardar_pos(terceto_index); } expresion_logica { if(strcmp(valor_comparacion, "") != 0) while_guardar_pos(crearTerceto_ccc(valor_comparacion, "", "")); else while_index++; }
	THEN bloque ENDWHILE              
    													{printf("Regla 20: bloque_while es WHILE expresion_logica THEN bloque ENDWHILE\n");
														char cadSalto[5];
														cadenaIndice(terceto_index+1,tercetos[while_pos_a_completar[while_index]].dos);
														while_index--;
														cadenaIndice(while_pos_a_completar[while_index],cadSalto);
														crearTerceto_ccc("BI", cadSalto, "");
														while_index--;
														completar_salto_si_es_comparacion_AND(terceto_index);
														};

/* FIN ASIGNACION */

/* IF */

bloque_if:
    IF expresion_logica 								{ 
															if(strcmp(valor_comparacion, "") != 0)
															if_guardar_salto(crearTerceto_ccc(valor_comparacion, "", ""));
															else
															if_index++;
														}
	THEN decision_bloque ENDIF   						{	printf("Regla 18: bloque_if es IF expresion_logica THEN decision_bloque ENDIF\n");	};

decision_bloque:
		  bloque 										{
															if_completar_ultimo_salto_guardado_con(terceto_index);
															completar_salto_si_es_comparacion_AND(terceto_index);
															printf("Regla 19: decision_bloque es bloque\n");
														}
		| bloque 										{ 
															if_completar_ultimo_salto_guardado_con(terceto_index+1);
															completar_salto_si_es_comparacion_AND(terceto_index+1);
															if_guardar_salto(crearTerceto_ccc("BI", "",""));
														}
		  ELSE bloque 									{
															if_completar_ultimo_salto_guardado_con(terceto_index);
															printf("Regla 20: decision_bloque es bloque ELSE bloque\n");
														};

/* FIN IF */

/* EXPRESIONES LOGICAS */

expresion_logica: termino_logico { and_index++; saltos_and_a_completar[and_index] = -1; }
         | termino_logico { and_index++; saltos_and_a_completar[and_index] = crearTerceto_ccc(valor_comparacion, "", ""); } AND termino_logico
		 | termino_logico {
				char cadInd[5];
				and_index++; saltos_and_a_completar[and_index] = -1;
				cadenaIndice(terceto_index+2,cadInd);
				crearTerceto_ccc(valor_comparacion, cadInd, ""); // salto a la prox comparación
				pos_a_completar_OR = crearTerceto_ccc("BI","",""); // tengo que saltar al final de la prox termino_logico
				}
			OR termino_logico {
				char *salto = (char*) malloc(sizeof(int));
				itoa(terceto_index+1, salto, 10);
				tercetos[pos_a_completar_OR].dos = (char*) malloc(sizeof(char)*strlen(salto));
				strcpy(tercetos[pos_a_completar_OR].dos, salto);
			}
		 ;

termino_logico: expresion_aritmetica { IndComparacion = IndExpresion; } MENOR expresion_aritmetica { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BGE");
			 }
		   | expresion_aritmetica { IndComparacion = IndExpresion; } MENOR_IGUAL expresion_aritmetica { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BGT");
			 }
		   | expresion_aritmetica { IndComparacion = IndExpresion; } MAYOR expresion_aritmetica       { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BLE");
			 }
		   | expresion_aritmetica { IndComparacion = IndExpresion; } MAYOR_IGUAL expresion_aritmetica { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BLT");
			 }
		   | expresion_aritmetica { IndComparacion = IndExpresion; } IGUAL expresion_aritmetica       { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BNE");
			 }
		   | expresion_aritmetica { IndComparacion = IndExpresion; } DISTINTO expresion_aritmetica    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BEQ");
			 }
			| NOT expresion_aritmetica { IndComparacion = IndExpresion; } MENOR expresion_aritmetica { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BLT");
			 }
		   | NOT expresion_aritmetica { IndComparacion = IndExpresion; } MENOR_IGUAL expresion_aritmetica { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BLE");
			 }
		   | NOT expresion_aritmetica { IndComparacion = IndExpresion; } MAYOR expresion_aritmetica       { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BGT");
			 }
		   | NOT expresion_aritmetica { IndComparacion = IndExpresion; } MAYOR_IGUAL expresion_aritmetica { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BGE");
			 }
		   | NOT expresion_aritmetica { IndComparacion = IndExpresion; } IGUAL expresion_aritmetica       { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BEQ");
			 }
		   | NOT expresion_aritmetica { IndComparacion = IndExpresion; } DISTINTO expresion_aritmetica    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); reiniciarTipoDato(); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BNE");
			 }
		   ;

comp_aritmetico:
	SUMA                                                {
															printf("Regla 48: comp_arimetico es SUMA\n");
															IndCompArit = crearTerceto_ccc("+","","");
														}
    |RESTA                                              {
															printf("Regla 49: comp_aritmetico es RESTA\n");
															IndCompArit = crearTerceto_ccc("-","","");
														}
    |POR                                        		{
															printf("Regla 50: comp_aritmetico es POR\n");
															IndCompArit = crearTerceto_ccc("*","","");
														}
    |DIVIDIDO                                        	{
															printf("Regla 51: comp_aritmetico es DIVIDIDO\n");
															IndCompArit = crearTerceto_ccc("/","","");
														}
															;	

/* FIN EXPRESIONES LOGICAS */

/*LONG  Y TAKE*/

long:
    LONG PA CA lista_exp_coma CC PC                     {
															printf("Regla 52: long es LONG PA CA lista_exp_coma CC PC\n");
															IndLong = crearTerceto_icc(cant_lista_long,"","");
															es_long = 1;
														}
	|LONG PA CA CC PC									{
															printf("Regla 53: long es LONG PA CA CC PC\n");
															IndLong = crearTerceto_icc(0,"","");
															es_long = 1;
														};

take:
    TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA lista_exp_punto_coma CC PC                    {
																											printf("Regla 54: TAKE es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA lista_exp_punto_coma CC PC\n");
																											int i;
																											int cant_operar = ($5);
																											char cadenaNumero[5], cadenaCompArit[5], cadenaTake[5];
																											if(cant_operar==0)
																											{
																												IndTake = crearTerceto_icc(0,"","");
																											}																											
																											if(cant_operar>(posicion_numero_take+1))
																											{
																												printf("Error: El 2do parametro de TAKE (Cantidad de operandos a aplicar operacion) es mayor a la cantidad de operandos de la lista.");
																												exit(1);
																											}
																											for(i=0;i<cant_operar;i++)
																											{
																												if(i==0)
																												{
																													cadenaIndice(take_numeros[i],cadenaNumero);
																													IndTake = crearTerceto_ccc(cadenaNumero,"","");
																												}
																												else
																												{
																													cadenaIndice(take_numeros[i],cadenaNumero);
																													cadenaIndice(IndCompArit,cadenaCompArit);
																													cadenaIndice(IndTake,cadenaTake);
																													IndTake = crearTerceto_ccc(cadenaCompArit,cadenaTake,cadenaNumero);
																												}
																											}
																											cadenaIndice(IndTake,cadenaTake);
																											IndTake = crearTerceto_ccc(cadenaTake,"","");
																											
																										}
	|TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA CC PC									{
																										printf("Regla 55: TAKE es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA CC PC");
																										IndTake = crearTerceto_icc(0,"","");
																									};

lista_exp_coma:
    lista_exp_coma COMA expresion_aritmetica            {
															printf("Regla 56: lista_exp_coma es lista_exp_coma COMA expresion_aritmetica\n");
															cant_lista_long++;
														}
    | expresion_aritmetica                              {
															printf("Regla 57: lista_exp_coma es expresion_aritmetica\n");
															cant_lista_long=1;
														};
														

lista_exp_punto_coma:
	lista_exp_punto_coma PUNTO_COMA expresion_aritmetica            {
																		printf("Regla 58: lista_exp_punto_coma es lista_exp_punto_coma PUNTO_COMA expresion_aritmetica\n");
																		posicion_numero_take++;
																		take_numeros[posicion_numero_take] = IndExpresion;
																	}
    | expresion_aritmetica                              			{
																		printf("Regla 59: lista_exp_punto_coma es expresion_aritmetica\n");
																		posicion_numero_take = 0;
																		take_numeros[posicion_numero_take] = IndExpresion;
																	};


/* FIN LONG Y TAKE */

/* EXPRESIONES ARITMETICAS */

expresion_aritmetica: expresion_aritmetica SUMA termino  { 	char cadIndExpr[5], cadIndTer[5];
															cadenaIndice(IndExpresion,cadIndExpr);
															cadenaIndice(IndTermino,cadIndTer);
															IndExpresion = crearTerceto_ccc("+", cadIndExpr, cadIndTer); }
		 | expresion_aritmetica RESTA termino { 	char cadIndExpr[5], cadIndTer[5];
															cadenaIndice(IndExpresion,cadIndExpr);
															cadenaIndice(IndTermino,cadIndTer);
															IndExpresion = crearTerceto_ccc("-", cadIndExpr, cadIndTer); }
		 | termino  { IndExpresion = IndTermino; }
		 ;

termino: termino POR factor  { 	char cadIndFac[5], cadIndTer[5];
								cadenaIndice(IndFactor,cadIndFac);
								cadenaIndice(IndTermino,cadIndTer);
								IndTermino = crearTerceto_ccc("*", cadIndTer, cadIndFac); }
	   | termino DIVIDIDO factor   { 	char cadIndFac[5], cadIndTer[5];
										cadenaIndice(IndFactor,cadIndFac);
										cadenaIndice(IndTermino,cadIndTer);
										IndTermino = crearTerceto_ccc("/", cadIndTer, cadIndFac); }
	   | factor                  { IndTermino = IndFactor; }
	   ;

factor: ID	               { 
								int tipo = buscarTipoTS(yylval.valor_string);
								verificarTipoDato(tipo);
								IndFactor = crearTerceto_ccc($1, "", ""); 
							}
	  | constante
	  | PA {    ponerEnPila(&pilaTermino, IndTermino);
                 ponerEnPila(&pilaExpresion, IndExpresion);
            }
        expresion_aritmetica PC  {
                            IndFactor = IndExpresion;
                            IndExpresion = sacarDePila(&pilaExpresion);
                            IndTermino = sacarDePila(&pilaTermino);
                        }
	  | long			{ 
						verificarTipoDato(Integer);
						IndFactor = IndLong; 
						}
	  | take			{ 
						verificarTipoDato(Float);
						IndFactor = IndTake; 
						}
	  ;


constante: CTE_INT    { verificarTipoDato(Integer); IndFactor = crearTerceto_icc($1, "", ""); }
         | CTE_STRING { IndFactor = crearTerceto_ccc($1, "", ""); }
		 | CTE_FLOAT  { verificarTipoDato(Float); IndFactor = crearTerceto_fcc($1, "", ""); }
		 ;

/* FIN EXPRESIONES ARITMETICAS */

/* LECTURA */

lectura: GET ID			{ 	char cadIndEntra[5];
							existe_en_ts($2);
							IndEntrada = crearTerceto_ccc($2, "", "");
							cadenaIndice(IndEntrada,cadIndEntra);
							crearTerceto_ccc("GET",cadIndEntra,"");
							}
       ;

/* FIN LECTURA */

/* ESCRITURA */

escritura: DISPLAY CTE_STRING	{ char cadIndSali[5];
								IndSalida = crearTerceto_ccc($2, "", "");
								cadenaIndice(IndSalida,cadIndSali);
							  crearTerceto_ccc("DISPLAY",cadIndSali,"");
							}
      | DISPLAY ID 			{ 
							  char cadIndSali[5];
							  existe_en_ts($2); 
							  IndSalida = crearTerceto_ccc($2, "", "");
							  cadenaIndice(IndSalida,cadIndSali);
							  crearTerceto_ccc("DISPLAY",cadIndSali,"");
							}
	  ;

/* FIN ESCRITURA */

%%

int main(int argc,char *argv[])
{

  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
    crearPila(&pilaExpresion);
    crearPila(&pilaTermino);
	yyparse();
	save_reg_ts();
	save_tercetos();
  }
  fclose(yyin);
  return 0;
}

int yyerror(char *errMessage)
{
   printf("(!) ERROR en la linea %d: %s\n",yylineno,errMessage);
   fprintf(stderr, "Fin de ejecucion.\n");
   system ("Pause");
   exit (1);
}

void reinicioVariables() {
	variableActual=0;
    strcpy(tipoActual,"");
}


/* Tercetos */
int crearTerceto_ccc(char *uno, char *dos, char *tres) {
	struct terceto terc;
	int index = terceto_index;
	terc.uno = malloc(sizeof(char)*strlen(uno)+1);
	strcpy(terc.uno, uno);
	terc.dos = malloc(sizeof(char)*strlen(dos)+1);
	strcpy(terc.dos, dos);
	terc.tres = malloc(sizeof(char)*strlen(tres)+1);
	strcpy(terc.tres, tres);
	tercetos[index] = terc;
	terceto_index++;
	return index; // devuelvo la pos del terceto creado
}

int crearTerceto_cci(char *uno, char *dos, int tres) {
	char *tres_char = (char*) malloc(sizeof(int));
	itoa(tres, tres_char, 10);
	return crearTerceto_ccc(uno, dos, tres_char);
}

int crearTerceto_cii(char *uno, int dos, int tres) {
	struct terceto terc;
	int index = terceto_index;
	char *dos_char = (char*) malloc(sizeof(int));
	itoa(dos, dos_char, 10);
	return crearTerceto_cci(uno, dos_char, tres);
}

int crearTerceto_fcc(float uno, char *dos, char *tres) {
	char *uno_char = (char*) malloc(sizeof(float));
	snprintf(uno_char, sizeof(float), "%f", uno);
	return crearTerceto_ccc(uno_char, dos, tres);
}

int crearTerceto_iii(int uno, int dos, int tres) {
	struct terceto terc;
	int index = terceto_index;
	char *uno_char = (char*) malloc(sizeof(int));
	itoa(uno, uno_char, 10);
	return crearTerceto_cii(uno_char, dos, tres);
}

int crearTerceto_icc(int uno, char *dos, char *tres) {
	char *uno_char = (char*) malloc(sizeof(int));
	itoa(uno, uno_char, 10);
	return crearTerceto_ccc(uno_char, dos, tres);
}

int crearTerceto_cic(char *uno, int dos, char *tres) {
	char *dos_char = (char*) malloc(sizeof(int));
	itoa(dos, dos_char, 10);
	return crearTerceto_ccc(uno, dos_char, tres);
}

void save_tercetos() {
	FILE *file = fopen("Intermedia.txt", "w");

	if(file == NULL)
	{
    	printf("(!) ERROR: No se pudo abrir el txt correspondiente a la generacion de codigo intermedio\n");
	}
	else
	{
		int i = 0;
		for (i;i<terceto_index;i++) {
			// printf("%d (%s, %s, %s)\n", i, tercetos[i].uno, tercetos[i].dos, tercetos[i].tres);
			fprintf(file, "%d (%s, %s, %s)\n", i, tercetos[i].uno, tercetos[i].dos, tercetos[i].tres);
		}
		fclose(file);
	}
}

/* Funcion para sintaxis indices */
void cadenaIndice(int indice, char* cadena)
{
	char ind[5];
	strcpy(cadena,"[");
	itoa(indice,ind,10);
	strcat(cadena,ind);
	strcat(cadena,"]");
}

/* Funcion para simil apilar las posiciones y permitir ifs anidados */
void if_guardar_salto(int pos) {
	if (if_index < 6)
	{
		if_index++;
		if_saltos[if_index] = pos;
	}
	else
	{
		yyerror("No se puede tener más de 5 ifs anidados\n");
	}
}

/* Funcion para simil desapilar y completar las posiciones del if */
void if_completar_ultimo_salto_guardado_con(int pos) {
	char salto[7];
	cadenaIndice(pos,salto);
	tercetos[if_saltos[if_index]].dos = (char*) malloc(sizeof(char)*strlen(salto));
	strcpy(tercetos[if_saltos[if_index]].dos, salto);
	if_index--;
}

/* Funcion para simil apilar las pos del while */
void while_guardar_pos(int pos) {
	if (if_index < 11) // se usa del 1 al 10 y se ocupan dos pos por cada while
	{
		while_index++;
		while_pos_a_completar[while_index] = pos;
	}
	else
	{
		yyerror("No se puede tener más de 5 whiles anidados");
	}
}

/* Si el flag de AND esta prendido completa la pos guardada y vuelve el flag a off */
void completar_salto_si_es_comparacion_AND(int pos) {
		if (saltos_and_a_completar[and_index] == -1){
			and_index--; // flags usados para mantener la correlatividad de la pila de if con la de and
		}
		else {
			char salto[7];
			cadenaIndice(pos,salto);
			tercetos[saltos_and_a_completar[and_index]].dos = (char*) malloc(sizeof(char)*strlen(salto));
			strcpy(tercetos[saltos_and_a_completar[and_index]].dos, salto);
			and_index--;
		}

}

int buscarTipoTS(char* nombreVar) {

	int pos = nombre_existe_en_ts(nombreVar);
	if (pos == -1) {
		
		char *nomCte = (char*) malloc(31*sizeof(char));
		*nomCte = '\0';
		strcat(nomCte, "_");
		strcat(nomCte, nombreVar);
	
		char *original = nomCte;
		while(*nomCte != '\0') {
			if (*nomCte == ' ' || *nomCte == '"' || *nomCte == '!' 
				|| *nomCte == '.') {
				*nomCte = '_';
			}
			nomCte++;
		}
		nomCte = original;

		int pos = nombre_existe_en_ts(nomCte);
		if (pos == -1) {
			yyerror("La variable no fue declarada");
		}
	}
	
	return tipoDeDato(pos);

}

void verificarTipoDato(int tipo) {

	if(tipoDatoActual == -1) {
		tipoDatoActual = tipo;
		return;
	}
	
	if(tipoDatoActual != tipo) {
		yyerror("No se admiten operaciones aritmeticas con tipo de datos distintos");
	}
	
}

void reiniciarTipoDato() {
	tipoDatoActual = -1;
}

/* PILA */

void crearPila( Pila *p){
    p->tope = 0;
}

int pilaLLena( Pila *p ){
    return p->tope == tamPila;
}

int pilaVacia( Pila *p){
    return p->tope == tamPila;
}

int ponerEnPila(Pila *p, int dato){
    if( p->tope == 100){
        return 0;
    }
    p->pila[p->tope] = dato;
    p->tope++;
    return 1;
}

int sacarDePila(Pila *p){
    if( p->tope == 0){
        return 0;
    }
    p->tope--;
    return p->pila[p->tope];
}

/************************************************************************************************************/

void genera_asm()
{
	int cont=0;
	char* file_asm = "Final.asm";
	FILE* pf_asm;
	char aux[10];
	
	int lista_etiquetas[1000];
	int cant_etiquetas = 0;
	char etiqueta_aux[10];

	char ult_op1_cmp[30];
	strcpy(ult_op1_cmp, "");
	char op1_guardado[30];
printf("HOLA1\n");
	if((pf_asm = fopen(file_asm, "w")) == NULL)
	{
		printf("Error al generar el asembler \n");
		exit(1);
	}
	 /* generamos el principio del assembler, que siempre es igual */

	 fprintf(pf_asm, "include macros2.asm\n");
	 fprintf(pf_asm, "include number.asm\n");
	 fprintf(pf_asm, ".MODEL	LARGE \n");
	 fprintf(pf_asm, ".386\n");
	 fprintf(pf_asm, ".STACK 200h \n");
	 generaSegmDatosAsm(pf_asm);
	 fprintf(pf_asm, ".CODE \n");
	 fprintf(pf_asm, "MAIN:\n");
	 fprintf(pf_asm, "\n");

    fprintf(pf_asm, "\n");
    fprintf(pf_asm, "\t MOV AX,@DATA 	;inicializa el segmento de datos\n");
    fprintf(pf_asm, "\t MOV DS,AX \n");
    fprintf(pf_asm, "\t MOV ES,AX \n");
    fprintf(pf_asm, "\t FNINIT \n");;
    fprintf(pf_asm, "\n");

	int i, j;
	int opSimple,  // Formato terceto (x,  ,  ) 
		opUnaria,  // Formato terceto (x, x,  )
		opBinaria; // Formato terceto (x, x, x)
	int agregar_etiqueta_final_nro = -1;
	
	// Guardo todos los tercetos donde tendrÃ­a que poner etiquetas
	for(i = 0; i < terceto_index; i++)
	{
		if (strcmp(tercetos[i].dos, "") != 0 && strcmp(tercetos[i].tres, "") ==0)
		{
			if (strcmp(tercetos[i].uno, "READ") != 0 && strcmp(tercetos[i].uno, "WRITE") != 0)
			{
				int found = -1;
				int j;
				for (j = 1; j<=cant_etiquetas; j++)
				{
					if (lista_etiquetas[j] == atoi(tercetos[i].dos))
					{
						found = 1;
					}
				}
				if (found == -1) 
				{
					cant_etiquetas++;
					lista_etiquetas[cant_etiquetas] = atoi(tercetos[i].dos);
				}
			}
		}	
	}
	printf("HOLA2 lenght: %d\n",terceto_index);

	// Armo el assembler
	for (i = 0; i < terceto_index; i++) 
	{
		//printf("TERCETO NUMERO %d \n", i);

		if (strcmp("", tercetos[i].dos) == 0) {
			opSimple = 1;
			opUnaria = 0;
			opBinaria = 0;
		} else if (strcmp("", tercetos[i].tres) == 0) {
			opSimple = 0;
			opUnaria = 1;
			opBinaria = 0;
		} else {
			opSimple = 0; 
			opUnaria = 0;
			opBinaria = 1;
		}
printf("HOLA3.%d.1\n",i);
		for (j=1;j<=cant_etiquetas;j++) {
			if (i == lista_etiquetas[j])
			{
				sprintf(etiqueta_aux, "ETIQ_%d", lista_etiquetas[j]);
				fprintf(pf_asm, "%s: \n", etiqueta_aux);
				printf("HOLA3.%d.14\n",i);
			}
		}
printf("HOLA3.%d.2\n",i);

		if (opSimple == 1) {
			// Ids, constantes
			cant_op++;
			printf("HOLA3.%d.12\n",i);
			strcpy(lista_operandos_assembler[cant_op], tercetos[i].uno);
		} 
		else if (opUnaria == 1) {
			// Saltos, write, read
			
			if (strcmp("DISPLAY", tercetos[i].uno) == 0) 
			{	
				int tipo = buscarTipoTS(tercetos[atoi(tercetos[i].dos)].uno);
				printf("HOLA3.%d.11\n",i);
				if (tipo == Float) 
				{
					fprintf(pf_asm, "\t DisplayFloat %s,2 \n", getNombreAsm(tercetos[atoi(tercetos[i].dos)].uno));
				}
				else if (tipo == Integer) 
				{
					fprintf(pf_asm, "\t DisplayFloat %s,2 \n", getNombreAsm(tercetos[atoi(tercetos[i].dos)].uno));
				} else 
				{
					fprintf(pf_asm, "\t DisplayString %s \n", getNombreAsm(tercetos[atoi(tercetos[i].dos)].uno));
				}
				// Siempre inserto nueva linea despues de mostrar msj
				printf("HOLA3.%d.12\n",i);
				fprintf(pf_asm, "\t newLine \n");
			}
			else if (strcmp("GET", tercetos[i].uno) == 0) 
			{
				int tipo = buscarTipoTS(tercetos[atoi(tercetos[i].dos)].uno);
				if (tipo == Float) 
				{
					fprintf(pf_asm, "\t GetFloat %s\n", getNombreAsm(tercetos[atoi(tercetos[i].dos)].uno));
				} 
				else if (tipo == Integer) 
				{
				printf("HOLA3.%d.9\n",i);
					// pongo getfloat para manejar todo con fld en las operaciones
					fprintf(pf_asm, "\t GetFloat %s\n", getNombreAsm(tercetos[atoi(tercetos[i].dos)].uno));
				}	
				else 
				{
				printf("HOLA3.%d.10\n",i);
					fprintf(pf_asm, "\t GetString %s\n", getNombreAsm(tercetos[atoi(tercetos[i].dos)].uno));
				}
			}
			else // saltos
			{
			printf("HOLA3.%d.7\n",i);
				char *codigo = getCodOp(tercetos[i].uno);
				sprintf(etiqueta_aux, "ETIQ_%d", atoi(tercetos[i].dos));
				if (atoi(tercetos[i].dos) >= terceto_index) 
				{
					agregar_etiqueta_final_nro = atoi(tercetos[i].dos);
				}
				fflush(pf_asm); 
				printf("HOLA3.%d.8\n",i);
				fprintf(pf_asm, "\t %s %s \t;Si cumple la condicion salto a la etiqueta\n", codigo, etiqueta_aux);
				printf("HOLA3.%d.81\n",i);
			}
			printf("HOLA3.%d.82\n",i);
 		}
		else {
			// Expresiones ; Comparaciones ; Asignacion
			char *op2 = (char*) malloc(100*sizeof(char));
			strcpy(op2, lista_operandos_assembler[cant_op]);
			cant_op--;
printf("HOLA3.%d.6\n",i);
			char *op1 = (char*) malloc(100*sizeof(char));
			if (strcmp(tercetos[i].uno, "CMP" ) == 0 && strcmp(ult_op1_cmp, tercetos[i].dos) == 0 )
			{
				strcpy(op1, op1_guardado);
			}
			else 
			{
				strcpy(op1, lista_operandos_assembler[cant_op]); 
				cant_op--;
				strcpy(op1_guardado, op1);
			}
			printf("HOLA3.%d.5\n",i);
			if (strcmp(tercetos[i].uno, "=" ) == 0)
			{
				int tipo = buscarTipoTS(tercetos[atoi(tercetos[i].dos)].uno);
				if (tipo == Float | tipo == Integer) // Si se quiere separar integer hay que ver tambien las expresiones
				{
					fprintf(pf_asm, "\t FLD %s \t;Cargo valor \n", getNombreAsm(op1));
					fprintf(pf_asm, "\t FSTP %s \t; Se lo asigno a la variable que va a guardar el resultado \n", getNombreAsm(op2));
				}
				else
				{
					fprintf(pf_asm, "\t mov si,OFFSET %s \t;Cargo en si el origen\n", getNombreAsm(op1));
					fprintf(pf_asm, "\t mov di,OFFSET %s \t; cargo en di el destino \n", getNombreAsm(op2));
					fprintf(pf_asm, "\t STRCPY\t; llamo a la macro para copiar \n");
				}	
			}
			else if (strcmp(tercetos[i].uno, "CMP" ) == 0)
			{
				int tipo = buscarTipoTS(op1);
				if (tipo == Float | tipo == Integer) 
				{
					fprintf(pf_asm, "\t FLD %s\t\t;comparacion, operando1 \n", getNombreAsm(op1));
					fprintf(pf_asm, "\t FLD %s\t\t;comparacion, operando2 \n", getNombreAsm(op2));
					fprintf(pf_asm, "\t FCOMP\t\t;Comparo \n");
					fprintf(pf_asm, "\t FFREE ST(0) \t; Vacio ST0\n");
					fprintf(pf_asm, "\t FSTSW AX \t\t; mueve los bits C a FLAGS\n");
					fprintf(pf_asm, "\t SAHF \t\t\t;Almacena el registro AH en el registro FLAGS \n");
				}
				else
				{
					fprintf(pf_asm, "\t mov si,OFFSET %s \t;Cargo operando1\n", getNombreAsm(op1));
					fprintf(pf_asm, "\t mov di,OFFSET %s \t; cargo operando2 \n", getNombreAsm(op2));
					fprintf(pf_asm, "\t STRCMP\t; llamo a la macro para comparar \n");	
				}

				strcpy(ult_op1_cmp, tercetos[i].dos);
			}
			else
			{
				int tipo = buscarTipoTS(op1);
				if (tipo == String)
				{
					yyerror("Ops! No estan soportadas las operaciones entre cadenas\n");
				}
				sprintf(aux, "_aux%d", i); // auxiliar relacionado al terceto
				insertar_ts_si_no_existe(aux, "FLOAT", "", "");
				fflush(pf_asm);
				fprintf(pf_asm, "\t FLD %s \t;Cargo operando 1\n", getNombreAsm(op1));
				fprintf(pf_asm, "\t FLD %s \t;Cargo operando 2\n", getNombreAsm(op2));
				fflush(pf_asm);
printf("HOLA3.%d.4\n",i);
				fprintf(pf_asm, "\t %s \t\t;Opero\n", getCodOp(tercetos[i].uno));
				fprintf(pf_asm, "\t FSTP %s \t;Almaceno el resultado en una var auxiliar\n", getNombreAsm(aux));
				
				cant_op++;
				strcpy(lista_operandos_assembler[cant_op], aux);
			}
			
		}
		printf("HOLA3.%d.323\n",i);
	}
printf("HOLA3\n");
	printf("HOLA4\n");
	if(agregar_etiqueta_final_nro != -1) {
	printf("HOLA2.2\n");
		sprintf(etiqueta_aux, "ETIQ_%d", agregar_etiqueta_final_nro);
		printf("HOLA2.3\n");
		fprintf(pf_asm, "%s: \n", etiqueta_aux);
		printf("HOLA2.4\n");
	}

printf("HOLA2.5\n");
	/*generamos el final */
	fprintf(pf_asm, "\t mov AX, 4C00h \t ; Genera la interrupcion 21h\n");
	fprintf(pf_asm, "\t int 21h \t ; Genera la interrupcion 21h\n");
	fprintf(pf_asm, "END MAIN\n");
	fclose(pf_asm);


}

/************************************************************************************************************/
char* getCodOp(char* token)
{
	if(!strcmp(token, "+"))
	{
		return "FADD";
	}
	else if(!strcmp(token, "="))
	{
		return "MOV";
	}
	else if(!strcmp(token, "-"))
	{
		return "FSUB";
	}
	else if(!strcmp(token, "*"))
	{
		return "FMUL";
	}
	else if(!strcmp(token, "/"))
	{
		return "FDIV";
	}
	else if(!strcmp(token, "BNE"))
	{
		return "JNE";
	}
	else if(!strcmp(token, "BEQ"))
	{
		return "JE";
	}
	else if(!strcmp(token, "BGE"))
	{
		return "JNA";
	}
	else if(!strcmp(token, "BGT"))
	{
		return "JNAE";
	}
	else if(!strcmp(token, "BLE"))
	{
		return "JNB";
	}
	else if(!strcmp(token, "BLT"))
	{
		return "JNBE";
	}
	else if (!strcmp(token, "BI")) {
		return "JMP";
	}
}

/*
	Obtiene los nombres para assembler
*/
char* getNombreAsm(char *cte_o_id) {
	char* nombreAsm = (char*) malloc(sizeof(char)*200);
	nombreAsm[0] = '\0';
	strcat(nombreAsm, "@"); // prefijo agregado
	
	int pos = nombre_existe_en_ts(cte_o_id);
	if (pos==-1) { //si no lo encuentro con el mismo nombre es porque debe ser cte		
		char *nomCte = (char*) malloc(31*sizeof(char));
		*nomCte = '\0';
		strcat(nomCte, "_");
		strcat(nomCte, cte_o_id);
	
		char *original = nomCte;
		while(*nomCte != '\0') {
			if (*nomCte == ' ' || *nomCte == '"' || *nomCte == '!' 
				|| *nomCte == '.') {
				*nomCte = '_';
			}
			nomCte++;
		}
		nomCte = original;
		strcat(nombreAsm, nomCte);
	} else {
		strcat(nombreAsm, cte_o_id);
	}
	
	return nombreAsm;
}




