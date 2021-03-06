#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

struct tNo_B *criaNo_B(int chave)
{
    struct tNo_B *n = (struct tNo_B *)malloc(sizeof(struct tNo_B));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

struct tNo_B *inclui_B(struct tNo_B *no, int c)
{
    if (no == NULL)
        return criaNo_B(c);
    if (c < no->chave)
    {
        no->esq = inclui_B(no->esq, c);
    }
    else
    {
        no->dir = inclui_B(no->dir, c);
    }
    return no;
}

int chars_para_int(const char *str, int *indice)
{
    char numero[10];
    int i;
    for (i = 0; str[*indice] > 47; i++)
    {
        numero[i] = str[*indice];
        (*indice)++;
    }
    numero[i] = '\0';
    return atoi(numero);
}

struct tNo_B *montaarvore_B(const char *str)
{
    struct tNo_B *raiz = NULL;
    int i = 1; /* o "0" seria o primeiro "(" */
    raiz = inclui_B(NULL, chars_para_int(str, &i));
    while (str[i] == ')' || str[i] == '(') /* pra passar para o proximo numero na string, nao parentese */
        i++;

    while (str[i] != '\n')
    {
        inclui_B(raiz, chars_para_int(str, &i));

        while (str[i] == ')' || str[i] == '(')
            i++;
    }

    return raiz;
}

int soma_arvore(struct tNo_B *no)
{
    /* soma os numeros nos nós da arvore contida */
    if (no == NULL)
        return 0;

    return (no->chave + soma_arvore(no->esq) + soma_arvore(no->dir));
}

int soma_entrada(char *bonsai)
{
    int i = 0;
    int soma = 0;
    while (bonsai[i] != '\0')
    {
        if (bonsai[i] > 47)
        { /* se for um numero */
            soma += chars_para_int(bonsai, &i);
        }
        else
            i++;
    }

    return soma;
}

struct tNo_A *criaNo(struct tNo_B *chave)
{
    struct tNo_A *n = (struct tNo_A *)malloc(sizeof(struct tNo_A));

    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}

struct tNo_A *inclui(struct tNo_A *no, char *bonsai)
{
    if (no == NULL)
        return criaNo(montaarvore_B(bonsai));

    if (soma_entrada(bonsai) < soma_arvore(no->chave)) /* se a arvore sendo incluida tiver soma menor que a arvore no no atual */
    {
        no->esq = inclui(no->esq, bonsai);
        no->esq->pai = no;
    }
    else
    {
        no->dir = inclui(no->dir, bonsai);
        no->dir->pai = no;
    }
    return no;
}

void imprime_noh_A(struct tNo_B *no)
{
    if (no == NULL)
        return;

    printf("(%d", no->chave);
    imprime_noh_A(no->esq);
    imprime_noh_A(no->dir);
    printf(")");
    return;
}

struct tNo_A *busca(struct tNo_A *no, int chave)
{
    if (!no){
        printf("busca falhou (nao foi possivel encontrar '%d')\n", chave);
        return NULL;
    }

    imprime_busca(no);

    if (soma_arvore(no->chave) == chave)
        return no;
    if (chave < soma_arvore(no->chave))
        return busca(no->esq, chave);
    else
        return busca(no->dir, chave);
}

struct tNo_A *busca_silenciosa(struct tNo_A *no, int chave)
{
    /* nao imprime a sequencia de nodos percorridos, 
    como pedido no enunciado para a saida da busca.
    funcao para ser utilizada em conjunto com a exclusao,
    de modo a nao poluir a saida da ultima */

    if (!no)
        return NULL;

    if (soma_arvore(no->chave) == chave)
        return no;
    if (chave < soma_arvore(no->chave))
        return busca_silenciosa(no->esq, chave);
    else
        return busca_silenciosa(no->dir, chave);
}

struct tNo_A *min(struct tNo_A *no)
{
    if (no->esq == NULL)
        return no;
    else
        return min(no->esq);
}

struct tNo_A *sucessor(struct tNo_A *no)
{
    struct tNo_A *s = NULL;
    if (no->dir != NULL)
        return min(no->dir);
    else
    {
        s = no->pai;
        while (s != NULL && no == s->dir)
        {
            no = s;
            s = s->pai;
        }
    }
    return s;
}

void ajustaNoPai(struct tNo_A *no, struct tNo_A *novo)
{
    if (no->pai != NULL)
    {
        if (no->pai->esq == no)
            no->pai->esq = novo;
        else
            no->pai->dir = novo;
        if (novo != NULL)
            novo->pai = no->pai;
    }
}

struct tNo_A *exclui(struct tNo_A *no, struct tNo_A *raiz)
{
    if(!no || !raiz){
        printf("exclusao nao efetuada (nao foi encontrada uma sub-arvore com o valor de indexacao desejado)\n");
        return NULL;
    }

    struct tNo_A *s, *novaRaiz = raiz;
    if (no->esq == NULL)
    {
        ajustaNoPai(no, no->dir);
        free(no);
    }
    else
    {
        if (no->dir == NULL)
        {
            ajustaNoPai(no, no->esq);
            free(no);
        }
        else
        {
            s = sucessor(no);
            ajustaNoPai(s, s->dir);
            s->esq = no->esq;
            s->dir = no->dir;
            ajustaNoPai(no, s);
            if (no == raiz)
                novaRaiz = s;
            free(no);
        }
    }
    return novaRaiz;
}

void imprime_busca(struct tNo_A *no)
{
    imprime_noh_A(no->chave);
    printf(" : %d\n", soma_arvore(no->chave));
}

void imprime_arvore_A(struct tNo_A *no)
{
    printf("[");

    imprime_noh_A(no->chave);
    printf(" : %d\n", soma_arvore(no->chave));

    if (no->esq != NULL)
        imprime_arvore_A(no->esq);
    else if (no->dir != NULL)
        printf("[\n]\n");

    if (no->dir != NULL)
        imprime_arvore_A(no->dir);
    else if (no->esq != NULL)
        printf("[\n]\n");

    printf("]\n");
}