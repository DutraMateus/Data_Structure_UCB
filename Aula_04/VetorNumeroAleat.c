#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAMANHO 20;

int main(){

    int array[TAMANHO];

    srand(time(NULL));

    for(int i=0; i<TAMANHO; i++) array[i] = rand();

    for(int i=0; i<TAMANHO; i++) printf("%d\n", array[i]);
    
    return 0;
}