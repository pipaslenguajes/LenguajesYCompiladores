
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
#line 1 "sintactico.y"

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


/* Line 189 of yacc.c  */
#line 125 "y.tab.c"

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

/* Line 214 of yacc.c  */
#line 52 "sintactico.y"

	int int_val;
	float float_val;
	char *string_val;



/* Line 214 of yacc.c  */
#line 251 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 263 "y.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNRULES -- Number of states.  */
#define YYNSTATES  87

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    12,    15,    17,    21,    23,    25,
      27,    31,    33,    36,    38,    41,    43,    45,    48,    51,
      54,    59,    66,    70,    74,    76,    78,    80,    84,    88,
      90,    94,    98,   100,   104,   106,   108,   110,   112,   116,
     120,   122,   125,   129,   131,   133,   135,   137,   139,   141,
     144,   147
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,     3,    44,    49,     4,    -1,     5,    45,
       6,    -1,    45,    46,    -1,    46,    -1,    47,    48,    33,
      -1,     8,    -1,     7,    -1,     9,    -1,    48,    32,    38,
      -1,    38,    -1,    49,    50,    -1,    50,    -1,    53,    33,
      -1,    51,    -1,    52,    -1,    62,    33,    -1,    63,    33,
      -1,    56,    33,    -1,    11,    59,    49,    13,    -1,    11,
      59,    49,    12,    49,    13,    -1,    10,    59,    49,    -1,
      38,    17,    54,    -1,    55,    -1,    56,    -1,    41,    -1,
      56,    18,    57,    -1,    56,    19,    57,    -1,    57,    -1,
      57,    20,    58,    -1,    57,    21,    58,    -1,    58,    -1,
      28,    56,    29,    -1,    37,    -1,    38,    -1,    39,    -1,
      40,    -1,    60,    14,    60,    -1,    60,    15,    60,    -1,
      60,    -1,    16,    60,    -1,    56,    61,    56,    -1,    22,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    35,    38,    -1,    36,    38,    -1,    36,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   102,   105,   106,   109,   115,   119,   123,
     129,   134,   146,   147,   150,   151,   152,   153,   154,   155,
     158,   161,   164,   167,   175,   176,   179,   185,   186,   187,
     190,   191,   192,   195,   196,   199,   203,   207,   214,   215,
     216,   217,   220,   224,   225,   226,   227,   228,   229,   251,
     257,   261
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "DEFVAR", "ENDDEF",
  "INT", "FLOAT", "STRING", "WHILE", "IF", "ELSE", "ENDIF", "AND", "OR",
  "NOT", "ASIG", "SUMA", "RESTA", "POR", "DIVIDIDO", "MENOR", "MAYOR",
  "MENOR_IGUAL", "MAYOR_IGUAL", "IGUAL", "DISTINTO", "PA", "PC", "CA",
  "CC", "COMA", "PUNTO_COMA", "DOS_PUNTOS", "GET", "DISPLAY", "LONG", "ID",
  "CONSTANTE_REAL", "CONSTANTE_ENTERA", "CONSTANTE_STRING", "$accept",
  "programa", "seccion_declaracion", "bloque_dec", "declaracion", "t_dato",
  "lista_id", "bloque", "sentencia", "bloque_if", "bloque_while",
  "asignacion", "expresion", "expresion_cadena", "expresion_aritmetica",
  "termino", "factor", "expresion_logica", "termino_logico", "comp_bool",
  "lectura", "escritura", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    47,    47,    47,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    53,    54,    54,    55,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    61,    61,    61,    61,    61,    61,    62,
      63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     3,     1,     1,     1,
       3,     1,     2,     1,     2,     1,     1,     2,     2,     2,
       4,     6,     3,     3,     1,     1,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     1,     3,     3,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     8,     7,     9,     0,
       5,     0,     0,     0,     0,     0,     0,    34,    35,    36,
      37,     0,    13,    15,    16,     0,     0,    29,    32,     0,
       0,     3,     4,    11,     0,     0,    35,     0,     0,    40,
       0,     0,    49,    50,    51,     0,     2,    12,    14,     0,
       0,    19,     0,     0,    17,    18,     0,     6,    41,    43,
      44,    45,    46,    47,    48,     0,    22,     0,     0,     0,
      33,    26,    23,    24,    25,    27,    28,    30,    31,    10,
      42,    38,    39,     0,    20,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     4,     9,    10,    11,    34,    21,    22,    23,
      24,    25,    72,    73,    26,    27,    28,    38,    39,    65,
      29,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -35
static const yytype_int8 yypact[] =
{
       4,    18,    27,    74,    62,   -35,   -35,   -35,   -35,    52,
     -35,     6,    -7,    -7,   -20,    17,   -16,   -35,    48,   -35,
     -35,     1,   -35,   -35,   -35,     2,    -5,    26,   -35,    41,
      76,   -35,   -35,   -35,    30,   -20,   -35,    99,    62,    71,
      62,    -3,   -35,   -35,   -35,    75,   -35,   -35,   -35,   -20,
     -20,   -35,   -20,   -20,   -35,   -35,    51,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -20,    62,   -20,   -20,    40,
     -35,   -35,   -35,   -35,    69,    26,    26,   -35,   -35,   -35,
      69,   -35,   -35,    62,   -35,    56,   -35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -35,   -35,    95,   -35,   -35,   -34,   -21,   -35,
     -35,   -35,   -35,   -35,   -11,    21,    53,    94,   -25,   -35,
     -35,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      47,    37,    37,    41,    66,    46,    69,     1,    14,    35,
      58,    12,    13,    49,    50,    49,    50,    17,    36,    19,
      20,    14,    43,     3,    37,    44,    70,     5,    51,    14,
      17,    36,    19,    20,    74,    48,    15,    16,    17,    18,
      19,    20,    81,    82,    33,    47,    52,    53,    47,    85,
      12,    13,    83,    84,    80,    42,    37,    37,    31,     6,
       7,     8,    56,    57,    47,    45,    12,    13,    14,    86,
      75,    76,    12,    13,    54,    15,    16,    17,    18,    19,
      20,     6,     7,     8,    14,    67,    68,    49,    50,    79,
      14,    15,    16,    17,    18,    19,    20,    15,    16,    17,
      18,    19,    20,    14,    32,    77,    78,    40,     0,    55,
       0,     0,    17,    36,    19,    20,    71,    49,    50,     0,
       0,    59,    60,    61,    62,    63,    64
};

static const yytype_int8 yycheck[] =
{
      21,    12,    13,    14,    38,     4,    40,     3,    28,    16,
      35,    10,    11,    18,    19,    18,    19,    37,    38,    39,
      40,    28,    38,     5,    35,    41,    29,     0,    33,    28,
      37,    38,    39,    40,    45,    33,    35,    36,    37,    38,
      39,    40,    67,    68,    38,    66,    20,    21,    69,    83,
      10,    11,    12,    13,    65,    38,    67,    68,     6,     7,
       8,     9,    32,    33,    85,    17,    10,    11,    28,    13,
      49,    50,    10,    11,    33,    35,    36,    37,    38,    39,
      40,     7,     8,     9,    28,    14,    15,    18,    19,    38,
      28,    35,    36,    37,    38,    39,    40,    35,    36,    37,
      38,    39,    40,    28,     9,    52,    53,    13,    -1,    33,
      -1,    -1,    37,    38,    39,    40,    41,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,     5,    44,     0,     7,     8,     9,    45,
      46,    47,    10,    11,    28,    35,    36,    37,    38,    39,
      40,    49,    50,    51,    52,    53,    56,    57,    58,    62,
      63,     6,    46,    38,    48,    16,    38,    56,    59,    60,
      59,    56,    38,    38,    41,    17,     4,    50,    33,    18,
      19,    33,    20,    21,    33,    33,    32,    33,    60,    22,
      23,    24,    25,    26,    27,    61,    49,    14,    15,    49,
      29,    41,    54,    55,    56,    57,    57,    58,    58,    38,
      56,    60,    60,    12,    13,    49,    13
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
#line 94 "sintactico.y"
    {
															printf("\nCOMPILACION EXITOSA\n");
															guardarTabla();
														}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 102 "sintactico.y"
    {printf("Regla 1: Seccion declaracion es DEFVAR bloque_dec ENDEC\n\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 105 "sintactico.y"
    {printf("Regla 2: bloque_dec es bloque_dec declaracion\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 106 "sintactico.y"
    {printf("Regla 3: bloque_dec es declaracion\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 109 "sintactico.y"
    {
															printf("Regla 4: declaracion es t_dato lista_id PUNTO_COMA\n");
															 agregarTiposDatosATabla();
														}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 115 "sintactico.y"
    {
															printf("Regla 5: t_dato es FLOAT\n");
															tipoDatoADeclarar = Float;
														}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 119 "sintactico.y"
    {
															printf("Regla 6: t_dato es INT\n");
															tipoDatoADeclarar = Int;
														}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 123 "sintactico.y"
    {
															printf("Regla 7: t_dato es STRING\n");
															tipoDatoADeclarar = String;
														}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 129 "sintactico.y"
    {
	                                                        printf("Regla 8: lista_id es lista_id COMA ID\n");
	                                                        agregarVarATabla(yylval.string_val);
															cantVarsADeclarar++;
                                                        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 134 "sintactico.y"
    {
	                                                        printf("Regla 9: lista_id es ID\n");
	                                                        agregarVarATabla(yylval.string_val);
															varADeclarar1 = fin_tabla; /* Guardo posicion de primer variable de esta lista de declaracion. */
															cantVarsADeclarar = 1;
                                                        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 146 "sintactico.y"
    {printf("Regla 10: bloque es bloque sentencia\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 147 "sintactico.y"
    {printf("Regla 11: bloque es sentencia\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 150 "sintactico.y"
    {printf("Regla 12: sentencia es asignacion PUNTO_COMA\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 151 "sintactico.y"
    {printf("Regla 13: sentencia es bloque_if\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 152 "sintactico.y"
    {printf("Regla 14: sentencia es bloque_while\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 153 "sintactico.y"
    {printf("Regla 15: sentencia es lectura PUNTO_COMA\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 154 "sintactico.y"
    {printf("Regla 16: sentencia es escritura PUNTO_COMA\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 155 "sintactico.y"
    {printf("Regla 17: sentencia es expresion_aritmetica PUNTO_COMA\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 158 "sintactico.y"
    {printf("Regla 18: bloque_if es IF expresion_logica THEN bloque ENDIF\n\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 161 "sintactico.y"
    {printf("Regla 19: bloque_if es IF expresion_logica THEN bloque ELSE bloque ENDIF\n\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 164 "sintactico.y"
    {printf("Regla 20: bloque_while es WHILE expresion_logica bloque ENDWHILE\n\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 167 "sintactico.y"
    {
															chequearVarEnTabla((yyvsp[(1) - (3)].string_val));
															printf("Regla 21: asignacion es ID ASIG expresion\n\n");
														}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 175 "sintactico.y"
    {printf("Regla 22: expresion es expresion_cadena\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 176 "sintactico.y"
    {printf("Regla 23: expresion es expresion_aritmetica\n");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 179 "sintactico.y"
    {
															printf("Regla 24: expresion_cadena es CONSTANTE_STRING\n");
															agregarCteStringATabla(yylval.string_val);
														}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 185 "sintactico.y"
    {printf("Regla 25: expresion_aritmetica es expresion_aritmetica SUMA termino\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 186 "sintactico.y"
    {printf("Regla 26: expresion_aritmetica es expresion_aritmetica RESTA termino\n");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 187 "sintactico.y"
    {printf("Regla 27: expresion_aritmetica es termino\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 190 "sintactico.y"
    {printf("Regla 28: termino es termino POR factor\n");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 191 "sintactico.y"
    {printf("Regla 29: termino es termino DIVIDIDO factor\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 192 "sintactico.y"
    {printf("Regla 30: termino es factor\n");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 195 "sintactico.y"
    {printf("Regla 31: factor es PA expresion_aritmetica PC\n");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 196 "sintactico.y"
    {printf("Regla 32: factor es LONG\n");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 199 "sintactico.y"
    {
															chequearVarEnTabla(yylval.string_val);
															printf("Regla 33: factor es ID\n");
														}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 203 "sintactico.y"
    {
															printf("Regla 34: factor es CONSTANTE_REAL\n");
															agregarCteFloatATabla(yylval.float_val);
														}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 207 "sintactico.y"
    {
															printf("Regla 35: factor es CONSTANTE_ENTERA\n");
															agregarCteIntATabla(yylval.int_val);
														}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 214 "sintactico.y"
    {printf("Regla 36: expresion_logica es termino_logico AND termino_logico\n");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 215 "sintactico.y"
    {printf("Regla 37: expresion_logica es termino_logico OR termino_logico\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 216 "sintactico.y"
    {printf("Regla 38: expresion_logica es termino_logico\n");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 217 "sintactico.y"
    {printf("Regla 39: expresion_logica es NOT termino_logico\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 220 "sintactico.y"
    {printf("Regla 40: termino_logico es expresion_aritmetica comp_bool expresion_aritmetica\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 224 "sintactico.y"
    {printf("Regla 42: comp_bool es MENOR\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 225 "sintactico.y"
    {printf("Regla 43: comp_bool es MAYOR\n");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 226 "sintactico.y"
    {printf("Regla 44: comp_bool es MENOR_IGUAL\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 227 "sintactico.y"
    {printf("Regla 45: comp_bool es MAYOR_IGUAL\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 228 "sintactico.y"
    {printf("Regla 46: comp_bool es IGUAL\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 229 "sintactico.y"
    {printf("Regla 47: comp_bool es DISTINTO\n");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 251 "sintactico.y"
    {
															chequearVarEnTabla((yyvsp[(2) - (2)].string_val));
															printf("Regla 54: lectura es GET ID\n");
														}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 257 "sintactico.y"
    {
															chequearVarEnTabla((yyvsp[(2) - (2)].string_val));
															printf("Regla 55: escritura es DISPLAY ID\n");
														}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 261 "sintactico.y"
    {
															printf("Regla 56: escritura es DISPLAY CONSTANTE_STRING\n\n");
															agregarCteStringATabla(yylval.string_val);
														}
    break;



/* Line 1455 of yacc.c  */
#line 1941 "y.tab.c"
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
#line 265 "sintactico.y"


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

/* Devuleve la posici�n en la que se encuentra el elemento buscado, -1 si no encontr� el elemento */
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
		 printf("Error: me quede sin espacio en la tabla de simbolos. Sori, gordi.\n");
		 system("Pause");
		 exit(2);
	 }
	 //Si no hay otra variable con el mismo nombre...
	 if(buscarEnTabla(nombre) == -1){
		 //Agregar a tabla
		 fin_tabla++;
		 escribirNombreEnTabla(nombre, fin_tabla);
	 }
	 else yyerror("Encontre dos declaraciones de variables con el mismo nombre. Decidite."); //Error, ya existe esa variable

 }

/** Agrega los tipos de datos a las variables declaradas. Usa las variables globales varADeclarar1, cantVarsADeclarar y tipoDatoADeclarar */
void agregarTiposDatosATabla(){
	for(int i = 0; i < cantVarsADeclarar; i++){
		tabla_simbolo[varADeclarar1 + i].tipo_dato = tipoDatoADeclarar;
	}
}

/** Guarda la tabla de simbolos en un archivo de texto */
void guardarTabla(){
	if(fin_tabla == -1)
		yyerror("No encontre la tabla de simbolos");

	FILE* arch = fopen("ts.txt", "w+");
	if(!arch){
		printf("No pude crear el archivo ts.txt\n");
		return;
	}

	for(int i = 0; i <= fin_tabla; i++){
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
			fprintf(arch, "CONSTANTE_REAL\t%f", tabla_simbolo[i].valor_f);
			break;
		case CteInt:
			fprintf(arch, "CONSTANTE_ENTERA\t%d", tabla_simbolo[i].valor_i);
			break;
		case CteString:
			fprintf(arch, "CONSTANTE_STRING\t%s\t%d", &(tabla_simbolo[i].valor_s), tabla_simbolo[i].longitud);
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
		printf("Error: me quede sin espacio en la tabla de simbolos. Sori, gordi.\n");
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
		printf("Error: me quede sin espacio en la tabla de simbolos. Sori, gordi.\n");
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
		printf("Error: me quede sin espacio en la tabla de simbolos. Sori, gordi.\n");
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
		sprintf(msg,"%s? No, man, tenes que declarar las variables arriba. Esto no es un viva la pepa como java...", nombre);
		yyerror(msg);
	}
	//Si existe en la tabla, dejo que la compilacion siga
}

