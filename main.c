#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

int main(void)
{
    struct tNo_A *raiz = NULL;

    char bonsai[100];
    char comando;
    char *ptr_bonsai;

    size_t len;
    size_t read;

    ptr_bonsai = bonsai;
    len = 100;

    while ((read = getline(&ptr_bonsai, &len, stdin)) != -1)
    {
        comando = ptr_bonsai[0];

        ptr_bonsai++;
        ptr_bonsai++;

        if (comando == 105)
        {
            printf("entrou");
            inclui(raiz, ptr_bonsai);
        }
    }

    return 0;
}