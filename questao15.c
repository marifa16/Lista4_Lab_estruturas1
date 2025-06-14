#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq_txt = fopen("naturais.txt", "w");
    FILE *arq_bin = fopen("naturais.bin", "wb");
    if (!arq_txt || !arq_bin)
    {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    // Grava os 100 primeiros números naturais
    for (int i = 0; i < 100; i++)
    {
        fprintf(arq_txt, "%d\n", i);
        fwrite(&i, sizeof(int), 1, arq_bin);
    }

    fclose(arq_txt);
    fclose(arq_bin);

    // Compara tamanhos dos arquivos
    long tam_txt = 0, tam_bin = 0;
    arq_txt = fopen("naturais.txt", "rb");
    arq_bin = fopen("naturais.bin", "rb");
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

    printf("Tamanho do arquivo texto: %ld bytes\n", tam_txt);
    printf("Tamanho do arquivo binario: %ld bytes\n", tam_bin);

    printf("\nExplicacao:\n");
    printf("No arquivo binario, cada numero e gravado usando sizeof(int) bytes (normalmente 4 bytes por numero).\n");
    printf("No arquivo texto, cada numero e gravado como caracteres, podendo ocupar 1 a 3 bytes por numero, mais o caractere de nova linha.\n");
    printf("Assim, o arquivo binario geralmente e menor e tem tamanho fixo por numero, enquanto o arquivo texto pode ser maior devido ao formato de representacao dos numeros como texto.\n");

    return 0;
}
