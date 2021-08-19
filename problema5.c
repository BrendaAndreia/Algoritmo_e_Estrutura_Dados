/*Uma operação comum em diversas áreas da computação científica
é a multiplicação de números inteiros positivos com grande número de dígitos. 
Por exemplo, multiplicar dois números de 30 dígitos cada, o que pode gerar um número de até 60 dígitos.
Você está participando de uma equipe de desenvolvimento de uma aplicação científica que
deve implementar a operação de multiplicação mencionada.
A aplicação deve ser desenvolvida utilizando a linguagem C ou C + +, conforme a seguir
especificado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *AddNumero(char *string1, char *string2)
{
    int i = 0, j = 0, temp;

    int l1 = strlen(string1);
    int l2 = strlen(string2);
    int a[30] = {0}, b[30] = {0};
    int intResult[60] = {0};
    char *resultado = calloc(l1 + l2 + 1, 1); // memoria do vetor resultado

    if (string1[0] == '0' || string2[0] == '0')
    {

        resultado[0] = '0';
        return resultado;
    }
    for (i = l1 - 1, j = 0; i >= 0; i--, j++)
    {
        a[j] = string1[i] - '0';
    }
    for (i = l2 - 1, j = 0; i >= 0; i--, j++)
    {
        b[j] = string2[i] - '0';
    }
    for (i = 0; i < l2; i++)
    {
        for (j = 0; j < l1; j++)
        {
            intResult[i + j] += b[i] * a[j];
        }
    }
    for (i = 0; i < l1 + l2; i++)
    {
        temp = intResult[i] / 10;
        intResult[i] = intResult[i] % 10;
        intResult[i + 1] = intResult[i + 1] + temp;
    }
    for (i = l1 + l2; i >= 0; i--)
    {
        if (intResult[i] > 0)
            break;
    }

    for (j = i; j >= 0; j--)
    {
        resultado[i - j] = (char)('0' + intResult[j]);
    }
    return resultado;
}
int main(int argc, char *argv[])
{
    int testes, i;

    scanf("%d", &testes);
    char *resultado[testes + 1];
    char *string1[testes][30];
    char *string2[testes][30];
    for (i = 0; i < testes; i++)
    {
        scanf(" %s", string1[i]);
        scanf(" %s", string2[i]);
    }

    for (i = 0; i < testes; i++)
    {
        resultado[i] = AddNumero(string1[i], string2[i]);

        printf("%s\n", resultado[i]);
        free(resultado[i]);
    }

    return 0;
}