
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

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


/* Line 189 of yacc.c  */
#line 190 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 118 "Sintactico.y"

	int valor_int;
	float valor_float;
	char *valor_string;



/* Line 214 of yacc.c  */
#line 322 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 334 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    11,    15,    19,    22,    24,
      28,    30,    32,    34,    38,    40,    43,    45,    47,    49,
      51,    53,    55,    56,    61,    62,    63,    71,    72,    79,
      81,    82,    87,    89,    90,    95,    96,   101,   102,   107,
     108,   113,   114,   119,   120,   125,   126,   131,   132,   137,
     138,   144,   145,   151,   152,   158,   159,   165,   166,   172,
     173,   179,   181,   183,   185,   187,   194,   200,   211,   221,
     225,   227,   231,   233,   237,   241,   243,   247,   251,   253,
     255,   257,   258,   263,   265,   267,   269,   271,   273,   276,
     279
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    -1,     3,    48,    53,     4,
      -1,     3,    53,     4,    -1,     5,    49,     6,    -1,    49,
      50,    -1,    50,    -1,    51,    36,    52,    -1,     8,    -1,
       7,    -1,     9,    -1,    52,    35,    41,    -1,    41,    -1,
      53,    54,    -1,    54,    -1,    55,    -1,    60,    -1,    57,
      -1,    90,    -1,    91,    -1,    -1,    41,    19,    56,    85,
      -1,    -1,    -1,    10,    58,    64,    59,    13,    53,    11,
      -1,    -1,    12,    64,    61,    13,    62,    15,    -1,    53,
      -1,    -1,    53,    63,    14,    53,    -1,    67,    -1,    -1,
      67,    65,    16,    67,    -1,    -1,    67,    66,    17,    67,
      -1,    -1,    85,    68,    24,    85,    -1,    -1,    85,    69,
      26,    85,    -1,    -1,    85,    70,    25,    85,    -1,    -1,
      85,    71,    27,    85,    -1,    -1,    85,    72,    28,    85,
      -1,    -1,    85,    73,    29,    85,    -1,    -1,    18,    85,
      74,    24,    85,    -1,    -1,    18,    85,    75,    26,    85,
      -1,    -1,    18,    85,    76,    25,    85,    -1,    -1,    18,
      85,    77,    27,    85,    -1,    -1,    18,    85,    78,    28,
      85,    -1,    -1,    18,    85,    79,    29,    85,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    39,    30,    32,
      83,    33,    31,    -1,    39,    30,    32,    33,    31,    -1,
      40,    30,    80,    35,    43,    35,    32,    84,    33,    31,
      -1,    40,    30,    80,    35,    43,    35,    32,    33,    31,
      -1,    83,    34,    85,    -1,    85,    -1,    84,    35,    85,
      -1,    85,    -1,    85,    20,    86,    -1,    85,    21,    86,
      -1,    86,    -1,    86,    22,    87,    -1,    86,    23,    87,
      -1,    87,    -1,    41,    -1,    89,    -1,    -1,    30,    88,
      85,    31,    -1,    81,    -1,    82,    -1,    43,    -1,    44,
      -1,    42,    -1,    37,    41,    -1,    38,    44,    -1,    38,
      41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   155,   158,   159,   164,   166,   167,   170,
     176,   180,   184,   190,   194,   204,   205,   208,   209,   210,
     211,   212,   217,   217,   239,   239,   239,   256,   256,   265,
     270,   270,   284,   285,   285,   286,   286,   301,   301,   304,
     304,   307,   307,   310,   310,   313,   313,   316,   316,   319,
     319,   322,   322,   325,   325,   328,   328,   331,   331,   334,
     334,   340,   344,   348,   352,   363,   368,   375,   408,   414,
     418,   425,   430,   441,   445,   449,   452,   456,   460,   463,
     464,   465,   465,   473,   474,   478,   479,   480,   487,   499,
     504
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "DEFVAR", "ENDDEF",
  "INT", "FLOAT", "STRING", "WHILE", "ENDWHILE", "IF", "THEN", "ELSE",
  "ENDIF", "AND", "OR", "NOT", "ASIG", "SUMA", "RESTA", "POR", "DIVIDIDO",
  "MENOR", "MAYOR", "MENOR_IGUAL", "MAYOR_IGUAL", "IGUAL", "DISTINTO",
  "PA", "PC", "CA", "CC", "COMA", "PUNTO_COMA", "DOS_PUNTOS", "GET",
  "DISPLAY", "LONG", "TAKE", "ID", "CTE_FLOAT", "CTE_INT", "CTE_STRING",
  "$accept", "start", "programa", "seccion_declaracion", "bloque_dec",
  "declaracion", "t_dato", "lista_id", "bloque", "sentencia", "asignacion",
  "$@1", "bloque_while", "$@2", "$@3", "bloque_if", "$@4",
  "decision_bloque", "$@5", "expresion_logica", "$@6", "$@7",
  "termino_logico", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "comp_aritmetico", "long",
  "take", "lista_exp_coma", "lista_exp_punto_coma", "expresion_aritmetica",
  "termino", "factor", "$@20", "constante", "lectura", "escritura", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      51,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    56,    55,    58,    59,    57,    61,    60,    62,
      63,    62,    64,    65,    64,    66,    64,    68,    67,    69,
      67,    70,    67,    71,    67,    72,    67,    73,    67,    74,
      67,    75,    67,    76,    67,    77,    67,    78,    67,    79,
      67,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    86,    87,
      87,    88,    87,    87,    87,    89,    89,    89,    90,    91,
      91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     3,     3,     2,     1,     3,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     0,     7,     0,     6,     1,
       0,     4,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     1,     1,     1,     1,     6,     5,    10,     9,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     2,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     0,    24,     0,     0,     0,     0,
       0,     0,    16,    17,    19,    18,    20,    21,     1,    11,
      10,    12,     0,     8,     0,     0,     0,    81,     0,     0,
      79,    87,    85,    86,    27,    32,    83,    84,    37,    75,
      78,    80,    88,    90,    89,    22,     0,     5,    15,     6,
       7,     0,    25,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,    14,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,    76,
      77,    23,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,    70,     0,    29,     0,    34,    36,    38,
      40,    42,    44,    46,    48,    13,     0,    50,    52,    54,
      56,    58,    60,    66,     0,     0,     0,     0,    28,    26,
      65,    69,     0,     0,     0,    31,     0,     0,    72,    68,
       0,     0,    67,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    22,    23,    24,    73,    11,    12,
      13,    70,    14,    25,    74,    15,    57,   116,   137,    34,
      58,    59,    35,    62,    63,    64,    65,    66,    67,    75,
      76,    77,    78,    79,    80,    87,    36,    37,   112,   147,
      38,    39,    40,    54,    41,    16,    17
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int16 yypact[] =
{
      -2,    11,    19,   -34,    85,   -34,    59,   -19,   -33,     6,
      50,     0,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   145,   -34,    -9,    59,    66,   -34,    -1,     4,
     -34,   -34,   -34,   -34,   -34,    23,   -34,   -34,   111,    22,
     -34,   -34,   -34,   -34,   -34,   -34,     5,   -34,   -34,   -34,
     -34,    15,   -34,   121,    66,    29,    97,    63,    47,    73,
      66,    66,    90,    71,    86,   106,   115,   128,    66,    66,
      66,   -34,   -34,   123,   146,   136,   135,   137,   138,   139,
     134,    -7,    25,   -34,   -34,   -34,   -34,   129,    50,    59,
      59,    22,    22,    66,    66,    66,    66,    66,    66,   -34,
     -34,    30,   125,    50,    66,    66,    66,    66,    66,    66,
     -34,   140,    45,    30,   126,    16,   153,   -34,   -34,    30,
      30,    30,    30,    30,    30,   -34,    -5,    30,    30,    30,
      30,    30,    30,   -34,   141,    66,   142,   156,   -34,   -34,
     -34,    30,   143,    50,    83,    50,   147,   -15,    30,   -34,
     148,    66,   -34,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,   -34,   -34,   -34,   151,   -34,   -34,    -8,   -11,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   149,
     -34,   -34,    40,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -23,    84,    87,   -34,   -34,   -34,   -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -60
static const yytype_int16 yytable[] =
{
      48,     1,    46,    53,    47,     5,   139,     6,    43,    71,
       5,    44,     6,    60,    61,     5,     4,     6,   150,    18,
     151,     5,    42,     6,   110,    45,     5,    51,     6,    55,
     -30,    81,     7,     8,    56,    48,     9,     7,     8,   -33,
     -35,     9,     7,     8,    68,    69,     9,   101,     7,     8,
      60,    61,     9,     7,     8,    27,    72,     9,   111,   113,
       5,    82,     6,    89,    28,    29,    30,    31,    32,    33,
     119,   120,   121,   122,   123,   124,    88,    26,   134,   135,
     115,   127,   128,   129,   130,   131,   132,     7,     8,    27,
      90,     9,    19,    20,    21,   126,    27,    94,    28,    29,
      30,    31,    32,    33,    48,    28,    29,    30,    31,    32,
      33,    95,   141,    27,    93,    48,   146,    83,    84,    85,
      86,   148,    28,    29,    30,    31,    32,    33,   153,   117,
     118,    60,    61,    96,    48,   145,   -41,   -39,   -43,   -45,
     -47,    60,    61,    97,    91,    92,   -53,   -51,   -55,   -57,
     -59,    49,    19,    20,    21,    99,   100,    98,   102,   103,
     104,   105,   106,   109,   114,   107,   125,   108,   138,   136,
     143,   133,   140,    50,    52,   144,     0,   142,   149,   152
};

static const yytype_int16 yycheck[] =
{
      11,     3,    10,    26,     4,    10,    11,    12,    41,     4,
      10,    44,    12,    20,    21,    10,     5,    12,    33,     0,
      35,    10,    41,    12,    31,    19,    10,    36,    12,    30,
      14,    54,    37,    38,    30,    46,    41,    37,    38,    16,
      17,    41,    37,    38,    22,    23,    41,    70,    37,    38,
      20,    21,    41,    37,    38,    30,    41,    41,    33,    82,
      10,    32,    12,    16,    39,    40,    41,    42,    43,    44,
      93,    94,    95,    96,    97,    98,    13,    18,    33,    34,
      88,   104,   105,   106,   107,   108,   109,    37,    38,    30,
      17,    41,     7,     8,     9,   103,    30,    26,    39,    40,
      41,    42,    43,    44,   115,    39,    40,    41,    42,    43,
      44,    25,   135,    30,    24,   126,    33,    20,    21,    22,
      23,   144,    39,    40,    41,    42,    43,    44,   151,    89,
      90,    20,    21,    27,   145,   143,    25,    26,    27,    28,
      29,    20,    21,    28,    60,    61,    25,    26,    27,    28,
      29,     6,     7,     8,     9,    68,    69,    29,    35,    13,
      24,    26,    25,    29,    35,    27,    41,    28,    15,    43,
      14,    31,    31,    22,    25,    32,    -1,    35,    31,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,    47,     5,    10,    12,    37,    38,    41,
      48,    53,    54,    55,    57,    60,    90,    91,     0,     7,
       8,     9,    49,    50,    51,    58,    18,    30,    39,    40,
      41,    42,    43,    44,    64,    67,    81,    82,    85,    86,
      87,    89,    41,    41,    44,    19,    53,     4,    54,     6,
      50,    36,    64,    85,    88,    30,    30,    61,    65,    66,
      20,    21,    68,    69,    70,    71,    72,    73,    22,    23,
      56,     4,    41,    52,    59,    74,    75,    76,    77,    78,
      79,    85,    32,    20,    21,    22,    23,    80,    13,    16,
      17,    86,    86,    24,    26,    25,    27,    28,    29,    87,
      87,    85,    35,    13,    24,    26,    25,    27,    28,    29,
      31,    33,    83,    85,    35,    53,    62,    67,    67,    85,
      85,    85,    85,    85,    85,    41,    53,    85,    85,    85,
      85,    85,    85,    31,    33,    34,    43,    63,    15,    11,
      31,    85,    35,    14,    32,    53,    33,    84,    85,    31,
      33,    35,    31,    85
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    { printf("\n\n\tCOMPILACION EXITOSA!!\n\n\n"); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 155 "Sintactico.y"
    { printf("\n El archivo 'Prueba.Txt' no tiene un programa\n"); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 164 "Sintactico.y"
    {printf("Regla 1: Seccion declaracion es DEFVAR bloque_dec ENDEC\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 166 "Sintactico.y"
    { guardarTipos(variableActual, listaVariables, tipoActual); reinicioVariables(); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 170 "Sintactico.y"
    {
															printf("Regla 4: declaracion es t_dato DOS_PUNTOS lista_id\n");
															guardarTipos(variableActual, listaVariables, tipoActual); reinicioVariables();
														}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 176 "Sintactico.y"
    {
															printf("Regla 5: t_dato es FLOAT\n");
															strcpy(tipoActual,"FLOAT");
														}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {
															printf("Regla 6: t_dato es INT\n");
															strcpy(tipoActual,"INT");;
														}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 184 "Sintactico.y"
    {
															printf("Regla 7: t_dato es STRING\n");
															strcpy(tipoActual,"STRING");;
														}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 190 "Sintactico.y"
    {
	                                                        printf("Regla 8: lista_id es lista_id PUNTO_COMA ID\n");
	                                                        strcpy(listaVariables[variableActual++],(yyvsp[(3) - (3)].valor_string)); insertar_id_en_ts((yyvsp[(3) - (3)].valor_string));
                                                        }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 194 "Sintactico.y"
    {
	                                                        printf("Regla 9: lista_id es ID\n");
	                                                        strcpy(listaVariables[variableActual++],(yyvsp[(1) - (1)].valor_string)); insertar_id_en_ts((yyvsp[(1) - (1)].valor_string));
                                                        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 204 "Sintactico.y"
    {printf("Regla 10: bloque es bloque sentencia\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 205 "Sintactico.y"
    {printf("Regla 11: bloque es sentencia\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 208 "Sintactico.y"
    {printf("Regla 12: sentencia es asignacion\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 209 "Sintactico.y"
    {printf("Regla 13: sentencia es bloque_if\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 210 "Sintactico.y"
    {printf("Regla 14: sentencia es bloque_while\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 211 "Sintactico.y"
    {printf("Regla 15: sentencia es lectura\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 212 "Sintactico.y"
    {printf("Regla 16: sentencia es escritura\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 217 "Sintactico.y"
    {IndId = crearTerceto_ccc((yyvsp[(1) - (2)].valor_string), "","");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 217 "Sintactico.y"
    { 
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
								 }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 239 "Sintactico.y"
    { while_guardar_pos(terceto_index); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 239 "Sintactico.y"
    { if(strcmp(valor_comparacion, "") != 0) while_guardar_pos(crearTerceto_ccc(valor_comparacion, "", "")); else while_index++; }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 241 "Sintactico.y"
    {printf("Regla 20: bloque_while es WHILE expresion_logica THEN bloque ENDWHILE\n");
														char cadSalto[5];
														cadenaIndice(terceto_index+1,tercetos[while_pos_a_completar[while_index]].dos);
														while_index--;
														cadenaIndice(while_pos_a_completar[while_index],cadSalto);
														crearTerceto_ccc("BI", cadSalto, "");
														while_index--;
														completar_salto_si_es_comparacion_AND(terceto_index);
														}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 256 "Sintactico.y"
    { 
															if(strcmp(valor_comparacion, "") != 0)
															if_guardar_salto(crearTerceto_ccc(valor_comparacion, "", ""));
															else
															if_index++;
														}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 262 "Sintactico.y"
    {	printf("Regla 18: bloque_if es IF expresion_logica THEN decision_bloque ENDIF\n");	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 265 "Sintactico.y"
    {
															if_completar_ultimo_salto_guardado_con(terceto_index);
															completar_salto_si_es_comparacion_AND(terceto_index);
															printf("Regla 19: decision_bloque es bloque\n");
														}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 270 "Sintactico.y"
    { 
															if_completar_ultimo_salto_guardado_con(terceto_index+1);
															completar_salto_si_es_comparacion_AND(terceto_index+1);
															if_guardar_salto(crearTerceto_ccc("BI", "",""));
														}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 275 "Sintactico.y"
    {
															if_completar_ultimo_salto_guardado_con(terceto_index);
															printf("Regla 20: decision_bloque es bloque ELSE bloque\n");
														}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 284 "Sintactico.y"
    { and_index++; saltos_and_a_completar[and_index] = -1; }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 285 "Sintactico.y"
    { and_index++; saltos_and_a_completar[and_index] = crearTerceto_ccc(valor_comparacion, "", ""); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 286 "Sintactico.y"
    {
				char cadInd[5];
				and_index++; saltos_and_a_completar[and_index] = -1;
				cadenaIndice(terceto_index+2,cadInd);
				crearTerceto_ccc(valor_comparacion, cadInd, ""); // salto a la prox comparación
				pos_a_completar_OR = crearTerceto_ccc("BI","",""); // tengo que saltar al final de la prox termino_logico
				}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 293 "Sintactico.y"
    {
				char *salto = (char*) malloc(sizeof(int));
				itoa(terceto_index+1, salto, 10);
				tercetos[pos_a_completar_OR].dos = (char*) malloc(sizeof(char)*strlen(salto));
				strcpy(tercetos[pos_a_completar_OR].dos, salto);
			}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 301 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 301 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BGE");
			 }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 304 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 304 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BGT");
			 }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 307 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 307 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BLE");
			 }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 310 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 310 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BLT");
			 }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 313 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 313 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BNE");
			 }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 316 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 316 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BEQ");
			 }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 319 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 319 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BLT");
			 }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 322 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 322 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
				strcpy(valor_comparacion, "BLE");
			 }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 325 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 325 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BGT");
			 }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 328 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 328 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BGE");
			 }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 331 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 331 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BEQ");
			 }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 334 "Sintactico.y"
    { IndComparacion = IndExpresion; }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 334 "Sintactico.y"
    { char indComp[5],indExpr[5]; cadenaIndice(IndComparacion,indComp); cadenaIndice(IndExpresion,indExpr); crearTerceto_ccc("CMP", indComp, indExpr);
		   		strcpy(valor_comparacion, "BNE");
			 }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 340 "Sintactico.y"
    {
															printf("Regla 48: comp_arimetico es SUMA\n");
															IndCompArit = crearTerceto_ccc("+","","");
														}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 344 "Sintactico.y"
    {
															printf("Regla 49: comp_aritmetico es RESTA\n");
															IndCompArit = crearTerceto_ccc("-","","");
														}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 348 "Sintactico.y"
    {
															printf("Regla 50: comp_aritmetico es POR\n");
															IndCompArit = crearTerceto_ccc("*","","");
														}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 352 "Sintactico.y"
    {
															printf("Regla 51: comp_aritmetico es DIVIDIDO\n");
															IndCompArit = crearTerceto_ccc("/","","");
														}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 363 "Sintactico.y"
    {
															printf("Regla 52: long es LONG PA CA lista_exp_coma CC PC\n");
															IndLong = crearTerceto_icc(cant_lista_long,"","");
															es_long = 1;
														}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 368 "Sintactico.y"
    {
															printf("Regla 53: long es LONG PA CA CC PC\n");
															IndLong = crearTerceto_icc(0,"","");
															es_long = 1;
														}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 375 "Sintactico.y"
    {
																											printf("Regla 54: TAKE es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA lista_exp_punto_coma CC PC\n");
																											int i;
																											int cant_operar = ((yyvsp[(5) - (10)].valor_int));
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
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 408 "Sintactico.y"
    {
																										printf("Regla 55: TAKE es TAKE PA comp_aritmetico PUNTO_COMA CTE_INT PUNTO_COMA CA CC PC");
																										IndTake = crearTerceto_icc(0,"","");
																									}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 414 "Sintactico.y"
    {
															printf("Regla 56: lista_exp_coma es lista_exp_coma COMA expresion_aritmetica\n");
															cant_lista_long++;
														}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 418 "Sintactico.y"
    {
															printf("Regla 57: lista_exp_coma es expresion_aritmetica\n");
															cant_lista_long=1;
														}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 425 "Sintactico.y"
    {
																		printf("Regla 58: lista_exp_punto_coma es lista_exp_punto_coma PUNTO_COMA expresion_aritmetica\n");
																		posicion_numero_take++;
																		take_numeros[posicion_numero_take] = IndExpresion;
																	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 430 "Sintactico.y"
    {
																		printf("Regla 59: lista_exp_punto_coma es expresion_aritmetica\n");
																		posicion_numero_take = 0;
																		take_numeros[posicion_numero_take] = IndExpresion;
																	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 441 "Sintactico.y"
    { 	char cadIndExpr[5], cadIndTer[5];
															cadenaIndice(IndExpresion,cadIndExpr);
															cadenaIndice(IndTermino,cadIndTer);
															IndExpresion = crearTerceto_ccc("+", cadIndExpr, cadIndTer); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 445 "Sintactico.y"
    { 	char cadIndExpr[5], cadIndTer[5];
															cadenaIndice(IndExpresion,cadIndExpr);
															cadenaIndice(IndTermino,cadIndTer);
															IndExpresion = crearTerceto_ccc("-", cadIndExpr, cadIndTer); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 449 "Sintactico.y"
    { IndExpresion = IndTermino; }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 452 "Sintactico.y"
    { 	char cadIndFac[5], cadIndTer[5];
								cadenaIndice(IndFactor,cadIndFac);
								cadenaIndice(IndTermino,cadIndTer);
								IndTermino = crearTerceto_ccc("*", cadIndTer, cadIndFac); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 456 "Sintactico.y"
    { 	char cadIndFac[5], cadIndTer[5];
										cadenaIndice(IndFactor,cadIndFac);
										cadenaIndice(IndTermino,cadIndTer);
										IndTermino = crearTerceto_ccc("/", cadIndTer, cadIndFac); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 460 "Sintactico.y"
    { IndTermino = IndFactor; }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 463 "Sintactico.y"
    { IndFactor = crearTerceto_ccc((yyvsp[(1) - (1)].valor_string), "", ""); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 465 "Sintactico.y"
    {    ponerEnPila(&pilaTermino, IndTermino);
                 ponerEnPila(&pilaExpresion, IndExpresion);
            }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 468 "Sintactico.y"
    {
                            IndFactor = IndExpresion;
                            IndExpresion = sacarDePila(&pilaExpresion);
                            IndTermino = sacarDePila(&pilaTermino);
                        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 473 "Sintactico.y"
    { IndFactor = IndLong; }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 474 "Sintactico.y"
    { IndFactor = IndTake; }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 478 "Sintactico.y"
    { IndFactor = crearTerceto_icc((yyvsp[(1) - (1)].valor_int), "", ""); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 479 "Sintactico.y"
    { IndFactor = crearTerceto_ccc((yyvsp[(1) - (1)].valor_string), "", ""); }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 480 "Sintactico.y"
    { IndFactor = crearTerceto_fcc((yyvsp[(1) - (1)].valor_float), "", ""); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 487 "Sintactico.y"
    { 	char cadIndEntra[5];
							existe_en_ts((yyvsp[(2) - (2)].valor_string));
							IndEntrada = crearTerceto_ccc((yyvsp[(2) - (2)].valor_string), "", "");
							cadenaIndice(IndEntrada,cadIndEntra);
							crearTerceto_ccc("GET",cadIndEntra,"");
							}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 499 "Sintactico.y"
    { char cadIndSali[5];
								IndSalida = crearTerceto_ccc((yyvsp[(2) - (2)].valor_string), "", "");
								cadenaIndice(IndSalida,cadIndSali);
							  crearTerceto_ccc("DISPLAY",cadIndSali,"");
							}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 504 "Sintactico.y"
    { 
							  char cadIndSali[5];
							  existe_en_ts((yyvsp[(2) - (2)].valor_string)); 
							  IndSalida = crearTerceto_ccc((yyvsp[(2) - (2)].valor_string), "", "");
							  cadenaIndice(IndSalida,cadIndSali);
							  crearTerceto_ccc("DISPLAY",cadIndSali,"");
							}
    break;



/* Line 1455 of yacc.c  */
#line 2466 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 515 "Sintactico.y"


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
	terc.uno = malloc(sizeof(char)*strlen(uno));
	strcpy(terc.uno, uno);
	terc.dos = malloc(sizeof(char)*strlen(dos));
	strcpy(terc.dos, dos);
	terc.tres = malloc(sizeof(char)*strlen(tres));
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
	FILE *file = fopen("Intermedia.txt", "a");

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


