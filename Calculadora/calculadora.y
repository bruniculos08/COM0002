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
%token T_NUMBER T_JUMP T_TRUE T_FALSE T_SUM T_SUB T_MUL T_DIV

%type<ival> expressao mul_div T_NUMBER

%start algebra

%%

algebra: 
	   | expressao END { printf("Resultado = %i\n", $1); }
	   | expressao { printf("Resultado = %i\n", $1); } T_JUMP algebra END
	   ;

expressao: expressao T_SUM mul_div  {$$ = $1 + $3;}
		 | expressao T_SUB mul_div	{$$ = $1 - $3;}
		 | mul_div 					{$$ = $1;}
		 ;

mul_div: mul_div T_MUL T_NUMBER {$$ = $1 * $3;}
	   | mul_div T_DIV T_NUMBER	{$$ = $1 / $3;}
	   | T_NUMBER				{$$ = $1;}
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