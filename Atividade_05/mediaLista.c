#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item *proximo;
} Item;

typedef struct Lista
{
    Item *cabeca;
    int tamanho;
} Lista;

void displayList(Lista *lista)
{
    printf("Lista: ");
    Item *current = lista->cabeca;
    while (current != NULL)
    {
        printf("%d ", current->chave);
        current = current->proximo;
    }
    printf("\n");
}

Lista *createEmptyList()
{
    Lista *newList = (Lista *)malloc(sizeof(Lista));
    if (newList == NULL)
    {
        printf("Erro ao alocar memória para a lista. \n");
        exit(1);
    }
    newList->cabeca = NULL;
    newList->tamanho = 0;
    return newList;
}

void insertAtPosition(Lista *lista, int position, Item *item)
{
    if (position < 0 || position > lista->tamanho)
    {
        printf("Posicao invalida.\n");
        return;
    }
    if (position == 0)
    {
        item->proximo = lista->cabeca;
        lista->cabeca = item;
    }
    else
    {
        Item *temp = lista->cabeca;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->proximo;
        }
        item->proximo = temp->proximo;
        temp->proximo = item;
    }
    lista->tamanho++;
}

void removeFromPosition(Lista *lista, int position)
{
    if (position < 0 || position >= lista->tamanho)
    {
        printf("Posicao invalida.\n");
        return;
    }
    if (position == 0)
    {
        Item *temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
        free(temp);
    }
    else
    {
        Item *temp = lista->cabeca;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->proximo;
        }
        Item *aux = temp->proximo;
        temp->proximo = aux->proximo;
        free(aux);
    }
    lista->tamanho--;
}

float calculateAverage(Lista *lista)
{
    if (lista->tamanho == 0)
    {
        printf("A lista está vazia. Não é possível calcular a média.\n");
        return 0.0;
    }

    float sum = 0.0;
    Item *current = lista->cabeca;

    while (current != NULL)
    {
        sum += current->chave;
        current = current->proximo;
    }

    return sum / lista->tamanho;
}

int main()
{
    Lista *X = createEmptyList();

    Item *I1 = (Item *)malloc(sizeof(Item));
    I1->chave = 10;
    Item *I2 = (Item *)malloc(sizeof(Item));
    I2->chave = 20;
    Item *I3 = (Item *)malloc(sizeof(Item));
    I3->chave = 30;
    Item *I4 = (Item *)malloc(sizeof(Item));
    I4->chave = 40;

    insertAtPosition(X, 0, I1);
    insertAtPosition(X, 0, I2);
    insertAtPosition(X, 0, I3);
    insertAtPosition(X, 0, I4);

    printf("Tamanho: %d\n", X->tamanho);
    displayList(X);
    printf("Média: %.2f\n", calculateAverage(X));
    removeFromPosition(X, 0);
    printf("Tamanho: %d\n", X->tamanho);
    displayList(X);

    return 0;
}