/**
 * 
 *  UNLaM
 *  Lenguajes y Compiladores ( 2019 1C )
 *   
 *  Temas especiales: 
 *     1-Longitud
 *	   2-Take
 *	   3-Tercetos
 *
 *  Docente:  Mara Capuya , Henan Villareal, Daniel Carrizo
 *
 *  Integrantes:
 *	Brian Bayarri, Nicolas Bedetti, Aylen Hoz, German Lopez, Julian Morganella
 *      
 */
%code requires {
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <string.h>
	#include "y.tab.h"

	#include "./tabla_simbolos.h"
	#include "./tercetos.h"
	#include "./sentencias_control.h"
	#include "./take_long.h"
}

%{
	int yystopparser=0;
	FILE  *yyin;	
	
	/* Funciones necesarias */
	int yyerror(char* mensaje);
	int yyerror();
	int yylex();

	void chequearTipoDato(int tipo);
	void resetTipoDato();

	/* Cosas de tabla de simbolos */
	simbolo tabla_simbolo[TAMANIO_TABLA];
	int fin_tabla = -1; /* Apunta al ultimo registro en la tabla de simbolos. Incrementarlo para guardar el siguiente. */

	/* Cosas para la declaracion de variables y la tabla de simbolos */
	int varADeclarar1 = 0;
	int cantVarsADeclarar = 0;
	int tipoDatoADeclarar;

	/* Cosas para las asignaciones */
	char idAsignar[TAM_NOMBRE];
	/* Cosas para comparadores booleanos */
	int comp_bool_actual;
	/* Cosas para control de tipo de datos en expresiones aritméticas */
	int tipoDatoActual = sinTipo;

	/* Cosas para tercetos */
	terceto lista_terceto[MAX_TERCETOS];
	int ultimo_terceto = -1; /* Apunta al ultimo terceto escrito. Incrementarlo para guardar el siguiente. */

	/* Cosas para anidamientos de if y while */
	int falseIzq=VALOR_NULO;
	int falseDer=VALOR_NULO;
	int verdadero=VALOR_NULO;
	int always=VALOR_NULO;

	info_elemento_pila pila_bloques[MAX_ANIDAMIENTOS];
	int ult_pos_pila_bloques=VALOR_NULO;

	int cant;

	/* Indices extras para if y while */
	int ind_if;
	int ind_endif;
	int ind_else;
	int ind_then;
	int ind_endwhile;

	/* Indices para no terminales */
	int ind_bloque;
	int ind_sent;
	int ind_bif;
	int ind_bwhile;
	int ind_btrue;
	int ind_asig;
	int ind_xp;
	int ind_xpcad;
	int ind_expr; //Expresion aritmetica
	int ind_term;
	int ind_factor;
	int ind_xplogic;
	int ind_tlogic;
	int ind_tlogic_izq;
	int ind_expr_izq;
	int ind_lec; //Lista expresion coma
	int ind_lepc; //Lista expresion punto y coma
	int ind_lectura;
	int ind_escritura;
	int ind_long;
	int ind_take;
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

%%

programa:
	START seccion_declaracion bloque END 	            {
															printf("\nCOMPILACION EXITOSA\n");
															guardarTabla();
															guardarTercetos(); 
														};

 /* Declaracion de variables */

seccion_declaracion:
	DEFVAR bloque_dec ENDDEF 				            {printf("Regla 1: Seccion declaracion es DEFVAR bloque_dec ENDEC\n");};

bloque_dec:
	bloque_dec declaracion					            {printf("Regla 2: bloque_dec es bloque_dec declaracion\n");}
	| declaracion							            {printf("Regla 3: bloque_dec es declaracion\n");};

declaracion:
	t_dato DOS_PUNTOS lista_id				            {
															printf("Regla 4: declaracion es t_dato DOS_PUNTOS lista_id\n");
															 agregarTiposDatosATabla();
														};

t_dato:
	FLOAT		                                        {
															printf("Regla 5: t_dato es FLOAT\n");
															tipoDatoADeclarar = Float;
														}
	| INT		                                        {
															printf("Regla 6: t_dato es INT\n");
															tipoDatoADeclarar = Int;
														}
	| STRING	                                        {
															printf("Regla 7: t_dato es STRING\n");
															tipoDatoADeclarar = String;
														};

lista_id:
	lista_id PUNTO_COMA ID	                            {
	                                                        printf("Regla 8: lista_id es lista_id PUNTO_COMA ID\n");
	                                                        agregarVarATabla(yylval.valor_string);
															cantVarsADeclarar++;
                                                        }
	| ID				                                {
	                                                        printf("Regla 9: lista_id es ID\n");
	                                                        agregarVarATabla(yylval.valor_string);
															varADeclarar1 = fin_tabla; /* Guardo posicion de primer variable de esta lista de declaracion. */
															cantVarsADeclarar = 1;
                                                        };

 /* Fin de Declaracion de variables */

 /* Seccion de codigo */

bloque:                                                 /* No existen bloques sin sentencias */
	bloque sentencia	                                {printf("Regla 10: bloque es bloque sentencia\n");
														 ind_bloque = crear_terceto(BLOQ, ind_bloque, ind_sent);}
	| sentencia			                                {printf("Regla 11: bloque es sentencia\n");
														 ind_bloque = ind_sent;};

sentencia:
	asignacion			                    			{printf("Regla 12: sentencia es asignacion\n");
														 ind_sent = ind_asig;}
	| bloque_if                                         {printf("Regla 13: sentencia es bloque_if\n");
														 ind_sent = ind_bif;}
	| bloque_while                                      {printf("Regla 14: sentencia es bloque_while\n");
														 ind_sent = ind_bwhile;}
	| lectura                                			{printf("Regla 15: sentencia es lectura\n");
														 ind_sent = ind_lectura;}
	| escritura                              			{printf("Regla 16: sentencia es escritura\n");
														 ind_sent = ind_escritura;}
	| expresion_aritmetica                   			{printf("Regla 17: sentencia es expresion_aritmetica\n");
														 resetTipoDato();
														 ind_sent = ind_expr;};
/* Cosas de if */

rutina_if:
														{
															ind_if=crear_terceto(IF, NOOP, NOOP);
															apilar_IEP();
														};
rutina_then:
														{
															ind_then=crear_terceto(THEN,NOOP,NOOP);
															ponerSaltosThen();
														};
rutina_else:
														{
														 	always = crear_terceto(JMP, NOOP, NOOP);
															ind_else = crear_terceto(ELSE,NOOP,NOOP);
															ponerSaltosElse();
														};




bloque_if:
    IF rutina_if expresion_logica THEN rutina_then bloque ENDIF               
    													{printf("Regla 18: bloque_if es IF expresion_logica THEN bloque ENDIF\n");
    													ind_endif=crear_terceto(ENDIF,NOOP,NOOP);
														ind_else=ind_endif;
														ponerSaltosElse();
														desapilar_IEP();
														ind_bif=ind_if;
    													};

bloque_if:
    IF rutina_if expresion_logica THEN rutina_then bloque ELSE rutina_else bloque ENDIF   
    													{printf("Regla 19: bloque_if es IF expresion_logica THEN bloque ELSE bloque ENDIF\n");
    													ind_endif=crear_terceto(ENDIF,NOOP,NOOP);
														ponerSaltoEndif();
														desapilar_IEP();
														ind_bif=ind_if;
    													};

 /*ver lo del then vacio*/

 /* Cosas de while */

rutina_while:
														{
															ind_bwhile = crear_terceto(WHILE, NOOP, NOOP);
															apilar_IEP();
														};

bloque_while:
    WHILE rutina_while expresion_logica THEN rutina_then bloque ENDWHILE              
    													{printf("Regla 20: bloque_while es WHILE expresion_logica THEN bloque ENDWHILE\n");
    													 always = crear_terceto(JMP,ind_bwhile,NOOP);
														 ind_endwhile = crear_terceto(ENDWHILE, NOOP, NOOP);
														 ponerSaltoEndwhile();
														 desapilar_IEP();
    													};

asignacion:
	ID ASIG {strcpy(idAsignar, $1);} expresion	        {
															printf("Regla 21: asignacion es ID(%s) ASIG expresion\n\n", idAsignar);
															int tipo = chequearVarEnTabla(idAsignar);
															chequearTipoDato(tipo);
															resetTipoDato();
															int pos=buscarEnTabla(idAsignar);
															ind_asig = crear_terceto(ASIG, pos, ind_xp);
														};

/* Expresiones aritmeticas y otras */

expresion:
	expresion_cadena				                    {printf("Regla 22: expresion es expresion_cadena\n");
														 ind_xp = ind_xpcad;}
	| expresion_aritmetica			                    {printf("Regla 23: expresion es expresion_aritmetica\n");
														 ind_xp = ind_expr;};

expresion_cadena:
	CTE_STRING						                    {
															printf("Regla 23: expresion_cadena es CTE_STRING\n");
															int pos= agregarCteStringATabla(yylval.valor_string);
															ind_xpcad = crear_terceto(NOOP,pos,NOOP);
														};

/* Expresiones aritmeticas */

expresion_aritmetica:
	expresion_aritmetica SUMA termino 		            {
															printf("Regla 24: expresion_aritmetica es expresion_aritmetica SUMA termino\n");
															ind_expr = crear_terceto(SUMA, ind_expr, ind_term);
														}
	| expresion_aritmetica RESTA termino 	            {
															printf("Regla 25: expresion_aritmetica es expresion_aritmetica RESTA termino\n");
															ind_expr = crear_terceto(RESTA, ind_expr, ind_term);
														}
	| termino								            {
															printf("Regla 26: expresion_aritmetica es termino\n");
															ind_expr = ind_term;
														};

termino:
	termino POR factor 			                        {
															printf("Regla 27: termino es termino POR factor\n");
															ind_rterm = crear_terceto(POR, ind_term, ind_factor);
														}
	| termino DIVIDIDO factor 	                        {
															printf("Regla 28: termino es termino DIVIDIDO factor\n");
															ind_rterm = crear_terceto(DIVIDIDO, ind_term, ind_factor);
														}
	| factor					                        {
															printf("Regla 29: termino es factor\n");
															ind_rterm = ind_factor;
														};

factor:
	PA {apilar_IAEA();} expresion_aritmetica PC	        {
															printf("Regla 30: factor es PA expresion_aritmetica PC\n");
															ind_factor = ind_expr;
															desapilar_IAEA();
														}
    | long                                          	{
															printf("Regla 31: factor es long\n");
															chequearTipoDato(Int);
															ind_factor = ind_long;
    													}
	| take												{
															printf("Regla 32: factor es TAKE\n");
															chequearTipoDato(Int);
															ind_factor = ind_take;
														}
	| ID			                                    {
															printf("Regla 33: factor es ID\n");
															int tipo = chequearVarEnTabla(yylval.valor_string);
															chequearTipoDato(tipo);
															int pos = buscarEnTabla($1);
															ind_factor = crear_terceto(NOOP, pos, NOOP);								
														}

	| CTE_FLOAT	                                        {
															printf("Regla 34: factor es CTE_FLOAT\n");
															chequearTipoDato(Float);
															int pos = agregarCteFloatATabla(yylval.valor_float);
															ind_factor = crear_terceto(NOOP, pos, NOOP);
														}

	| CTE_INT	                                        {
															printf("Regla 35: factor es CTE_INT\n");
															chequearTipoDato(Int);
															int pos = agregarCteIntATabla(yylval.valor_int);
															ind_factor = crear_terceto(NOOP, pos, NOOP);
														};
/* Expresiones logicas */

/* Expresiones logicas */

expresion_logica:
    termino_logico_izq AND {falseIzq = crear_terceto(saltarFalse(comp_bool_actual), ind_tlogic, NOOP);}
							termino_logico              {
															printf("Regla 36: expresion_logica es termino_logico AND termino_logico\n");
															falseDer =  crear_terceto(saltarFalse(comp_bool_actual), ind_tlogic, NOOP);
															ind_xplogic = crear_terceto(AND, ind_tlogic_izq, ind_tlogic);
														}
    | termino_logico_izq OR {verdadero = crear_terceto(saltarTrue(comp_bool_actual), ind_tlogic, NOOP);}
							termino_logico              {
															printf("Regla 37: expresion_logica es termino_logico OR termino_logico\n");
															falseDer =  crear_terceto(saltarFalse(comp_bool_actual), ind_tlogic, NOOP);
															ind_xplogic = crear_terceto(OR, ind_tlogic_izq, ind_tlogic);
														}
    | termino_logico                                    {
															printf("Regla 38: expresion_logica es termino_logico\n");
															ind_xplogic = ind_tlogic;
															falseIzq = crear_terceto(saltarFalse(comp_bool_actual), ind_tlogic, NOOP);
														}
    | NOT termino_logico                                {
															printf("Regla 39: expresion_logica es NOT termino_logico\n");
															ind_xplogic = ind_tlogic;
															falseIzq = crear_terceto(saltarTrue(comp_bool_actual), ind_tlogic, NOOP);
														};

termino_logico_izq:
		termino_logico									{
															printf("Regla 40: termino_logico_izq es termino_logico\n");
															ind_tlogic_izq = ind_tlogic;
														};

termino_logico:
    expr_aritmetica_izquierda comp_bool expresion_aritmetica {
															printf("Regla 41: termino_logico es expr_aritmetica_izquierda comp_bool expresion_aritmetica\n");
															resetTipoDato();
															ind_tlogic = crear_terceto(CMP, ind_expr_izq, ind_expr);
														}
    
expr_aritmetica_izquierda:
	expresion_aritmetica								{
															printf("Regla 42: expr_aritmetica_izquierda es expresion_aritmetica\n");
															ind_expr_izq = ind_expr;
														}

comp_bool:
    MENOR                                               {
															printf("Regla 43: comp_bool es MENOR\n");
															comp_bool_actual = MENOR;
														}
    |MAYOR                                              {
															printf("Regla 44: comp_bool es MAYOR\n");
															comp_bool_actual = MAYOR;
														}
    |MENOR_IGUAL                                        {
															printf("Regla 45: comp_bool es MENOR_IGUAL\n");
															comp_bool_actual = MENOR_IGUAL;
														}
    |MAYOR_IGUAL                                        {
															printf("Regla 46: comp_bool es MAYOR_IGUAL\n");
															comp_bool_actual = MAYOR_IGUAL;
														}
    |IGUAL                                              {
															printf("Regla 47: comp_bool es IGUAL\n");
															comp_bool_actual = IGUAL;
														}
    |DISTINTO                                           {
															printf("Regla 48: comp_bool es DISTINTO\n");
															comp_bool_actual = DISTINTO;
														};
	
comp_aritmetico:
	SUMA                                                {printf("Regla 49: comp_arimetico es SUMA\n");}
    |RESTA                                              {printf("Regla 50: comp_aritmetico es RESTA\n");}
    |POR                                        		{printf("Regla 51: comp_aritmetico es POR\n");}
    |DIVIDIDO                                        	{printf("Regla 52: comp_aritmetico es DIVIDIDO\n");};												

/* Funciones nativas */

long:
    LONG PA CA lista_exp_coma CC PC                     {printf("Regla 53: long es LONG PA CA lista_exp_coma CC PC\n");}
	|LONG PA CA CC PC									{printf("Regla 54: long es LONG PA CA CC PC\n");};
	
take:
	TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA lista_exp_punto_coma CC PC 	
														{printf("Regla 55: TAKE es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA lista_exp_punto_coma CC PC\n");}
	|TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA CC PC					
														{printf("Regla 56: TAKES es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA CC PC\n");};


lista_exp_coma:
    lista_exp_coma COMA expresion_aritmetica            {printf("Regla 57: lista_exp_coma es lista_exp_coma COMA expresion_aritmetica\n");
    													 resetTipoDato();
														 cant++;
    													}
    | expresion_aritmetica                              {printf("Regla 58: lista_exp_coma es expresion_aritmetica\n");
    													ind_lec = ind_expr;
														resetTipoDato();
														cant = 1;
    													};

lista_exp_punto_coma:
	lista_exp_punto_coma PUNTO_COMA expresion_aritmetica
														{printf("Regla 59: lista_exp_punto_coma es lista_exp_punto_coma PUNTO_COMA expresion_aritmetica\n");}
    | expresion_aritmetica                              {printf("Regla 60: lista_exp_punto_coma es expresion_aritmetica\n");
    													};

lectura:
    GET ID												{chequearVarEnTabla($2);
														 int pos = buscarEnTabla($2);
														 ind_lectura = crear_terceto(GET, pos, NOOP);
														 printf("Regla 61: lectura es GET ID\n");
														};

escritura:
    DISPLAY ID                                          {
															chequearVarEnTabla($2);
														   int pos = buscarEnTabla($2);
														   ind_escritura = crear_terceto(DISPLAY, pos, NOOP);
														   printf("Regla 62: escritura es DISPLAY ID\n");
														}
    | DISPLAY CTE_STRING                                {
															printf("Regla 63: escritura es DISPLAY CTE_STRING\n");
															int pos = agregarCteStringATabla(yylval.valor_string);
															ind_escritura = crear_terceto(DISPLAY, pos, NOOP);
														};
%%

int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
  	fclose(yyin);
  }
  return 0;
}

/** Compara el tipo de dato pasado por parámetro contra el que se está trabajando actualmente en tipoDatoActual.
Si es distinto, tira error. Si no hay tipo de dato actual, asigna el pasado por parámetro. */
void chequearTipoDato(int tipo){
	if(tipoDatoActual == sinTipo){
		tipoDatoActual = tipo;
		return;
	}
	if(tipoDatoActual != tipo)
		yyerror("me estas mezclando numeros enteros con reales. Por que me odias tanto?");
}

/** Vuelve tipoDatoActual a sinTipo */
void resetTipoDato(){
	tipoDatoActual = sinTipo;
}
