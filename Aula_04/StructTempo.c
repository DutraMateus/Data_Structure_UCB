#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int Fibonacci(int N){
    if(N == 1) return 1;
    if(N == 2) return 1;
    return Fibonacci(N - 1)+ Fibonacci(N - 2);
}

int main(){
    LARGE_INTEGER F;
    LARGE_INTEGER MI, MF;
    double tempo;

    QueryPerformanceFrequency(&F);

    QueryPerformanceCounter(&MI);
    int X = Fibonacci(30);
   QueryPerformanceCounter(&MF);

    tempo = (MF.QuadPart - MI.QuadPart)/F.QuadPart;

    printf("\nTermo da serie: %d\n", X);
    printf("\nTempo de execucao: %f\n", tempo);

    return 0;
}