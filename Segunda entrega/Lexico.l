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
 *  Docente: Mara Capuya , Hernan Villareal, Daniel Carrizo
 *
 *  Integrantes:
 *	Brian Bayarri, Nicolas Bedetti, Aylen Hoz, German Lopez, Julian Morganella
 *      
 */
%{

/* include area */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"

FILE *yyin;

/* Tabla de simbolos */

struct registro_ts {
	char *nombre;
	char *tipo;
	char *valor;
	char *longitud;
};

struct registro_ts tabla_simbolos[100];
int cant_reg = 0;

/* FUNCIONES */
int validarInt(int entero);
int insertar_cteint_en_ts(int entero);

int validarString(char *str);
int insertar_ctestring_en_ts(char *str);

int validarReal(float flotante);
int insertar_ctereal_en_ts(float flotante);

int validarID(char *str);
int insertar_id_en_ts(char *id);


void mensaje_error();
int nombre_existe_en_ts(char *id);
void existe_en_ts(char *id);
void insertar_tabla_simbolos(char *nombre, char *tipo, char *valor, char *longitud);
void save_reg_ts();
void mostrar_ts();
void guardarTipos(int variableActual, char listaVariables[][20], char tipoActual[]);

void cota_error(char* mensaje);

%}

%option noyywrap
%option yylineno

DIGITO 			[0-9]
CHAR 			[a-zA-Z]

ENTERO 			{DIGITO}+
CONSTANTE_ENTERA 	-?{ENTERO}

CONSTANTE_REAL 	-?[0-9]{1,10}\.[0-9]{0,10}|-?[0-9]{0,10}\.[0-9]{1,10}

ID 	{CHAR}({CHAR}|{DIGITO}|_)*

NUEVA_SENTENCIA	[\r\n]
TABULACION 		[\t]
ESPACIO       " "
CARACTERES_ESPECIALES [\@\$\_\~\\\,\%]
CARACTERES_NO_PERMITIDOS [#\^\*\(\)\-\+\=\|\/\?\>\<\!\;\.\:\'\"\[\]\{\}]

INICIO_FIN_STR \"
CADENA ({CARACTERES_ESPECIALES}|{CARACTERES_NO_PERMITIDOS}|{DIGITO}|{CHAR}|{ESPACIO}|{TABULACION})
CONSTANTE_STRING {INICIO_FIN_STR}{CADENA}*{INICIO_FIN_STR}

INICIO_COMENTARIO "*/"
FIN_COMENTARIO "/*"
COMENTARIO {INICIO_COMENTARIO}{CADENA}*{FIN_COMENTARIO}

%%

"START"                   { return START; }

"END"                     { return END; }

"IF"                      { return IF; }

"ELSE"                    { return ELSE; }

"THEN"					  { return THEN; }

"ENDIF"                   { return ENDIF; }

"WHILE"                   { return WHILE; }

"ENDWHILE"                { return ENDWHILE; }

"long"                    { return LONG; }

"TAKE"					  { return TAKE; }
                   
"DEFVAR"                  { return DEFVAR; }

"ENDDEF"                  { return ENDDEF; }

"DISPLAY"                 { return DISPLAY; }

"GET"                     { return GET; }

"INT"                     { 
                            yylval.valor_int = atoi( yytext );
                            return INT;
                          }

"FLOAT"                   { 
                            yylval.valor_float = atof( yytext );
                            return FLOAT;
                          }

"STRING"                  { 
                            yylval.valor_string = strdup( yytext );
                            return STRING;
                          }

":"                       { return DOS_PUNTOS; }

";"                       { return PUNTO_COMA; }

","                       { return COMA; }                          

"+"                       { return SUMA; }

"-"                       { return RESTA; }

"*"                       { return POR; }

"/"                       { return DIVIDIDO; }

"AND"                     { return AND; }

"OR"                      { return OR; }

"NOT"                     { return NOT; }

":="                      { return ASIG; }

"<"                       { return MENOR; }

"<="                      { return MENOR_IGUAL; }

">"                       { return MAYOR; }

">="                      { return MAYOR_IGUAL; }

"=="                      { return IGUAL; }

"!="                      { return DISTINTO; }
                            
"("                       { return PA; }

")"                       { return PC; }

"["                       { return CA; }

"]"                       { return CC; }

{ID}          			  { 
							yylval.valor_string = strdup(yytext);; 
							validarID(yylval.valor_string); 
							return ID;
			              }    
                        
{CONSTANTE_REAL}  		  {
							yylval.valor_float = atof(yytext); 
							validarReal(yylval.valor_float); 
							insertar_ctereal_en_ts(yylval.valor_float); 
							return CTE_FLOAT;
		                  }  

{CONSTANTE_ENTERA}        {
							yylval.valor_int = atoi(yytext);
							validarInt(yylval.valor_int); 
							insertar_cteint_en_ts(yylval.valor_int); 
							return CTE_INT;
		                  } 

{CONSTANTE_STRING}		  {	
							strcpy(yylval.valor_string,yytext); 
							validarString(yylval.valor_string); 
							insertar_ctestring_en_ts(yylval.valor_string); 
							return CTE_STRING;
						  }
						  
{COMENTARIO}			{	
							printf("_____COMENTARIO: %s_____",yytext);
						}			
%%

/* Funcion para validar identificador */
int validarID(char *str)
{
    int largo = strlen(str);
	if(largo > 30)
	{
		printf("Error lexico: El nombre de variable excede el limite permitido -> Linea %d\n", yylineno);
		fprintf(stderr, "Fin de ejecucion.\n");
		system ("Pause");
		exit (1);
	}
	return 1;
}

int insertar_id_en_ts(char *id)
{
	if (nombre_existe_en_ts(id) == -1) 
		insertar_tabla_simbolos(id, "","","-");
	return 1;
}

/* Funcion para validar float */
int validarReal(float real)
{

	if(real < -3.40282347e+38F || real > 3.40282347e+38F)
	{
		printf("Error lexico: El valor de un flotante excede el limite permitido -> Linea %d\n", yylineno);
		fprintf(stderr, "Fin de ejecucion.\n");
		system ("Pause");
		exit (1);
	}
	return 1;
}

int insertar_ctereal_en_ts(float flotante)
{
	char *valor = (char*) malloc(sizeof(float));
	snprintf(valor, sizeof(float), "%f", flotante);
	char *nombre = (char*) malloc(sizeof(float)+1);
	*nombre = '\0';
	strcat(nombre, "_");
	strcat(nombre, valor);
	if (nombre_existe_en_ts(nombre) == -1)
		insertar_tabla_simbolos(nombre, "CTE_FLOAT", valor, "-");
	return 1;
}

/* Funcion para validar el rango de enteros */
int validarInt(int entero)
{

	if(entero < -32767 || entero > 32767)
	{
		printf("Error lexico: El valor de un entero excede el limite permitido -> Linea %d\n", yylineno);
		fprintf(stderr, "Fin de ejecucion.\n");
		system ("Pause");
		exit (1);
	}
	return 1;
}

int insertar_cteint_en_ts(int entero)
{
	char *valor = (char*) malloc(sizeof(int));
	itoa(entero, valor, 10);
	char *nombre = (char*) malloc(sizeof(int)+1);
	*nombre = '\0';
	strcat(nombre, "_");
	strcat(nombre, valor);
	if (nombre_existe_en_ts(nombre) == -1)
		insertar_tabla_simbolos(nombre, "CTE_INT", valor, "-");
	return 1;
}

/* Funcion para validar string */
int validarString(char *str)
{
	if(strlen(str) > 30)
	{
		printf("Error lexico: El contenido de una cadena excede el limite permitido -> Linea %d\n", yylineno);
		fprintf(stderr, "Fin de ejecucion.\n");
		system ("Pause");
		exit (1);
	}
	return 1;
}

int insertar_ctestring_en_ts(char *str) 
{
	char *nombre = (char*) malloc(31*sizeof(char));
	*nombre = '\0';
	strcat(nombre, "_");
	strcat(nombre, str);
	
	char *longitud = (char*) malloc(10*sizeof(char));	
	itoa(strlen(str), longitud, 10);

	if (nombre_existe_en_ts(nombre) == -1)
		insertar_tabla_simbolos(nombre, "CTE_STRING", str, longitud);
	return 1;
}

int nombre_existe_en_ts(char *id) 
{
	int i;
	for(i=0;i<cant_reg;i++){
		if (strcmpi(id, tabla_simbolos[i].nombre) == 0)
			return i;
	}
	return -1;
}

/* 	Funcion para comprobar que un simbolo existe en la tabla de simbolos */

void existe_en_ts (char *id){
  if(nombre_existe_en_ts(id)==-1){
	printf("\nERROR: ID no declarado\n");
    yyerror();
  }
}


void insertar_tabla_simbolos(char *nombre, char *tipo, char *valor, char *longitud)
{
	struct registro_ts reg;
	
	reg.nombre = nombre;
	reg.tipo = tipo;
	reg.valor = valor;
	reg.longitud = longitud;
	
	tabla_simbolos[cant_reg] = reg;
	cant_reg++;
}

void save_reg_ts()
{
	FILE *file = fopen("ts.txt", "a");
	
	if(file == NULL) 
	{
    	printf("(!) ERROR: No se pudo abrir el txt correspondiente a la tabla de simbolos\n");
	}
	else 
	{
		int i = 0;
		for (i; i < cant_reg; i++) 
		{
			//printf("%s\t%s\t%s\t%s\n", tabla_simbolos[i].nombre, tabla_simbolos[i].tipo, tabla_simbolos[i].valor, tabla_simbolos[i].longitud);
			fprintf(file, "%-30s\t%-30s\t%-30s\t%-30s\n", tabla_simbolos[i].nombre, tabla_simbolos[i].tipo, tabla_simbolos[i].valor, tabla_simbolos[i].longitud);
		}		
		fclose(file);
	}
}

void mostrar_ts()
{
	printf("\n\nMOSTRAR COMO QUEDO LA TS \n");
	int i = 0;
	for (i; i < cant_reg; i++) 
	{
		printf("%s\t%s\t%s\t%s\n", tabla_simbolos[i].nombre, tabla_simbolos[i].tipo, tabla_simbolos[i].valor, tabla_simbolos[i].longitud);	
	}
	printf("\n");
}

/* 	Funcion para actualizar el tipo de una variable en la tabla de simbolos */

void guardarTipos(int variableActual, char listaVariables[][20], char tipoActual[]){
  int i;
  for(i=0; i<variableActual; i++){
    int pos=nombre_existe_en_ts(listaVariables[i]);
    if(pos!=-1) {
	  char *tipoDato = (char*) malloc(10*sizeof(char));
	  *tipoDato = '\0';
	  strcat(tipoDato, tipoActual);
	  tabla_simbolos[pos].tipo = tipoDato;
	}
  }
}

