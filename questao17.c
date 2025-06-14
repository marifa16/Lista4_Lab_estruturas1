#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union
{
    char alfa[50];
    int num;
} Senha;

int main()
{
    FILE *arq;
    int tipo;
    Senha senha;
    char opcao;

    do
    {
        printf("\n[S]alvar nova senha\n[E]xibir senha\n[X] Sair\nOpcao: ");
        scanf(" %c", &opcao);

        if (opcao == 'S' || opcao == 's')
        {
            printf("Tipo de senha:\n[1] Alfanumerica\n[2] Numerica\nEscolha: ");
            scanf("%d", &tipo);

            if (tipo == 1)
            {
                printf("Digite a senha alfanumerica: ");
                scanf(" %49s", senha.alfa);
            }
            else if (tipo == 2)
            {
                printf("Digite a senha numerica: ");
                scanf("%d", &senha.num);
            }
            else
            {
                printf("Tipo invalido!\n");
                continue;
            }

            arq = fopen("senha.bin", "wb");
            if (!arq)
            {
                printf("Erro ao abrir arquivo!\n");
                continue;
            }
            fwrite(&tipo, sizeof(int), 1, arq);
            if (tipo == 1)
                fwrite(&senha, sizeof(senha.alfa), 1, arq);
            else
                fwrite(&senha, sizeof(int), 1, arq);
            fclose(arq);
            printf("Senha salva com sucesso!\n");
        }
        else if (opcao == 'E' || opcao == 'e')
        {
            arq = fopen("senha.bin", "rb");
            if (!arq)
            {
                printf("Arquivo de senha nao existe.\n");
                continue;
            }
            if (fread(&tipo, sizeof(int), 1, arq) != 1)
            {
                printf("Arquivo corrompido ou vazio.\n");
                fclose(arq);
                continue;
            }
            if (tipo == 1)
            {
                fread(&senha, sizeof(senha.alfa), 1, arq);
                printf("Senha alfanumerica: %s\n", senha.alfa);
            }
            else if (tipo == 2)
            {
                fread(&senha, sizeof(int), 1, arq);
                printf("Senha numerica: %d\n", senha.num);
            }
            else
            {
                printf("Tipo de senha desconhecido no arquivo.\n");
            }
            fclose(arq);
        }
        else if (opcao == 'X' || opcao == 'x')
        {
            printf("Saindo...\n");
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 'X' && opcao != 'x');

    return 0;
}
