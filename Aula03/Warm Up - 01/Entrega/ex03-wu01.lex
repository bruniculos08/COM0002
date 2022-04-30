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

DIGITO  ([0-9])
DIGITOHEX [0-9A-F]
NUMEROIP1 ([0-1]?[0-9]?[0-9])
NUMEROIP2 (([2][0-4][0-9])|([2][5][5]))
ID       [a-z][a-z0-9]*

%%

"double"" "*{DIGITO}+"."{DIGITO}+";"[ \t]*$      {
	printf( "Uma constante double em C: %s\n", yytext);
		}

[a]+b[a]+[ \t]*$      {
	printf( "Uma palavra pertencente a linguagem da questão 02: %s\n", yytext);
		}

[0|1]+0[ \t]*$      {
	printf( "Um número binário terminado em 0: %s\n", yytext);
		}

(([0]?[1][0|4])|(0{1,3})|([0]?[3][9])|([1][2][7|8])|([2][2][4])|([2][4][0]))"."0{1,3}"."0{1,3}"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

[1][9][2]"."0?[8][8]"."0?[9][9]"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

[1][9][2]"."0?[1][8]"."0{1,3}"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

[1][9][1]"."[2][5][5]"."0{1,3}"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

[1][7][2]"."0?[1][6]"."0{1,3}"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

[1][6][9]"."[2][4][0]"."0{1,3}"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

[1][9][2]"."0{1,3}"."0{0,2}[2]"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

[2][2][3]"."[2][5][5]"."[2][5][5]"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

([2][5][5]"."[2][5][5]"."[2][5][5]"."[2][5][5])[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

([1][7][2]"."0?[1][6])|([1][6][9]"."[2][5][4])|([1][9][1]]"."[2][5][5])|([1][9][8]"."[0]?[1][8])"."0{1,3}"."0{1,3}[ \t]*$      {
	printf( "Um valor de IPV4 reservado: %s\n", yytext);
		}

(([1]?[0-9]?[0-9])|([2]?[0-4]?[0-9])|([2]?[5]?[0-5]))"."(([0-1]?[0-9]?[0-9])|([2]?[0-4]?[0-9])|([2]?[5]?[0-5]))"."(([1]?[0-9]?[0-9])|([2]?[0-4]?[0-9])|([2]?[5]?[0-5]))"."(([0-1]?[0-9]?[0-9])|([2]?[0-4]?[0-9])|([2]?[5]?[0-5]))[ \t]*$      {
	printf( "Um valor de IPV4 válido: %s\n", yytext);
		}

{NUMEROIP1}|{NUMEROIP2}"."{NUMEROIP1}|{NUMEROIP2}"."{NUMEROIP1}|{NUMEROIP2}"."{NUMEROIP1}|{NUMEROIP2}[ \t]*$      {
	printf( "Um valor de IPV4 válido: %s\n", yytext);
		}

{DIGITOHEX}{DIGITOHEX}":"{DIGITOHEX}{DIGITOHEX}":"{DIGITOHEX}{DIGITOHEX}":"{DIGITOHEX}{DIGITOHEX}":"{DIGITOHEX}{DIGITOHEX}":"{DIGITOHEX}{DIGITOHEX}[ \t]*$ {
	printf( "Um valor de endereço MAC: %s\n", yytext);
	}

{DIGITO}+"."[1][0]"^"{DIGITO}+[ \t]*$ {printf( "Um valor em notação científica: %s\n", yytext ); }


[0][xX]{DIGITOHEX}*[ \t]*$ {printf( "Um valor hexadecimal: %s\n", yytext ); }

{DIGITO}+$    {
            printf( "Um valor inteiro: %s (%d)", yytext,
                    atoi( yytext ) ); 
		num_columns += strlen(yytext);
		printf(" linha = %i, coluna = %i \n", num_lines, num_columns);
            }

{DIGITO}+"."{DIGITO}*$        {
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
