#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *arquivo = fopen("questao5.txt", "w");
    if (arquivo == NULL)
    {
        perror("Erro ao criar o arquivo");
        return 1;
    }

    char texto[1000];
    printf("Digite o texto a ser analisado:\n");
    fflush(stdin);
    fgets(texto, sizeof(texto), stdin);
    fprintf(arquivo, "%s", texto);
    fclose(arquivo);

    arquivo = fopen("questao5.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    int total = 0, vogal = 0, consoante = 0, diferente = 0;
    char c;

    while ((c = fgetc(arquivo)) != EOF)
    {
        if (c == '\n' || c == '\r')
            continue;
        total++;
        if (isalpha(c))
        {
            char lower_c = tolower(c);
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u')
            {
                vogal++;
            }
            else
            {
                consoante++;
            }
        }
        else
        {
            diferente++;
        }
    }

    fclose(arquivo);

    printf("Total de caracteres: %d\n", total);
    printf("Total de vogais: %d\n", vogal);
    printf("Total de consoantes: %d\n", consoante);
    printf("Total de outros caracteres: %d\n", diferente);

    return 0;
}