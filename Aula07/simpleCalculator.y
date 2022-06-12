%{
// (1) Colocar linhas entre "%colchetes" e "%colchetes" permite que se escreva código em C nestas linhas:	
#include <stdio.h>
#include <stdlib.h>
// (2) Deve se declarar a função yylex, qual retorna um inteiro com um valor que indica o tipo de token que foi...
// ... obtido. Se o token tem um valor, este (ou alguma representação deste, como um ponteiro para uma string...
// ... contendo o valor) é retornado em uma variável externa chamada yyval.
	
extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
}

%token<ival> NUMBER 
%token ADD SUB MULT DIVIDE P_LEFT P_RIGHT
%token CALCULAR JUMP_LINE
%start simbolo_inicial

%type<ival> expressao

%%
	// (5) Entre "%%" são colocadas as regras gramaticais
	simbolo_inicial: 
				   | simbolo_inicial line
				   | line
				   ;

	line: JUMP_LINE
		| expressao JUMP_LINE { printf("\nResultado = %i\n", $1); }
		;
	
	expressao: P_LEFT expressao P_RIGHT { $$ = $2; }
			 | expressao ADD expressao	{ $$ = $1 + $3; }
			 | expressao SUB expressao	{ $$ = $1 - $3; }
			 | expressao MULT expressao	{ $$ = $1 * $3; }
			 | expressao DIVIDE expressao	{ $$ = $1 / $3;}
			 | NUMBER	{$$ = $1;}
			 ;

	// Obs.: note que o $ seguido de algum número indica uma varíavel ou terminal da gramática em relação a regra...
	// ... em questão, já $$ significa toda a expressão da regra, logo quando fazemos uma atribuição em $$ estamos...
	// ... indicando que o valor da expressão será "reduzido" ao valor qual estamos atribuindo para $$.

%%

int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de análise (sintática): %s\n", s);
	exit(1);
}