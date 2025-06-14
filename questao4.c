#include <stdio.h>
#include <stdlib.h>

void cadastrar_alunos() {
    FILE *arquivo = fopen("questao4.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }

    int quantidade;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);

    char nome[100];
    int nota1, nota2, nota3;

    for (int i = 0; i < quantidade; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Digite o nome do aluno: ");
        scanf("%s", nome);

        printf("Digite a primeira nota: ");
        scanf("%d", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%d", &nota2);

        printf("Digite a terceira nota: ");
        scanf("%d", &nota3);

        fprintf(arquivo, "%s %d %d %d\n", nome, nota1, nota2, nota3);
    }

    fclose(arquivo);
    printf("\nCadastro concluído!\n");
}

void exibir_alunos() {
    FILE *arquivo = fopen("questao4.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char nome[100];
    int nota1, nota2, nota3;
    float media;

    printf("\nAlunos cadastrados:\n");
    printf("Nome            Nota1   Nota2   Nota3   Media   Situacao\n");
    printf("-------------------------------------------------------\n");

    while (fscanf(arquivo, "%s %d %d %d", nome, &nota1, &nota2, &nota3) == 4) {
        media = (nota1 + nota2 + nota3) / 3.0;

        printf("%-15s%-8d%-8d%-8d%-8.2f", nome, nota1, nota2, nota3, media);

        if (media >= 7.0) {
            printf("Aprovado\n");
        } else if (media > 3.0 && media < 7.0) {
            printf("Quarta Prova\n");
        } else {
            printf("Reprovado\n");
        }
    }

    fclose(arquivo);
}

int main() {
    cadastrar_alunos(); // Permite ao usuário cadastrar os alunos
    exibir_alunos();    // Exibe os alunos cadastrados com a situação
    return 0;
}