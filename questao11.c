#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    int numero;

    arquivo = fopen("integer.bin", "rb");

    if (arquivo != NULL)
    {
        fread(&numero, sizeof(int), 1, arquivo);
        printf("O numero lido do arquivo eh: %d\n", numero);
        fclose(arquivo);
    }

    printf("Digite um numero inteiro:\n");
    scanf("%d", &numero);

    arquivo = fopen("integer.bin", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    fwrite(&numero, sizeof(int), 1, arquivo);
    fclose(arquivo);

    printf("Numero %d gravado com sucesso no arquivo integer.bin.\n", numero);

    return 0;
}