/*Escreva um programa, em C ou C + +, que seja capaz de realizar
a inserção de valores inteiros e positivos numa lista linear duplamente encadeada com nó
descritor e, em seguida, apresentar o valor da soma dos valores não repetidos nas células
da lista.
A entrada de dados para o programa será realizada no seguinte formato:
1ª linha da entrada: n – quantidade de elementos que serão inseridos na lista;
2ª linha da entrada: n elementos – valores da lista separados por um único “espaço
em branco” entre eles.
A saída deve expressa numa única linha com o valor da soma dos valores não repetidos
nas células da lista.
Veja um exemplo:
1ª linha da entrada: 10
2ª linha da entrada: 1 2 3 4 5 6 7 8 9 10
linha de saída : 55
*/

#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 1
#define FALHA -1

//
// Declaração de tipos globais
//
typedef struct Celula *ApontadorCelula;
typedef struct Descritor *ApontadorDescritor;

struct Descritor
{
    ApontadorCelula prim;
    ApontadorCelula ult;
    int tam;
} Descritor;

struct Celula
{
    int dado;
    ApontadorCelula ant;
    ApontadorCelula prox;
} Celula;
//
// Protótipos das funções...
//
int CriarListaVazia(ApontadorDescritor *descritor);
int InsInicio(ApontadorDescritor *descritor, struct Celula celula);
int InsFinal(ApontadorDescritor *descritor, struct Celula celula);
int SomaLista(ApontadorDescritor *descritor);
void RemoveDuplicados(ApontadorDescritor *descritor);
void MostrarLista(ApontadorDescritor *descritor);

int CriarListaVazia(ApontadorDescritor *descritor)
{
    (*descritor) = (ApontadorDescritor)malloc(sizeof(struct Descritor));
    if ((*descritor) == NULL)
    {
        return (FALHA);
    }
    else
    {
        (*descritor)->prim = (ApontadorCelula)NULL;
        (*descritor)->tam = 0;
        (*descritor)->ult = (ApontadorCelula)NULL;
        return (SUCESSO);
    }
}
int InsInicio(ApontadorDescritor *descritor, struct Celula celula)
{
    ApontadorCelula q;

    q = (ApontadorCelula)malloc(sizeof(struct Celula));
    if (q == NULL)
    {
        return (FALHA);
    }
    else
    {

        q->dado = celula.dado;
        q->ant = (ApontadorCelula)NULL;
        q->prox = (*descritor)->prim;

        if ((*descritor)->tam == 0)
        {
            (*descritor)->prim = q;
            (*descritor)->ult = q;
        }
        else
        {
            ((*descritor)->prim)->ant = q;
            (*descritor)->prim = q;
        }
        (*descritor)->tam++;
        return (SUCESSO);
    }
}

int InsFinal(ApontadorDescritor *descritor, struct Celula celula)
{
    ApontadorCelula q;

    if ((*descritor)->tam == 0)
    {
        return (InsInicio(descritor, celula));
    }
    else
    {
        q = (ApontadorCelula)malloc(sizeof(struct Celula));
        if (q == NULL)
        {
            return (FALHA);
        }
        else
        {

            q->dado = celula.dado;
            q->prox = (ApontadorCelula)NULL;
            q->ant = (*descritor)->ult;

            ((*descritor)->ult)->prox = q;
            (*descritor)->ult = q;
            (*descritor)->tam++;

            return (SUCESSO);
        }
    }
}
void RemoveDuplicados(ApontadorDescritor *descritor)
{

    struct Celula *corrente, *index, *temp;

    if ((*descritor)->prim == NULL)
    {
        return FALHA;
    }
    else
    {

        for (corrente = (*descritor)->prim; corrente != NULL; corrente = corrente->prox)
        {
            //index apontara para o proximo nó de corrente
            for (index = corrente->prox; index != NULL; index = index->prox)
            {
                if (corrente->dado == index->dado)
                {
                    //Armazena o nó duplicado em temp
                    temp = index;
                    //o no anterior do index apontará para o proximo, portanto, remove o nó duplicado
                    index->ant->prox = index->prox;
                    if (index->prox != NULL)
                        index->prox->ant = index->ant;
                    //exclui o no duplicado tornando o temp NULL
                    temp = NULL;
                }
            }
        }
    }
}

void MostraLista(ApontadorDescritor *descritor)
{
    ApontadorCelula r;

    if ((*descritor)->tam == 0)
    {
        printf("A lista esta VAZIA.\n\n");
    }
    else
    {
        r = (*descritor)->prim;
        while (r->prox != NULL)
        {
            printf("[%d] -> ", r->dado);
            r = r->prox;
        }
        printf("[%d]\n\n", r->dado);
    }
}
int SomaLista(ApontadorDescritor *descritor)
{
    ApontadorCelula r;
    int total = 0;
    for (r = (*descritor)->prim; r != NULL; r = r->prox)
    {
        total += r->dado;
    }
    return (total);
}

int main(void)
{

    ApontadorDescritor descritor;
    unsigned long int tamanho, valor;
    int i;
    struct Celula celulaAuxiliar;

    CriarListaVazia(&descritor);
    scanf("%d", &tamanho);
    while (tamanho > 1000)
    {
        scanf("%d", &tamanho);
    }
    for (i = 0; i < tamanho; i++)
    {

        scanf("%d", &valor);
        celulaAuxiliar.dado = valor;
        InsFinal(&descritor, celulaAuxiliar);
    }
    RemoveDuplicados(&descritor);
    int soma = SomaLista(&descritor);
    printf("%d", soma);
}
