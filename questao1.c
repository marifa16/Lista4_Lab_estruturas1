#include <stdio.h>
#include <stdlib.h>

// Função criar arquivo 
void criar_arquivo() {
    FILE *fout = fopen("questao1.txt", "w");
    if (fout == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }
    fprintf(fout, "No Brasil, o Discord eh usado para crimes graves como discurso de odio e abuso infantil. Grupos se aproveitam do anonimato da plataforma, tendo jovens como principais vitimas.\nA nobre hungara Elizabeth Bathory, conhecida como Condessa Sangrenta, foi acusada de matar centenas de jovens no seculo XVII. A lenda diz que ela se banhava no sangue das vitimas para rejuvenescer, e por seus crimes, morreu aprisionada em seu castelo.\n");
    fclose(fout);
}

// Função para ler o oitavo caractere
void ler_oitavo_caractere() {
    FILE *fin = fopen("questao1.txt", "r");
    if (fin == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    char c;
    fseek(fin, 7, SEEK_SET);
    fscanf(fin, "%c", &c);
    fclose(fin);
    printf("O oitavo caractere do arquivo eh: %c\n", c);
}

// Função para ler a primeira palavra
void ler_primeira_palavra() {
    FILE *fin = fopen("questao1.txt", "r");
    if (fin == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    char palavra[100];
    fscanf(fin, "%s", palavra);
    fclose(fin);
    printf("A primeira palavra do arquivo eh: %s\n", palavra);
}

// Função para ler a quinta palavra
void ler_quinta_palavra() {
    FILE *fin = fopen("questao1.txt", "r");
    if (fin == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    char palavra[100];
    for (int i = 0; i < 5; i++) {
        if (fscanf(fin, "%s", palavra) == EOF) {
            printf("Menos de 5 palavras no arquivo.\n");
            fclose(fin);
            return;
        }
    }
    fclose(fin);
    printf("A quinta palavra do arquivo eh: %s\n", palavra);
}

// Função para ler uma linha
void ler_uma_linha() {
    FILE *fin = fopen("questao1.txt", "r");
    if (fin == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    char linha[256];
    if (fgets(linha, sizeof(linha), fin) != NULL) {
        printf("A primeira linha do arquivo eh: %s", linha);
    } else {
        printf("Nao foi possivel ler a linha.\n");
    }
    fclose(fin);
}

int main() {
    criar_arquivo();
    ler_oitavo_caractere();
    ler_primeira_palavra();
    ler_quinta_palavra();
    ler_uma_linha();
    return 0;
}