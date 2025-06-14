#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;
    int n, qtd = 0, *vetor = NULL;

    // Verifica se o arquivo já existe e exibe os valores, se existir
    arquivo = fopen("vet.dat", "rb");
    if (arquivo != NULL)
    {
        fread(&qtd, sizeof(int), 1, arquivo);
        if (qtd > 0)
        {
            vetor = (int *)malloc(qtd * sizeof(int));
            fread(vetor, sizeof(int), qtd, arquivo);
            printf("Valores ja cadastrados no arquivo:\n");
            for (int i = 0; i < qtd; i++)
            {
                printf("%d ", vetor[i]);
            }
            printf("\n");
            free(vetor);
        }
        fclose(arquivo);
    }

    // Leitura dos números do usuário
    printf("Digite uma sequencia de numeros inteiros (0 para terminar):\n");
    qtd = 0;
    vetor = NULL;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        vetor = (int *)realloc(vetor, (qtd + 1) * sizeof(int));
        vetor[qtd] = n;
        qtd++;
    }

    // Salva no arquivo binário
    arquivo = fopen("vet.dat", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        free(vetor);
        return 1;
    }
    fwrite(&qtd, sizeof(int), 1, arquivo);
    if (qtd > 0)
    {
        fwrite(vetor, sizeof(int), qtd, arquivo);
    }
    fclose(arquivo);
    free(vetor);

    printf("Dados gravados com sucesso em vet.dat!\n");
    return 0;
}
