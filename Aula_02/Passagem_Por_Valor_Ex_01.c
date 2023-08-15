#include <stdio.h>

/*A passagem de parametros se da por valor, logo, a funcao nao modifica o vetor fora dela*/

void exibirArray(int array[], int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    
    printf("\n%d\t", array[i]);
    printf("\n");
}

int main()
{

    int meuArray[] = {2, 5, 6, 9, 0};
    int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);
    exibirArray(meuArray, tamanho);

    return 0;
}