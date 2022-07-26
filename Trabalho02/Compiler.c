#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Compiler.h"

headTable *fila = NULL;
int numberOfTokens = 0;
int numberOfUsedStackLocation = 0; // (1) Ao armazenar nova variável na pilha armazene-a em numberOfUsedStackLocation + 1
int num_lines = 0;
int num_columns = 0;
FILE *f;

void setTypeID(char *id, char *type){
	table *auxTable = fila->first;
	while(auxTable != NULL) if(strcmp(auxTable->token, id) == 0) auxTable->type = type;
}

void setLocation(char *string, int stackLocation){
	table *auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token, string) == 0) auxTable->stackLocation = stackLocation;
		auxTable = auxTable->next;
	}
	return;
}

int getLocation(char *string){
	if(fila == NULL) return -1;
	table *auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token,string) == 0) return auxTable->stackLocation;
		auxTable = auxTable->next;
	}
	return -1;
}

char *getLastID(){
	table *auxTable = fila->last;
	while(auxTable != NULL){
		if(strcmp(auxTable->about, "id") == 0) return auxTable->token;
		auxTable = auxTable->before;
	}
	return NULL;
}

void addToken(char *string){
    if(fila == NULL) fila = createHeadTable(string);
	else{
		table *newToken;
		newToken = createTable(string);
		fila->last->next = newToken;
		newToken->before = fila->last;
		newToken->stackLocation = getLocation(string);
		fila->last = newToken;
	}
	num_columns += strlen(string);
}

void setAbout(char *string){
	fila->last->about = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->about, string);
}

void setType(char *string){
	fila->last->type = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->type, string);
}

void tableMain(){
	table *aux;
	aux = (table *)malloc(sizeof(table));
	aux = fila->first;

	FILE *filePointer;
    filePointer = fopen("resultado.txt", "w+");
    fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|                               Tabela de simbolos                              |\n");
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	fprintf(filePointer, "|\tToken\t|\tSobre\t\t|\tTamanho\t|\tLinha\t|\tColuna\t|\tStackLocal\t\t|\n");
	for(int i = 0; i < numberOfTokens; i++){
		fprintf(filePointer, "|\t%s\t|\t%s\t\t|\t%i\t|\t%i\t|\t%i\t|\t%i\t\t|\n", aux->token, aux->about, aux->lenght, aux->line, aux->column, aux->stackLocation);
		aux = aux->next;
	}
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	printf("# total de linhas = %d\n", num_lines+1);
}

table *createTable(char *string){
	numberOfTokens++;
	table *newToken;
	newToken = (table *)malloc(sizeof(table));
	newToken->token = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(newToken->token, string);
	newToken->lenght = strlen(string);
	newToken->line = num_lines;
	newToken->column = num_columns;
	newToken->about = NULL;
	newToken->type = NULL;
	newToken->before = NULL; 
	newToken->next = NULL;
	newToken->stackLocation = -1;
}

headTable *createHeadTable(char *string){
	fila = (headTable *)malloc(sizeof(headTable));
	fila->first = createTable(string);
	fila->last = fila->first;
}


void generateHeader(){
	f = fopen("output.j", "w+");
	fprintf(f, ".source teste.txt\n.class public test\n.super java/lang/Object\n");
	fprintf(f, ".method public <init>()V\n");
	fprintf(f, "	aload_0\n");
	fprintf(f, "	invokenonvirtual java/lang/Object/<init>()V\n");
	generateFooter();
}

void generateMainFooter(){
	f = fopen("output.j", "a");
	fprintf(f, "return\n");
	fprintf(f, ".end method");
}

void generateFooter(){
	f = fopen("output.j", "a");
	fprintf(f, "return\n");
	fprintf(f, ".end method\n\n");
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

createHeaderListOfStrings(){

}

createListOfStrings(char *newString){

}

void addToStringList(stringListHead *HeaderListOfStrings, char *newString){
	stringList *auxListOfStrings = HeaderListOfStrings->first;
	if(auxListOfStrings == NULL) auxListOfStrings = createListOfStrings(newString);
	else while
}