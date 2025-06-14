#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct peixe
{
    char nome[100];
    float peso;
    float comprimento;
};

int main()
{
    FILE *arq_txt = fopen("peixes.txt", "r");
    if (!arq_txt)
    {
        perror("Erro ao abrir peixes.txt");
        return 1;
    }

    FILE *arq_bin = fopen("peixes.bin", "wb");
    if (!arq_bin)
    {
        perror("Erro ao criar peixes.bin");
        fclose(arq_txt);
        return 1;
    }

    struct peixe p;
    int qtd = 0;
    // Espera-se que cada linha do arquivo texto tenha: nome peso comprimento
    while (fscanf(arq_txt, "%s %f %f", p.nome, &p.peso, &p.comprimento) == 3)
    {
        fwrite(&p, sizeof(struct peixe), 1, arq_bin);
        qtd++;
    }

    fclose(arq_txt);
    fclose(arq_bin);

    // Comparação dos tamanhos dos arquivos
    long tam_txt = 0, tam_bin = 0;
    arq_txt = fopen("peixes.txt", "rb");
    arq_bin = fopen("peixes.bin", "rb");
    if (arq_txt)
    {
        fseek(arq_txt, 0, SEEK_END);
        tam_txt = ftell(arq_txt);
        fclose(arq_txt);
    }
    if (arq_bin)
    {
        fseek(arq_bin, 0, SEEK_END);
        tam_bin = ftell(arq_bin);
        fclose(arq_bin);
    }

    printf("Foram lidos %d peixes do arquivo texto e gravados no arquivo binario.\n", qtd);
    printf("Tamanho do arquivo texto: %ld bytes\n", tam_txt);
    printf("Tamanho do arquivo binario: %ld bytes\n", tam_bin);

    return 0;
}
