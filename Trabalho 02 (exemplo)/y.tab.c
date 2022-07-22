/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>

#include <stdio.h>
#include <unistd.h>



#include "bytecode_inst.h"

#define GetCurrentDir getcwd

using namespace std;

extern  int yylex();
//extern  int yyparse();
extern  FILE *yyin;
void yyerror(const char * s);
extern int lineCounter;

#define TRUE 1
#define FALSE 0
string outfileName ;

ofstream fout("output.j");	/* file for writing output */
void generateHeader(void);	/* generate  header for class to be able to compile the code*/
void generateFooter(void);	/* generate  footer for class to be able to compile the code*/

int varaiblesNum = 1; 	/* new variable will be issued this number, java starts with 1, 0 is 'this' */
int labelsCount = 0;	/* to generate labels */

typedef enum {INT_T, FLOAT_T, BOOL_T, VOID_T, ERROR_T} type_enum;

map<string, pair<int,type_enum> > symbTab;




void cast (string x, int type_t1);
void arithCast(int from , int to, string op);
void relaCast(string op,char * nTrue, char * nFalse);

bool checkId(string id);
string getOp(string op);
void defineVar(string name, int type);

string genLabel();
string getLabel(int n);
//char *strdup (const char *s) throw ();

void backpatch(vector<int> *list, int num);
vector<int> * merge (vector<int> *list1, vector<int>* list2);

vector<string> codeList;
void writeCode(string x);

void printCode(void);
void printLineNumber(int num)
{
	writeCode(".line "+ to_string(num));
}




#line 141 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 71 "syntax.y"

	#include <vector>
	using namespace std;

#line 181 "y.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    BOOL = 260,                    /* BOOL  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    ARITH_OP = 262,                /* ARITH_OP  */
    RELA_OP = 263,                 /* RELA_OP  */
    BOOL_OP = 264,                 /* BOOL_OP  */
    IF_WORD = 265,                 /* IF_WORD  */
    ELSE_WORD = 266,               /* ELSE_WORD  */
    WHILE_WORD = 267,              /* WHILE_WORD  */
    FOR_WORD = 268,                /* FOR_WORD  */
    INT_WORD = 269,                /* INT_WORD  */
    FLOAT_WORD = 270,              /* FLOAT_WORD  */
    BOOLEAN_WORD = 271,            /* BOOLEAN_WORD  */
    SEMI_COLON = 272,              /* SEMI_COLON  */
    EQUALS = 273,                  /* EQUALS  */
    LEFT_BRACKET = 274,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 275,           /* RIGHT_BRACKET  */
    LEFT_BRACKET_CURLY = 276,      /* LEFT_BRACKET_CURLY  */
    RIGHT_BRACKET_CURLY = 277,     /* RIGHT_BRACKET_CURLY  */
    SYSTEM_OUT = 278               /* SYSTEM_OUT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define BOOL 260
#define IDENTIFIER 261
#define ARITH_OP 262
#define RELA_OP 263
#define BOOL_OP 264
#define IF_WORD 265
#define ELSE_WORD 266
#define WHILE_WORD 267
#define FOR_WORD 268
#define INT_WORD 269
#define FLOAT_WORD 270
#define BOOLEAN_WORD 271
#define SEMI_COLON 272
#define EQUALS 273
#define LEFT_BRACKET 274
#define RIGHT_BRACKET 275
#define LEFT_BRACKET_CURLY 276
#define RIGHT_BRACKET_CURLY 277
#define SYSTEM_OUT 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "syntax.y"

	int ival;
	float fval;
	int bval;
	char * idval;
	char * aopval;
	struct {
		int sType;
	} expr_type;
	struct {
		vector<int> *trueList, *falseList;//no need for next because every if has else
	} bexpr_type;
	struct {
		vector<int> *nextList;
	} stmt_type;
	int sType;

#line 265 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_ARITH_OP = 7,                   /* ARITH_OP  */
  YYSYMBOL_RELA_OP = 8,                    /* RELA_OP  */
  YYSYMBOL_BOOL_OP = 9,                    /* BOOL_OP  */
  YYSYMBOL_IF_WORD = 10,                   /* IF_WORD  */
  YYSYMBOL_ELSE_WORD = 11,                 /* ELSE_WORD  */
  YYSYMBOL_WHILE_WORD = 12,                /* WHILE_WORD  */
  YYSYMBOL_FOR_WORD = 13,                  /* FOR_WORD  */
  YYSYMBOL_INT_WORD = 14,                  /* INT_WORD  */
  YYSYMBOL_FLOAT_WORD = 15,                /* FLOAT_WORD  */
  YYSYMBOL_BOOLEAN_WORD = 16,              /* BOOLEAN_WORD  */
  YYSYMBOL_SEMI_COLON = 17,                /* SEMI_COLON  */
  YYSYMBOL_EQUALS = 18,                    /* EQUALS  */
  YYSYMBOL_LEFT_BRACKET = 19,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 20,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_BRACKET_CURLY = 21,        /* LEFT_BRACKET_CURLY  */
  YYSYMBOL_RIGHT_BRACKET_CURLY = 22,       /* RIGHT_BRACKET_CURLY  */
  YYSYMBOL_SYSTEM_OUT = 23,                /* SYSTEM_OUT  */
  YYSYMBOL_YYACCEPT = 24,                  /* $accept  */
  YYSYMBOL_method_body = 25,               /* method_body  */
  YYSYMBOL_26_1 = 26,                      /* $@1  */
  YYSYMBOL_statement_list = 27,            /* statement_list  */
  YYSYMBOL_marker = 28,                    /* marker  */
  YYSYMBOL_statement = 29,                 /* statement  */
  YYSYMBOL_declaration = 30,               /* declaration  */
  YYSYMBOL_primitive_type = 31,            /* primitive_type  */
  YYSYMBOL_goto = 32,                      /* goto  */
  YYSYMBOL_if = 33,                        /* if  */
  YYSYMBOL_while = 34,                     /* while  */
  YYSYMBOL_for = 35,                       /* for  */
  YYSYMBOL_assignment = 36,                /* assignment  */
  YYSYMBOL_expression = 37,                /* expression  */
  YYSYMBOL_system_print = 38,              /* system_print  */
  YYSYMBOL_b_expression = 39               /* b_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   87

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  30
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  83

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   138,   138,   138,   147,   149,   158,   164,   165,   166,
     167,   168,   169,   172,   185,   186,   187,   190,   196,   215,
     231,   259,   287,   288,   289,   290,   310,   313,   340,   357,
     375
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "BOOL",
  "IDENTIFIER", "ARITH_OP", "RELA_OP", "BOOL_OP", "IF_WORD", "ELSE_WORD",
  "WHILE_WORD", "FOR_WORD", "INT_WORD", "FLOAT_WORD", "BOOLEAN_WORD",
  "SEMI_COLON", "EQUALS", "LEFT_BRACKET", "RIGHT_BRACKET",
  "LEFT_BRACKET_CURLY", "RIGHT_BRACKET_CURLY", "SYSTEM_OUT", "$accept",
  "method_body", "$@1", "statement_list", "marker", "statement",
  "declaration", "primitive_type", "goto", "if", "while", "for",
  "assignment", "expression", "system_print", "b_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -61,    14,     7,   -61,    19,    20,    21,   -61,   -61,   -61,
      38,   -61,    46,     6,   -61,    53,   -61,   -61,   -61,   -61,
     -61,    42,    28,    54,    42,   -61,    47,     7,    50,   -61,
     -61,   -61,    42,    48,   -61,     3,    -5,   -61,     5,    28,
     -61,   -61,    36,    42,   -61,    42,   -61,    49,    28,    51,
      29,   -61,    62,    62,    28,   -61,    45,   -61,    52,    63,
       7,   -61,   -61,   -61,    54,     7,    55,   -61,    56,    60,
      59,   -61,    61,    64,   -61,   -61,     7,     7,    58,   -61,
     -61,    65,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     6,     1,     0,     0,     0,    14,    15,    16,
       0,     6,     0,     6,     7,     0,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     3,     0,     6,     0,    23,
      22,    25,     0,     0,    28,     0,     0,     6,     0,     0,
       5,    13,     0,     0,    21,     0,     6,     0,     0,     0,
       0,    26,    24,    30,     0,     6,     0,    27,     0,    29,
       6,     6,     6,    17,     0,     6,     0,    17,     0,     0,
       0,    19,     0,     0,     6,     6,     6,     6,     0,    17,
      18,     0,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -24,   -11,   -61,   -61,   -61,   -60,   -61,
     -61,   -61,   -22,   -16,   -61,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    11,    12,    13,    14,    15,    66,    16,
      17,    18,    19,    35,    20,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    37,    27,    40,    46,    33,    -4,    70,    38,    50,
      43,    45,    43,     4,     3,    47,    42,     5,    56,    81,
       6,     7,     8,     9,    59,    49,    48,    52,    -4,    53,
      10,    29,    30,    34,    31,    54,    63,    21,    46,    22,
      23,    68,    67,    43,    60,    29,    30,    32,    31,    58,
      64,    65,    78,    79,    46,    43,    51,    24,    26,    28,
       4,    32,    61,    76,    77,    44,    39,    41,    57,    43,
      55,    72,    46,    62,     0,     0,     0,    69,    71,    73,
      80,     0,    74,     0,     0,    75,     0,    82
};

static const yytype_int8 yycheck[] =
{
      11,    23,    13,    27,     9,    21,     0,    67,    24,    39,
       7,     8,     7,     6,     0,    20,    32,    10,    48,    79,
      13,    14,    15,    16,    54,    20,    37,    43,    22,    45,
      23,     3,     4,     5,     6,    46,    60,    18,     9,    19,
      19,    65,    64,     7,    55,     3,     4,    19,     6,    20,
      61,    62,    76,    77,     9,     7,    20,    19,    12,     6,
       6,    19,    17,    74,    75,    17,    19,    17,    17,     7,
      21,    11,     9,    21,    -1,    -1,    -1,    22,    22,    20,
      22,    -1,    21,    -1,    -1,    21,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    26,     0,     6,    10,    13,    14,    15,    16,
      23,    27,    28,    29,    30,    31,    33,    34,    35,    36,
      38,    18,    19,    19,    19,    28,    12,    28,     6,     3,
       4,     6,    19,    37,     5,    37,    39,    36,    37,    19,
      27,    17,    37,     7,    17,     8,     9,    20,    28,    20,
      39,    20,    37,    37,    28,    21,    39,    17,    20,    39,
      28,    17,    21,    27,    28,    28,    32,    36,    27,    22,
      32,    22,    11,    20,    21,    21,    28,    28,    27,    27,
      22,    32,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    24,    26,    25,    27,    27,    28,    29,    29,    29,
      29,    29,    29,    30,    31,    31,    31,    32,    33,    34,
      35,    36,    37,    37,    37,    37,    37,    38,    39,    39,
      39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     0,    14,     9,
      15,     4,     1,     1,     3,     1,     3,     5,     1,     4,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 138 "syntax.y"
        {	generateHeader();	}
#line 1328 "y.tab.c"
    break;

  case 3: /* method_body: $@1 statement_list marker  */
#line 141 "syntax.y"
        {
		backpatch((yyvsp[-1].stmt_type).nextList,(yyvsp[0].ival));
		generateFooter();
	}
#line 1337 "y.tab.c"
    break;

  case 5: /* statement_list: statement marker statement_list  */
#line 152 "syntax.y"
        {
		backpatch((yyvsp[-2].stmt_type).nextList,(yyvsp[-1].ival));
		(yyval.stmt_type).nextList = (yyvsp[0].stmt_type).nextList;
	}
#line 1346 "y.tab.c"
    break;

  case 6: /* marker: %empty  */
#line 158 "syntax.y"
{
	(yyval.ival) = labelsCount;
	writeCode(genLabel() + ":");
}
#line 1355 "y.tab.c"
    break;

  case 7: /* statement: declaration  */
#line 164 "syntax.y"
                    {vector<int> * v = new vector<int>(); (yyval.stmt_type).nextList =v;}
#line 1361 "y.tab.c"
    break;

  case 8: /* statement: if  */
#line 165 "syntax.y"
            {(yyval.stmt_type).nextList = (yyvsp[0].stmt_type).nextList;}
#line 1367 "y.tab.c"
    break;

  case 9: /* statement: while  */
#line 166 "syntax.y"
                {(yyval.stmt_type).nextList = (yyvsp[0].stmt_type).nextList;}
#line 1373 "y.tab.c"
    break;

  case 10: /* statement: for  */
#line 167 "syntax.y"
             {(yyval.stmt_type).nextList = (yyvsp[0].stmt_type).nextList;}
#line 1379 "y.tab.c"
    break;

  case 11: /* statement: assignment  */
#line 168 "syntax.y"
                     {vector<int> * v = new vector<int>(); (yyval.stmt_type).nextList =v;}
#line 1385 "y.tab.c"
    break;

  case 12: /* statement: system_print  */
#line 169 "syntax.y"
                       {vector<int> * v = new vector<int>(); (yyval.stmt_type).nextList =v;}
#line 1391 "y.tab.c"
    break;

  case 13: /* declaration: primitive_type IDENTIFIER SEMI_COLON  */
#line 173 "syntax.y"
        {
		string str((yyvsp[-1].idval));
		if((yyvsp[-2].sType) == INT_T)
		{
			defineVar(str,INT_T);
		}else if ((yyvsp[-2].sType) == FLOAT_T)
		{
			defineVar(str,FLOAT_T);
		}
	}
#line 1406 "y.tab.c"
    break;

  case 14: /* primitive_type: INT_WORD  */
#line 185 "syntax.y"
                 {(yyval.sType) = INT_T;}
#line 1412 "y.tab.c"
    break;

  case 15: /* primitive_type: FLOAT_WORD  */
#line 186 "syntax.y"
                     {(yyval.sType) = FLOAT_T;}
#line 1418 "y.tab.c"
    break;

  case 16: /* primitive_type: BOOLEAN_WORD  */
#line 187 "syntax.y"
                      {(yyval.sType) = BOOL_T;}
#line 1424 "y.tab.c"
    break;

  case 17: /* goto: %empty  */
#line 190 "syntax.y"
{
	(yyval.ival) = codeList.size();
	writeCode("goto ");
}
#line 1433 "y.tab.c"
    break;

  case 18: /* if: IF_WORD LEFT_BRACKET b_expression RIGHT_BRACKET LEFT_BRACKET_CURLY marker statement_list goto RIGHT_BRACKET_CURLY ELSE_WORD LEFT_BRACKET_CURLY marker statement_list RIGHT_BRACKET_CURLY  */
#line 207 "syntax.y"
        {
		backpatch((yyvsp[-11].bexpr_type).trueList,(yyvsp[-8].ival));
		backpatch((yyvsp[-11].bexpr_type).falseList,(yyvsp[-2].ival));
		(yyval.stmt_type).nextList = merge((yyvsp[-7].stmt_type).nextList, (yyvsp[-1].stmt_type).nextList);
		(yyval.stmt_type).nextList->push_back((yyvsp[-6].ival));
	}
#line 1444 "y.tab.c"
    break;

  case 19: /* while: marker WHILE_WORD LEFT_BRACKET b_expression RIGHT_BRACKET LEFT_BRACKET_CURLY marker statement_list RIGHT_BRACKET_CURLY  */
#line 222 "syntax.y"
        {
		writeCode("goto " + getLabel((yyvsp[-8].ival)));
		
		backpatch((yyvsp[-1].stmt_type).nextList,(yyvsp[-8].ival));
		backpatch((yyvsp[-5].bexpr_type).trueList,(yyvsp[-2].ival));
		(yyval.stmt_type).nextList = (yyvsp[-5].bexpr_type).falseList;
	}
#line 1456 "y.tab.c"
    break;

  case 20: /* for: FOR_WORD LEFT_BRACKET assignment marker b_expression SEMI_COLON marker assignment goto RIGHT_BRACKET LEFT_BRACKET_CURLY marker statement_list goto RIGHT_BRACKET_CURLY  */
#line 246 "syntax.y"
        {
		backpatch((yyvsp[-10].bexpr_type).trueList,(yyvsp[-3].ival));
		vector<int> * v = new vector<int> ();
		v->push_back((yyvsp[-6].ival));
		backpatch(v,(yyvsp[-11].ival));
		v = new vector<int>();
		v->push_back((yyvsp[-1].ival));
		backpatch(v,(yyvsp[-8].ival));
		backpatch((yyvsp[-2].stmt_type).nextList,(yyvsp[-8].ival));
		(yyval.stmt_type).nextList = (yyvsp[-10].bexpr_type).falseList;
	}
#line 1472 "y.tab.c"
    break;

  case 21: /* assignment: IDENTIFIER EQUALS expression SEMI_COLON  */
#line 260 "syntax.y"
        {
		string str((yyvsp[-3].idval));
		/* after expression finishes, its result should be on top of stack. 
		we just store the top of stack to the identifier*/
		if(checkId(str))
		{
			if((yyvsp[-1].expr_type).sType == symbTab[str].second)
			{
				if((yyvsp[-1].expr_type).sType == INT_T)
				{
					writeCode("istore " + to_string(symbTab[str].first));
				}else if ((yyvsp[-1].expr_type).sType == FLOAT_T)
				{
					writeCode("fstore " + to_string(symbTab[str].first));
				}
			}
			else
			{
				cast(str,(yyvsp[-1].expr_type).sType);	/* do casting */
			}
		}else{
			string err = "identifier: "+str+" isn't declared in this scope";
			yyerror(err.c_str());
		}
	}
#line 1502 "y.tab.c"
    break;

  case 22: /* expression: FLOAT  */
#line 287 "syntax.y"
                {(yyval.expr_type).sType = FLOAT_T; writeCode("ldc "+to_string((yyvsp[0].fval)));}
#line 1508 "y.tab.c"
    break;

  case 23: /* expression: INT  */
#line 288 "syntax.y"
                {(yyval.expr_type).sType = INT_T;  writeCode("ldc "+to_string((yyvsp[0].ival)));}
#line 1514 "y.tab.c"
    break;

  case 24: /* expression: expression ARITH_OP expression  */
#line 289 "syntax.y"
                                                {arithCast((yyvsp[-2].expr_type).sType, (yyvsp[0].expr_type).sType, string((yyvsp[-1].aopval)));}
#line 1520 "y.tab.c"
    break;

  case 25: /* expression: IDENTIFIER  */
#line 290 "syntax.y"
                     {
		string str((yyvsp[0].idval));
		if(checkId(str))
		{
			(yyval.expr_type).sType = symbTab[str].second;
			if(symbTab[str].second == INT_T)
			{
				writeCode("iload " + to_string(symbTab[str].first));
			}else if (symbTab[str].second == FLOAT_T)
			{
				writeCode("fload " + to_string(symbTab[str].first));
			}
		}
		else
		{
			string err = "identifier: "+str+" isn't declared in this scope";
			yyerror(err.c_str());
			(yyval.expr_type).sType = ERROR_T;
		}
	}
#line 1545 "y.tab.c"
    break;

  case 26: /* expression: LEFT_BRACKET expression RIGHT_BRACKET  */
#line 310 "syntax.y"
                                                {(yyval.expr_type).sType = (yyvsp[-1].expr_type).sType;}
#line 1551 "y.tab.c"
    break;

  case 27: /* system_print: SYSTEM_OUT LEFT_BRACKET expression RIGHT_BRACKET SEMI_COLON  */
#line 314 "syntax.y"
        {
		if((yyvsp[-2].expr_type).sType == INT_T)
		{
			/* expression is at top of stack now */
			/* save it at the predefined temp syso var */			
			writeCode("istore " + to_string(symbTab["1syso_int_var"].first));
			/* call syso */			
			writeCode("getstatic      java/lang/System/out Ljava/io/PrintStream;");
			/*insert param*/
			writeCode("iload " + to_string(symbTab["1syso_int_var"].first ));
			/*invoke syso*/
			writeCode("invokevirtual java/io/PrintStream/println(I)V");

		}else if ((yyvsp[-2].expr_type).sType == FLOAT_T)
		{
			writeCode("fstore " + to_string(symbTab["1syso_float_var"].first));
			/* call syso */			
			writeCode("getstatic      java/lang/System/out Ljava/io/PrintStream;");
			/*insert param*/
			writeCode("fload " + to_string(symbTab["1syso_float_var"].first ));
			/*invoke syso*/
			writeCode("invokevirtual java/io/PrintStream/println(F)V");
		}
	}
#line 1580 "y.tab.c"
    break;

  case 28: /* b_expression: BOOL  */
#line 341 "syntax.y"
        {
		if((yyvsp[0].bval))
		{
			/* bool is 'true' */
			(yyval.bexpr_type).trueList = new vector<int> ();
			(yyval.bexpr_type).trueList->push_back(codeList.size());
			(yyval.bexpr_type).falseList = new vector<int>();
			writeCode("goto ");
		}else
		{
			(yyval.bexpr_type).trueList = new vector<int> ();
			(yyval.bexpr_type).falseList= new vector<int>();
			(yyval.bexpr_type).falseList->push_back(codeList.size());
			writeCode("goto ");
		}
	}
#line 1601 "y.tab.c"
    break;

  case 29: /* b_expression: b_expression BOOL_OP marker b_expression  */
#line 361 "syntax.y"
        {
		if(!strcmp((yyvsp[-2].aopval), "&&"))
		{
			backpatch((yyvsp[-3].bexpr_type).trueList, (yyvsp[-1].ival));
			(yyval.bexpr_type).trueList = (yyvsp[0].bexpr_type).trueList;
			(yyval.bexpr_type).falseList = merge((yyvsp[-3].bexpr_type).falseList,(yyvsp[0].bexpr_type).falseList);
		}
		else if (!strcmp((yyvsp[-2].aopval),"||"))
		{
			backpatch((yyvsp[-3].bexpr_type).falseList,(yyvsp[-1].ival));
			(yyval.bexpr_type).trueList = merge((yyvsp[-3].bexpr_type).trueList, (yyvsp[0].bexpr_type).trueList);
			(yyval.bexpr_type).falseList = (yyvsp[0].bexpr_type).falseList;
		}
	}
#line 1620 "y.tab.c"
    break;

  case 30: /* b_expression: expression RELA_OP expression  */
#line 376 "syntax.y"
        {
		string op ((yyvsp[-1].aopval));
		(yyval.bexpr_type).trueList = new vector<int>();
		(yyval.bexpr_type).trueList ->push_back (codeList.size());
		(yyval.bexpr_type).falseList = new vector<int>();
		(yyval.bexpr_type).falseList->push_back(codeList.size()+1);
		writeCode(getOp(op)+ " ");
		writeCode("goto ");
	}
#line 1634 "y.tab.c"
    break;


#line 1638 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 387 "syntax.y"






/*------------------------------separator------------------------------------------------*/

main (int argv, char * argc[])
{
	FILE *myfile;
	if(argv == 1) 
	{
		myfile = fopen("input_code.txt", "r");
		outfileName = "input_code.txt";
	}
	else 
	{
		myfile = fopen(argc[1], "r");
		outfileName = string(argc[1]);
	}
	if (!myfile) {
		printf("I can't open input code file!\n");
		char cCurrentPath[200];
		 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
		     {
		     return -1;
		     }
		printf("%s\n",cCurrentPath);  
				getchar();

		return -1;

	}
	yyin = myfile;
	yyparse();
	//getchar();
	printCode();
}

void yyerror(const char * s)
{
	printf("error@%d: %s\n",lineCounter, s);
}

void generateHeader()
{
	writeCode(".source " + outfileName);
	writeCode(".class public test\n.super java/lang/Object\n"); //code for defining class
	writeCode(".method public <init>()V");
	writeCode("aload_0");
	writeCode("invokenonvirtual java/lang/Object/<init>()V");
	writeCode("return");
	writeCode(".end method\n");
	writeCode(".method public static main([Ljava/lang/String;)V");
	writeCode(".limit locals 100\n.limit stack 100");

	/* generate temporal vars for syso*/
	defineVar("1syso_int_var",INT_T);
	defineVar("1syso_float_var",FLOAT_T);

	/*generate line*/
	writeCode(".line 1");
}

void generateFooter()
{
	writeCode("return");
	writeCode(".end method");
}

void cast (string str, int t1)
{
	yyerror("casting not implemented yet :)");
}

void arithCast(int from , int to, string op)
{
	if(from == to)
	{
		if(from == INT_T)
		{
			writeCode("i" + getOp(op));
		}else if (from == FLOAT_T)
		{
			writeCode("f" + getOp(op));
		}
	}
	else
	{
		yyerror("cast not implemented yet");
	}
}


string getOp(string op)
{
	if(inst_list.find(op) != inst_list.end())
	{
		return inst_list[op];
	}
	return "";
}

bool checkId(string op)
{
	return (symbTab.find(op) != symbTab.end());
}

void defineVar(string name, int type)
{
	if(checkId(name))
	{
		string err = "variable: "+name+" declared before";
		yyerror(err.c_str());
	}else
	{
		if(type == INT_T)
		{
			writeCode("iconst_0\nistore " + to_string(varaiblesNum));
		}
		else if ( type == FLOAT_T)
		{
			writeCode("fconst_0\nfstore " + to_string(varaiblesNum));
		}
		symbTab[name] = make_pair(varaiblesNum++,(type_enum)type);
	}
}

string genLabel()
{
	return "L_"+to_string(labelsCount++);
}

string getLabel(int n)
{
	return "L_"+to_string(n);
}

vector<int> * merge(vector<int> *list1, vector<int> *list2)
{
	if(list1 && list2){
		vector<int> *list = new vector<int> (*list1);
		list->insert(list->end(), list2->begin(),list2->end());
		return list;
	}else if(list1)
	{
		return list1;
	}else if (list2)
	{
		return list2;
	}else
	{
		return new vector<int>();
	}
}
void backpatch(vector<int> *lists, int ind)
{
	if(lists)
	for(int i =0 ; i < lists->size() ; i++)
	{
		codeList[(*lists)[i]] = codeList[(*lists)[i]] + getLabel(ind);
//		printf("%s\n",codeList[(*lists)[i]].c_str());
	}
}
void writeCode(string x)
{
	codeList.push_back(x);
}

void printCode(void)
{
	for ( int i = 0 ; i < codeList.size() ; i++)
	{
		fout<<codeList[i]<<endl;
	}
}
/*
char *strdup (const char *s) {
    char *d = (char *) malloc (strlen (s) + 1);   // Space for length plus nul
    if (d == NULL) return NULL;          // No memory
    strcpy (d,s);                        // Copy the characters
    return d;                            // Return the new string
}
*/
