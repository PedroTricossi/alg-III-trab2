# alg-III-trab2

## Autores
  Este trabalho for realizado inteiramente por Pedro Tricossi (GRR20203895) e Thomas Todt (GRR20203910)
  
## Implementação
  Para ambas as árvores do trabalho foram utilizadas Árvores Binárias de Busca (BST) e árvores binárias. Sendo a árvore A uma BST e também a árvore principal e a Arvore B uma árvore binária, a árvore que serve como chave para a indexação da primeira.

  Para a implementação deste algoritmo foram utilizadas 3 funções principais, sendo elas inclusão, exclusão e busca. Para mostrar o resultados das operações foi implementada também uma função de impressão de árvore.

### Inclusão
  A função de inserção recebe dois parametros, sendo um deles a árvore A, e o segundo um ponteiro apontando para uma string que virá a se tornar a árvore B e chave da árvore A.
  
  O funcionamento da função é baseado na BST apresentadas em sala, e seguindo sempre as políticas de árvore binária. O diferencial para essa versão da árvore é que ao invés de passar como argumento para criar o nó um inteiro é passado um struct (criada pela função montaarvore_B)

### Busca
  A função de busca recebe também dois parametros, sendo um deles a árvore A e o segundo a soma da árvore fornecida via stdin.
  
  Para buscar um nó dentro da árvore são utilizadas as mesmas politicas de uma BST padrão, com a unica diferença sendo que a comparação é feita entre um inteiro (fornecido como parametro da função) e o valor de indexacao da sub-arvore que esta no nodo passado, dado pela soma dos valores nos nodos da árvore B.

### Exclusão
  A função de exclusão também recebe dois parametros, sendo um deles a árvore A, e o segundo o nó que será excluido da árvore (esse nó é dado a função utilizando a função de busca).
  
  Para realizar a exclusão de um nó são utilizadas as mesmas políticas de exclusão de uma BST, como o nó que será excluido já vem como parametro da função, essa não possiu nenhuma diferença de implementação em relação a função da árvore exposta em aula.
  
### Impressão
  Para a impressão foi criada uma função para imprimir árvore utilizando o padrão de parenteses, porém neste caso os parentes foram substituidos por chaves, para uma melhor visualização, buscando diferenciar a arvore principal A das arvores B que estao em seus nodos.
  
  Foram também seguidos os protocolos de impressão especificado nos exemplos dados no enunciado do trabalho.
  
### Outras Funções
  Alem das funcoes normalmente necessarias para a funcionalidade adequada das arvores, tambem foi necessaria a criacao de duas funcoes em particular para a resolucao do trabalho como enunciado. Uma realiza a soma dos valores que estariam nos nodos de uma entrada com o padrao de parenteses (soma_entrada, que recebe um ponteiro para char, essencialmente a string de entrada), enquanto a outra faz uma soma similar, mas a partir da arvore que foi montada a partir de uma entrada como a da primeira, ja estando presente na arvore A (soma_arvore, que recebe um ponteiro para nodo do tipo da arvore B)
