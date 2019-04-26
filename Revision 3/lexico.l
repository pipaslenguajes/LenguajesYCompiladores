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

 
/*==================================================================================================
 * Configuracion
 *==================================================================================================*/

/** para loguear*/
#define LEX_LOGGER 0

/*==================================================================================================
 * macros
 *==================================================================================================*/

#if LEX_LOGGER
  #define LEX_LOG printf
#else
  #define LEX_LOG(...)
#endif

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

"START"                   { LEX_LOG("START "); return START; }

"END"                     { LEX_LOG("END "); return END; }

"IF"                      { LEX_LOG("IF "); return IF; }

"ELSE"                    { LEX_LOG("ELSE\n"); return ELSE; }

"THEN"					          { LEX_LOG("THEN\n"); return THEN; }

"ENDIF"                   { LEX_LOG("ENDIF\n"); return ENDIF; }

"WHILE"                   { LEX_LOG("WHILE\n"); return WHILE; }

"ENDWHILE"                { LEX_LOG("ENDWHILE\n"); return ENDWHILE; }

"long"                    { LEX_LOG("LONG "); return LONG; }

"TAKE"					  { LEX_LOG("TAKE "); return TAKE; }
                   
"DEFVAR"                  { 
                            LEX_LOG("DEFVAR\n");
                            return DEFVAR;
                          }
"ENDDEF"                  { LEX_LOG("ENDDEF\n"); 
                            return ENDDEF;
                          }

"DISPLAY"                 { LEX_LOG("DISPLAY"); return DISPLAY; }

"GET"                     { LEX_LOG("GET"); return GET; }

"INT"                     { 
                            LEX_LOG("INT\n"); 
                            yylval.valor_int = atoi( yytext );
                            return INT;
                          }

"FLOAT"                   { 
                            LEX_LOG("FLOAT\n"); 
                            yylval.valor_float = atof( yytext );
                            return FLOAT;
                          }

"STRING"                  { 
                            LEX_LOG("STRING\n");
                            yylval.valor_string = strdup( yytext );
                            return STRING;
                          }

":"                       { 
                            LEX_LOG("DOS_PUNTOS\n"); 
                            return DOS_PUNTOS;
                          }
";"                       { 
                            LEX_LOG("PUNTO_COMA\n"); 
                            return PUNTO_COMA; 
                          }

","                       { 
                            LEX_LOG("COMA\n"); 
                            return COMA; 
                          }                          

"+"                       { LEX_LOG("SUMA "); return SUMA; }

"-"                       { LEX_LOG("RESTA "); return RESTA; }

"*"                       { LEX_LOG("POR "); return POR; }

"/"                       { LEX_LOG("DIVIDIR"); return DIVIDIDO; }

"AND"                     { LEX_LOG("AND"); return AND; }
"OR"                      { LEX_LOG("OR"); return OR; }
"NOT"                     { LEX_LOG("NOT"); return NOT; }

":="                      { LEX_LOG("ASIGNACION"); return ASIG; }

"<"                       { LEX_LOG(" MENOR "); return MENOR; }
"<="                      { LEX_LOG(" MENOR_IGUAL "); return MENOR_IGUAL; }
">"                       { LEX_LOG(" MAYOR"); return MAYOR; }
">="                      { LEX_LOG(" MAYOR_IGUAL "); return MAYOR_IGUAL; }
"=="                      { LEX_LOG(" IGUAL "); return IGUAL; }
"!="                      { LEX_LOG(" DISTINTO "); return DISTINTO; }
                            
"("                       { LEX_LOG(" PA "); return PA; }
")"                       { LEX_LOG(" PC "); return PC; }
"["                       { LEX_LOG(" CA "); return CA; }
"]"                       { LEX_LOG(" CC "); return CC; }

{ID}          			  {
			                if(strlen(yytext) <= 30){
			                  yylval.valor_string = strdup(yytext);
			                  return ID;
			                }
			                LEX_LOG("ERROR- Supera la cantidad de 30 caracteres.");
			              }    
                        
{CONSTANTE_REAL}  		  {
		                    if(atof(yytext)>=-3.40282347e+38F && atof(yytext)<=3.40282347e+38F){
		                    	yylval.valor_float = atof(yytext);
		                    	return CTE_FLOAT;
		                    }
		                   LEX_LOG("ERROR- Supera el tamaño maximo de un real.");
		                  }  

{CONSTANTE_ENTERA}        {
		                      if(atoll(yytext)>=-32768 && atoll(yytext)<=32767){
		                      	yylval.valor_int = atoi(yytext);
		                      	return CTE_INT;
		                      }
		                    LEX_LOG("ERROR- Supera el tamaño maximo de un real.");
		                  } 

{CONSTANTE_STRING}		  {	strcpy(yylval.valor_string,yytext);
							return CTE_STRING;
						  }
							
						        

%%