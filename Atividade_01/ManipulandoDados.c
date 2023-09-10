#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char telefone[20];
    char materia[100];
    double nota1;
    double nota2;
} Aluno;

double calcularMedia(const Aluno *aluno)
{
    return (aluno->nota1 + aluno->nota2) / 2.0;
}

const char *determinarSituacao(const Aluno *aluno)
{
    return (calcularMedia(aluno) >= 7.0) ? "Aprovado" : "Reprovado";
}

int main()
{
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoAlunos.csv", "w");

    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir os arquivos\n");
        return 1;
    }

    char linha[256];

    fgets(linha, sizeof(linha), entrada);

    while (fgets(linha, sizeof(linha), entrada) != NULL)
    {
        Aluno aluno;

        char *token = strtok(linha, ",");
        if (token == NULL)
        {
            printf("Erro ao analisar a linha: %s\n", linha);
            continue;
        }

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Erro ao analisar a linha: %s\n", linha);
            continue;
        }

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Erro ao analisar a linha: %s\n", linha);
            continue;
        }

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Erro ao analisar a linha: %s\n", linha);
            continue;
        }
        aluno.nota1 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            printf("Erro ao analisar a linha: %s\n", linha);
            continue;
        }
        aluno.nota2 = atof(token);

        const char *situacao = determinarSituacao(&aluno);

        fprintf(saida, "%s, %.2lf, %s\n", aluno.nome, calcularMedia(&aluno), situacao);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}