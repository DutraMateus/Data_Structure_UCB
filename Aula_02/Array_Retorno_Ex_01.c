#include <stdio.h>
#include <stdlib.h>

int *criarArray(int tamanho)
{
    int *array = malloc(tamanho * sizeof(int)); // alocacao dinamica de memoria
    for (int i = 0; i < tamanho; i++)
        array[i] = 2 * i + 3;

    return array;
}
int main()
{

    int tamanho;

    printf("\nInforme o tamanho do vetor (array): ");
    scanf("%d", &tamanho);

    int *meuArray = criarArray(tamanho);

    for (int i = 0; i < tamanho; i++)printf("%d\t", meuArray[i]);
    free(meuArray);

    return 0;
}
