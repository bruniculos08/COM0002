flex Trabalho02.lex
bison -d Trabalho02.y --warnings cex
gcc Trabalho02.tab.c lex.yy.c Compiler.c -o Trabalho02 -lm
type teste.txt | .\Trabalho02.exe
java -jar C:\Users\bruni\Downloads\jasmin-2.4\jasmin.jar output.j
java test