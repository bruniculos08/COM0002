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
%token OP_AD
%token OP_DIV
%token OP_REL

%type<ival> expr
%type<fval> mixed_expr

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


calculation:	/* Aqui temos a representação do epsilon na gramática... */
	| calculation line
	;

line: T_NEWLINE
	| mixed_expr T_NEWLINE					{ printf("\tResultado: %f\n", $1);}
	| expr T_NEWLINE							{ printf("\tResultado: %i\n", $1); }
	| T_QUIT T_NEWLINE						{ printf("Até mais...\n"); exit(0); }
	;

mixed_expr: T_REAL							{ $$ = $1; }
	| T_PLUS mixed_expr mixed_expr 			{ $$ = $2 + $3; }
	| T_MINUS mixed_expr mixed_expr			{ $$ = $2 - $3; }
	| T_MULTIPLY mixed_expr mixed_expr		{ $$ = $2 * $3; }
	| T_DIVIDE mixed_expr mixed_expr		{ $$ = $2 / $3; }
	| T_LEFT mixed_expr T_RIGHT				{ $$ = $2; }
	| T_PLUS expr mixed_expr				{ $$ = $2 + $3; }
	| T_MINUS expr mixed_expr				{ $$ = $2 - $3; }
	| T_MULTIPLY expr mixed_expr			{ $$ = $2 * $3; }
	| T_DIVIDE expr mixed_expr				{ $$ = $2 / $3; }
	| T_PLUS mixed_expr expr				{ $$ = $2 + $3; }
	| T_MINUS mixed_expr expr				{ $$ = $2 - $3; }
	| T_MULTIPLY mixed_expr expr			{ $$ = $2 * $3; }
	| T_DIVIDE mixed_expr expr				{ $$ = $2 / $3; }
	| T_DIVIDE expr expr					{ $$ = $2 / (float)$3; }
	;

expr: T_INT									{ $$ = $1; }
	| T_PLUS expr expr						{ $$ = $2 + $3; }
	| T_MINUS expr expr						{ $$ = $2 - $3; }
	| T_MULTIPLY expr expr					{ $$ = $2 * $3; }
	| T_LEFT expr T_RIGHT					{ $$ = $2; }
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
