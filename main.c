#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

int main(void)
{
    struct tNo_A raiz;

    char comando;
    char bonsai[100];

    do
    {
        scanf(" %c", &comando);
        scanf(" %s", bonsai);

        switch (comando)
        {
        case 'i':
            inclui(&raiz, bonsai);
            break;
        case 'b':

            if (busca(&raiz, soma_entrada(bonsai)) != NULL)
            {
                printf("Encontrado");
            }
            break;
        case 'r':
            exclui((busca(&raiz, soma_entrada(bonsai))), &raiz);
            break;
        }

    } while (comando != 'f');

    return 0;
}