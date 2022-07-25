bison -d simpleCalculator.y
flex simpleCalculator.lex
gcc simpleCalculator.tab.c lex.yy.c -o simpleCalculator -lm
.\simpleCalculator.exe