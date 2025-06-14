#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrar_peixes() {
    FILE *arquivo = fopen("questao3.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }

    char nome[100];
    int peso, comprimento;
    char resposta[10];

    do {
        printf("Digite o nome do peixe: ");
        scanf("%s", nome);

        printf("Digite o peso do peixe (em gramas): ");
        scanf("%d", &peso);

        printf("Digite o comprimento do peixe (em cm): ");
        scanf("%d", &comprimento);

        fprintf(arquivo, "%s %d %d\n", nome, peso, comprimento);

        printf("Deseja cadastrar outro peixe? (sim/nao): ");
        scanf("%s", resposta);

    } while (strcmp(resposta, "sim") == 0);

    fclose(arquivo);
}

void calcular_peso() {
    FILE *arquivo = fopen("questao3.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char nome[100];
    int peso, comprimento;
    int peso_total = 0;

    printf("\nDetalhes dos peixes cadastrados:\n");
    printf("Nome\t\tPeso (g)\tComprimento (cm)\n");

    while (fscanf(arquivo, "%s %d %d", nome, &peso, &comprimento) == 3) {
        peso_total += peso;
        printf("%-10s\t%d\t\t%d\n", nome, peso, comprimento);
    }

    fclose(arquivo);

    printf("Peso total de peixes cadastrados: %d g (%.2f kg)\n", peso_total, peso_total / 1000.0);
}

int main() {
    cadastrar_peixes(); // Permite ao usuário cadastrar os peixes
    calcular_peso();    // Calcula e exibe os detalhes e o peso total
    return 0;
}