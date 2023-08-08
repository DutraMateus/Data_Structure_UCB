#include <stdio.h>

int Fatorial(int N)
{
    if (N == 0)
        return 1;
    else
        return N * Fatorial(N - 1);
}

int main()
{
    int N;

    printf("\nInforme um numero: ");
    scanf("%d", &N);
    printf("\nResultado: %d", Fatorial(N));
    
    return;
}