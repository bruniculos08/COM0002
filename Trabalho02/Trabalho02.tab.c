
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
#line 1 "Trabalho02.y"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Compiler.h"

extern int count_label;



/* Line 189 of yacc.c  */
#line 85 "Trabalho02.tab.c"

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
     END = 0,
     PROGRAM_TOKEN = 258,
     PRINT_TOKEN = 259,
     TRUE_TOKEN = 260,
     FALSE_TOKEN = 261,
     ID_TOKEN = 262,
     ADD_TOKEN = 263,
     SUB_TOKEN = 264,
     OR_TOKEN = 265,
     MULT_TOKEN = 266,
     DIVIDE_TOKEN = 267,
     AND_TOKEN = 268,
     SMALLER_TOKEN = 269,
     BIGGER_TOKEN = 270,
     SMALLER_EQUAL_TOKEN = 271,
     BIGGER_EQUAL_TOKEN = 272,
     EQUAL_TOKEN = 273,
     DIFF_TOKEN = 274,
     OUTROS_TOKEN = 275,
     DOT_TOKEN = 276,
     INTEGER_TOKEN = 277,
     REAL_TOKEN = 278,
     BOOLEAN_TOKEN = 279,
     VAZIO_TOKEN = 280,
     INT_TOKEN = 281,
     FLOAT_TOKEN = 282,
     IF_TOKEN = 283,
     ELSE_TOKEN = 284,
     THEN_TOKEN = 285,
     BEGIN_TOKEN = 286,
     END_TOKEN = 287,
     FUNCTION_TOKEN = 288,
     DOTCOMMA_TOKEN = 289,
     TWODOTS_TOKEN = 290,
     WHILE_TOKEN = 291,
     DO_TOKEN = 292,
     COMMA_TOKEN = 293,
     ARRAY_TOKEN = 294,
     BLEFT_TOKEN = 295,
     BRIGHT_TOKEN = 296,
     VAR_TOKEN = 297,
     PROCEDURE_TOKEN = 298,
     OF_TOKEN = 299,
     PLEFT_TOKEN = 300,
     PRIGHT_TOKEN = 301,
     TWODOTS_EQUAL_TOKEN = 302,
     TO_TOKEN = 303,
     FOR_TOKEN = 304,
     CBLEFT_TOKEN = 305,
     CBRIGHT_TOKEN = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 12 "Trabalho02.y"

	int ival;
	float fval;
	char cval;
	char *sval;
	book *bookval;



/* Line 214 of yacc.c  */
#line 183 "Trabalho02.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "Trabalho02.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,     9,    11,    14,    16,    18,    20,
      22,    25,    28,    32,    33,    34,    35,    36,    52,    53,
      54,    64,    65,    66,    77,    78,    79,    91,    95,   100,
     103,   105,   108,   110,   115,   118,   122,   124,   128,   130,
     132,   134,   138,   140,   143,   145,   149,   151,   153,   155,
     157,   159,   161,   163,   165,   167,   169,   171,   173,   175,
     177,   179,   181,   182,   189,   190,   196,   200,   202,   204,
     206,   208,   210,   212
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      85,     0,    -1,    92,    47,    77,    -1,     5,    -1,     6,
      -1,    53,    34,    -1,    68,    -1,    56,    -1,    57,    -1,
      62,    -1,    65,    34,    -1,    87,    34,    -1,    31,    79,
      32,    -1,    -1,    -1,    -1,    -1,    49,    45,    53,    58,
      34,    71,    59,    34,    53,    60,    46,    50,    79,    61,
      51,    -1,    -1,    -1,    36,    63,    45,    71,    64,    46,
      50,    79,    51,    -1,    -1,    -1,    37,    66,    50,    79,
      51,    36,    45,    71,    67,    46,    -1,    -1,    -1,    28,
      45,    71,    46,    30,    50,    69,    79,    51,    70,    72,
      -1,    77,    84,    77,    -1,    29,    50,    79,    51,    -1,
      29,    68,    -1,    93,    -1,    76,    56,    -1,    75,    -1,
      42,    80,    35,    90,    -1,    74,    34,    -1,    76,    74,
      34,    -1,    93,    -1,    77,    82,    89,    -1,    89,    -1,
      92,    -1,    81,    -1,    45,    77,    46,    -1,    55,    -1,
      79,    55,    -1,    93,    -1,    80,    38,     7,    -1,     7,
      -1,    26,    -1,    27,    -1,    54,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    -1,     3,    86,     7,    34,    73,     0,    -1,    -1,
       4,    45,    88,    77,    46,    -1,    89,    83,    78,    -1,
      78,    -1,    91,    -1,    22,    -1,    23,    -1,    24,    -1,
       7,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    55,    56,    59,    60,    61,    62,    63,
      64,    65,    68,    71,    71,    71,    71,    71,    74,    74,
      74,    77,    77,    77,    80,    80,    80,    83,    86,    87,
      88,    91,    94,    97,   102,   103,   104,   111,   112,   115,
     116,   117,   120,   121,   122,   125,   126,   130,   131,   132,
     135,   136,   137,   140,   141,   142,   145,   146,   147,   148,
     149,   150,   153,   153,   162,   162,   172,   173,   176,   179,
     180,   181,   184,   187
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "PROGRAM_TOKEN",
  "PRINT_TOKEN", "TRUE_TOKEN", "FALSE_TOKEN", "ID_TOKEN", "ADD_TOKEN",
  "SUB_TOKEN", "OR_TOKEN", "MULT_TOKEN", "DIVIDE_TOKEN", "AND_TOKEN",
  "SMALLER_TOKEN", "BIGGER_TOKEN", "SMALLER_EQUAL_TOKEN",
  "BIGGER_EQUAL_TOKEN", "EQUAL_TOKEN", "DIFF_TOKEN", "OUTROS_TOKEN",
  "DOT_TOKEN", "INTEGER_TOKEN", "REAL_TOKEN", "BOOLEAN_TOKEN",
  "VAZIO_TOKEN", "INT_TOKEN", "FLOAT_TOKEN", "IF_TOKEN", "ELSE_TOKEN",
  "THEN_TOKEN", "BEGIN_TOKEN", "END_TOKEN", "FUNCTION_TOKEN",
  "DOTCOMMA_TOKEN", "TWODOTS_TOKEN", "WHILE_TOKEN", "DO_TOKEN",
  "COMMA_TOKEN", "ARRAY_TOKEN", "BLEFT_TOKEN", "BRIGHT_TOKEN", "VAR_TOKEN",
  "PROCEDURE_TOKEN", "OF_TOKEN", "PLEFT_TOKEN", "PRIGHT_TOKEN",
  "TWODOTS_EQUAL_TOKEN", "TO_TOKEN", "FOR_TOKEN", "CBLEFT_TOKEN",
  "CBRIGHT_TOKEN", "$accept", "atribuicao", "bool_lit", "comando",
  "comando_composto", "comando_for", "$@1", "$@2", "$@3", "$@4",
  "comando_while", "$@5", "$@6", "comando_do_while", "$@7", "$@8",
  "condicional", "$@9", "$@10", "condicao_contraria", "comando_else",
  "corpo", "declaracao", "declaracao_de_variavel", "declaracoes",
  "expressao_simples", "fator", "lista_de_comandos", "lista_de_ids",
  "literal", "op_ad", "op_mul", "op_rel", "programa", "$@11", "printar",
  "$@12", "termo", "tipo", "tipo_simples", "variavel", "vazio", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    56,    58,    59,    60,    61,    57,    63,    64,
      62,    66,    67,    65,    69,    70,    68,    71,    72,    72,
      72,    73,    74,    75,    76,    76,    76,    77,    77,    78,
      78,    78,    79,    79,    79,    80,    80,    81,    81,    81,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    86,    85,    88,    87,    89,    89,    90,    91,
      91,    91,    92,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     2,     1,     1,     1,     1,
       2,     2,     3,     0,     0,     0,     0,    15,     0,     0,
       9,     0,     0,    10,     0,     0,    11,     3,     4,     2,
       1,     2,     1,     4,     2,     3,     1,     3,     1,     1,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    62,     0,     0,     1,     0,    73,     0,     0,     0,
      32,     0,    36,    46,     0,    63,    34,    73,    31,     0,
       0,     0,     0,    72,     0,    18,    21,     0,     0,    42,
       7,     8,     9,     0,     6,     0,     0,     0,    44,    35,
      69,    70,    71,    33,    68,    45,    64,     0,     0,     0,
       0,     5,    10,    12,    43,    11,     0,     0,     3,     4,
      47,    48,     0,    49,     0,     0,    67,    40,    38,    39,
       0,    73,    13,     2,     0,     0,     0,    50,    51,    52,
      56,    57,    58,    59,    60,    61,     0,     0,    53,    54,
      55,     0,    19,     0,     0,    65,    41,     0,    37,    27,
      66,     0,     0,     0,    24,     0,     0,    14,    73,    73,
       0,     0,     0,     0,    22,     0,    25,    20,     0,    15,
      73,    23,     0,     0,    26,    30,     0,    73,    29,    73,
       0,    16,    28,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    63,    29,    30,    31,    94,   111,   122,   133,
      32,    48,   101,    33,    49,   118,    34,   108,   120,    64,
     124,     8,     9,    10,    11,    65,    66,    35,    14,    67,
      86,    91,    87,     2,     3,    36,    57,    68,    43,    44,
      37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
       5,   -68,    21,     2,   -68,   -11,     1,    22,    46,    13,
     -68,    -5,   -68,   -68,   -13,   -68,   -68,    97,   -68,    24,
      50,    56,    20,   -68,    37,   -68,   -68,    38,    32,   -68,
     -68,   -68,   -68,    58,   -68,    87,    59,    48,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,     6,    54,    52,
      96,   -68,   -68,   -68,   -68,   -68,     6,     6,   -68,   -68,
     -68,   -68,     6,   -68,    63,   133,   -68,   -68,    77,   -68,
       6,    97,   -68,   112,     9,    61,    75,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,     6,     6,   -68,   -68,
     -68,     6,   -68,    -1,    76,   -68,   -68,    62,    77,   112,
     -68,    67,    90,     6,   -68,    82,    85,   -68,    97,    97,
       6,    93,     3,    49,   -68,    96,   -68,   -68,    89,   -68,
     108,   -68,    92,   -12,   -68,   -68,    94,    97,   -68,    97,
      80,    97,   -68,    88,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -48,   -68,   -34,   129,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,    30,   -68,   -68,   -46,
     -68,   -68,   134,   -68,   -68,    19,    64,   -67,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,    68,   -68,   -68,
     -42,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      12,    54,    72,    22,    93,    69,    23,    22,     1,     5,
      23,    58,    59,    23,    69,    69,    24,    77,    78,    79,
      69,     4,    20,     6,    92,    21,    17,    24,    69,    13,
      17,    24,    60,    61,    17,    25,    26,     7,   127,    25,
      26,   112,   113,     7,    69,    69,    15,    16,    27,    69,
     102,    62,    27,    22,   116,    95,    23,   107,    39,    54,
     130,    69,   131,    45,   114,    46,    51,   119,    69,    77,
      78,    79,    40,    41,    42,    73,    74,    24,    54,    54,
      17,    75,    47,    50,    22,    25,    26,    23,    88,    89,
      90,    22,    52,    55,    23,    56,    54,    54,    27,    70,
     117,    22,    71,    23,    23,    97,    99,    96,    24,    76,
     103,    17,   104,   105,   125,    24,    25,    26,    17,    53,
      77,    78,    79,    25,    26,    24,   106,   115,    17,    27,
     110,   132,   109,    25,    26,   121,    27,   123,   126,   134,
      18,    77,    78,    79,   129,    19,    27,    80,    81,    82,
      83,    84,    85,   128,    98,   100
};

static const yytype_uint8 yycheck[] =
{
       6,    35,    50,     4,    71,    47,     7,     4,     3,     7,
       7,     5,     6,     7,    56,    57,    28,     8,     9,    10,
      62,     0,    35,    34,    70,    38,    31,    28,    70,     7,
      31,    28,    26,    27,    31,    36,    37,    42,    50,    36,
      37,   108,   109,    42,    86,    87,     0,    34,    49,    91,
      51,    45,    49,     4,    51,    46,     7,   103,    34,    93,
     127,   103,   129,     7,   110,    45,    34,   115,   110,     8,
       9,    10,    22,    23,    24,    56,    57,    28,   112,   113,
      31,    62,    45,    45,     4,    36,    37,     7,    11,    12,
      13,     4,    34,    34,     7,    47,   130,   131,    49,    45,
      51,     4,    50,     7,     7,    30,    87,    46,    28,    46,
      34,    31,    50,    46,   120,    28,    36,    37,    31,    32,
       8,     9,    10,    36,    37,    28,    36,    34,    31,    49,
      45,    51,    50,    36,    37,    46,    49,    29,    46,    51,
      11,     8,     9,    10,    50,    11,    49,    14,    15,    16,
      17,    18,    19,   123,    86,    91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    85,    86,     0,     7,    34,    42,    73,    74,
      75,    76,    93,     7,    80,     0,    34,    31,    56,    74,
      35,    38,     4,     7,    28,    36,    37,    49,    53,    55,
      56,    57,    62,    65,    68,    79,    87,    92,    93,    34,
      22,    23,    24,    90,    91,     7,    45,    45,    63,    66,
      45,    34,    34,    32,    55,    34,    47,    88,     5,     6,
      26,    27,    45,    54,    71,    77,    78,    81,    89,    92,
      45,    50,    53,    77,    77,    77,    46,     8,     9,    10,
      14,    15,    16,    17,    18,    19,    82,    84,    11,    12,
      13,    83,    71,    79,    58,    46,    46,    30,    89,    77,
      78,    64,    51,    34,    50,    46,    36,    71,    69,    50,
      45,    59,    79,    79,    71,    34,    51,    51,    67,    53,
      70,    46,    60,    29,    72,    93,    46,    50,    68,    50,
      79,    79,    51,    61,    51
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
#line 52 "Trabalho02.y"
    { atributeIntVariable((yyvsp[(1) - (3)].sval)); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 55 "Trabalho02.y"
    { (yyval.ival) = 1;	;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 56 "Trabalho02.y"
    { (yyval.ival) = 0;	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 71 "Trabalho02.y"
    {(yyvsp[(1) - (3)].ival) = count_label; onlyLabel((yyvsp[(1) - (3)].ival)); count_label+=4;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 71 "Trabalho02.y"
    {onlyLabelForIf((yyvsp[(1) - (6)].ival) + 1); onlyGoTo((yyvsp[(1) - (6)].ival) + 2); onlyLabel((yyvsp[(1) - (6)].ival) + 3); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 71 "Trabalho02.y"
    {onlyGoTo((yyvsp[(1) - (9)].ival)); onlyLabel((yyvsp[(1) - (9)].ival) + 2);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 71 "Trabalho02.y"
    {onlyGoTo((yyvsp[(1) - (13)].ival) + 3); onlyLabel((yyvsp[(1) - (13)].ival) + 1);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 74 "Trabalho02.y"
    { (yyvsp[(1) - (1)].ival) = count_label; onlyLabel((yyvsp[(1) - (1)].ival)); count_label+=2; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 74 "Trabalho02.y"
    { onlyLabelForIf((yyvsp[(1) - (4)].ival) + 1); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 74 "Trabalho02.y"
    { onlyGoTo((yyvsp[(1) - (9)].ival)); onlyLabel((yyvsp[(1) - (9)].ival) + 1); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 77 "Trabalho02.y"
    { (yyvsp[(1) - (1)].ival) = count_label; onlyLabel((yyvsp[(1) - (1)].ival)); count_label+=2; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 77 "Trabalho02.y"
    { onlyLabelForIf((yyvsp[(1) - (8)].ival) + 1); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 77 "Trabalho02.y"
    { onlyGoTo((yyvsp[(1) - (10)].ival)); onlyLabel((yyvsp[(1) - (10)].ival) + 1); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 80 "Trabalho02.y"
    { (yyvsp[(1) - (6)].ival) = count_label; onlyLabelForIf((yyvsp[(1) - (6)].ival)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 80 "Trabalho02.y"
    { onlyGoTo((yyvsp[(1) - (9)].ival) +1); onlyLabel((yyvsp[(1) - (9)].ival)); count_label+=2;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 80 "Trabalho02.y"
    {onlyLabel((yyvsp[(1) - (11)].ival) + 1); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 83 "Trabalho02.y"
    { putOpInStack('-'); ifStackInverse((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 111 "Trabalho02.y"
    { putOpInStack((yyvsp[(2) - (3)].cval)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 112 "Trabalho02.y"
    { ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 115 "Trabalho02.y"
    { loadVariableValue(getLocation((yyvsp[(1) - (1)].sval))); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 117 "Trabalho02.y"
    { ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 125 "Trabalho02.y"
    { ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 126 "Trabalho02.y"
    { ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 130 "Trabalho02.y"
    { putIntInStack((yyvsp[(1) - (1)].ival)); 	   ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 131 "Trabalho02.y"
    { putIntInStack((int)(yyvsp[(1) - (1)].fval)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 132 "Trabalho02.y"
    { putIntInStack((int)(yyvsp[(1) - (1)].ival)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 135 "Trabalho02.y"
    { (yyval.cval) = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 136 "Trabalho02.y"
    { (yyval.cval) = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 137 "Trabalho02.y"
    { (yyval.cval) = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 140 "Trabalho02.y"
    { (yyval.cval) = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 141 "Trabalho02.y"
    { (yyval.cval) = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 142 "Trabalho02.y"
    { (yyval.cval) = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 145 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 146 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 147 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 148 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 149 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 150 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 153 "Trabalho02.y"
    { generateHeader(); generateMainHeader();;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 153 "Trabalho02.y"
    { 
													  // (6) Se os comandos desse bloco forem executados então...
													  // ... a sentença (programa) pode ser gerada pela gramática (o...
													  // ... programa está sintáticamente correto).
													  generateMainFooter();
													  printf("\nPrograma valido\n");
													;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 162 "Trabalho02.y"
    {writeCode("getstatic java/lang/System/out Ljava/io/PrintStream;\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 162 "Trabalho02.y"
    {writeCode("invokevirtual java/io/PrintStream/println(I)V\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 172 "Trabalho02.y"
    { putOpInStack((yyvsp[(2) - (3)].cval)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 173 "Trabalho02.y"
    { 					;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 176 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 179 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 180 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); /*Obs: converter qualquer número para int enquanto não podemos tratar diferente tipos. */;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 181 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); /*Obs: converter qualquer número para int enquanto não podemos tratar diferente tipos. */;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 184 "Trabalho02.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1875 "Trabalho02.tab.c"
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
#line 190 "Trabalho02.y"


int main() {
	
	// (7) A variável yyin recebe a entrada do terminal (stdin):
	yyin = stdin;

	// (8) Enquanto não se chega no final do arquivo de entrada (yyin) se executa a função de analise...
	// ... sintatica (yyparse):
	do {
		yyparse();
	} while(!feof(yyin));
	//tableMain();


	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de analise (sintatica): %s\n", s);
	exit(1);
}
