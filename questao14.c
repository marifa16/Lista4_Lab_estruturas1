#include <stdio.h>
#include <stdlib.h>

int main()
{
    int largura, altura;
    int **matriz = NULL;
    char opcao;

    do
    {
        printf("\nImagens Coloridas\n");
        printf("[A]rmazenar\n");
        printf("[E]xibir\n");
        printf("[S]air\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        if (opcao == 'A' || opcao == 'a')
        {
            printf("Largura: ");
            scanf("%d", &largura);
            printf("Altura : ");
            scanf("%d", &altura);

            // Aloca matriz dinamicamente
            matriz = (int **)malloc(altura * sizeof(int *));
            for (int i = 0; i < altura; i++)
                matriz[i] = (int *)malloc(largura * sizeof(int));

            printf("\nDefina %d cores em cada linha\n", largura);
            for (int i = 0; i < altura; i++)
            {
                printf("#%d: ", i + 1);
                for (int j = 0; j < largura; j++)
                {
                    scanf("%d", &matriz[i][j]);
                }
            }

            FILE *arq = fopen("imagem.dat", "wb");
            if (!arq)
            {
                printf("Erro ao abrir o arquivo!\n");
                for (int i = 0; i < altura; i++)
                    free(matriz[i]);
                free(matriz);
                continue;
            }
            fwrite(&largura, sizeof(int), 1, arq);
            fwrite(&altura, sizeof(int), 1, arq);
            for (int i = 0; i < altura; i++)
                fwrite(matriz[i], sizeof(int), largura, arq);
            fclose(arq);

            for (int i = 0; i < altura; i++)
                free(matriz[i]);
            free(matriz);

            printf("Imagem colorida foi armazenada.\n");
        }
        else if (opcao == 'E' || opcao == 'e')
        {
            FILE *arq = fopen("imagem.dat", "rb");
            if (!arq)
            {
                printf("Nenhuma imagem armazenada ainda.\n");
                continue;
            }
            fread(&largura, sizeof(int), 1, arq);
            fread(&altura, sizeof(int), 1, arq);

            matriz = (int **)malloc(altura * sizeof(int *));
            for (int i = 0; i < altura; i++)
                matriz[i] = (int *)malloc(largura * sizeof(int));

            for (int i = 0; i < altura; i++)
                fread(matriz[i], sizeof(int), largura, arq);
            fclose(arq);

            printf("\nImagem exibida:\n");
            for (int i = 0; i < altura; i++)
            {
                for (int j = 0; j < largura; j++)
                {
                    printf("\033[48;5;%03dm ", matriz[i][j]);
                }
                printf("\033[0m\n");
            }

            for (int i = 0; i < altura; i++)
                free(matriz[i]);
            free(matriz);
        }
        else if (opcao == 'S' || opcao == 's')
        {
            printf("Saindo...\n");
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 'S' && opcao != 's');

    return 0;
}
