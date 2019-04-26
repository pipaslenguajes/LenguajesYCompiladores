/**
 * 
 *  UNLaM
 *  Lenguajes y Compiladores ( 2019 1C )
 *   
 *  Temas especiales: 
 *     1-Longitud
 *
 *  Docente:  Prof. Mara Capuya
 *
 *  Grupo: 
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

%}

%option noyywrap
%option yylineno

DIGITO 			[0-9]
CHAR 			[a-zA-Z]

ENTERO 			[1-9][0-9]{0,4}|0
CONSTANTE_ENTERA 	-?{ENTERO}

CONSTANTE_REAL 	-?[0-9]{1,10}\.[0-9]{0,10}|-?[0-9]{0,10}\.[0-9]{1,10}

ID 	{CHAR}({CHAR}|{DIGITO}|_)*

NUEVA_SENTENCIA	[\r\n]
TABULACION 		[\t]
ESPACIO       " "
CARACTERES_ESPECIALES [\@\$\_\~\\\,\%]
CARACTERES_NO_PERMITIDOS [#\^\*\(\)\-\+\=\|\/\?\>\<\!\;\.\:\'\"\[\]\{\}{DIGITO}{CHAR}]

INICIO_FIN_STR \"
CONSTANTE_STRING {INICIO_FIN_STR}({CARACTERES_ESPECIALES}|{CARACTERES_NO_PERMITIDOS}|{ESPACIO}|{TABULACION}){0,30}{INICIO_FIN_STR}

INICIO_COMENTARIO */
FIN_COMENTARIO /*
COMENTARIO {INICIO_COMENTARIO}({CARACTERES_ESPECIALES}|{CARACTERES_NO_PERMITIDOS}){FIN_COMENTARIO}

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
			                if(strlen(yytext) <= 30){
			                  yylval.valor_string = strdup(yytext);
			                  return ID;
			                }
			              }    
                        
{CONSTANTE_REAL}  		  {
		                    if(atof(yytext)>=-3.40282347e+38F && atof(yytext)<=3.40282347e+38F){
		                    	yylval.valor_float = atof(yytext);
		                    	return CTE_FLOAT;
		                    }
		                  }  

{CONSTANTE_ENTERA}        {
		                      if(atoll(yytext)>=-32768 && atoll(yytext)<=32767){
		                      	yylval.valor_int = atoi(yytext);
		                      	return CTE_INT;
		                      }
		                  } 

{CONSTANTE_STRING}		  {	strcpy(yylval.valor_string,yytext);
							return CTE_STRING;
						  }
							
%%