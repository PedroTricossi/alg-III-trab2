struct tNo_A
{
    struct tNo_B *chave;
    struct tNo_A *esq, *dir, *pai;
};

struct tNo_B
{
    int chave;
    struct tNo_B *esq, *dir;
};

struct tNo_B *criaNo_B(int chave);

struct tNo_B *inclui_B(struct tNo_B *no, int c);

int chars_para_int(const char *str, int *indice);

struct tNo_B *montaarvore_B(const char *str);

int soma_arvore(struct tNo_B *no);

int soma_entrada(char *bonsai);

struct tNo_A *criaNo(struct tNo_B *chave);

struct tNo_A *inclui(struct tNo_A *no, char *bonsai);

void imprime_noh_A(struct tNo_B *no);

struct tNo_A *busca(struct tNo_A *no, int chave);

struct tNo_A *busca_silenciosa(struct tNo_A *no, int chave);

struct tNo_A *min(struct tNo_A *no);

struct tNo_A *sucessor(struct tNo_A *no);

void ajustaNoPai(struct tNo_A *no, struct tNo_A *novo);

struct tNo_A *exclui(struct tNo_A *no, struct tNo_A *raiz);

void imprime_busca(struct tNo_A *no);

void imprime_arvore_A(struct tNo_A *no);