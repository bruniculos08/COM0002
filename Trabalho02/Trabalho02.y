%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int getLocation(char *string);
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
extern struct headTable *fila;

void generateHeader();
void generateFooter();
void yyerror(const char* s);
FILE *f;

// (2) O token END é um token especial que representa o EOF (end of file):
%}

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

%start programa

%%

atribuicao: variavel TWODOTS_EQUAL_TOKEN expressao
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

corpo: declaracao comando_composto
  	 ;

declaracao: 
		  |	declaracao_de_variavel
  		  ;

declaracao_de_variavel: VAR_TOKEN lista_de_ids TWODOTS_TOKEN tipo
  		  			  ;

declaracoes: 
		   | declaracao DOTCOMMA_TOKEN
		   | declaracoes declaracao DOTCOMMA_TOKEN
		   | vazio
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

iterativo: WHILE_TOKEN expressao DO_TOKEN comando
		 ;

lista_de_comandos: 
			     | comando DOTCOMMA_TOKEN 
				 | lista_de_comandos comando DOTCOMMA_TOKEN
				 | vazio
				 ;

lista_de_ids: ID_TOKEN lista_de_ids COMMA_TOKEN ID_TOKEN
			| ID_TOKEN COMMA_TOKEN ID_TOKEN
			;


literal: bool_lit
	   | INT_TOKEN
	   | FLOAT_TOKEN
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

programa: PROGRAM_TOKEN { generateHeader(); } ID_TOKEN DOTCOMMA_TOKEN corpo END { 
													  // (6) Se os comandos desse bloco forem executados então...
													  // ... a sentença (programa) pode ser gerada pela gramática (o...
													  // ... programa está sintáticamente correto).
													  printf("\nPrograma valido\n");
													  generateFooter();
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

variavel: ID_TOKEN seletor
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

void generateHeader(){
	f = fopen("output.j", "w+");
	fprintf(f, ".class public output/Verb\n.super java/lang/Object\n");
	fprintf(f, ".method public <init>()V\n");
	fprintf(f, "	aload_0\n");
	fprintf(f, "	invokenonvirtual java/lang/Object/<init>()V\n");
}

void generateFooter(){
	f = fopen("output.j", "a");
	fprintf(f, "	return\n");
	fprintf(f, ".end method");
}

void generateMainHeader(){
	f = fopen("output.j", "a");
	fprintf(f, "	return\n");
	fprintf(f, ".end method\n");
}

void generateMainFooter(){

}

void atributeVariable(char *id, int value){
	f = fopen("output.j", "a");
	fprintf(f, ".bipush %i\n", value);
	fprintf(f, ".istore %i", getLocation(id));
}