/* Linguagem: Pascal-like */

/* ========================================================================== */
/* Abaixo, indicado pelos limitadores "%{" e "%}", as includes necessárias... */
/* ========================================================================== */

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
	char *escope;
    int token_len;
    table *next;
    int line;
    int column;
};


table *pilhaDeTokens = NULL;
int numberOfTokens = 0;

// podemos botar o token em uma pilha ou em um vetor (penso em colocar em um vetor e fazer
// uma função para realocar a memória quando necessário, pois pilha e lista não tem indice
// logo não são as melhores opções para uma tabela)

// Para rodar no windows: gcc lex.yy.c -L"C:\GnuWin32\lib" -lfl -o nomeDoArquivo


void addToken(char *string){
    numberOfTokens++;
    if(pilhaDeTokens == NULL){
        pilhaDeTokens = (table *)malloc(sizeof(table));
        pilhaDeTokens->token = string;
        pilhaDeTokens->token_len = strlen(string);
        pilhaDeTokens->next = NULL;
    }
    else{
        table *newToken;
        newToken = (table *)malloc(sizeof(table));
        newToken->token = string;
        newToken->token_len = strlen(string);
        newToken->next = pilhaDeTokens;
        pilhaDeTokens = newToken;
    }
}

char *getToken(table *stack, int *stackLen, int *stackLine, int *stackColumn){
	if(stack == NULL) return NULL;
	else{
		char *tokenRemoved = stack->token;
		*stackLen = stack->token_len;
		*stackLine = stack->line;
		*stackColumn = stack->column;
		table *OldStack = stack;
		stack = stack->next;
		free(OldStack);
		return tokenRemoved;
	}
}

// Um vetor é uma solução ineficiente comparada à uma pilha pois ambos tem as mesmas vantagens (busca O(n) e inserção O(1))...
// ... mas a pilha é um meio de alocação dinâmica o que proporciona uma melhor forma de armazenamento.

// Para os atributos talvez seja melhor salvar o nome do atributo na própria estrutura de token.

%}

/* ========================================================================== */
/* ===========================  Sessão DEFINIÇÔES  ========================== */
/* ========================================================================== */

DIGITO  ([0-9])
BOOL-LIT true|false
OP-AD "+"|"-"|"or"
OP-MUL  "*"|"/"|"and"
OP-REL "<"|">"|"<="|">="|"="|"<>"
OUTROS "!"|"@"|"#"|"$"|"%"|"¨"|"&"
TIPO "integer"|"real"|"boolean"
VAZIO "ε"
LETRA[a-z]
%%

{OP-AD} {
			printf("Um operador de adição: %s\n", yytext);
			addToken(yytext);
			pilhaDeTokens->line = num_lines;
			pilhaDeTokens->column = num_columns;
			num_columns += strlen(yytext);
			printf("linha = %i, coluna = %i \n", num_lines, num_columns);
			printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
			return 'a';
		}

{OP-MUL} 	{
				printf("Um operador de multiplicação: %s\n", yytext);
				pilhaDeTokens->line = num_lines;
				pilhaDeTokens->column = num_columns;
				num_columns += strlen(yytext);
				addToken(yytext);
				printf("linha = %i, coluna = %i \n", num_lines, num_columns);
				printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
			}

{OP-REL} 	{
				printf("Um operador de relação: %s\n", yytext);
				addToken(yytext);
				pilhaDeTokens->line = num_lines;
				pilhaDeTokens->column = num_columns;
				num_columns += strlen(yytext);
				printf("linha = %i, coluna = %i \n", num_lines, num_columns);
				printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
			}

{OUTROS} 	{
				printf("Um caracter especial: %s\n", yytext);
				addToken(yytext);
				pilhaDeTokens->line = num_lines;
				pilhaDeTokens->column = num_columns;
				num_columns += strlen(yytext);
				printf("linha = %i, coluna = %i \n", num_lines, num_columns);
				printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
			}

{TIPO} 	{	
			printf("Um tipo: %s\n", yytext);
			addToken(yytext);
			pilhaDeTokens->line = num_lines;
			pilhaDeTokens->column = num_columns;
			num_columns += strlen(yytext);
			printf("linha = %i, coluna = %i \n", num_lines, num_columns);
			printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
		}

{VAZIO} 	{	
				printf("Um epsilon (vazio): %s\n", yytext);
				addToken(yytext);
				pilhaDeTokens->line = num_lines;
				pilhaDeTokens->column = num_columns;
				num_columns += strlen(yytext);
				printf("linha = %i, coluna = %i \n", num_lines, num_columns);
				printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
			}

{DIGITO}+$  {
            	printf( "Um valor inteiro: %s (%d)\n", yytext, atoi( yytext )); 
				addToken(yytext);
				pilhaDeTokens->line = num_lines;
				pilhaDeTokens->column = num_columns;
				num_columns += strlen(yytext);
				printf("linha = %i, coluna = %i \n", num_lines, num_columns);
				printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
            }

{DIGITO}+"."{DIGITO}*$      {
            					printf( "Um valor real: %s (%g)\n", yytext, atof( yytext ) );
								addToken(yytext);
								pilhaDeTokens->line = num_lines;
								pilhaDeTokens->column = num_columns; 
								num_columns += strlen(yytext);
								printf("linha = %i, coluna = %i \n", num_lines, num_columns);
								printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
            				}

if|else|then|begin|end|function|;|:|while|do|,|array|"["|"]"|var|procedure|of|"("|")"|:=   {
         									printf( "Uma palavra-chave: %s\n", yytext );
											addToken(yytext);
											pilhaDeTokens->line = num_lines;
											pilhaDeTokens->column = num_columns;
	    									num_columns += strlen(yytext);
											printf("linha = %i, coluna = %i \n", num_lines, num_columns);
											printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
            							}


"{"[^}\n]*"}"     /* Lembre-se... comentários não tem utilidade! */

[ \t]+  {
			num_columns++;
		}/* Lembre-se... espaços em branco não tem utilidade! */

\n      {
			++num_lines; num_columns = 0;
		}

.           {
				printf( "Caracter não reconhecido ou id: %s\n", yytext );
				addToken(yytext);
				pilhaDeTokens->line = num_lines;
				pilhaDeTokens->column = num_columns;
	      		num_columns += strlen(yytext);
				printf("linha = %i, coluna = %i \n", num_lines, num_columns);
				printf("token = %s\nnúmero = %i\n", pilhaDeTokens->token, numberOfTokens);
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
	
	printf("# total de linhas = %d\n", num_lines);
    
	return 0;
}
