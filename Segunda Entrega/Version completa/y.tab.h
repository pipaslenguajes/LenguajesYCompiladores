
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     START = 258,
     END = 259,
     DEFVAR = 260,
     ENDDEF = 261,
     INT = 262,
     FLOAT = 263,
     STRING = 264,
     WHILE = 265,
     ENDWHILE = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     ENDIF = 270,
     AND = 271,
     OR = 272,
     NOT = 273,
     ASIG = 274,
     SUMA = 275,
     RESTA = 276,
     POR = 277,
     DIVIDIDO = 278,
     MENOR = 279,
     MAYOR = 280,
     MENOR_IGUAL = 281,
     MAYOR_IGUAL = 282,
     IGUAL = 283,
     DISTINTO = 284,
     PA = 285,
     PC = 286,
     CA = 287,
     CC = 288,
     COMA = 289,
     PUNTO_COMA = 290,
     DOS_PUNTOS = 291,
     GET = 292,
     DISPLAY = 293,
     LONG = 294,
     TAKE = 295,
     ID = 296,
     CTE_FLOAT = 297,
     CTE_INT = 298,
     CTE_STRING = 299
   };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define DEFVAR 260
#define ENDDEF 261
#define INT 262
#define FLOAT 263
#define STRING 264
#define WHILE 265
#define ENDWHILE 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define AND 271
#define OR 272
#define NOT 273
#define ASIG 274
#define SUMA 275
#define RESTA 276
#define POR 277
#define DIVIDIDO 278
#define MENOR 279
#define MAYOR 280
#define MENOR_IGUAL 281
#define MAYOR_IGUAL 282
#define IGUAL 283
#define DISTINTO 284
#define PA 285
#define PC 286
#define CA 287
#define CC 288
#define COMA 289
#define PUNTO_COMA 290
#define DOS_PUNTOS 291
#define GET 292
#define DISPLAY 293
#define LONG 294
#define TAKE 295
#define ID 296
#define CTE_FLOAT 297
#define CTE_INT 298
#define CTE_STRING 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 118 "Sintactico.y"

	int valor_int;
	float valor_float;
	char *valor_string;



/* Line 1676 of yacc.c  */
#line 148 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


