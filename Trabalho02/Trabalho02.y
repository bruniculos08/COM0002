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
extern void tableMain();
extern void setType();
extern int num_lines;
extern int num_columns;
extern int numberOfTokens;
// Obs.: stucts devem ser declaradas normalmente (sem o uso de extern).
extern struct Table table;
extern struct HeadTable headTable;
//extern struct headTable *fila;


void yyerror(const char* s);

void setType(char *string){
	fila->last->type = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->type, string);
}

// (2) O token END é um token especial que representa o EOF (end of file):
%}

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


%token INT_TOKEN 


%token IF_TOKEN ELSE_TOKEN THEN_TOKEN BEGIN_TOKEN END_TOKEN FUNCTION_TOKEN DOTCOMMA_TOKEN TWODOTS_TOKEN WHILE_TOKEN DO_TOKEN COMMA_TOKEN ARRAY_TOKEN BLEFT_TOKEN BRIGHT_TOKEN VAR_TOKEN PROCEDURE_TOKEN OF_TOKEN PLEFT_TOKEN PRIGHT_TOKEN TWODOTS_EQUAL_TOKEN 

%token TO_TOKEN FOR_TOKEN 

%start programa

%%

atribuicao: variavel TWODOTS_EQUAL_TOKEN expressao
		  ;

bool_lit: TRUE_TOKEN
		| FALSE_TOKEN
		;

chamada_de_procedimento: id PLEFT_TOKEN vazio PRIGHT_TOKEN
					   ;

comando: atribuicao
	   | condicional
	   | iterativo
	   | chamada_de_procedimento
	   | comando_composto
	   | comando_for
	   | comando_while
	   ;

comando_composto: BEGIN_TOKEN lista_de_comandos END_TOKEN
				;
			
			
comando_for: FOR_TOKEN atribuicao TWODOTS_TOKEN digito TWODOTS_TOKEN
		   ;
				
comando_while: WHILE_TOKEN id op_rel id TWODOTS_TOKEN

condicional: IF_TOKEN expressao THEN_TOKEN comando ELSE_TOKEN comando 
		   | IF_TOKEN expressao THEN_TOKEN comando vazio
		   ;

corpo: declaracao comando_composto
  	 ;

declaracao: 
		  |	declaracao_de_variavel
		  | declaracao_de_procedimento
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

programa: PROGRAM_TOKEN id DOTCOMMA_TOKEN corpo END { 
													  // (6) Se os comandos desse bloco forem executados então...
													  // ... a sentença (programa) pode ser gerada pela gramática (o...
													  // ... programa está sintáticamente correto).
													  printf("\nPrograma valido\n");
													}
		;
				
seletor: seletor BLEFT_TOKEN expressao BRIGHT_TOKEN 
	   | BLEFT_TOKEN expressao BRIGHT_TOKEN
	   | vazio
	   ;

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
		;

vazio: 
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
	tableMain();


	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de analise (sintatica): %s\n", s);
	exit(1);
}
