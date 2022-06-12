bison -d Trabalho02.y
flex Trabalho02.lex
gcc Trabalho02.tab.c lex.yy.c -o Trabalho02 -lm
type teste.txt | .\Trabalho02.exe