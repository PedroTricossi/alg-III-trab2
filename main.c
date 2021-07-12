#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

int main(void)
{
    struct tNo_A raiz;

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
            inclui(&raiz, ptr_bonsai);
            break;
        case 'b':

            if (busca(&raiz, soma_entrada(ptr_bonsai)) != NULL)
            {
                printf("Encontrado");
            }
            break;
        case 'r':
            exclui((busca(&raiz, soma_entrada(ptr_bonsai))), &raiz);
            break;
        }
    }

    return 0;
}