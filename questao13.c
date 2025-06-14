#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char texto[81]; // 80 caracteres + 1 para o terminador nulo
    int cor_texto;
    int cor_fundo;
} Mensagem;

int main()
{
    Mensagem msg;
    char opcao;

    do
    {
        printf("\nMensagem Colorida\n");
        printf("[A]rmazenar\n");
        printf("[E]xibir\n");
        printf("[S]air\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        if (opcao == 'A' || opcao == 'a')
        {
            getchar(); // Limpa o buffer do teclado
            printf("Digite a mensagem: ");
            fgets(msg.texto, sizeof(msg.texto), stdin);
            msg.texto[strcspn(msg.texto, "\n")] = 0; // Remove o '\n' do final da string

            do
            {
                printf("Cor do texto (000 - 255): ");
                scanf("%d", &msg.cor_texto);
            } while (msg.cor_texto < 0 || msg.cor_texto > 255);

            do
            {
                printf("Cor do fundo (000 - 255): ");
                scanf("%d", &msg.cor_fundo);
            } while (msg.cor_fundo < 0 || msg.cor_fundo > 255);

            FILE *arquivo = fopen("mensagem.dat", "wb");
            if (arquivo == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                continue;
            }
            fwrite(&msg, sizeof(Mensagem), 1, arquivo);
            fclose(arquivo);
            printf("Mensagem armazenada com sucesso!\n");
        }
        else if (opcao == 'E' || opcao == 'e')
        {
            FILE *arquivo = fopen("mensagem.dat", "rb");
            if (!arquivo)
            {
                printf("Erro ao abrir o arquivo.\n");
                continue;
            }
            if (fread(&msg, sizeof(Mensagem), 1, arquivo) == 1)
            {
                printf("\nMensagem: %s\n", msg.texto);
                printf("Cor do texto: %d\n", msg.cor_texto);
                printf("Cor do fundo: %d\n", msg.cor_fundo);
            }
            else
            {
                printf("Nenhuma mensagem armazenada.\n");
            }
            fclose(arquivo);
        }
        else if (opcao == 'S' || opcao == 's')
        {
            printf("Saindo....\n");
        }
        else
        {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 'S' && opcao != 's');

    return 0;
}