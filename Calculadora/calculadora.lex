/* Linguagem: Pascal-like */
/* Abaixo, indicado pelos limitadores "%{" e "%}", as includes necessárias... */
%option noyywrap 
/* Para não ter que declarar a variável yywrap */
%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "calculadora.tab.h"
#define yyterminate() return END;
#define YY_DECL int yylex()

void tableMain();

int num_lines = 0;
int num_columns = 0;
int num_tokens = 0;

// Para rodar no windows: gcc lex.yy.c -L"C:\GnuWin32\lib" -lfl -o nomeDoArquivo

%}

DIGITO  ([0-9])
TRUE "true"
FALSE "false"

%%

{DIGITO}+ { num_tokens++; num_columns += strlen(yytext); return T_NUMBER; }

{DIGITO}+"."{DIGITO}+ { num_tokens++; num_columns += strlen(yytext); return T_NUMBER; }

{TRUE} { num_tokens++; num_columns += strlen(yytext); return T_TRUE; }

{FALSE} { num_tokens++; num_columns += strlen(yytext); return T_FALSE; }

[ \t]+  { num_columns++; }	

\n { ++num_lines; num_columns = 0; }

. {}
%%
