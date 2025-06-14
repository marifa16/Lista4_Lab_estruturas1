#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int eliminacoes;
    int mortes;
    float taxa;
    int partidas;
} Soldado;

void exibe_soldado(Soldado s)
{
    printf("\n--- Soldado ---\n");
    printf("Nome: %s\n", s.nome);
    printf("Eliminacoes: %d\n", s.eliminacoes);
    printf("Mortes: %d\n", s.mortes);
    printf("Partidas jogadas: %d\n", s.partidas);
    printf("Taxa de eliminacao por morte: %.2f\n", s.taxa);
}

int main()
{
    Soldado s;
    FILE *arq = fopen("soldado.bin", "rb");
    char opcao;
    int existe = 0;

    if (arq)
    {
        if (fread(&s, sizeof(Soldado), 1, arq) == 1)
        {
            existe = 1;
            printf("Soldado carregado do arquivo.\n");
        }
        fclose(arq);
    }

    if (!existe)
    {
        printf("Nenhum soldado cadastrado. Cadastre um novo soldado:\n");
        printf("Nome: ");
        getchar(); // Limpa buffer
        fgets(s.nome, sizeof(s.nome), stdin);
        s.nome[strcspn(s.nome, "\n")] = 0;
        printf("Eliminacoes: ");
        scanf("%d", &s.eliminacoes);
        printf("Mortes: ");
        scanf("%d", &s.mortes);
        printf("Partidas jogadas: ");
        scanf("%d", &s.partidas);
        s.taxa = (s.mortes == 0) ? s.eliminacoes : (float)s.eliminacoes / s.mortes;
    }

    do
    {
        printf("\n[N]ovo soldado\n[A]tualiza soldado\n[E]xibe soldado\n[S]air\nOpcao: ");
        scanf(" %c", &opcao);

        if (opcao == 'N' || opcao == 'n')
        {
            getchar();
            printf("Nome: ");
            fgets(s.nome, sizeof(s.nome), stdin);
            s.nome[strcspn(s.nome, "\n")] = 0;
            printf("Eliminacoes: ");
            scanf("%d", &s.eliminacoes);
            printf("Mortes: ");
            scanf("%d", &s.mortes);
            printf("Partidas jogadas: ");
            scanf("%d", &s.partidas);
            s.taxa = (s.mortes == 0) ? s.eliminacoes : (float)s.eliminacoes / s.mortes;
        }
        else if (opcao == 'A' || opcao == 'a')
        {
            int elim, mort;
            printf("Eliminacoes na ultima partida: ");
            scanf("%d", &elim);
            printf("Mortes na ultima partida: ");
            scanf("%d", &mort);
            s.eliminacoes += elim;
            s.mortes += mort;
            s.partidas += 1;
            s.taxa = (s.mortes == 0) ? s.eliminacoes : (float)s.eliminacoes / s.mortes;
            printf("Soldado atualizado!\n");
        }
        else if (opcao == 'E' || opcao == 'e')
        {
            exibe_soldado(s);
        }
        else if (opcao == 'S' || opcao == 's')
        {
            // Salva no arquivo ao sair
            arq = fopen("soldado.bin", "wb");
            if (arq)
            {
                fwrite(&s, sizeof(Soldado), 1, arq);
                fclose(arq);
                printf("Dados salvos em soldado.bin.\n");
            }
            else
            {
                printf("Erro ao salvar arquivo!\n");
            }
            printf("Saindo...\n");
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 'S' && opcao != 's');

    return 0;
}