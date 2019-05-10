%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
FILE  *yyin;
%}

%option noyywrap
%option yylineno

DIGITO			      	[0-9]
LETRA			        [a-z]
COMA               		[","]

EXP1					({LETRA}{LETRA})+
EXP2					{COMA}|({LETRA}|{DIGITO})+
EXP3					{LETRA}|{DIGITO}+|{COMA}

%%
{EXP1}			        { printf("\n Token1: %s\n", yytext);}
{EXP2}			    	{ printf("\n Token2: %s\n", yytext);}
{EXP3}			   		{ printf("\n Token3: %s\n", yytext);}
"\n"
"\t"
