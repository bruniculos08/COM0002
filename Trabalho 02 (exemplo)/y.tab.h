/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 54 "y.tab.h"

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

#line 138 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
