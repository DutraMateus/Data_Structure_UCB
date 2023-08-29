#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Fibonacci(int N){
    if(N == 1) return 1;
    if(N == 2) return 1;
    return Fibonacci(N - 1)+ Fibonacci(N - 2);
}

int main(){
    clock_t momentoInicial, momentoFinal;
    double tempo;

    momentoInicial=clock();
    int X = Fibonacci(30);
    momentoFinal = clock();

    tempo = ((double)(momentoFinal - momentoInicial))/CLOCKS_PER_SEC;

    printf("\nTermo da serie: %d\n", X);
    printf("\nTempo de execucao: %f\n", tempo);

    return 0;
}