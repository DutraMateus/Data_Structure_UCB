#include<stdio.h>
#include<stdlib.h>

void insercao(int vetor[], int N, int *C, int *M){
	*C = 0;
    *M - 0;
    for(int i=1; i<N; i++){
        int chave = vetor[i];
        int j = i - 1;
        (*C)++;
        while(j >=0 && chave < vetor[j]){
            (*C)++;
            (*M)++;
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = chave;
	}
}

int main(){
    int V[] = {64, 25, 12, 22, 11};
    int N = sizeof(V)/sizeof(V[0]);
    int M, C;

    insercao(V, N, &C, &M);
    

    printf("\nVetor ordenado: ");
    for(int i=0; i<N; i++){
        printf("\n%d ", V[i]);
    }
    return 0;

}