%{
	// (1) Colocar linhas entre "%colchetes" e "%colchetes" permite que se escreva código em C nestas linhas:	
	#include <stdio.h>
	// (2) Deve se declarar a função yylex, qual retorna um inteiro com um valor que indica o tipo de token que foi...
	// ... obtido. Se o token tem um valor, este (ou alguma representação deste, como um ponteiro para uma string...
	// ... contendo o valor) é retornado em uma variável externa chamada yyval.
	int yylex(void);
	// (3) Deve-se declarar a função de erro aqui também (assim como no flex): 
	void yyerror(char *s);
	// (4) Após o "%}" são declarados os tokens que podem ser retornados pelo analisador léxico e a variável inicial:
%}

%token NUMBER CALCULAR
%start simbolo_inicial

%%
	// (5) Entre "%%" são colocadas as regras gramaticais
	simbolo_inicial: 
				   | CALCULAR expressao ';'	{ printf("\nResultado = %i\n", $2); }
				   ;
	
	expressao:
			 | '(' expressao ')'
			 | expressao '+' expressao	{ $$ = $1 + $3 }
			 | expressao '-' expressao	{ $$ = $1 - $3 }
			 | expressao '*' expressao	{ $$ = $1 + $3 }
			 | expressao '/' expressao	{ $$ = $1 + $3 }
			 ;

	// Obs.: note que o $ seguido de algum número indica uma varíavel ou terminal da gramática em relação a regra...
	// ... em questão, já $$ significa toda a expressão da regra, logo quando fazemos uma atribuição em $$ estamos...
	// ... indicando que o valor da expressão será "reduzido" ao valor qual estamos atribuindo para $$.

%%