#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char titulo[100];
    char codigo_filme[20];
    int quantidade_disponivel;
    int n_alugueis;
    int n_devolucoes;
    float preco_aluguel;
    int status; // 1 = ativo, 0 = removido
} Filme;

int adicionar(Filme *filmes) {
    Filme a;
    printf("== Adicionar filme ==\n");
    printf("Titulo: ");
    fgets(a.titulo, 100, stdin);
    a.titulo[strcspn(a.titulo, "\n")] = 0;

    printf("Codigo: ");
    fgets(a.codigo_filme, 20, stdin);
    a.codigo_filme[strcspn(a.codigo_filme, "\n")] = 0;

    for (int i = 0; i < 100; i++) {
        if (strcmp(a.codigo_filme, filmes[i].codigo_filme) == 0) {
            printf("Codigo ja cadastrado!\n");
            return 0;
        }
    }

    printf("Quantidade disponivel: ");
    scanf("%d", &a.quantidade_disponivel);
    getchar();

    printf("Preco do aluguel: ");
    scanf("%f", &a.preco_aluguel);
    getchar();

    a.n_alugueis = 0;
    a.n_devolucoes = 0;
    a.status = 1;

    for (int i = 0; i < 100; i++) {
        if (strcmp(filmes[i].codigo_filme, "0") == 0) {
            filmes[i] = a;
            break;
        }
    }

    return 1;
}

void listar(Filme *filmes) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(filmes[i].codigo_filme, "0") != 0) {
            printf("\n==== %s ====\n Codigo: %s\n Disponiveis: %i\n Valor: R$%.2f\n",
                   filmes[i].titulo, filmes[i].codigo_filme,
                   filmes[i].quantidade_disponivel, filmes[i].preco_aluguel);
        }
    }
}

int remover(Filme *filmes) {
    printf("\nEscolha o CODIGO do filme que voce quer remover\n >>>");
    char buscar[20];
    fgets(buscar, 20, stdin);
    buscar[strcspn(buscar, "\n")] = 0;
    int achou = 0;

    for (int i = 0; i < 100; i++) {
        if (strcmp(buscar, filmes[i].codigo_filme) == 0) {
            strcpy(filmes[i].codigo_filme, "0");
            strcpy(filmes[i].titulo, "");
            filmes[i].quantidade_disponivel = 0;
            filmes[i].preco_aluguel = 0;
            filmes[i].n_alugueis = 0;
            filmes[i].n_devolucoes = 0;
            filmes[i].status = 0;
            achou = 1;
        }
    }

    if (!achou) {
        printf("\nCodigo Nao encontrado. Tente novamente\n");
    }

    return achou;
}

int alugar(Filme *filmes, float *extrato) {
    printf("\n===Bem Vindo ao Painel de Aluguel ===\n");
    char codigo[20];
    printf("Digite o CODIGO do filme\n>>> ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    for (int i = 0; i < 100; i++) {
        if (strcmp(codigo, filmes[i].codigo_filme) == 0 && filmes[i].quantidade_disponivel > 0) {
            filmes[i].quantidade_disponivel -= 1;
            filmes[i].n_alugueis += 1;
            printf("Reservado com sucesso!\n");
            *extrato += filmes[i].preco_aluguel;
            return 1;
        }
    }

    printf("ERRO: Codigo invalido ou Filme nao Disponivel\n");
    return 0;
}

int devolver(Filme *filmes) {
    printf("\n===Bem Vindo ao Painel de Devolucao ===\n");
    char codigo[20];
    printf("Digite o CODIGO do filme\n>>> ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    for (int i = 0; i < 100; i++) {
        if (strcmp(codigo, filmes[i].codigo_filme) == 0 &&
            filmes[i].n_alugueis > filmes[i].n_devolucoes) {
            filmes[i].quantidade_disponivel += 1;
            filmes[i].n_devolucoes += 1;
            printf("Entregue com Sucesso!\n");
            return 1;
        }
    }

    printf("ERRO: Codigo invalido ou Filme nao Alugado\n");
    return 0;
}

int main(void) {
    Filme filmes[100];
    float extrato = 0;

    for (int i = 0; i < 100; i++) {
        strcpy(filmes[i].codigo_filme, "0");
        strcpy(filmes[i].titulo, "");
        filmes[i].quantidade_disponivel = 0;
        filmes[i].preco_aluguel = 0;
        filmes[i].n_alugueis = 0;
        filmes[i].n_devolucoes = 0;
        filmes[i].status = 0;
    }

    int opcao = 0;

    while (1) {
        do {
            printf("\n=== Bem vindo a locadora da UFRPE ===\n");
            printf("[1] - Adicionar filme\n");
            printf("[2] - Remover filme\n");
            printf("[3] - Listar filmes\n");
            printf("[4] - Alugar filme\n");
            printf("[5] - Devolver filme\n");
            printf("[6] - Sair\n");
            printf(">>> ");
            scanf("%d", &opcao);
            getchar();
        } while (opcao < 1 || opcao > 6);

        switch (opcao) {
            case 1:
                adicionar(filmes);
                break;
            case 2:
                remover(filmes);
                break;
            case 3:
                listar(filmes);
                break;
            case 4:
                alugar(filmes, &extrato);
                break;
            case 5:
                devolver(filmes);
                break;
            case 6:
                printf("Extrato final: R$ %.2f\n", extrato);
                printf("Saindo...\n");
                return 0;
        }
    }
}
