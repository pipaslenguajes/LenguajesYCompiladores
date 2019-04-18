
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
     IF = 266,
     ELSE = 267,
     ENDIF = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     ASIG = 272,
     SUMA = 273,
     RESTA = 274,
     POR = 275,
     DIVIDIDO = 276,
     MENOR = 277,
     MAYOR = 278,
     MENOR_IGUAL = 279,
     MAYOR_IGUAL = 280,
     IGUAL = 281,
     DISTINTO = 282,
     PA = 283,
     PC = 284,
     CA = 285,
     CC = 286,
     COMA = 287,
     PUNTO_COMA = 288,
     DOS_PUNTOS = 289,
     GET = 290,
     DISPLAY = 291,
     LONG = 292,
     ID = 293,
     CONSTANTE_REAL = 294,
     CONSTANTE_ENTERA = 295,
     CONSTANTE_STRING = 296
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
#define IF 266
#define ELSE 267
#define ENDIF 268
#define AND 269
#define OR 270
#define NOT 271
#define ASIG 272
#define SUMA 273
#define RESTA 274
#define POR 275
#define DIVIDIDO 276
#define MENOR 277
#define MAYOR 278
#define MENOR_IGUAL 279
#define MAYOR_IGUAL 280
#define IGUAL 281
#define DISTINTO 282
#define PA 283
#define PC 284
#define CA 285
#define CC 286
#define COMA 287
#define PUNTO_COMA 288
#define DOS_PUNTOS 289
#define GET 290
#define DISPLAY 291
#define LONG 292
#define ID 293
#define CONSTANTE_REAL 294
#define CONSTANTE_ENTERA 295
#define CONSTANTE_STRING 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 52 "sintactico.y"

	int int_val;
	float float_val;
	char *string_val;



/* Line 1676 of yacc.c  */
#line 142 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


