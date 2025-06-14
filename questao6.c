#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Cria o arquivo questao6.txt com o texto fornecido
    FILE *arquivo = fopen("questao6.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(arquivo, "Em \"Casos de Familia: Arquivos Richthofen e Arquivos Nardoni\", a criminologa Ilana Casoy abre seus arquivos pessoais para oferecer um acesso sem precedentes a dois dos crimes que mais chocaram o Brasil. A autora, que acompanhou de perto ambas as investigacoes, guia o leitor pelos bastidores do assassinato do casal Richthofen e da morte da menina Isabella Nardoni.\n\nCom base em suas anotacoes, documentos oficiais e laudos periciais, o livro detalha o passo a passo do trabalho da policia, as reviravoltas dos inqueritos e os momentos mais marcantes dos julgamentos. E um mergulho profundo nos metodos da investigacao criminal e na complexidade de casos que se tornaram parte do imaginario brasileiro.");
    fclose(arquivo);

    char palavra[100], linha[1000], resposta[10];
    int encontrou;

    do {
        encontrou = 0;
        printf("Digite a palavra que deseja buscar: ");
        scanf("%s", palavra);

        arquivo = fopen("questao6.txt", "r");
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo");
            return 1;
        }

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            if (strstr(linha, palavra) != NULL) {
                encontrou = 1;
                break;
            }
        }

        fclose(arquivo);

        if (encontrou) {
            printf("A palavra '%s' foi encontrada no arquivo.\n", palavra);
        } else {
            printf("A palavra '%s' nao foi encontrada no arquivo.\n", palavra);
        }

        printf("Deseja tentar outra palavra? (sim/nao): ");
        scanf("%s", resposta);

    } while (strcmp(resposta, "sim") == 0);

    return 0;
}