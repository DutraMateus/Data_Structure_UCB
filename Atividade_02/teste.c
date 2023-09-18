#include <stdio.h>
#include <string.h>

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *arr[], int low, int high)
{
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (strcmp(arr[j], pivot) < 0)
            swap(&arr[++i], &arr[j]);

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char *arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    char *arr[20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
                     "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);

    quicksort(arr, 0, n - 1);

    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);

    return 0;
}