/*Um dos grandes problemas brasileiros é o atendimento do SUS –
Sistema Único de Saúde. Nele os pacientes que chegam para atendimento numa unidade,
digamos X, são inseridos numa na fila e passam, imediatamente, por uma triagem que os
coloca numa fila para atendimento.
Na triagem, o atendente (enfermeiro ou enfermeira) anota o horário de entrada do paciente, quantos minutos ele tem 
até que sua condição de saúde se torne crítica. Sabe-se
que, quando estão na fila para atendimento, os pacientes são atendidos em intervalos de
30 em 30 minutos. Considere, para simplificação, que são sempre nas horas “cheias” ou
“meias horas”: 07h, 07h30min, 08h, e assim sucessivamente.
O inicio da triagem e do atendimento ocorre às 07h e, portanto, neste horário as filas de
triagem e atendimento estão vazias. O primeiro paciente é atendido no instente em que
chega na triagem. Considere também que o médico atende até o último paciente da fila
(lembre-se: isto é para simplificar a solução, não refletindo a realidade!).
A principal preocupação aqui é se um paciente atingiu uma condição crítica antes de ter
seu atendimento iniciado e, por isso, você convidado para desenvolver uma aplicação – em
C ou C++ – que seja capaz de verificar na fila de atendimento quantos pacientes atingem
a condição crítica.
Para facilitar o desenvolvimento, o líder da equipe lhe deu as seguintes orientações:
(1ª) considere que a aplicação receberá os dados em linhas de entrada, cada linha contém
certos dados;
(2ª) a PRIMEIRA LINHA contém apenas um número inteiro n (0 < n < 25) que indica
o número de pacientes que chegaram na fila de triagem;
(3ª) as próximas n linhas apresentam os valores para a hora (h), minuto (m) e tempo
crítico (tc) em que cada paciente chegou na triagem, sempre sabendo que o paciente
da linha i chega antes, ou junto, com o paciente da linha (i + 1) – nunca depois deste.
Sabe-se também que 7 < h < 19, 0 ≤ m < 60 e que 0 ≤ tc ≤ 720. O tc é o número
de minutos até que o paciente atinja a condição crítica em seu estado de saúde. Os
números estão, dois a dois, separados por um ‘espaço em branco”.
O programa deverá imprimir – numa única linha de saída – o número de pacientes que
atingiram a condição crítica ainda na fila de atendimento. Veja um exemplo:
1ª linha da entrada: 4
2ª linha da entrada: 7 0 20
3ª linha da entrada: 7 0 30
4ª linha da entrada: 7 30 20
5ª linha da entrada: 8 15 30*/
#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 1
#define FALHA 0
typedef struct Node *ApontadorNode;
typedef struct Node
{
    int hora, minutos, tc;
    struct Node *prox, *ant;
} Node;

//prototipos das funçoes
int HorarioPaciente(ApontadorNode *p);
int CriarListaVazia(ApontadorNode *a);
int InsInicio(ApontadorNode *p, Node celula);
int InsFinal(ApontadorNode *p, Node celula);

int CriarListaVazia(ApontadorNode *a)
{
    (*a) = (ApontadorNode)NULL;
    return (1);
}
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
        q->hora = celula.hora;
        q->minutos = celula.minutos;
        q->tc = celula.tc;

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
            q->hora = celula.hora;
            q->minutos = celula.minutos;
            q->tc = celula.tc;

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
int HorarioPaciente(ApontadorNode *p)
{
    ApontadorNode paciente;
    paciente = (*p);
    int horarioAtendimento = 0, horarioCritico, pacientesCriticos = 0;
    int horarioChegada;

    while (paciente != NULL)
    {

        horarioChegada = (((paciente->hora) - 7) * 60) + paciente->minutos;
        horarioCritico = horarioChegada + paciente->tc;
        while (horarioAtendimento < horarioChegada)
        {

            horarioAtendimento += 30;
        }
        if (horarioAtendimento > horarioCritico)
        {

            pacientesCriticos++;
        }

        horarioAtendimento += 30;

        paciente = paciente->prox;
    }

    return pacientesCriticos;
}

int main(void)
{
    struct Node *inicio;

    int hora, minutos, tc, nrPacientes;
    struct Node celulaAuxiliar;
    int i;

    CriarListaVazia(&inicio);

    scanf("%d", &nrPacientes);
    for (i = 0; i < nrPacientes; i++)
    {

        scanf("%d", &hora);
        celulaAuxiliar.hora = hora;
        scanf("%d", &minutos);
        celulaAuxiliar.minutos = minutos;
        scanf("%d", &tc);
        celulaAuxiliar.tc = tc;
        InsFinal(&inicio, celulaAuxiliar);
    }
    int resultado = HorarioPaciente(&inicio);
    printf("%d\n", resultado);
}