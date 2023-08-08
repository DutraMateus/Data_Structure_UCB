#include <stdio.h>

int Fibonacci(int N)
{
    if (N == 1 || N == 2)
        return 1;
    else
        return Fibonacci(N - 1) + Fibonacci(N - 2);
}

int main()
{
    int N;

    printf("\nInforme um numero: ");
    scanf("%d", &N);
    printf("\nResultado: %d\n", Fibonacci(N));
    system("pause");
}