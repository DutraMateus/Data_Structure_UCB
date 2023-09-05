//crescente
#include<stdio.h>
#include<stdlib.h>

void insercao(int vetor[], int N){
	
    for(int i=1; i<N; i++){
        int chave = vetor[i];
        int j = i - 1;
        while(j >=0 && chave < vetor[j]){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = chave;
	}
}

int main(){
    int V[] = {64, 25, 12, 22, 11};
    int N = sizeof(V)/sizeof(V[0]);

    insercao(V, N);
    

    printf("\nVetor ordenado: ");
    for(int i=0; i<N; i++){
        printf("\n%d ", V[i]);
    }
    return 0;

}