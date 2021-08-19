#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct tree
{
    TIPOCHAVE chave;
    struct tree *esq, *dir;
} NO;
typedef NO *Ponteiro;
Ponteiro inicializa()
{
    return (NULL);
}
Ponteiro criarNovoNo(TIPOCHAVE ch)
{
    Ponteiro novoNo = (Ponteiro)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return (novoNo);
}
Ponteiro insere(Ponteiro raiz, Ponteiro no)
{
    if (raiz == NULL)
        return (no);
    if (no->chave < raiz->chave)
    {
        raiz->esq = insere(raiz->esq, no);
    }
    else
    {
        raiz->dir = insere(raiz->dir, no);
    }
    return (raiz);
}
void mostrarArvorePrefixa(Ponteiro raiz)
{

    if (raiz != NULL)
    {
        printf(" ");
        printf("%i", raiz->chave);
        mostrarArvorePrefixa(raiz->esq);
        mostrarArvorePrefixa(raiz->dir);
    }
}
void mostrarArvoreInfixa(Ponteiro raiz)
{

    if (raiz != NULL)
    {
        mostrarArvoreInfixa(raiz->esq);
        printf(" ");
        printf("%i", raiz->chave);

        mostrarArvoreInfixa(raiz->dir);
    }
}
void mostrarArvorePosfixa(Ponteiro raiz)
{

    if (raiz != NULL)
    {
        mostrarArvorePosfixa(raiz->esq);
        mostrarArvorePosfixa(raiz->dir);
        printf(" ");
        printf("%i", raiz->chave);
    }
}
int main()
{

    int chave, numeroTestes, qtdNumeros;
    int i, n;

    Ponteiro no;
    scanf("%i", &numeroTestes);

    for (n = 1; n <= numeroTestes; n++)
    {
        Ponteiro r = inicializa();

        scanf("%i", &qtdNumeros);
        for (i = 0; i < qtdNumeros; i++)
        {
            scanf("%i", &chave);
            no = criarNovoNo(chave);
            r = insere(r, no);
        }
        printf("Case %d:\n", n);
        printf("Pre.:");
        mostrarArvorePrefixa(r);
        printf("\n");
        printf("In..:");
        mostrarArvoreInfixa(r);
        printf("\n");
        printf("Post:");
        mostrarArvorePosfixa(r);
        printf("\n\n");
    }
}
