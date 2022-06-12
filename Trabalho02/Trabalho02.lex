/* Linguagem: Pascal-like */
/* Abaixo, indicado pelos limitadores "%{" e "%}", as includes necessárias... */
%option noyywrap 
/* Para não ter que declarar a variável yywrap */
%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Trabalho02.tab.h"

int num_lines = 0;
int num_columns = 0;

typedef struct Table table;
struct Table {
    char *token;
	char *type;
    int lenght;
    int line;
    int column;
	table *next;
};

typedef struct HeadTable headTable;
struct HeadTable {
	table *first;
	table *last;
};


headTable *fila = NULL;
int numberOfTokens = 0;

// Para rodar no windows: gcc lex.yy.c -L"C:\GnuWin32\lib" -lfl -o nomeDoArquivo

void addToken(char *string){
    numberOfTokens++;
    if(fila == NULL){
		fila = (headTable *)malloc(sizeof(headTable));
		fila->first = (table *)malloc(sizeof(table));
		fila->first->token = (char *)malloc(sizeof(char)*strlen(string));
		strcpy(fila->first->token, string);
		fila->first->lenght = strlen(string);
		fila->first->line = num_lines;
		fila->first->column = num_columns;
		fila->first->next = NULL;
		fila->last = fila->first;
	}
	else{
		table *newToken;
		newToken = (table *)malloc(sizeof(table));
		newToken->token = (char *)malloc(sizeof(char)*strlen(string));
		strcpy(newToken->token, string);
    	newToken->lenght = strlen(string);
		newToken->line = num_lines;
		newToken->column = num_columns;
		newToken->type = NULL; 
		newToken->next = NULL;
		fila->last->next = newToken;
		fila->last = newToken;
	}
	num_columns += strlen(string);
	//printf("\n");
}

void setType(char *string){
	fila->last->type = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->type, string);
}

%}
/*Definições*/

DIGITO  ([0-9])
BOOL_IT "true"|"false"
OP_AD "+"|"-"|"or"
OP_MUL  "*"|"/"|"and"
OP_REL "<"|">"|"<="|">="|"="|"<>"
OUTROS "!"|"@"|"#"|"$"|"%"|"¨"|"&"|"?"|"."|"'"|"{"|"}"
TIPO "integer"|"real"|"boolean"
VAZIO ""
LETRA[a-z]
KEY_WORD "if"|"else"|"then"|"begin"|"end"|"function"|";"|":"|"while"|"do"|","|"array"|"["|"]"|"var"|"procedure"|"of"|"("|")"|":="
%%

"program" {	
			addToken(yytext);
			setType("keyWord");
			return PROGRAM_TOKEN;
		  }

{BOOL_IT} {
			addToken(yytext);
			setType("boolit");
			if(strcmp(yytext, "true") == 0) return TRUE_TOKEN;
			else return FALSE_TOKEN;
		  }

{LETRA} {
			addToken(yytext);
			setType("letter");
			return LETTER_TOKEN;
		}

{OP_AD} {
			addToken(yytext);
			setType("opAd");
			if(strcmp(yytext, "+") == 0) return ADD_TOKEN;
			else if(strcmp(yytext, "-") == 0) return SUB_TOKEN;
			else return OR_TOKEN;
		}

{OP_MUL} 	{
				addToken(yytext);
				setType("opMul");
				if(strcmp(yytext, "*") == 0) return MULT_TOKEN;
				else if(strcmp(yytext, "/") == 0) return DIVIDE_TOKEN;
				else return AND_TOKEN;
			}

{OP_REL} 	{
				addToken(yytext);
				setType("opRel");
				if(strcmp(yytext, "<") == 0) return SMALLER_TOKEN;
				else if(strcmp(yytext, ">") == 0) return BIGGER_TOKEN;
				else if(strcmp(yytext, "<=") == 0) return SMALLER_EQUAL_TOKEN;
				else if(strcmp(yytext, ">=") == 0) return BIGGER_EQUAL_TOKEN;
				else if(strcmp(yytext, "=") == 0) return EQUAL_TOKEN;
				else return DIFF_TOKEN;
			}

{OUTROS} 	{
				addToken(yytext);
				setType("outro");
				if(strcmp(yytext, ".") == 0) return DOT_TOKEN;
				return OUTROS_TOKEN;
			}

{TIPO} 	{	
			addToken(yytext);
			setType("tipo");
			if(strcmp(yytext, "integer") == 0) return INT_TOKEN;
			else if(strcmp(yytext, "real") == 0) return REAL_TOKEN;
			else return BOOLEAN_TOKEN;
		}

{VAZIO} 	{	
				addToken(yytext);
				setType("empty");
				return VAZIO_TOKEN;
			}

{DIGITO}  {
				addToken(yytext);
				setType("intlit");
            	return INT_TOKEN;
           }

{KEY_WORD}  {	
				addToken(yytext);
				setType("keyWord");
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
				else return TWODOTS_EQUAL_TOKEN;
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


int argc;
char **argv;
void tableMain()
{
	++argv, --argc;
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;

	yylex();

	// Imprimir tabela aqui
	table *aux;
	aux = (table *)malloc(sizeof(table));
	aux = fila->first;
    
	FILE *filePointer;
    filePointer = fopen("resultado.txt", "w+");
    fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|                               Tabela de simbolos                              |\n");
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|\tToken\t|\tTipo\t\t|\tTamanho\t|\tLinha\t|\tColuna\t\t|\n");
	for(int i = 0; i < numberOfTokens; i++){
		fprintf(filePointer, "|\t%s\t|\t%s\t\t|\t%i\t|\t%i\t|\t%i\t\t|\n", aux->token, aux->type, aux->lenght, aux->line, aux->column);
		aux = aux->next;
	}
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	return;
}
