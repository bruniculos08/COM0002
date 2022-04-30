/* Linguagem: Pascal-like */

/* ========================================================================== */
/* Abaixo, indicado pelos limitadores "%{" e "%}", as includes necessárias... */
/* ========================================================================== */

%{
/* Para as funções atoi() e atof() */
#include <math.h>
#include <string.h>

int num_lines = 0;
int num_columns = 0;
%}

/* ========================================================================== */
/* ===========================  Sessão DEFINIÇÔES  ========================== */
/* ========================================================================== */

DIGITO   [0-9]
ID       [a-z][a-z0-9]*

%%

{DIGITO}+    {
            printf( "Um valor inteiro: %s (%d)", yytext,
                    atoi( yytext ) ); 
		num_columns += strlen(yytext);
		printf(" linha = %i, coluna = %i \n", num_lines, num_columns);
            }

{DIGITO}+"."{DIGITO}*        {
            printf( "Um valor real: %s (%g)\n", yytext,
                    atof( yytext ) ); 
		num_columns += strlen(yytext);
		printf(" linha = %i, coluna = %i \n", num_lines, num_columns);
            }

if|then|begin|end|procedure|function        {
         		printf( "Uma palavra-chave: %s\n", yytext );
	    		num_columns += strlen(yytext);
			printf(" linha = %i, coluna = %i \n", num_lines, num_columns);
            }

{ID}        {printf( "Um identificador: %s\n", yytext ); 		
		 num_columns += strlen(yytext);
		 printf(" linha = %i, coluna = %i \n", num_lines, num_columns);}

"+"|"-"|"*"|"/"  { printf( "Um operador: %s\n", yytext );
				num_columns += strlen(yytext);
				printf(" linha = %i, coluna = %i \n", num_lines, num_columns);}

"{"[^}\n]*"}"     /* Lembre-se... comentários não tem utilidade! */

[ \t]+          {num_columns++;}/* Lembre-se... espaços em branco não tem utilidade! */

\n        {++num_lines; num_columns = 0;}

.           {printf( "Caracter não reconhecido: %s\n", yytext ); 		
	      num_columns += strlen(yytext);}

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
