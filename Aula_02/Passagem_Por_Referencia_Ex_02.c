#include <stdio.h>

struct pessoa
{
    char nome[20];
    int idade;
};

/*Em modificarPessoa, a passagem de parametros se da por REFERENCIA*/

void modificarPessoa(struct pessoa *p)
{
    p->idade += 1;
}
void testarPessoa(struct pessoa X)
{
    X.idade = X.idade * 2;
}

int main()
{
    struct pessoa X = {"\nJoao", 25};

    modificarPessoa(&X);
    printf("\nNome; %s\n", X.nome);
    printf("\nIdade: %d\n", X.idade);

    testarPessoa(X);
    printf("\nNome; %s\n", X.nome);
    printf("\nIdade: %d\n", X.idade);

    return 0;
}