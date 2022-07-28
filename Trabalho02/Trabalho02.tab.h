
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

/* Line 1676 of yacc.c  */
#line 12 "Trabalho02.y"

	int ival;
	float fval;
	char cval;
	char *sval;
	book *bookval;



/* Line 1676 of yacc.c  */
#line 114 "Trabalho02.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


