#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char codigo[4]; // Ex.: "M8" ou "T1"
} Aluno;

typedef struct No
{
    Aluno aluno;
    struct No *prox;
} No;

void listar_por_turno(No *inicio);

int main()
{
    int qtd;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &qtd);

    No *inicio = NULL, *fim = NULL;
    char nome_temp[100], sobrenome_temp[100], codigo_temp[4];

    for (int i = 0; i < qtd; i++)
    {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", nome_temp);
        printf("Sobrenome: ");
        scanf("%s", sobrenome_temp);
        printf("Codigo das turmas: ");
        scanf("%s", codigo_temp);

        No *novo = (No *)malloc(sizeof(No));
        if (!novo)
        {
            perror("Erro de memória");
            // Libera lista antes de sair
            while (inicio)
            {
                No *tmp = inicio;
                inicio = inicio->prox;
                free(tmp);
            }
            return 1;
        }
        snprintf(novo->aluno.nome, sizeof(novo->aluno.nome), "%s %s", nome_temp, sobrenome_temp);
        strcpy(novo->aluno.codigo, codigo_temp);
        novo->prox = NULL;

        if (fim)
        {
            fim->prox = novo;
        }
        else
        {
            inicio = novo;
        }
        fim = novo;
    }

    // agrupamento por turno e série
    char grupos[6][3] = {"M6", "M7", "M8", "T6", "T7", "T8"};
    char descricoes[6][25] = {
        "Matutino 6a Serie", "Matutino 7a Serie", "Matutino 8a Serie",
        "Vespertino 6a Serie", "Vespertino 7a Serie", "Vespertino 8a Serie"};

    printf("\n--- Alunos cadastrados ---\n");
    for (No *p = inicio; p != NULL; p = p->prox)
    {
        printf("%-20s %s\n", p->aluno.nome, p->aluno.codigo);
    }

    printf("\n--- Competicao Interclasses ---\n\n");
    printf("Alunos agrupados por turno e serie:\n\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", descricoes[i]);
        printf("------------------\n");
        int encontrou = 0;
        for (No *p = inicio; p != NULL; p = p->prox)
        {
            if (strcmp(p->aluno.codigo, grupos[i]) == 0)
            {
                printf("%-20s %s\n", p->aluno.nome, p->aluno.codigo);
                encontrou = 1;
            }
        }
        if (!encontrou)
        {
            printf("Nenhum aluno cadastrado neste grupo.\n");
        }
        printf("\n");
    }

    // Libera memória
    while (inicio)
    {
        No *tmp = inicio;
        inicio = inicio->prox;
        free(tmp);
    }

    printf("a) Não é possível separar os alunos por sexo usando os dados do programa porque eles armazenam apenas os nomes dos alunos e os códigos da turma , sem informações de gênero.\n");
    printf("b) A forma mais fácil de separar por sexo seria adicionar um campo 'sexo' na struct Aluno e pedir essa informação ao usuário no cadastro.\n");
    
    return 0;

    
}

