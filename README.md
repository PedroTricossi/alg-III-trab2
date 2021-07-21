# alg-III-trab2

## Autores
  Este trabalho for realizado inteiramente por Pedro Tricossi (GRR20203895) e Thomas Todt (<Colocar GRR>)
  
## Implementação
  Para ambas as árvores do trabalho foram utilizadas Árvores Binárias de Busca (BST) e árvores binárias. Sendo a árvore A uma BST e também a árvore principal e a Arvore B uma árvore binária, a árvore que serve como chave para a indexação da primeira.

  Para a implementação deste algoritmo foram utilizadas 3 funções principais, sendo elas inclusão, exclusão e busca. Para mostrar o resultados das operações foi implementada também uma função de impressão de árvore.

### Inclusão
  A função de inserção recebe dois parametros, sendo um deles a árvore A, e o segundo um ponteiro apontando para uma string que virá a se tornar a árvore B e chave da árvore A.
  
  O funcionamento da função é baseado na BST apresentadas em sala, e seguindo sempre as políticas de árvore binária. O diferencial para essa versão da árvore é que ao invés de passar como argumento para criar o nó um inteiro é passado um struct (criada pela função montaarvore_B)

### Busca
  A função de busca recebe também dois parametros, sendo um deles a árvore A e o segundo a soma da árvore fornecida via stdin.
  
  Para realizar a buscar um nó dentro da árvore são utilizadas as mesmas politicas de uma BST padrão, com a unica diferença que a comparação é feita entre um inteira (fornecido como parametro da função), e a soma da árvore B.

### Exclusão
  A função de exclusão também recebe dois parametros, sendo um deles a árvore A, e o segundo o nó que será excluido da árvore (esse nó é dado a função utilizando a função de busca).
  
  Para realizar a exclusão de um nó são utilizadas as mesmas políticas de exclusão de uma BST, como o nó que será excluido já vem como parametro da função, essa não possiu nenhuma diferença de implementação em relação a função da árvore exposta em aula.
  
### Impressão
  Para a impressão foi criada uma função para imprimir árvore utilizando o padrão de parenteses, porém neste caso os parentes fora substituidos por chaves, para uma melhor visualização.
  
  Foram também seguidos os protocolos de impressão especificado nos exemplos dados no enunciado do trabalho.
  
### Observações
  Foram deixados no trabalhos as funções utilizadas para debug do mesmo, por conta disso podem haver algumas funções no código que não estão sendo utilizadas de maneira direta dentro do programa.
