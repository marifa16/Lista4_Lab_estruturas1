#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct peixe
{
    char nome[100];
    float peso;
    float comprimento;
};

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void exibir_peixes(FILE *arquivo)
{
    struct peixe p;
    rewind(arquivo);

    printf("\nPeixes cadastrados:\n");
    int encontrou = 0;
    while (fread(&p, sizeof(struct peixe), 1, arquivo) == 1)
    {
        printf("Nome: %s, Peso: %.2f kg, Comprimento: %.2f cm\n", p.nome, p.peso, p.comprimento);
        encontrou = 1;
    }
    if (!encontrou)
    {
        printf("Nenhum peixe cadastrado.\n");
    }
    printf("\n");
}

int main()
{
    struct peixe p;
    FILE *arquivo;

    arquivo = fopen("peixes.bin", "ab+");
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    exibir_peixes(arquivo);

    // Cadastro de peixes
    while (1)
    {
        printf("Digite o nome do peixe:\n");
        scanf("%s", p.nome);
        printf("Digite o peso do peixe (kg):\n");
        scanf("%f", &p.peso);
        printf("Digite o comprimento do peixe (cm):\n");
        scanf("%f", &p.comprimento);
        limpar_buffer();
        if (p.peso <= 0 || p.comprimento <= 0)
        {
            printf("Peso e comprimento devem ser positivos. Tente novamente.\n");
            continue;
        }

        fwrite(&p, sizeof(struct peixe), 1, arquivo);

        fclose(arquivo);

        printf("Peixe cadastrado com sucesso!\n");
        printf("Deseja cadastrar outro peixe? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        limpar_buffer();
        if (resposta != 's' && resposta != 'S')
        {
            break;
        }
    }
    fclose(arquivo);

    // Exibir peixes cadastrados
    arquivo = fopen("peixes.bin", "rb");
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    exibir_peixes(arquivo);
    fclose(arquivo);
    return 0;
}