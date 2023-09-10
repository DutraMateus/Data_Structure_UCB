#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um aluno
typedef struct {
    char nome[100];
    char telefone[20];
    char materia[100];
    double nota1;
    double nota2;
} Aluno;

// Função para calcular a média de um aluno
double calcularMedia(const Aluno *aluno) {
    return (aluno->nota1 + aluno->nota2) / 2.0;
}

// Função para determinar a situação de um aluno
const char *determinarSituacao(const Aluno *aluno) {
    return (calcularMedia(aluno) >= 7.0) ? "Aprovado" : "Reprovado";
}

int main() {
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoAlunos.csv", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos\n");
        return 1;
    }

    char linha[256];

    // Ler e descartar a primeira linha (cabeçalho)
    fgets(linha, sizeof(linha), entrada);

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        Aluno aluno;

        // Usar sscanf para analisar a linha CSV
        if (sscanf(linha, "%99[^,], %19[^,], %99[^,], %lf, %lf", aluno.nome, aluno.telefone, aluno.materia, &aluno.nota1, &aluno.nota2) != 5) {
            printf("Erro ao analisar a linha: %s\n", linha);
            continue;  // Pular linhas com formato inválido
        }

        // Determinar a situação do aluno
        const char *situacao = determinarSituacao(&aluno);

        // Escrever no arquivo de saída
        fprintf(saida, "%s, %.2lf, %s\n", aluno.nome, calcularMedia(&aluno), situacao);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}