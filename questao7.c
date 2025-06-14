#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limpa_pontuacao(char *palavra) {
    int inicio = 0;
    while (palavra[inicio] && ispunct((unsigned char)palavra[inicio]))
        inicio++;
    int fim = strlen(palavra) - 1;
    while (fim >= inicio && ispunct((unsigned char)palavra[fim])) {
        palavra[fim] = '\0';
        fim--;
    }
    if (inicio > 0)
        memmove(palavra, palavra + inicio, strlen(palavra + inicio) + 1);
}

int eh_palindromo(const char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;
    while (inicio < fim) {
        if (tolower((unsigned char)str[inicio]) != tolower((unsigned char)str[fim])) {
            return 0;
        }
        inicio++;
        fim--;
    }
    return 1;
}

int main() {
    // Escreve o texto no arquivo questao7.txt
    FILE *arquivo = fopen("questao7.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(arquivo, "Ana, ao reler a ata, teve que reviver esse crime com socos fatais.\n");
    fclose(arquivo);

    // Mostra o texto cadastrado
    arquivo = fopen("questao7.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    printf("Texto cadastrado:\n");
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    rewind(arquivo); // Volta ao início do arquivo para análise

    char palavra[100];
    int total = 0;

    printf("\nPalavras palindromas encontradas:\n");
    while (fscanf(arquivo, "%s", palavra) == 1) {
        limpa_pontuacao(palavra);
        if (strlen(palavra) > 1 && eh_palindromo(palavra)) {
            printf("%s\n", palavra);
            total++;
        }
    }
    fclose(arquivo);

    printf("Total de palavras palindromas: %d\n", total);
    return 0;
}