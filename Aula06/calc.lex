%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "calc.tab.h"
// fazer converção de notação normal para polonesa
%}

DIGITO		[0-9]+

%%

[ \t]	; // ignore todos os espaços em branco
{DIGITO}+\.{DIGITO}+ 		{yylval.fval = atof(yytext); return T_REAL;}
{DIGITO}+					{yylval.ival = atoi(yytext); return T_INT;}
\n							{return T_NEWLINE;}
"+"							{return T_PLUS;}
"-"							{return T_MINUS;}
"*"							{return T_MULTIPLY;}
"/"							{return T_DIVIDE;}
"("							{return T_LEFT;}
")"							{return T_RIGHT;}
"fora"						{return T_QUIT;}
"sair"						{return T_QUIT;}
.							{printf("Caracter misterioso... %s\n", yytext);}

%%