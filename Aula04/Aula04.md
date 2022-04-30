# Analisador Sintático
É responsável por obter uma sequência de **tokens** do **analisador léxico** e verifica se estes seguem as regras gramáticais, podendo realizar a análise a partir dos seguintes modelos de métodos:
1. Métodos **top-down** (descendente): verifica se há uma árvore de derivação, partindo da raiz para a derivação mais à esquerda.
  - **Análise Preditiva**: utilização da fatoração à esquerda e eliminação da recursividade à esquerda para criar a regra gramatical.

