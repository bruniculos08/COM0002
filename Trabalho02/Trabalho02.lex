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
#define yyterminate() return END;

void tableMain();

int num_lines = 0;
int num_columns = 0;

typedef struct Table table;
struct Table {
    char *token;
	char *about;
	char *type;
    int lenght;
    int line;
    int column;
	int stackLocation;
	//table *before;
	table *next;
};

typedef struct HeadTable headTable;
struct HeadTable {
	table *first;
	table *last;
};

headTable *fila = NULL;
int numberOfTokens = 0;

void setLocation(char *string, int stackLocation){
	table *auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token,string) == 0) auxTable->stackLocation = stackLocation;
	}
}

int getLocation(char *string){
	table *auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token,string) == 0) return auxTable->stackLocation;
	}
	return -1;
}

char *getLastID(){

}


// Para rodar no windows: gcc lex.yy.c -L"C:\GnuWin32\lib" -lfl -o nomeDoArquivo

table *createTable(char *string){
	numberOfTokens++;
	table *newToken;
	newToken = (table *)malloc(sizeof(table));
	newToken->token = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(newToken->token, string);
	newToken->lenght = strlen(string);
	newToken->line = num_lines;
	newToken->column = num_columns;
	newToken->stackLocation = -1;
	newToken->about = NULL;
	newToken->type = NULL;
	//newToken->before = NULL; 
	newToken->next = NULL;
}

headTable *createHeadTable(char *string){
	fila = (headTable *)malloc(sizeof(headTable));
	fila->first = createTable(string);
	fila->last = fila->first;
}

void addToken(char *string){
    if(fila == NULL) fila = createHeadTable(string);
	else{
		table *newToken;
		newToken = createTable(string);
		fila->last->next = newToken;
		//newToken->before = fila->last;
		fila->last = newToken;
	}
	num_columns += strlen(string);
}

void setAbout(char *string){
	fila->last->about = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->about, string);
}

void setType(char *string){
	fila->last->type = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->type, string);
}

void findIDStackLocation(char *string){

}

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
			addToken(yytext);
			setAbout("opAd");
			if(strcmp(yytext, "+") == 0) return ADD_TOKEN;
			else if(strcmp(yytext, "-") == 0) return SUB_TOKEN;
			else return OR_TOKEN;
		}

{OP_MUL} 	{
				addToken(yytext);
				setAbout("opMul");
				if(strcmp(yytext, "*") == 0) return MULT_TOKEN;
				else if(strcmp(yytext, "/") == 0) return DIVIDE_TOKEN;
				else return AND_TOKEN;
			}

{OP_REL} 	{
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
			addToken(yytext);
			setAbout("tipo");
			if(strcmp(yytext, "integer") == 0) return INT_TOKEN;
			else if(strcmp(yytext, "real") == 0) return REAL_TOKEN;
			else return BOOLEAN_TOKEN;
		}

{VAZIO} 	{	
				addToken(yytext);
				setAbout("empty");
				return VAZIO_TOKEN;
			}

{DIGITO}+  {
				addToken(yytext);
				setAbout("int");
            	return INT_TOKEN;
           }

({DIGITO}+"."{DIGITO}*)|({DIGITO}*"."{DIGITO}+)   {
				addToken(yytext);
				setAbout("float");
            	return INT_TOKEN;
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
			addToken(yytext);
			setAbout("ID");
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

void tableMain(){
	table *aux;
	aux = (table *)malloc(sizeof(table));
	aux = fila->first;

	FILE *filePointer;
    filePointer = fopen("resultado.txt", "w+");
    fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|                               Tabela de simbolos                              |\n");
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|\tToken\t|\tSobre\t\t|\tTamanho\t|\tLinha\t|\tColuna\t\t|\n");
	for(int i = 0; i < numberOfTokens; i++){
		fprintf(filePointer, "|\t%s\t|\t%s\t\t|\t%i\t|\t%i\t|\t%i\t\t|\n", aux->token, aux->about, aux->lenght, aux->line, aux->column);
		aux = aux->next;
	}
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	printf("# total de linhas = %d\n", num_lines+1);
}