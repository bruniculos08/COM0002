%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Compiler.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;


// (1) As funções e variáveis declaradas no arquivo .lex devem ser declaradas no arquivo .y com o uso de "extern",...
// ... caso contrário o linker (programa que une o código .lex com o código .y) irá entender que as variávais foram...
// ... declaradas duas vezes (se foram declaradas no código .y) 

extern FILE *f;
extern int num_lines;
extern int num_columns;
extern int numberOfTokens;
extern int numberOfUsedStackLocation;
// Obs.: stucts devem ser declaradas normalmente (sem o uso de extern).



// (2) O token END é um token especial que representa o EOF (end of file):
%}

%union {
	int ival;
	float fval;
	char cval;
	char *sval;
	book *bookval;
}
%token END 0 "end of file"
%token PROGRAM_TOKEN 
%token TRUE_TOKEN FALSE_TOKEN 
%token ID_TOKEN
%token ADD_TOKEN SUB_TOKEN OR_TOKEN
%token MULT_TOKEN DIVIDE_TOKEN AND_TOKEN
%token SMALLER_TOKEN BIGGER_TOKEN SMALLER_EQUAL_TOKEN BIGGER_EQUAL_TOKEN EQUAL_TOKEN DIFF_TOKEN
%token OUTROS_TOKEN DOT_TOKEN
%token INTEGER_TOKEN REAL_TOKEN BOOLEAN_TOKEN
%token VAZIO_TOKEN 
%token INT_TOKEN FLOAT_TOKEN
%token IF_TOKEN ELSE_TOKEN THEN_TOKEN BEGIN_TOKEN END_TOKEN FUNCTION_TOKEN DOTCOMMA_TOKEN TWODOTS_TOKEN WHILE_TOKEN DO_TOKEN COMMA_TOKEN ARRAY_TOKEN BLEFT_TOKEN BRIGHT_TOKEN VAR_TOKEN PROCEDURE_TOKEN OF_TOKEN PLEFT_TOKEN PRIGHT_TOKEN TWODOTS_EQUAL_TOKEN 
%token TO_TOKEN FOR_TOKEN 

%type<fval> FLOAT_TOKEN
%type<ival> expressao_simples INT_TOKEN termo bool_lit TRUE_TOKEN FALSE_TOKEN
%type<cval> op_ad op_mul ADD_TOKEN SUB_TOKEN OR_TOKEN MULT_TOKEN DIVIDE_TOKEN AND_TOKEN
%type<sval> variavel ID_TOKEN tipo_simples tipo INTEGER_TOKEN REAL_TOKEN BOOLEAN_TOKEN
%type<sval> op_rel SMALLER_TOKEN BIGGER_TOKEN SMALLER_EQUAL_TOKEN BIGGER_EQUAL_TOKEN EQUAL_TOKEN DIFF_TOKEN
%type<bookval> lista_de_ids

%start programa
%%

atribuicao: variavel TWODOTS_EQUAL_TOKEN expressao_simples { atributeVariable($1); }
		  ;

bool_lit: TRUE_TOKEN
		| FALSE_TOKEN
		;

comando: atribuicao
	   | condicional
	   | iterativo
	   | comando_composto
	   | comando_for
	   | comando_while
	   ;

comando_composto: BEGIN_TOKEN lista_de_comandos END_TOKEN
				;
			
			
comando_for: FOR_TOKEN atribuicao TWODOTS_TOKEN INT_TOKEN TWODOTS_TOKEN
		   ;
				
comando_while: WHILE_TOKEN ID_TOKEN op_rel ID_TOKEN TWODOTS_TOKEN

condicional: IF_TOKEN expressao THEN_TOKEN comando ELSE_TOKEN comando 
		   | IF_TOKEN expressao THEN_TOKEN comando vazio
		   ;

corpo: declaracoes comando_composto
  	 ;

declaracao: declaracao_de_variavel
  		  ;

declaracao_de_variavel: VAR_TOKEN lista_de_ids TWODOTS_TOKEN tipo {	// (7) Eis aqui a utilização da estrutura "Book":
																	setBookType($2, $4);
																  }
  		  			  ;

declaracoes: declaracao DOTCOMMA_TOKEN
		   | declaracoes declaracao DOTCOMMA_TOKEN
		   | vazio
		   ;

expressao: expressao_simples {}
		 | expressao_simples op_rel expressao_simples {}
		 ;

expressao_simples: expressao_simples op_ad termo { putOpInStack($2);}
				 | termo { }
				 ;

fator: variavel { int stackLocation = getLocation($1); loadVariableValue(stackLocation); }
	 | literal { }
	 | PLEFT_TOKEN expressao_simples PRIGHT_TOKEN { }
	 ;

iterativo: WHILE_TOKEN expressao DO_TOKEN comando
		 ;

lista_de_comandos: comando DOTCOMMA_TOKEN 
				 | lista_de_comandos comando DOTCOMMA_TOKEN
				 | vazio
				 ;

lista_de_ids: lista_de_ids COMMA_TOKEN ID_TOKEN { $$ = createBook(); addStringsFrom($$, $1); addString($$, $3); }
			| ID_TOKEN 							{ $$ = createBook(); addString($$, $1); }
			;


literal: INT_TOKEN { putNumberInStack($1); }
	   ;	//| FLOAT_TOKEN e bool_lit

op_ad: ADD_TOKEN { $$ = $1; }
	 | SUB_TOKEN { $$ = $1; }
	 | OR_TOKEN  { $$ = $1; }
	 ;

op_mul: MULT_TOKEN		{ $$ = $1; }
	  | DIVIDE_TOKEN	{ $$ = $1; }
	  | AND_TOKEN		{ $$ = $1; }
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

programa: PROGRAM_TOKEN { generateHeader(); generateMainHeader();} ID_TOKEN DOTCOMMA_TOKEN corpo END { 
													  // (6) Se os comandos desse bloco forem executados então...
													  // ... a sentença (programa) pode ser gerada pela gramática (o...
													  // ... programa está sintáticamente correto).
													  generateMainFooter();
													  printf("\nPrograma valido\n");
													}
		;
				
seletor: seletor BLEFT_TOKEN expressao BRIGHT_TOKEN 
	   | BLEFT_TOKEN expressao BRIGHT_TOKEN
	   | vazio
	   ;

termo: termo op_mul fator 	{ putOpInStack($2); }
	 | fator 				{ 					}
	 ;

tipo: tipo_simples { $$ = strdup($1); }
	;	//tipo_agregado

//tipo_agregado: ARRAY_TOKEN BLEFT_TOKEN literal BRIGHT_TOKEN OF_TOKEN tipo
//			 ;

tipo_simples: INTEGER_TOKEN { $$ = strdup($1); }
			| REAL_TOKEN 	{ $$ = strdup($1); }
			| BOOLEAN_TOKEN { $$ = strdup($1); }
		    ;

variavel: ID_TOKEN { $$ = strdup($1); }
		; //ID_TOKEN seletor
		

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
	//tableMain();


	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de analise (sintatica): %s\n", s);
	exit(1);
}