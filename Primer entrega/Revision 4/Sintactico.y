/**
 * 
 *  UNLaM
 *  Lenguajes y Compiladores ( 2019 1C )
 *   
 *  Temas especiales: 
 *     1-Longitud
 *	   2-Take
 *
 *  Docente:  Mara Capuya , Henan Villareal
 *
 *  Integrantes:
 *	Brian Bayarri, Nicolas Bedetti, Aylen Hoz, German Lopez, Julian Morganella
 *      
 */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <string.h>
	#include "y.tab.h"

	/* Tipos de datos para la tabla de simbolos */
  	#define Int 1
	#define Float 2
	#define String 3
	#define CteInt 4
	#define CteFloat 5
	#define CteString 6

	#define TAMANIO_TABLA 300
	#define TAM_NOMBRE 32

	int yylex();
	
	/* Funciones necesarias */
	int yyerror(char* mensaje);
	void agregarVarATabla(char* nombre);
	void agregarTiposDatosATabla(void);
	void agregarCteStringATabla(char* nombre);
	void agregarCteIntATabla(int valor);
	void agregarCteFloatATabla(float valor);
	void chequearVarEnTabla(char* nombre);
	int buscarEnTabla(char * name);
	void escribirNombreEnTabla(char* nombre, int pos);
	void guardarTabla(void);

	int yystopparser=0;
	FILE  *yyin;

	/* Cosas de tabla de simbolos */
	typedef struct {
		char nombre[TAM_NOMBRE];
		int tipo_dato;
		char valor_s[TAM_NOMBRE];
		float valor_f;
		int valor_i;
		int longitud;
	} simbolo;

	simbolo tabla_simbolo[TAMANIO_TABLA];
	int fin_tabla = -1;

	/* Cosas para la declaracion de variables y la tabla de simbolos */
	int varADeclarar1 = 0;
	int cantVarsADeclarar = 0;
	int tipoDatoADeclarar;
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
	bloque sentencia	                                {printf("Regla 10: bloque es bloque sentencia\n");}
	| sentencia			                                {printf("Regla 11: bloque es sentencia\n");};

sentencia:
	asignacion			                    			{printf("Regla 12: sentencia es asignacion\n");}
	| bloque_if                                         {printf("Regla 13: sentencia es bloque_if\n");}
	| bloque_while                                      {printf("Regla 14: sentencia es bloque_while\n");}
	| lectura                                			{printf("Regla 15: sentencia es lectura\n");}
	| escritura                              			{printf("Regla 16: sentencia es escritura\n");}
	| expresion_aritmetica                   			{printf("Regla 17: sentencia es expresion_aritmetica\n");};

bloque_if:
    IF expresion_logica THEN bloque ENDIF               {printf("Regla 18: bloque_if es IF expresion_logica THEN bloque ENDIF\n");};

bloque_if:
    IF expresion_logica THEN bloque ELSE bloque ENDIF   {printf("Regla 19: bloque_if es IF expresion_logica THEN bloque ELSE bloque ENDIF\n");};

bloque_while:
    WHILE expresion_logica bloque ENDWHILE              {printf("Regla 20: bloque_while es WHILE expresion_logica bloque ENDWHILE\n");};

asignacion:
	ID ASIG expresion	                                {
															chequearVarEnTabla($1);
															printf("Regla 21: asignacion es ID ASIG expresion\n");
														};

/* Expresiones aritmeticas y otras */

expresion:
	expresion_cadena				                    {printf("Regla 22: expresion es expresion_cadena\n");}
	| expresion_aritmetica			                    {printf("Regla 23: expresion es expresion_aritmetica\n");};

expresion_cadena:
	CTE_STRING						                    {
															printf("Regla 24: expresion_cadena es CTE_STRING\n");
															agregarCteStringATabla(yylval.valor_string);
														};

expresion_aritmetica:
	expresion_aritmetica SUMA termino 		            {printf("Regla 25: expresion_aritmetica es expresion_aritmetica SUMA termino\n");}
	| expresion_aritmetica RESTA termino 	            {printf("Regla 26: expresion_aritmetica es expresion_aritmetica RESTA termino\n");}
	| termino								            {printf("Regla 27: expresion_aritmetica es termino\n");};

termino:
	termino POR factor 			                        {printf("Regla 28: termino es termino POR factor\n");}
	| termino DIVIDIDO factor 	                        {printf("Regla 29: termino es termino DIVIDIDO factor\n");}
	| factor					                        {printf("Regla 30: termino es factor\n");};

factor:
	PA expresion_aritmetica PC	                        {printf("Regla 31: factor es PA expresion_aritmetica PC\n");}
    | long                                          	{printf("Regla 32: factor es long\n");}
	| take												{printf("Regla 33: factor es TAKE\n");};

factor:
	ID			                                        {
															chequearVarEnTabla(yylval.valor_string);
															printf("Regla 34: factor es ID\n");
														}
	| CTE_FLOAT	                                        {
															printf("Regla 35: factor es CTE_FLOAT\n");
															agregarCteFloatATabla(yylval.valor_float);
														}
	| CTE_INT	                                        {
															printf("Regla 36: factor es CTE_INT\n");
															agregarCteIntATabla(yylval.valor_int);
														};
/* Expresiones logicas */

expresion_logica:
    termino_logico AND termino_logico                   {printf("Regla 37: expresion_logica es termino_logico AND termino_logico\n");}
    | termino_logico OR termino_logico                  {printf("Regla 38: expresion_logica es termino_logico OR termino_logico\n");}
    | termino_logico                                    {printf("Regla 39: expresion_logica es termino_logico\n");}
    | NOT termino_logico                                {printf("Regla 40: expresion_logica es NOT termino_logico\n");};

termino_logico:
    expresion_aritmetica comp_bool expresion_aritmetica {printf("Regla 41: termino_logico es expresion_aritmetica comp_bool expresion_aritmetica\n");};

comp_bool:
    MENOR                                               {printf("Regla 42: comp_bool es MENOR\n");}
    |MAYOR                                              {printf("Regla 43: comp_bool es MAYOR\n");}
    |MENOR_IGUAL                                        {printf("Regla 44: comp_bool es MENOR_IGUAL\n");}
    |MAYOR_IGUAL                                        {printf("Regla 45: comp_bool es MAYOR_IGUAL\n");}
    |IGUAL                                              {printf("Regla 46: comp_bool es IGUAL\n");}
    |DISTINTO                                           {printf("Regla 47: comp_bool es DISTINTO\n");};
	
comp_aritmetico:
	SUMA                                                {printf("Regla 48: comp_arimetico es SUMA\n");}
    |RESTA                                              {printf("Regla 49: comp_aritmetico es RESTA\n");}
    |POR                                        		{printf("Regla 50: comp_aritmetico es POR\n");}
    |DIVIDIDO                                        	{printf("Regla 51: comp_aritmetico es DIVIDIDO\n");};												

/* Funciones nativas */

long:
    LONG PA CA lista_exp_coma CC PC                     {printf("Regla 52: long es LONG PA CA lista_exp_coma CC PC\n");}
	|LONG PA CA CC PC									{printf("Regla 53: long es LONG PA CA CC PC\n");};
	
take:
	TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA lista_exp_punto_coma CC PC 	{printf("Regla 54: TAKE es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA lista_exp_punto_coma CC PC\n");}
	|TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA CC PC					{printf("Regla 55: TAKES es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA CC PC\n");};


lista_exp_coma:
    lista_exp_coma COMA expresion_aritmetica            {printf("Regla 56: lista_exp_coma es lista_exp_coma COMA expresion_aritmetica\n");}
    | expresion_aritmetica                              {printf("Regla 57: lista_exp_coma es expresion_aritmetica\n");};

lista_exp_punto_coma:
	lista_exp_punto_coma PUNTO_COMA expresion_aritmetica            {printf("Regla 58: lista_exp_punto_coma es lista_exp_punto_coma PUNTO_COMA expresion_aritmetica\n");}
    | expresion_aritmetica                              			{printf("Regla 59: lista_exp_punto_coma es expresion_aritmetica\n");};

lectura:
    GET ID												{
															chequearVarEnTabla($2);
															printf("Regla 60: lectura es GET ID\n");
														};

escritura:
    DISPLAY ID                                            {
															chequearVarEnTabla($2);
															printf("Regla 61: escritura es DISPLAY ID\n");
														}
    | DISPLAY CTE_STRING                                  {
															printf("Regla 62: escritura es DISPLAY CTE_STRING\n");
															agregarCteStringATabla(yylval.valor_string);
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


int yyerror(char* mensaje)
 {
	printf("Syntax Error: %s\n", mensaje);
	system ("Pause");
	exit (1);
 }

/* Funciones de la tabla de simbolos */

/* Devuleve la posicion en la que se encuentra el elemento buscado, -1 si no encontr� el elemento */
int buscarEnTabla(char * name){
   int i=0;
   while(i<=fin_tabla){
	   if(strcmp(tabla_simbolo[i].nombre,name) == 0){
		   return i;
	   }
	   i++;
   }
   return -1;
}

/** Escribe el nombre de una variable o constante en la posición indicada */
void escribirNombreEnTabla(char* nombre, int pos){
	strcpy(tabla_simbolo[pos].nombre, nombre);
}

 /** Agrega un nuevo nombre de variable a la tabla **/
 void agregarVarATabla(char* nombre){
	 //Si se llena, error
	 if(fin_tabla >= TAMANIO_TABLA - 1){
		 printf("Error: No hay mas espacio en la tabla de simbolos.\n");
		 system("Pause");
		 exit(2);
	 }
	 //Si no hay otra variable con el mismo nombre...
	 if(buscarEnTabla(nombre) == -1){
		 //Agregar a tabla
		 fin_tabla++;
		 escribirNombreEnTabla(nombre, fin_tabla);
	 }
	 else 
	 {
	 char msg[100] ;
	 sprintf(msg,"'%s' ya se encuentra declarada previamente.", nombre);
	 yyerror(msg);
	}
 }

/** Agrega los tipos de datos a las variables declaradas. Usa las variables globales varADeclarar1, cantVarsADeclarar y tipoDatoADeclarar */
void agregarTiposDatosATabla(){
	int i;
	for(i = 0; i < cantVarsADeclarar; i++){
		tabla_simbolo[varADeclarar1 + i].tipo_dato = tipoDatoADeclarar;
	}
}

/** Guarda la tabla de simbolos en un archivo de texto */
void guardarTabla(){
	if(fin_tabla == -1)
		yyerror("No se encontro la tabla de simbolos");

	FILE* arch = fopen("ts.txt", "w+");
	if(!arch){
		printf("No se pudo crear el archivo ts.txt\n");
		return;
	}
	
	int i;

	for(i = 0; i <= fin_tabla; i++){
		fprintf(arch, "%s\t", &(tabla_simbolo[i].nombre) );

		switch (tabla_simbolo[i].tipo_dato){
		case Float:
			fprintf(arch, "FLOAT");
			break;
		case Int:
			fprintf(arch, "INT");
			break;
		case String:
			fprintf(arch, "STRING");
			break;
		case CteFloat:
			fprintf(arch, "CTE_FLOAT\t%f", tabla_simbolo[i].valor_f);
			break;
		case CteInt:
			fprintf(arch, "CTE_INT\t%d", tabla_simbolo[i].valor_i);
			break;
		case CteString:
			fprintf(arch, "CTE_STRING\t%s\t%d", &(tabla_simbolo[i].valor_s), tabla_simbolo[i].longitud);
			break;
		}

		fprintf(arch, "\n");
	}
	fclose(arch);
}

/* Calculo que estas 3 funciones se podrían juntar en una sola */

/** Agrega una constante string a la tabla de simbolos */
void agregarCteStringATabla(char* nombre){
	if(fin_tabla >= TAMANIO_TABLA - 1){
		printf("Error: No hay mas espacio en la tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}

	//Si no hay otra variable con el mismo nombre...
	if(buscarEnTabla(nombre) == -1){
		//Agregar nombre a tabla
		fin_tabla++;
		escribirNombreEnTabla(nombre, fin_tabla);

		//Agregar tipo de dato
		tabla_simbolo[fin_tabla].tipo_dato = CteString;

		//Agregar valor a la tabla
		strcpy(tabla_simbolo[fin_tabla].valor_s, nombre+1); //nombre+1 es para no copiar el _ del principio

		//Agregar longitud
		tabla_simbolo[fin_tabla].longitud = strlen(nombre) - 1;
	}
}

/** Agrega una constante real a la tabla de simbolos */
void agregarCteFloatATabla(float valor){
	if(fin_tabla >= TAMANIO_TABLA - 1){
		printf("Error: No hay mas espacio en la tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}

	//Genero el nombre
	char nombre[12];
	sprintf(nombre, "_%f", valor);

	//Si no hay otra variable con el mismo nombre...
	if(buscarEnTabla(nombre) == -1){
		//Agregar nombre a tabla
		fin_tabla++;
		escribirNombreEnTabla(nombre, fin_tabla);

		//Agregar tipo de dato
		tabla_simbolo[fin_tabla].tipo_dato = CteFloat;

		//Agregar valor a la tabla
		tabla_simbolo[fin_tabla].valor_f = valor;
	}
}

/** Agrega una constante entera a la tabla de simbolos */
void agregarCteIntATabla(int valor){
	if(fin_tabla >= TAMANIO_TABLA - 1){
		printf("Error: No hay mas espacio en la tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}

	//Genero el nombre
	char nombre[30];
	sprintf(nombre, "_%d", valor);

	//Si no hay otra variable con el mismo nombre...
	if(buscarEnTabla(nombre) == -1){
		//Agregar nombre a tabla
		fin_tabla++;
		escribirNombreEnTabla(nombre, fin_tabla);

		//Agregar tipo de dato
		tabla_simbolo[fin_tabla].tipo_dato = CteInt;

		//Agregar valor a la tabla
		tabla_simbolo[fin_tabla].valor_i = valor;
	}
}

/** Se fija si ya existe una entrada con ese nombre en la tabla de simbolos. Si no existe, muestra un error de variable sin declarar y aborta la compilacion. */
void chequearVarEnTabla(char* nombre){
	//Si no existe en la tabla, error
	if( buscarEnTabla(nombre) == -1){
		char msg[100];
		sprintf(msg,"La variable '%s' debe ser declarada previamente en la seccion de declaracion de variables", nombre);
		yyerror(msg);
	}
	//Si existe en la tabla, dejo que la compilacion siga
}
