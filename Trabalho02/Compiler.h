#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Table table;
struct Table {
    char *token;
	char *about;
	char *type;
    int lenght;
    int line;
    int column;
	int stackLocation;
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
char *getLastID();
table *createTable(char *string);
headTable *createHeadTable(char *string);

void loadVariableValue(int stackLocal);
void putNumberInStack(int value);
void putOpInStack(char op);
void atributeVariable(char *id);
void generateHeader();
void generateFooter();
void generateMainHeader();
void generateMainFooter();
void yyerror(const char* s);

typedef struct StringListHead stringListHead;
struct StringListHead{
	stringList *first;
	stringList *last;
};

typedef struct StringList stringList;
struct StringList{
	char *string;
	stringList *next;
};


void addToStringList(stringListHead *HeaderListOfStrings, char *newString);