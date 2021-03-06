
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
     TRUE_TOKEN = 259,
     FALSE_TOKEN = 260,
     LETTER_TOKEN = 261,
     ADD_TOKEN = 262,
     SUB_TOKEN = 263,
     OR_TOKEN = 264,
     MULT_TOKEN = 265,
     DIVIDE_TOKEN = 266,
     AND_TOKEN = 267,
     SMALLER_TOKEN = 268,
     BIGGER_TOKEN = 269,
     SMALLER_EQUAL_TOKEN = 270,
     BIGGER_EQUAL_TOKEN = 271,
     EQUAL_TOKEN = 272,
     DIFF_TOKEN = 273,
     OUTROS_TOKEN = 274,
     DOT_TOKEN = 275,
     INTEGER_TOKEN = 276,
     REAL_TOKEN = 277,
     BOOLEAN_TOKEN = 278,
     VAZIO_TOKEN = 279,
     INT_TOKEN = 280,
     IF_TOKEN = 281,
     ELSE_TOKEN = 282,
     THEN_TOKEN = 283,
     BEGIN_TOKEN = 284,
     END_TOKEN = 285,
     FUNCTION_TOKEN = 286,
     DOTCOMMA_TOKEN = 287,
     TWODOTS_TOKEN = 288,
     WHILE_TOKEN = 289,
     DO_TOKEN = 290,
     COMMA_TOKEN = 291,
     ARRAY_TOKEN = 292,
     BLEFT_TOKEN = 293,
     BRIGHT_TOKEN = 294,
     VAR_TOKEN = 295,
     PROCEDURE_TOKEN = 296,
     OF_TOKEN = 297,
     PLEFT_TOKEN = 298,
     PRIGHT_TOKEN = 299,
     TWODOTS_EQUAL_TOKEN = 300,
     TO_TOKEN = 301,
     FOR_TOKEN = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


