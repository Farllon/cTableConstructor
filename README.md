# cTableConstructor
 Esta é uma biblioteca simples para criar tabelas que se auto formatam em c
 
 ## Como isto funciona
Adicione os arquivos table.c e table.h na pasta do seu projeto, e no seu arquivo principal chame a biblioteca #include "table.c".

Para a criação da tabela, crie um arquivo txt na pasta do seu projeto. Seu arquivo vai depender do tamanho da sua tabela. Os itens tem de ser secritos um em cada linha e o programa irá lê-los do primeiro para o último. Por exemplo, uma tabela com 5 linhas e 3 colunas ficará assim:

![txt](https://github.com/Farllon/cTableConstructor/blob/master/text.PNG)

Como minha tabela terá 3 colunas, as três primeiras linhas serão a cabeçalho da tabela e o resto são os dados. Obs: O cabeçalho também é contado como linha da tabela. Lembre-se também de deixar a ultima linha do arquivo em branco para que o algorítimo funcione bem.

No arquivo principal, crie a seguinte estrutura:

Table * minhaTabela = create_table(numeroLinhas, numeroColunas, quantidadeCaractersMaximoPalavra, "nomeDoTxt");

No numeroLinhas substitua por um inteiro com o número de linhas da sua tabela, neste caso 5.
No numeroColunas substitua por um inteiro com o número de colunas da sua tabela, neste caso 2.
Na quantidadeCaractersMaximoPalavra substitua por um inteiro que será qual o máximo de chars que uma palavra poderá conter, neste caso vou colocar 5.
No nomeDoTxt substitua pelo nome do seu arquivo txt, exemplo: "tabela.txt".

Após isso para imprimir a tabela, faça o seguinte:

print_table(minhaTabela);

Observações:

- Se um dos campos tiver que ser vazio , não pule a linha . Simplismente escreva vazio no txt;

A saída deste exemplo será:

![Output](https://github.com/Farllon/cTableConstructor/blob/master/output.PNG)
