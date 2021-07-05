#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

int main(void)
{
    struct tNo_A *raiz = NULL;
    char entrada[] = "\0";

    char comando;
    char bonsai[100];
    char continuar = 'y';

    while (continuar == 'y')
    { /* na verdade, tem que dar um jeito disso ler um arquivo ate o final */
        printf("Digite o comando para árvore: ");
        scanf(" %c", &comando);
        printf("digite a árvore chave: ");
        scanf(" %s", bonsai);

        switch (comando)
        {
        case 'i':
            inclui(raiz, bonsai);
            break;
        case 'b':
            busca(raiz, soma_entrada(bonsai));
            break;
        case 'r':
            exclui((busca(raiz, soma_entrada(bonsai))), raiz);
            break;
        }
        printf("continuar? (y/n): ");
        scanf(" %c", &continuar);
    }
    /*emordem(raiz);*/

    return 0;
}