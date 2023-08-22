#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    FILE *arquivo;
    char linha[100];
    int i = 0;                  //variacao codigo

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        i++;                               // variacao codigo
        printf("%s", i, linha);         // "i" variacao codigo
    }

    fclose(arquivo);
    return 0;
}