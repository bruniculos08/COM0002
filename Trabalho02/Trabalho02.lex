/* Linguagem: Pascal-like */
/* Abaixo, indicado pelos limitadores "%{" e "%}", as includes necessárias... */
%option noyywrap 
/* Para não ter que declarar a variável yywrap */
%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Compiler.h"
#include "Trabalho02.tab.h"
#define yyterminate() return END;

extern int num_columns;
extern int num_lines;

%}

DIGITO  ([0-9])
BOOL_IT "true"|"false"
OP_AD "+"|"-"|"or"
OP_MUL  "*"|"/"|"and"
OP_REL "<"|">"|"<="|">="|"="|"<>"
OUTROS "!"|"@"|"#"|"$"|"%"|"¨"|"&"|"?"|"."|"'"|"{"|"}"
TIPO "integer"|"real"|"boolean"
VAZIO ""
LETRA[a-zA-Z]
KEY_WORD "if"|"else"|"then"|"begin"|"end"|"function"|";"|":"|"while"|"do"|","|"array"|"["|"]"|"var"|"procedure"|"of"|"("|")"|":="|"to"|"for"
%%

"program" {	
			addToken(yytext);
			setAbout("keyWord");
			return PROGRAM_TOKEN;
		  }

{BOOL_IT} {
			addToken(yytext);
			setAbout("boolit");
			if(strcmp(yytext, "true") == 0) return TRUE_TOKEN;
			else return FALSE_TOKEN;
		  }

{OP_AD} {
			yylval.cval = yytext[0];
			addToken(yytext);
			setAbout("opAd");
			if(strcmp(yytext, "+") == 0) return ADD_TOKEN;
			else if(strcmp(yytext, "-") == 0) return SUB_TOKEN;
			else return OR_TOKEN;
		}

{OP_MUL} 	{
				yylval.cval = yytext[0];
				addToken(yytext);
				setAbout("opMul");
				if(strcmp(yytext, "*") == 0) return MULT_TOKEN;
				else if(strcmp(yytext, "/") == 0) return DIVIDE_TOKEN;
				else return AND_TOKEN;
			}

{OP_REL} 	{
				yylval.sval = yytext;
				addToken(yytext);
				setAbout("opRel");
				if(strcmp(yytext, "<") == 0) return SMALLER_TOKEN;
				else if(strcmp(yytext, ">") == 0) return BIGGER_TOKEN;
				else if(strcmp(yytext, "<=") == 0) return SMALLER_EQUAL_TOKEN;
				else if(strcmp(yytext, ">=") == 0) return BIGGER_EQUAL_TOKEN;
				else if(strcmp(yytext, "=") == 0) return EQUAL_TOKEN;
				else return DIFF_TOKEN;
			}

{OUTROS} 	{
				addToken(yytext);
				setAbout("outro");
				if(strcmp(yytext, ".") == 0) return DOT_TOKEN;
				return OUTROS_TOKEN;
			}

{TIPO} 	{	
			yylval.sval = yytext;
			addToken(yytext);
			setAbout("tipo");
			if(strcmp(yytext, "integer") == 0) return INTEGER_TOKEN;
			else if(strcmp(yytext, "real") == 0) return REAL_TOKEN;
			else return BOOLEAN_TOKEN;
		}

{VAZIO} 	{	
				addToken(yytext);
				setAbout("empty");
				return VAZIO_TOKEN;
			}

{DIGITO}+  {
				yylval.ival = atoi(yytext);
				addToken(yytext);
				setAbout("int");
            	return INT_TOKEN;
           }

({DIGITO}+"."{DIGITO}*)|({DIGITO}*"."{DIGITO}+)   {
				yylval.fval = atof(yytext);
				addToken(yytext);
				setAbout("float");
            	return FLOAT_TOKEN;
           }

{KEY_WORD}  {	
				addToken(yytext);
				setAbout("keyWord");
				if(strcmp(yytext, "if") == 0) return IF_TOKEN;
				else if(strcmp(yytext, "else") == 0) return ELSE_TOKEN;
				else if(strcmp(yytext, "then") == 0) return THEN_TOKEN;
				else if(strcmp(yytext, "begin") == 0) return BEGIN_TOKEN;
				else if(strcmp(yytext, "end") == 0) return END_TOKEN;
				else if(strcmp(yytext, "function") == 0) return FUNCTION_TOKEN;
				else if(strcmp(yytext, ";") == 0) return DOTCOMMA_TOKEN;
				else if(strcmp(yytext, ":") == 0) return TWODOTS_TOKEN;
				else if(strcmp(yytext, "while") == 0) return WHILE_TOKEN;
				else if(strcmp(yytext, "do") == 0) return DO_TOKEN;
				else if(strcmp(yytext, ",") == 0) return COMMA_TOKEN;
				else if(strcmp(yytext, "array") == 0) return ARRAY_TOKEN;
				else if(strcmp(yytext, "[") == 0) return BLEFT_TOKEN;
				else if(strcmp(yytext, "]") == 0) return BRIGHT_TOKEN;
				else if(strcmp(yytext, "var") == 0) return VAR_TOKEN;
				else if(strcmp(yytext, "procedure") == 0) return PROCEDURE_TOKEN;
				else if(strcmp(yytext, "of") == 0) return OF_TOKEN;
				else if(strcmp(yytext, "(") == 0) return PLEFT_TOKEN;
				else if(strcmp(yytext, ")") == 0) return PRIGHT_TOKEN;
				else if(strcmp(yytext, "to") == 0) return TO_TOKEN;
				else if(strcmp(yytext, "for") == 0) return FOR_TOKEN;
				else return TWODOTS_EQUAL_TOKEN;
            }

{LETRA}+({DIGITO}|{LETRA})* {
			yylval.sval = yytext;
			addToken(yytext);
			setAbout("id");
			return ID_TOKEN;
		}

[ \t]+  {
			num_columns++;
		}	

\n      {
			++num_lines; num_columns = 0;
		}

.           {

		    }
%%