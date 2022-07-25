flex calculadora.lex
bison -d calculadora.y

gcc calculadora.tab.c lex.yy.c -o calculadora -lm
type teste.txt |.\calculadora.exe