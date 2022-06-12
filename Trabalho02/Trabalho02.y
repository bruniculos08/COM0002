%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void tableMain();
void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
}

%token END 0 "end of file"

%token PROGRAM_TOKEN 
%token TRUE_TOKEN FALSE_TOKEN
%token LETTER_TOKEN
%token ADD_TOKEN SUB_TOKEN OR_TOKEN
%token MULT_TOKEN DIVIDE_TOKEN AND_TOKEN
%token SMALLER_TOKEN BIGGER_TOKEN SMALLER_EQUAL_TOKEN BIGGER_EQUAL_TOKEN EQUAL_TOKEN DIFF_TOKEN
%token OUTROS_TOKEN DOT_TOKEN
%token INTEGER_TOKEN REAL_TOKEN BOOLEAN_TOKEN
%token VAZIO_TOKEN
%token<ival> INT_TOKEN
%token IF_TOKEN ELSE_TOKEN THEN_TOKEN BEGIN_TOKEN END_TOKEN FUNCTION_TOKEN DOTCOMMA_TOKEN TWODOTS_TOKEN WHILE_TOKEN DO_TOKEN COMMA_TOKEN ARRAY_TOKEN BLEFT_TOKEN BRIGHT_TOKEN VAR_TOKEN PROCEDURE_TOKEN OF_TOKEN PLEFT_TOKEN PRIGHT_TOKEN TWODOTS_EQUAL_TOKEN

%start programa

%%

atribuicao: variavel TWODOTS_EQUAL_TOKEN expressao
		  ;

bool_lit: TRUE_TOKEN
		| FALSE_TOKEN
		;

chamada_de_funcao: id PLEFT_TOKEN lista_de_expressoes PRIGHT_TOKEN
				 | id PLEFT_TOKEN vazio PRIGHT_TOKEN
				 ;

chamada_de_procedimento: id PLEFT_TOKEN lista_de_expressoes PRIGHT_TOKEN
				 	   | id PLEFT_TOKEN vazio PRIGHT_TOKEN
					   ;

comando: atribuicao
	   | condicional
	   | iterativo
	   | chamada_de_procedimento
	   | comando_composto
	   ;

comando_composto: BEGIN_TOKEN lista_de_comandos END_TOKEN
				;

condicional: IF_TOKEN expressao THEN_TOKEN comando ELSE_TOKEN comando 
		   | IF_TOKEN expressao THEN_TOKEN comando vazio
		   ;

corpo: declaracao comando_composto
  	 ;

declaracao: 
		  |	declaracao_de_variavel
		  | declaracao_de_funcoes
		  | declaracao_de_procedimento
  		  ;

declaracao_de_funcoes: FUNCTION_TOKEN id PLEFT_TOKEN lista_de_parametros TWODOTS_TOKEN tipo_simples DOTCOMMA_TOKEN corpo
  		  			 | FUNCTION_TOKEN id PLEFT_TOKEN vazio TWODOTS_TOKEN tipo_simples DOTCOMMA_TOKEN corpo
  		  			 ;

declaracao_de_procedimento: PROCEDURE_TOKEN id PLEFT_TOKEN lista_de_parametros TWODOTS_TOKEN tipo_simples DOTCOMMA_TOKEN corpo
  		  			 	  | PROCEDURE_TOKEN id PLEFT_TOKEN vazio TWODOTS_TOKEN tipo_simples DOTCOMMA_TOKEN corpo
  		  			 	  ;

declaracao_de_variavel: VAR_TOKEN lista_de_ids TWODOTS_TOKEN tipo
  		  			  ;

declaracoes: 
		   | declaracao DOTCOMMA_TOKEN
		   | declaracoes declaracao DOTCOMMA_TOKEN
		   | vazio
		   ;

digito: INT_TOKEN digito
	  | INT_TOKEN
	  ;

expressao: expressao_simples
		 | expressao_simples op_rel expressao_simples
		 ;

expressao_simples: expressao_simples op_ad termo
				 | termo
				 ;

fator: variavel
	 | literal
	 | PLEFT_TOKEN expressao PRIGHT_TOKEN
	 | chamada_de_funcao
	 ;

float_lit: int_lit DOT_TOKEN int_lit
		 | int_lit DOT_TOKEN
		 | DOT_TOKEN int_lit
		 ;

id: letra
  | id letra 
  | id digito
  ;

int_lit: digito
	   | int_lit digito

iterativo: WHILE_TOKEN expressao DO_TOKEN comando
		 ;
	
letra: LETTER_TOKEN
	 ;

lista_de_comandos: 
			     | comando DOTCOMMA_TOKEN 
				 | lista_de_comandos comando DOTCOMMA_TOKEN
				 | vazio
				 ;

lista_de_expressoes: expressao
				   | lista_de_expressoes COMMA_TOKEN expressao
				   ;

lista_de_ids: id lista_de_ids COMMA_TOKEN id
			| id COMMA_TOKEN id
			;

lista_de_parametros: parametros
				   | lista_de_parametros DOTCOMMA_TOKEN parametros
				   ;

literal: bool_lit
	   | int_lit
	   | float_lit
	   ;

literals: literals literal
		| literal
	   	;

op_ad: ADD_TOKEN 
	 | SUB_TOKEN
	 | OR_TOKEN
	 ;

op_mul: MULT_TOKEN
	  | DIVIDE_TOKEN
	  | AND_TOKEN
	  ;

op_rel: SMALLER_TOKEN
	  | BIGGER_TOKEN
	  | SMALLER_EQUAL_TOKEN
	  | BIGGER_EQUAL_TOKEN
	  | EQUAL_TOKEN
	  | DIFF_TOKEN
	  ;

outros: OUTROS_TOKEN
	  ;

parametros: VAR_TOKEN lista_de_ids TWODOTS_TOKEN tipo_simples
		  | vazio lista_de_ids TWODOTS_TOKEN tipo_simples
		  ;

programa: PROGRAM_TOKEN id DOTCOMMA_TOKEN corpo END {printf("\nPrograma valido\n");}
		| PROGRAM_TOKEN id DOTCOMMA_TOKEN END {printf("\nPrograma valido\n");}
		;

seletor: seletor BLEFT_TOKEN expressao BRIGHT_TOKEN
	   | BLEFT_TOKEN expressao BRIGHT_TOKEN
	   | vazio

termo: termo op_mul fator
	 | fator 
	 ;

tipo: tipo_agregado
	| tipo_simples
	;

tipo_agregado: ARRAY_TOKEN BLEFT_TOKEN literals BRIGHT_TOKEN OF_TOKEN tipo
			 ;

tipo_simples: INTEGER_TOKEN | REAL_TOKEN | BOOLEAN_TOKEN
		    ;

variavel: id seletor

vazio: 
	 ;

%%

int main() {
	//tableMain();
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de analise (sintatica): %s\n", s);
	exit(1);
}
