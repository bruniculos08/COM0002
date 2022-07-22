flex Trabalho02.lex
bison -d Trabalho02.y
gcc Trabalho02.tab.c lex.yy.c -o Trabalho02 -lm
type teste.txt | .\Trabalho02.exe