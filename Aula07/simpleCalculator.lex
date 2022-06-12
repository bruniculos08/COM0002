%option noyywrap
%{ 
// (1) Colocar linhas entre "%colchetes" e "%colchetes" permite que se escreva código em C nestas linhas:	
#include <stdio.h>
#include <string.h>
// (2) Deve-se declarar a função de erro (para quando um token não corresponde a nenhuma expressão regular):
#define YY_DECL int yylex()

#include "simpleCalculator.tab.h"
%}

/* (3) Definições de conjuntos de símbolos com o auxílio de expressões regulares (isto não é algo obrigatório,...
   ... mas pode simplificar alguns itens da próxima etapa): */
DIGITO [0-9]
NUM {DIGITO}+

/* (4) Definição do que ocorre qunando se encontra cada token:
   Obs.: aqui também podem se utilizar expressões regulares.*/
%%

\n     { // (10) Quando há "avanço de linha" não é necessário fazer nada (não é token a ser reconhecido):
         return JUMP_LINE;
       }

{NUM} { // (5) A varíavel global yylval é usada para passar o valor semántico associado à um token do analisador...
        // ... léxico para o analisador sintático, por isso, neste caso o valor a ser passado deve ser o valor do...
        // ... texto lido convertido para um inteiro, visto que queremos fazer uma calculadora:
        yylval.ival = atoi(yytext);

        // (6) As variáveis retornadas em blocos de código como este, em arquivos flex, podem, assim como quaisquer...
        // ... outras variáveis serem declaradas no código bison (do analisador sintático):
        return NUMBER;
      }

[+()-/]   { // (7) Quando se retorna o conteúdo do endereço yytext, está se retornando o que foi lido sem nenhuma...
            // ... alteração:
            if(*yytext == '+') return ADD;
            else if(*yytext == '-') return SUB;
            else if(*yytext == '*') return MULT;
            else if(*yytext == '(') return P_LEFT;
            else if(*yytext == ')') return P_RIGHT;
            else return DIVIDE;
          }

[ \t]+  {
         // (9) Quando há espaçamento em branco não é necessário fazer nada (não é token a ser reconhecido).
         // Obs.: note que a expressão regular "[ \t]+" significa 1 ou mais espaçamentos.
        }

.      {
        // (11) Qualquer outro caracter digitado é um erro:
        yyerror("Caracter inválido.\n");
       }

%%

// (12) Como iremos utilizar um código bison também não é necessário colocar aqui uma função "main".