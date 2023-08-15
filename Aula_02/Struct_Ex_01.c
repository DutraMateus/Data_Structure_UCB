#include <stdio.h>
#include <string.h>

struct pessoa
{
    char nome[20];
    int idade;
    float altura;
};

int main()
{
    struct pessoa X;
    strcpy(X.nome, "Joao");
    X.idade = 25;
    X.altura = 1.75;

    printf("\nNome: %s\n", X.nome);
    printf("\nIdade: %d\n", X.idade);
    printf("\nAltura: %.2f\n", X.altura);

    return 0;
}