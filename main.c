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

        switch (comando)
        {
        case 'i':

            if (raiz == NULL)
                raiz = inclui(raiz, ptr_bonsai);
            else
                inclui(raiz, ptr_bonsai);
            imprime_arvore_A(raiz);

            printf("-----------------------------------------------------------------------------\n");

            break;

        case 'b':

            busca(raiz, soma_entrada(ptr_bonsai));

            printf("-----------------------------------------------------------------------------\n");

            break;

        case 'r':

            if ((exclui(busca_silenciosa(raiz, soma_entrada(ptr_bonsai)), raiz)) != NULL) /*realiza a exclusao e checa se ocorreu*/
                imprime_arvore_A(raiz); /*se nao ocorreu, nao imprime*/

            printf("-----------------------------------------------------------------------------\n");

            break;
        }
    }

    return 0;
}