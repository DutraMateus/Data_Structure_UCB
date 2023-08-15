#include <stdio.h>

int main()
{
    int soma = 0;
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("\nElemento na segunda linha, terceira coluna: %d\n", matriz[1][2]);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            soma = soma + matriz[i][j];

    printf("\nA soma dos elementos vai ser: %d\n", soma);
    return 0;
}