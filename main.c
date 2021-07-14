#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

int main(void)
{
    struct tNo_A *raiz = NULL;

    char comando;
    char bonsai[100];
    char *ptr_bonsai;
    size_t len;

    ptr_bonsai = bonsai;

    while ((getline(&ptr_bonsai, &len, stdin)) != -1)
    {
        comando = ptr_bonsai[0];
        ptr_bonsai++;
        ptr_bonsai++;

        printf("%s", ptr_bonsai);

        switch (comando)
        {
        case 'i':
            if(raiz == NULL) 
                raiz = inclui(raiz, ptr_bonsai);
            else
                inclui(raiz, ptr_bonsai);
            imprime_arvore_A(raiz);
            break;
        case 'b':

            if (busca(raiz, soma_entrada(ptr_bonsai)) != NULL)
            {
                printf("Encontrado\n");
            }
            else printf("nao encontrado\n");
            break;
        case 'r':
            exclui((busca(raiz, soma_entrada(ptr_bonsai))), raiz);
            imprime_arvore_A(raiz);
            break;
        }
    }

    return 0;
}