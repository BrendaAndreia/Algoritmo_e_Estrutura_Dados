/*Considere uma lista linear duplamente encadeada de números inteiros positivos V, cujo tamanho máximo é de 10000 elementos.
Escreva um programa, em C ou C + +, que seja capaz de realizar a seguintes operações:
C – ordenação dos elementos em ordem estritamente crescente a partir da primeira célula da lista;
D – ordenação dos elementos em ordem estritamente descrente a partir da primeira célula da lista;
M – apresentar o maior elemento existente na lista;
m – apresentar o menor elemento existente na lista.*/

#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 1
#define FALHA 0
#define CHAVE_INVALIDA -1
typedef struct Node *ApontadorNode;
typedef struct Node
{
    unsigned int dado;
    struct Node *prox, *ant;
} Node;

//prototipos das funções utilizadas
int CriarListaVazia(ApontadorNode *a);
int InsInicio(ApontadorNode *p, Node celula);
int InsFinal(ApontadorNode *p, Node celula);
struct Node *Merge(struct Node *primeiro, struct Node *segundo);
struct Node *DivideLista(struct Node *inicio);
struct Node *MergeSort(struct Node *inicio);
void MostraLista(struct Node *inicio, char opcao);
int CriarListaVazia(ApontadorNode *a)
{
    (*a) = (ApontadorNode)NULL;
    return (1);
}
// inserindo dados na listas
int InsInicio(ApontadorNode *p, Node celula)
{
    ApontadorNode q;

    q = (ApontadorNode)malloc(sizeof(Node));
    if (q == NULL)
    {
        return 1;
    }
    else
    {
        q->dado = celula.dado;

        q->prox = (ApontadorNode)(*p);
        (*p) = q;
        return 0;
    }
}
int InsFinal(ApontadorNode *p, Node celula)
{
    ApontadorNode q, r;

    if ((*p) == NULL)
        return (InsInicio(p, celula));
    else
    {
        q = (ApontadorNode)malloc(sizeof(Node));
        if (q == NULL)
        {
            return (1);
        }
        else
        {
            q->dado = celula.dado;

            q->prox = (ApontadorNode)NULL;
            r = (*p);
            while (r->prox != NULL)
            {
                r = r->prox;
            }
            r->prox = q;
            return (0);
        }
    }
}
// Mesclar duas listas
struct Node *Merge(struct Node *primeiro, struct Node *segundo)
{
    // / se a primeira lista estiver vazia
    if (!primeiro)
        return segundo;

    if (!segundo)
        return primeiro;

    // Pegando o menor valor
    if (primeiro->dado < segundo->dado)
    {
        primeiro->prox = Merge(primeiro->prox, segundo);
        primeiro->prox->ant = primeiro;
        primeiro->ant = NULL;
        return primeiro;
    }
    else
    {
        segundo->prox = Merge(primeiro, segundo->prox);
        segundo->prox->ant = segundo;
        segundo->ant = NULL;
        return segundo;
    }
}

// Dividindo a lista em 2 para uso no MergeSort
struct Node *DivideLista(struct Node *inicio)
{
    struct Node *r = inicio, *q = inicio;
    while (r->prox && r->prox->prox)
    {
        r = r->prox->prox;
        q = q->prox;
    }
    struct Node *temp = q->prox;
    q->prox = NULL;
    return temp;
}
// Algoritmo merge sort
struct Node *MergeSort(struct Node *inicio)
{
    if (!inicio || !inicio->prox)
        return inicio;
    struct Node *segundo = DivideLista(inicio);

    //Recorre para metade da esqueda e direita
    inicio = MergeSort(inicio);
    segundo = MergeSort(segundo);

    // Mescla as duas metades
    return Merge(inicio, segundo);
}

//Mostrando lista resultante conforme a opcao escolhida
void MostraLista(struct Node *inicio, char opcao)
{
    struct Node *temp = inicio;

    if (opcao == 'm')
    {
        //printf("Menor numero: ");
        printf("%d", inicio->dado);
    }
    else
    {
        if (opcao == 'M')
        {
            while (inicio->prox != NULL)
            {
                inicio = inicio->prox;
            }
            //printf("Maior numero: ");
            printf("%d", inicio->dado);
        }
    }
    if (opcao == 'C')
    {

        while (inicio)
        {
            printf("%d ", inicio->dado);
            temp = inicio;
            inicio = inicio->prox;
        }
    }
    else
    {
        if (opcao == 'D')
        {
            while (inicio)
            {
                temp = inicio;
                inicio = inicio->prox;
            }

            while (temp)
            {
                printf("%d ", temp->dado);
                temp = temp->ant;
            }
        }
    }
}

int main(void)
{
    struct Node *inicio;

    unsigned int intValor;
    struct Node celulaAuxiliar;
    char opcao;

    CriarListaVazia(&inicio);
    do
    {

        scanf("%d", &intValor);
        if (intValor != -1)
        {
            celulaAuxiliar.dado = intValor;
            InsFinal(&inicio, celulaAuxiliar);
        };
    } while (intValor != CHAVE_INVALIDA);

    scanf(" %c", &opcao);
    inicio = MergeSort(inicio);
    MostraLista(inicio, opcao);
}