/* Linguagem: Pascal-like */
/* Abaixo, indicado pelos limitadores "%{" e "%}", as includes necessárias... */

%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// (1) Contador de linhas:
int num_lines = 0, num_columns = 0;

%}

/* Definições: */
DIGITO  ([0-9])

%%

[ \t]+  {
			num_columns++;
		}	

\n      {
			++num_lines; num_columns = 0;
		}

.           {
				
		    }

%%

int main(argc, argv)
int argc;
char **argv;
{
	++argv;
	--argc;

	if (argc > 0) yyin = fopen( argv[0], "r" );
	else yyin = stdin;

	yylex();
	printf("# total de linhas = %d\n", num_lines);
    
	return 0;
}
