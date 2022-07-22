bison -d calculadora.y
flex calculadora.lex
gcc calculadora.tab.c lex.yy.c -o calculadora -lm
type teste.txt | .\calculadora.exe