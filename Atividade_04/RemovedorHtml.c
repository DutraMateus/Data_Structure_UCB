#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputFile, *outputFile;
    char inputFileName[] = "index.html";
    char outputFileName[] = "saida.txt";
    char ch;
    int insideTag = 0;

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        printf("Erro ao criar o arquivo de saida");
        fclose(inputFile);
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF)
    {
        if (ch == '<')
        {
            insideTag = 1;
        }
        else if (ch == '>')
        {
            insideTag = 0;
        }
        else if (!insideTag)
        {
            fputc(ch, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Tags HTML removidas com sucesso\n");
    return 0;
}