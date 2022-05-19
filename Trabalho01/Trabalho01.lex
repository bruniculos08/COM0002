/* Linguagem: Pascal-like */
/* Abaixo, indicado pelos limitadores "%{" e "%}", as includes necessárias... */

%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


char *actualType = NULL;
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
	printf("\n");
}

void setTypeID(char *string, int flag){
	if(flag == 0){
		if(actualType != NULL){ 
			fila->last->type = (char *)malloc(sizeof(char)*strlen("(erro)"));
			strcpy(fila->last->type, "(erro)");
			free(actualType);
			actualType = (char *)malloc(sizeof(char)*strlen(string));
			strcpy(actualType, "(erro)");
			
		}
		else{
		free(actualType);
		actualType = (char *)malloc(sizeof(char)*strlen(string));
		strcpy(actualType, string);
		fila->last->type = (char *)malloc(sizeof(char)*strlen(string));
		strcpy(fila->last->type, string);
		}
	}
	else{
		if(actualType == NULL){
			actualType = (char *)malloc(sizeof(char)*strlen("(erro)"));
			strcpy(actualType, "(erro)");
		}
		fila->last->type = (char *)malloc(sizeof(char)*strlen(actualType));
		strcpy(fila->last->type, actualType);
		actualType = NULL;
	}
}

void setType(char *string){
	fila->last->type = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->type, string);
	actualType = NULL;
}

%}
/*Definições*/

DIGITO  ([0-9])
BOOL-LIT "true"|"false"
OP-AD "+"|"-"|"or"
OP-MUL  "*"|"/"|"and"
OP-REL "<"|">"|"<="|">="|"="|"<>"
OUTROS "!"|"@"|"#"|"$"|"%"|"¨"|"&"
TIPO "integer"|"real"|"boolean"
VAZIO "ε"
LETRA[a-z]
KEY-WORD "if"|"else"|"then"|"begin"|"end"|"function"|";"|":"|"while"|"do"|","|"array"|"["|"]"|"var"|"procedure"|"of"|"("|")"|":="
%%

{OP-AD} {
			printf("Um operador de adição: %s", yytext);
			addToken(yytext);
			setType("operador");
		}

{OP-MUL} 	{
				printf("Um operador de multiplicação: %s", yytext);
				addToken(yytext);
				setType("operador");
			}

{OP-REL} 	{
				printf("Um operador de relação: %s", yytext);
				addToken(yytext);
				setType("operador");
			}

{OUTROS} 	{
				printf("Um caracter especial: %s", yytext);
				addToken(yytext);
				setType("outro");
			}

{TIPO} 	{	
			printf("Um tipo: %s", yytext);
			addToken(yytext);
			setTypeID(yytext, 0);
		}

{VAZIO} 	{	
				printf("Um epsilon (vazio): %s", yytext);
				addToken(yytext);
				setType("operador");
			}

{DIGITO}+  {
            	printf( "Um valor inteiro: %s (%d)", yytext, atoi( yytext )); 
				addToken(yytext);
				setType("inteiro");
            }

{DIGITO}+"."{DIGITO}*      {
            					printf( "Um valor real: %s (%g)", yytext, atof( yytext ) );
								addToken(yytext);
								setType("real");
            				}

{KEY-WORD}  {
         		printf( "Uma palavra-chave: %s", yytext );
				addToken(yytext);
				setType("keyWord");
            }

{LETRA}+({DIGITO}|{LETRA})* {
								printf("Um possível id: %s", yytext);
								addToken(yytext);
								setTypeID(yytext, 1);
							}

"{"[^}\n]*"}"     /* Lembre-se... comentários não tem utilidade! */

[ \t]+  {
			num_columns++;
		}	/* Lembre-se... espaços em branco não tem utilidade! */

\n      {
			++num_lines; num_columns = 0;
		}

.           {
				printf( "Caracter nao reconhecido ou id: %s", yytext );
				addToken(yytext);
				setType("NaoReconhecido");
		    }

%%

int main( argc, argv )
int argc;
char **argv;
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
	printf("---------------------------------------------------------------------------------\n");
	printf("|                               Tabela de simbolos                              |\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("|\tToken\t|\tTipo\t|\tTamanho\t|\tLinha\t|\tColuna\t|\n");
	for(int i = 0; i < numberOfTokens; i++){
		printf("|\t%s\t|\t%s\t|\t%i\t|\t%i\t|\t%i\t|\n", aux->token, aux->type, aux->lenght, aux->line, aux->column);
		aux = aux->next;
	}
	printf("---------------------------------------------------------------------------------\n");

	printf("# total de linhas = %d\n", num_lines);
    
	return 0;
}
