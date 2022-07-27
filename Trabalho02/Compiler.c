#include "Compiler.h"

headTable *fila = NULL;
int numberOfTokens = 0;
int numberOfUsedHeapLocation = 0; // (1) Ao armazenar nova variável na pilha armazene-a em numberOfUsedHeapLocation + 1
int num_lines = 0;
int num_columns = 0;
int count_label = 0;
FILE *f;

// (1) Def.: essa função recebe a string de um ID e a string de um tipo e percorre a tabela de símbolos...
// ... de modo que quando acha um elemento da tabela com o atributo Token igual ao ID recebido, coloca...
// ... o atributo de tipo de tal elemento igual ao tipo do recebido pela função. 
void setTypeID(char *id, char *type){
	table *auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token, id) == 0) auxTable->type = type;
		auxTable = auxTable->next;
	}
}

// (2) Def.: essa função recebe um id e uma localização da heap de variáveis (do assembly code) e anota...
// ... tal localização em no atributo stackLocation de toda ocorrência do ID na tabela de símbolos.
void setLocation(char *id, int heapLocation){
	table *auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token, id) == 0) auxTable->heapLocation = heapLocation;
		auxTable = auxTable->next;
	}
	return;
}

// (3) Def.: essa função recebe um id e busca alguma ocorrência do mesmo na tabela de símbolos e então...
// ... retorna o atributo heapLocation (localização na heap de símbolos do assembly code) associado ao id.
int getLocation(char *id){
	if(fila == NULL) return -1;
	table *auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token, id) == 0) return auxTable->heapLocation;
		auxTable = auxTable->next;
	}
	return -1;
}

// (4) Def.: essa função retorna o último id registrado na tabela de símbolos.
char *getLastID(){
	table *auxTable = fila->last;
	while(auxTable != NULL){
		if(strcmp(auxTable->about, "id") == 0) return auxTable->token;
		auxTable = auxTable->before;
	}
	return NULL;
}

// (5) Def.: recebe a string (yytext) de um token e então adiciona um registro desse token na tabela de símbolos.
void addToken(char *string){
    if(fila == NULL) fila = createHeadTable(string);
	else{
		table *newToken;
		newToken = createTable(string);
		fila->last->next = newToken;
		newToken->before = fila->last;
		newToken->heapLocation = getLocation(string);
		fila->last = newToken;
	}
	num_columns += strlen(string);
}

// (6) Def.: recebe uma descrição e atribui esta ao atributo "about" do último símbolo posto na tabela de símbolos.
void setAbout(char *string){
	fila->last->about = (char *)malloc(sizeof(char)*strlen(string));
	strcpy(fila->last->about, string);
}

// (7) Def.: imprime a tabela de símbolos em um arquivo texto.
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
		fprintf(filePointer, "|\t%s\t|\t%s\t\t|\t%i\t|\t%i\t|\t%i\t|\t%i\t\t|\n", aux->token, aux->about, aux->lenght, aux->line, aux->column, aux->heapLocation);
		aux = aux->next;
	}
	fprintf(filePointer, "---------------------------------------------------------------------------------\n");
	printf("# total de linhas = %d\n", num_lines+1);
}

// (8) Def.: cria uma cabeça de tabela de símbolos. 
table *createTable(char *string){
	numberOfTokens++;
	table *newToken;
	newToken = (table *)malloc(sizeof(table));
	newToken->token = strdup(string);
	newToken->lenght = strlen(string);
	newToken->line = num_lines;
	newToken->column = num_columns;
	newToken->about = NULL;
	newToken->type = NULL;
	newToken->before = NULL; 
	newToken->next = NULL;
	newToken->heapLocation = -1;
}

// (9) Def.: cria um elemento na tabela de símbolos.
headTable *createHeadTable(char *string){
	fila = (headTable *)malloc(sizeof(headTable));
	fila->first = createTable(string);
	fila->last = fila->first;
}

int simbolExists(char *id){
	if(fila == NULL || fila->first == NULL) return 1;
	table *auxTable;
	auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token, id) == 0) return 0;
		auxTable = auxTable->next; 
	}
	return 1;
}

char *getSymbolType(char *id){
	if(fila == NULL || fila->first == NULL) return "noType";
	table *auxTable;
	auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token, id) == 0){
			if(auxTable->type != NULL) return auxTable->type;
			else return "noType";
		}
		auxTable = auxTable->next; 
	}
	return "noType";
}

int verifySymbolType(char *id, char *type){
	if(fila == NULL || fila->first == NULL) return 1;
	table *auxTable;
	auxTable = fila->first;
	while(auxTable != NULL){
		if(strcmp(auxTable->token, id) == 0){
			if(strcmp(auxTable->type, type) == 0) return 0;
			else return 1;
		}
		auxTable = auxTable->next; 
	}
	return 1;
}

// (12) Def.: criar o arquivo e gera o cabeçalho do código resultante da tradução dirigida por sintaxe
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

void atributeIntVariable(char *id){
	f = fopen("output.j", "a");
	int heapLocation = getLocation(id);
	if(heapLocation == -1){
		numberOfUsedHeapLocation++;
		heapLocation = numberOfUsedHeapLocation;
	}
	fprintf(f, "istore %i\n", heapLocation);
	printf("Setting variable %s stackLocal as %i\n", id, heapLocation);
	setLocation(id, heapLocation);
}

void atributeFloatVariable(char *id){
	f = fopen("output.j", "a");
	int heapLocation = getLocation(id);
	if(heapLocation == -1){
		numberOfUsedHeapLocation++;
		heapLocation = numberOfUsedHeapLocation;
	}
	fprintf(f, "fstore %i\n", heapLocation);
	printf("Setting variable %s stackLocal as %i\n", id, heapLocation);
	setLocation(id, heapLocation);
}

void putIntInStack(int value){
	f = fopen("output.j", "a");
	printf("bipush %i\n", value);
	fprintf(f, "bipush %i\n", value);
}

void putFloatInStack(float value){
	f = fopen("output.j", "a");
	printf("bipush %f\n", value);
	fprintf(f, "bipush %f\n", value);
}

void putOpInStack(char op){
	f = fopen("output.j", "a");
	if(op == '+') fprintf(f, "iadd\n");
	else if(op == '-') fprintf(f, "isub\n");
	else if(op == '*') fprintf(f, "imul\n");
	else fprintf(f, "div\n");
}

void loadVariableValue(int heapLocation){
	f = fopen("output.j", "a");
	fprintf(f, "iload %i\n", heapLocation);
}

book *createBook(){
	book *newStringListHead;
	newStringListHead = (book *)malloc(sizeof(book));
	newStringListHead->first = NULL;
	newStringListHead->last = NULL;
	return newStringListHead;
}

bookPage *createBookPage(char *newString){
	bookPage *newStringList;
	newStringList = (bookPage *)malloc(sizeof(bookPage));
	newStringList->string = strdup(newString);
	newStringList->next = NULL;
	return newStringList;
}

void addString(book *headerListOfStrings, char *newString){
	if(headerListOfStrings->first == NULL){
		headerListOfStrings->first = createBookPage(newString);
		headerListOfStrings->last = headerListOfStrings->first;
	}
	else{
		headerListOfStrings->last->next = createBookPage(newString);
		headerListOfStrings->last = headerListOfStrings->last->next;
	}
}

void addStringsFrom(book *newBook, book *oldBook){
	bookPage *auxPage;
	auxPage = oldBook->first;
	while(auxPage != NULL){
		addString(newBook, auxPage->string);
		auxPage = auxPage->next;
	}
}

void setBookType(book *listOfID, char *type){
	bookPage *auxPage;
	auxPage = listOfID->first;
	while(auxPage != NULL){
		printf("setting ID %s as type %s\n", auxPage->string, type);
		setTypeID(auxPage->string, type);
		auxPage = auxPage->next;
	}
	free(listOfID);
}

char *numType(double val){
    int truncated = (int)val;
    if(val == truncated) return "integer";
	else return "float";
}

void cmpVarNumberType(char *variableType, char *numberType){
	if(strcmp(variableType, "real") == 0) return;
	if(strcmp(variableType, numberType) != 0) printf("Warning: variavel de tipo %s atribuida a %s\n", variableType, numberType);
}

void intToFloat(){
	f = fopen("output.j", "a");
	fprintf(f, "i2f\n");
}

void floatToInt(){
	f = fopen("output.j", "a");
	fprintf(f, "f2i\n");
}

void ifStack(char *op){
	f = fopen("output.j", "a");
	if(strcmp(op, "=") == 0) fprintf(f, "ifeq");
	else if(strcmp(op, ">") == 0) fprintf(f, "ifgt");
	else if(strcmp(op, ">=") == 0) fprintf(f, "ifge");
	else if(strcmp(op, "<") == 0) fprintf(f, "iflt");
	else if(strcmp(op, "<=") == 0) fprintf(f, "ifle");
	else fprintf(f, "ifne");
}

void onlylabel(int label){
	f = fopen("output.j", "a");
	fprintf(f, "L_%i:\n", label);
}

void labelGoToLabel(int label1, int label2){
	f = fopen("output.j", "a");
	fprintf(f, " L_%i\n", label1);
	fprintf(f, "goto L_%i\n", label2);
}
