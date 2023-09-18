#include <stdio.h>
#include <string.h>

void swap(char **a, char **b, int *trocas)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
    (*trocas)++;
}

int partition(char *arr[], int low, int high, int *comparacoes, int *trocas)
{
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        (*comparacoes)++;
        if (strcmp(arr[j], pivot) < 0)
        {
            swap(&arr[++i], &arr[j], trocas);
        }
    }

    swap(&arr[i + 1], &arr[high], trocas);
    return i + 1;
}

void quicksort(char *arr[], int low, int high, int *comparacoes, int *trocas)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, comparacoes, trocas);
        quicksort(arr, low, pi - 1, comparacoes, trocas);
        quicksort(arr, pi + 1, high, comparacoes, trocas);
    }
}

int main()
{
    char *arr[20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
                     "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

    int n = sizeof(arr) / sizeof(arr[0]);
    int comparacoes = 0;
    int trocas = 0;

    FILE *outputFile = fopen("saida.txt", "w");
    if (outputFile == NULL)
    {
        printf("Erro ao criar o arquivo de saida.\n");
        return 1;
    }

    fprintf(outputFile, "Vetor antes da ordenacao:\n");
    for (int i = 0; i < n; i++)
        fprintf(outputFile, "\t%s ", arr[i]);

    quicksort(arr, 0, n - 1, &comparacoes, &trocas);

    fprintf(outputFile, "\n\nVetor ordenado:\n");
    for (int i = 0; i < n; i++)
        fprintf(outputFile, "\n%s ", arr[i]);

    fprintf(outputFile, "\n\nNumero de comparacoes: %d\n", comparacoes);
    fprintf(outputFile, "Numero de trocas: %d\n", trocas);

    char *mediana;
    if (n % 2 == 0)
    {
        int meio = n / 2;
        mediana = arr[meio - 1];
    }
    else
    {
        int meio = n / 2;
        mediana = arr[meio];
    }

    fprintf(outputFile, "\n\nMediana do conjunto de dados: %s\n", mediana);

    fclose(outputFile);

    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);
    return 0;
}