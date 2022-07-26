%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int getLocation(char *string);
extern void setLocation(char *string, int stackLocation);
extern char *getLastID();
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
extern int numberOfUsedStackLocation;
// Obs.: stucts devem ser declaradas normalmente (sem o uso de extern).
extern struct Table table;
extern struct HeadTable headTable;
extern struct headTable *fila;

void loadVariableValue(int stackLocal);
void putNumberInStack(int value);
void putOpInStack(char op);
void atributeVariable(char *id);
void generateHeader();
void generateFooter();
void generateMainHeader();
void yyerror(const char* s);
FILE *f;

// (2) O token END é um token especial que representa o EOF (end of file):
%}

%union {
	int ival;
	float fval;
	char cval;
	char *sval;
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
%type<ival> expressao_simples INT_TOKEN termo bool_lit
%type<cval> op_rel op_ad op_mul ADD_TOKEN SUB_TOKEN OR_TOKEN MULT_TOKEN DIVIDE_TOKEN AND_TOKEN
%type<sval> variavel ID_TOKEN

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

declaracao_de_variavel: VAR_TOKEN lista_de_ids TWODOTS_TOKEN tipo
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

fator: variavel { int stackLocation = getLocation($1); //printf("load variavel %s local %i\n", $1, stackLocation); 
																				loadVariableValue(stackLocation); }
	 | literal { }
	 | PLEFT_TOKEN expressao_simples PRIGHT_TOKEN { }
	 ;

iterativo: WHILE_TOKEN expressao DO_TOKEN comando
		 ;

lista_de_comandos: comando DOTCOMMA_TOKEN 
				 | lista_de_comandos comando DOTCOMMA_TOKEN
				 | vazio
				 ;

lista_de_ids: ID_TOKEN lista_de_ids COMMA_TOKEN ID_TOKEN
			| ID_TOKEN COMMA_TOKEN ID_TOKEN
			;


literal: INT_TOKEN { printf("putting integer %i in stack\n", $1); putNumberInStack($1); }
	   ;	//| FLOAT_TOKEN { putNumberInStack($2); }  e bool_lit

op_ad: ADD_TOKEN {$$ = $1}
	 | SUB_TOKEN {$$ = $1}
	 | OR_TOKEN  {$$ = $1}
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

programa: PROGRAM_TOKEN { generateHeader(); generateMainHeader();} ID_TOKEN DOTCOMMA_TOKEN corpo END { 
													  // (6) Se os comandos desse bloco forem executados então...
													  // ... a sentença (programa) pode ser gerada pela gramática (o...
													  // ... programa está sintáticamente correto).
													  generateFooter();
													  printf("\nPrograma valido\n");
													}
		;
				
seletor: seletor BLEFT_TOKEN expressao BRIGHT_TOKEN 
	   | BLEFT_TOKEN expressao BRIGHT_TOKEN
	   | vazio
	   ;

termo: termo op_mul fator 	{ putOpInStack($2); }
	 | fator 				{ }
	 ;

tipo: tipo_agregado
	| tipo_simples
	;

tipo_agregado: ARRAY_TOKEN BLEFT_TOKEN literal BRIGHT_TOKEN OF_TOKEN tipo
			 ;

tipo_simples: INTEGER_TOKEN | REAL_TOKEN | BOOLEAN_TOKEN
		    ;

variavel: ID_TOKEN { $$ = (char *)malloc(sizeof(char)*strlen($1)); strcpy($$, $1);}
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

void generateHeader(){
	f = fopen("output.j", "w+");
	fprintf(f, ".source input_code.txt\n.class public test\n.super java/lang/Object\n");
	fprintf(f, ".method public <init>()V\n");
	fprintf(f, "	aload_0\n");
	fprintf(f, "	invokenonvirtual java/lang/Object/<init>()V\n");
	generateFooter();
}

void generateFooter(){
	f = fopen("output.j", "a");
	fprintf(f, "return\n");
	fprintf(f, ".end method\n\n");
}

void generateMainFooter(){
	f = fopen("output.j", "a");
	fprintf(f, "return\n");
	fprintf(f, ".end method\n");
}

void generateMainHeader(){
	f = fopen("output.j", "a");
	fprintf(f, ".method public static main([Ljava/lang/String;)V\n");
	fprintf(f, ".limit locals 100\n");
	fprintf(f, ".limit stack 100\n");

}

void atributeVariable(char *id){
	f = fopen("output.j", "a");
	int stackLocal = getLocation(id);
	if(stackLocal == -1){
		numberOfUsedStackLocation++;
		stackLocal = numberOfUsedStackLocation;
	}
	fprintf(f, ".istore %i\n", stackLocal);
	printf("Setting variable %s stackLocal as %i\n", id, stackLocal);
	setLocation(id, stackLocal);
}

void putNumberInStack(int value){
	f = fopen("output.j", "a");
	printf(".bipush %i\n", value);
	fprintf(f, ".bipush %i\n", value);
}

void putOpInStack(char op){
	f = fopen("output.j", "a");
	if(op == '+') fprintf(f, ".iadd\n");
	else if(op == '-') fprintf(f, ".isub\n");
	else if(op == '*') fprintf(f, ".imul\n");
	else fprintf(f, ".div\n");
}

void loadVariableValue(int stackLocal){
	f = fopen("output.j", "a");
	fprintf(f, ".iload %i\n", stackLocal);
}