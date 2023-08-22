#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    FILE *arquivo;
    arquivo = fopen("saida.txt", "a");  //modo a acrescenta dados no final do arquivo
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    const char *mensagem = "\nTeste...........";
    fputs(mensagem, arquivo);

    fclose(arquivo);
    return 0;
}