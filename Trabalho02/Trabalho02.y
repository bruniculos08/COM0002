%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Compiler.h"

extern int count_label;

%}

%union {
	int ival;
	float fval;
	char cval;
	char *sval;
	book *bookval;
}

%token END 0 "end of file"
%token PROGRAM_TOKEN PRINT_TOKEN
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
%token TO_TOKEN FOR_TOKEN CBLEFT_TOKEN CBRIGHT_TOKEN

%type<fval> FLOAT_TOKEN
%type<ival> INT_TOKEN TRUE_TOKEN FALSE_TOKEN bool_lit IF_TOKEN ELSE_TOKEN WHILE_TOKEN
%type<cval> op_ad op_mul ADD_TOKEN SUB_TOKEN OR_TOKEN MULT_TOKEN DIVIDE_TOKEN AND_TOKEN
%type<sval> variavel ID_TOKEN tipo_simples tipo INTEGER_TOKEN REAL_TOKEN BOOLEAN_TOKEN literal expressao_simples fator termo
%type<sval> op_rel SMALLER_TOKEN BIGGER_TOKEN SMALLER_EQUAL_TOKEN BIGGER_EQUAL_TOKEN EQUAL_TOKEN DIFF_TOKEN
%type<bookval> lista_de_ids

%start programa
%%

// TODO (1) Regras a serem recolocadas:
//	bool_lit -> TRUE_TOKEN | FALSE_TOKEN
//	literal -> FLOAT_TOKEN | bool_lit
//	tipo -> tipo_agregado
//	tipo_agregado -> ARRAY_TOKEN BLEFT_TOKEN literal BRIGHT_TOKEN OF_TOKEN tipo
// 	variavel -> ID_TOKEN seletor 


atribuicao: variavel TWODOTS_EQUAL_TOKEN expressao_simples { atributeIntVariable($1); }
		  ;

bool_lit: TRUE_TOKEN 	{ $$ = 1;	}
		| FALSE_TOKEN 	{ $$ = 0;	}
		;

comando: atribuicao DOTCOMMA_TOKEN
	   | condicional
	   | iterativo
	   | comando_composto
	   | comando_for
	   | comando_while
	   | printar DOTCOMMA_TOKEN
	   ;

comando_composto: BEGIN_TOKEN lista_de_comandos END_TOKEN
				;
			
			
comando_for: FOR_TOKEN atribuicao TWODOTS_TOKEN INT_TOKEN TWODOTS_TOKEN
		   ;
				
comando_while: WHILE_TOKEN PLEFT_TOKEN condicao_contraria PLEFT_TOKEN { $1 = count_label; onlyLabel($1); onlyLabelForIf($1 + 1); } CBLEFT_TOKEN lista_de_comandos CBRIGHT_TOKEN { onlyGoTo($1); onlyLabel($1 + 1); count_label+=2; }
			 ;
// Ideia para funcionamento do if else:
// - criar contador de label de modo que sempre o laber de um else tem índice igual ao índice do if + 1,
// ... ou seja, após o if else é adicionado +2 ao contador de label.

condicional: IF_TOKEN PLEFT_TOKEN condicao_contraria PRIGHT_TOKEN THEN_TOKEN CBLEFT_TOKEN { $1 = count_label; onlyLabelForIf($1); } lista_de_comandos CBRIGHT_TOKEN { onlyGoTo($1 +1); onlyLabel($1); count_label+=2;} comando_else {onlyLabel($1 + 1); }
		// | condicionalElse
		   ;

//condicao: expressao_simples op_rel expressao_simples { putOpInStack('-'); ifStack($2); }
//		;

condicao_contraria: expressao_simples op_rel expressao_simples { putOpInStack('-'); ifStackInverse($2); }
				  ;

comando_else: ELSE_TOKEN CBLEFT_TOKEN lista_de_comandos CBRIGHT_TOKEN
			| vazio
			;
//condicionalElse: IF_TOKEN condicao { $1 = count_label; labelGoToLabel($1, $1 + 1); count_label += 3;} THEN_TOKEN { onlyLabel($1); } comando { onlyLabel($1 + 1); } ELSE_TOKEN comando { onlyLabel($1 + 2); }
//			   ;

corpo: declaracoes comando_composto
  	 ;

declaracao: declaracao_de_variavel
  		  ;

declaracao_de_variavel: VAR_TOKEN lista_de_ids TWODOTS_TOKEN tipo {	/* (7) Eis aqui a utilização da estrutura "Book": */
																	setBookType($2, $4);
																  	/* Obs.: isso só sera útil quando houver tratamento de tipos.*/ }
  		  			  ;

declaracoes: declaracao DOTCOMMA_TOKEN
		   | declaracoes declaracao DOTCOMMA_TOKEN
		   | vazio
		   ;

expressao: expressao_simples {}
		 | expressao_simples op_rel expressao_simples {}
		 ;

expressao_simples: expressao_simples op_ad termo { putOpInStack($2); }
				 | termo { }
				 ;

fator: variavel { loadVariableValue(getLocation($1)); }
	 | literal 	
	 | PLEFT_TOKEN expressao_simples PRIGHT_TOKEN { }
	 ;

iterativo: WHILE_TOKEN expressao DO_TOKEN comando
		 ;

lista_de_comandos: comando 
				 | lista_de_comandos comando
				 | vazio
				 ;

lista_de_ids: lista_de_ids COMMA_TOKEN ID_TOKEN { }
			| ID_TOKEN 							{ }
			;


literal: INT_TOKEN 	 { putIntInStack($1); 	   }
	   | FLOAT_TOKEN { putIntInStack((int)$1); }
	   | bool_lit 	 { putIntInStack((int)$1); }
	   ;

op_ad: ADD_TOKEN { $$ = $1; }
	 | SUB_TOKEN { $$ = $1; }
	 | OR_TOKEN  { $$ = $1; }
	 ;

op_mul: MULT_TOKEN		{ $$ = $1; }
	  | DIVIDE_TOKEN	{ $$ = $1; }
	  | AND_TOKEN		{ $$ = $1; }
	  ;

op_rel: SMALLER_TOKEN 		{ $$ = strdup($1); }	
	  | BIGGER_TOKEN		{ $$ = strdup($1); }
	  | SMALLER_EQUAL_TOKEN { $$ = strdup($1); }
	  | BIGGER_EQUAL_TOKEN	{ $$ = strdup($1); }
	  | EQUAL_TOKEN			{ $$ = strdup($1); }
	  | DIFF_TOKEN			{ $$ = strdup($1); }
	  ;

programa: PROGRAM_TOKEN { generateHeader(); generateMainHeader();} ID_TOKEN DOTCOMMA_TOKEN corpo END { 
													  // (6) Se os comandos desse bloco forem executados então...
													  // ... a sentença (programa) pode ser gerada pela gramática (o...
													  // ... programa está sintáticamente correto).
													  generateMainFooter();
													  printf("\nPrograma valido\n");
													}
		;
				
printar: PRINT_TOKEN PLEFT_TOKEN {writeCode("getstatic      java/lang/System/out Ljava/io/PrintStream;\n");} expressao_simples PRIGHT_TOKEN {writeCode("invokevirtual java/io/PrintStream/println(I)V\n");}
	   ;

/*
seletor: seletor BLEFT_TOKEN expressao BRIGHT_TOKEN 
	   | BLEFT_TOKEN expressao BRIGHT_TOKEN
	   | vazio
	   ;
*/

termo: termo op_mul fator 	{ putOpInStack($2); }
	 | fator 				{ 					}
	 ;

tipo: tipo_simples { $$ = strdup($1); }
	;	

tipo_simples: INTEGER_TOKEN { $$ = strdup($1); }
			| REAL_TOKEN 	{ $$ = strdup($1); /*Obs: converter qualquer número para int enquanto não podemos tratar diferente tipos. */}
			| BOOLEAN_TOKEN { $$ = strdup($1); /*Obs: converter qualquer número para int enquanto não podemos tratar diferente tipos. */}
		    ;

variavel: ID_TOKEN { $$ = strdup($1); }
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
	//tableMain();


	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de analise (sintatica): %s\n", s);
	exit(1);
}