%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
}

/* Declaração dos tokens... */

%token<ival> T_INT
%token<fval> T_REAL
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT
%token T_NEWLINE T_QUIT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE

//fazer a declaração dos tokens aqui (returns)
%token OP_AD OP_DIV OP_REL FUNCTION_TOKEN PLEFT_TOKEN )_TOKEN DOTCOMMA_TOKEN TWODOTS_TOKEN VAR_TOKEN VAZIO_TOKEN

%start programa

%%

programa: PROGRAM_TOKEN id DOTCOMMA_TOKEN corpo {}
		;

id: letra
  | id letra 
  | id digito
  ;

corpo: declaracao comando-composto
  	;

declaracao: declaracao-de-variavel
		  | declaracao-de-funcoes
		  | declaracao-de-procedimento
  		  ;

declaracao-de-funcoes: FUNCTION_TOKEN id (_TOKEN lista-de-parametros TWODOTS_TOKEN tipo simples DOTCOMMA_TOKEN corpo
  		  			 | FUNCTION_TOKEN id (_TOKEN VAZIO_TOKEN TWODOTS_TOKEN tipo simples DOTCOMMA_TOKEN corpo
  		  			 ;

declaracao-de-procedimento: PROCEDURE_TOKEN id (_TOKEN lista-de-parametros TWODOTS_TOKEN tipo simples DOTCOMMA_TOKEN corpo
  		  			 	  | PROCEDURE_TOKEN id (_TOKEN VAZIO_TOKEN TWODOTS_TOKEN tipo simples DOTCOMMA_TOKEN corpo
  		  			 	  ;

declaracao-de-variavel: VAR_TOKEN lista-de-ids TWODOTS_TOKEN tipo
  		  			  ;

declaracoes: declaracao DOTCOMMA_TOKEN
		   | declaracoes declaracao DOTCOMMA_TOKEN
		   | VAZIO_TOKEN

opad: OP_AD { printf("\nOP-AD detectado\n";)}
	;

opmul: OP_MUL { printf("\nOP-MUL detectado\n";)}
	;

oprel: OP_REL { printf("\nOP-REL detectado\n";)}
	;

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
