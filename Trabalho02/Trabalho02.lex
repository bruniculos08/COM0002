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
BOOL-LIT "true"|"false"
OP-AD "+"|"-"|"or"
OP-MUL  "*"|"/"|"and"
OP-REL "<"|">"|"<="|">="|"="|"<>"
OUTROS "!"|"@"|"#"|"$"|"%"|"¨"|"&"|"?"|"."|"'"|"{"|"}"
TIPO "integer"|"real"|"boolean"
VAZIO ""
LETRA[a-z]
KEY-WORD "if"|"else"|"then"|"begin"|"end"|"function"|";"|":"|"while"|"do"|","|"array"|"["|"]"|"var"|"procedure"|"of"|"("|")"|":="
%%

{OP-AD} {
			//printf("Um operador de adição: %s", yytext);
			addToken(yytext);
			setType("opAd");
			if(yytext == "+") return ADDTOKEN;
			else if(yytext == "-") return LESSTOKEN;
			else return ORTOKEN;
		}

{OP-MUL} 	{
				//printf("Um operador de multiplicação: %s", yytext);
				addToken(yytext);
				setType("opMul");
			}

{OP-REL} 	{
				//printf("Um operador de relação: %s", yytext);
				addToken(yytext);
				setType("opRel");
			}

{OUTROS} 	{
				//printf("Um caracter especial: %s", yytext);
				addToken(yytext);
				setType("outro");
			}

{TIPO} 	{	
			//printf("Um tipo: %s", yytext);
			addToken(yytext);
			setType("tipo");
		}

{VAZIO} 	{	
				//printf("Um epsilon (vazio): %s", yytext);
				//addToken(yytext);
				//setType("vazio");
			}

{DIGITO}+  {
            	//printf("Um valor inteiro: %s (%d)", yytext, atoi( yytext )); 
				addToken(yytext);
				setType("intlit");
            }

({DIGITO}+"."{DIGITO}*)|({DIGITO}*"."{DIGITO}+)      {
            					//printf("Um valor real: %s (%g)", yytext, atof( yytext ));
								addToken(yytext);
								setType("floatlit");
            				}

{KEY-WORD}  {
         		//printf("Uma palavra-chave: %s", yytext);
				addToken(yytext);
				setType("keyWord");
            }

{LETRA}+({DIGITO}|{LETRA})* {
								//printf("Um possível id: %s", yytext);
								addToken(yytext);
								setType("ID");
							}

[ \t]+  {
			num_columns++;
		}	/* Lembre-se... espaços em branco não tem utilidade! */

\n      {
			++num_lines; num_columns = 0;
		}

.           {
				//printf("Caracter nao reconhecido ou id: %s", yytext );
				addToken(yytext);
				setType("naoRec");
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
    
	FILE *filePointer;
    filePointer = fopen("resultado.txt", "w+");
    fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|                               Tabela de simbolos                              |\n");
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|\tToken\t|\tTipo\t\t|\tTamanho\t|\tLinha\t|\tColuna\t\t|\n");

	printf("---------------------------------------------------------------------------------\n");
	printf("|                               Tabela de simbolos                              |\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("|\tToken\t|\tTipo\t|\tTamanho\t|\tLinha\t|\tColuna\t|\n");
	for(int i = 0; i < numberOfTokens; i++){
		printf("|\t%s\t\t|\t%s\t\t|\t\t%i\t|\t%i\t|\t%i\t|\n", aux->token, aux->type, aux->lenght, aux->line, aux->column);
		fprintf(filePointer, "|\t%s\t|\t%s\t\t|\t%i\t|\t%i\t|\t%i\t\t|\n", aux->token, aux->type, aux->lenght, aux->line, aux->column);
		aux = aux->next;
	}
	printf("---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");


	printf("# total de linhas = %d\n", num_lines);
    
	return 0;
}
