#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo_entrada;
    FILE *arquivo_saida;
    int n;

    // Abrir o arquivo no modo de escrita para criar o conteúdo
    arquivo_entrada = fopen("questao2.txt", "w");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return EXIT_FAILURE;
    }
    fprintf(arquivo_entrada, "Ontem, as 12 horas, faziam 40 graus ao sol e 38 a sombra.\n");
    fprintf(arquivo_entrada, "Eu andei 100 metros antes de alcancar um lugar a sombra.\n");
    fprintf(arquivo_entrada, "Foram 5 minutos de sofrimento.");
    fclose(arquivo_entrada);

    // Reabrir o arquivo no modo de leitura
    arquivo_entrada = fopen("questao2.txt", "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return EXIT_FAILURE;
    }

    // Criar o arquivo de saída no modo de escrita
    arquivo_saida = fopen("questao2_saida.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(arquivo_entrada);
        return EXIT_FAILURE;
    }
    
    // Ler números do arquivo de entrada e gravar no arquivo de saída
    while (fscanf(arquivo_entrada, "%d", &n) == 1) {
        if (n > 0) {
            fprintf(arquivo_saida, "%d\n", n);
        }
    }
    printf("Numeros positivos foram escritos no arquivo de saida.\n");

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}