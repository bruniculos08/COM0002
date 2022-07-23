%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;


// (1) As funções e variáveis declaradas no arquivo .lex devem ser declaradas no arquivo .y com o uso de "extern",...
// ... caso contrário o linker (programa que une o código .lex com o código .y) irá entender que as variávais foram...
// ... declaradas duas vezes (se foram declaradas no código .y) 
extern int num_lines;
extern int num_columns;
extern int numberOfTokens;
// Obs.: stucts devem ser declaradas normalmente (sem o uso de extern).

void yyerror(const char* s);
int or_OP(int x, int y);
int and_OP(int x, int y);

// (2) O token END é um token especial que representa o EOF (end of file):
%}

%union {
	int ival;
	float fval;
}

%token END 0 "end of file"
%token T_NUMBER T_JUMP T_TRUE T_FALSE 

%type<ival> expressao soma_sub mult_div T_NUMBER

%start algebra

%%

algebra: expressao END 	    { printf("Resultado = %f ", $1); }
	   ;

expressao: soma_sub { $$ = $1; } // (1) Essa regra é inútil porém estou usando pela organização.
		 ;

soma_sub: soma_sub "+" mult_div { $$ = $1 + $3; }
		| soma_sub "-" mult_div { $$ = $1 - $3; }
		| mult_div {$$ = $1}
		;

mult_div: mult_div "*" T_NUMBER { $$ = $1 * $3; }
		| mult_div "/" T_NUMBER { $$ = $1 / $3; }
		| T_NUMBER				{ $$ = $1; }
		;
%%

int main() {
	// (7) A variável yyin recebe a entrada do terminal (stdin):
	yyin = stdin;
	// (8) Enquanto não se chega no final do arquivo de entrada (yyin) se executa a função de analise...
	// ... sintatica (yyparse):
	do {
		yyparse();
	} while(!feof(yyin));
	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de analise (sintatica): %s\n", s);
	exit(1);
}