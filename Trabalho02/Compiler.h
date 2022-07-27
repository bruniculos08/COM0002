#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int yylex(); 
int yyparse();
FILE* yyin;

typedef struct Table table;
struct Table {
    char *token;
	char *about;
	char *type;
    int lenght;
    int line;
    int column;
	int heapLocation;
	table *before;
	table *next;
};

typedef struct HeadTable headTable;
struct HeadTable {
	table *first;
	table *last;
};

void tableMain();
void setType(char *string);
void setAbout(char *string);
void addToken(char *string);
void setTypeID(char *id, char *type);
void setLocation(char *string, int stackLocation);
int getLocation(char *string);
int simbolExists(char *id);
char *getLastID();
table *createTable(char *string);
headTable *createHeadTable(char *string);

void loadVariableValue(int stackLocal);
void putIntInStack(int value);
void putFloatInStack(float value);
void putOpInStack(char op);
void atributeIntVariable(char *id);
void atributeFloatVariable(char *id);
void generateHeader();
void generateFooter();
void generateMainHeader();
void generateMainFooter();
void yyerror(const char* s);
char *getSymbolType(char *id);
char *numType(double val);
void cmpVarNumberType(char *variableType, char *numberType);

typedef struct BookPage bookPage;
struct BookPage{
	char *string;
	bookPage *next;
};

typedef struct Book book;
struct Book{
	bookPage *first;
	bookPage *last;
};

void addString(book *lista, char *newString);
void addStringsFrom(book *newBook, book *oldBook);
void setBookType(book *listOfID, char *type);
book *createBook();
bookPage *createBookPage(char *newString);