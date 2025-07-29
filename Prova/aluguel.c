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

    return 1; //filmme adicioado
}

int buscar(Filme* filmes){
    char cod[20];
    printf("Digite o código do filme para buscar:\n>>> ");
    fgets(cod, 20, stdin);
    cod[strcspn(cod, "\n")] = 0;
    
    for (int i = 0; i < 100; i++) {
        if (filmes[i].status == 1 && strcmp(filmes[i].codigo_filme, cod) == 0) {
            return i; 
        }
    }
    return -1; 
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

int comparar_alugueis(const void *a, const void *b) {
    Filme *f1 = (Filme *)a;
    Filme *f2 = (Filme *)b;
    return f2->n_alugueis - f1->n_alugueis;
}

void ListarMaisAlugados(Filme *filmes) {
    Filme copia[100];
    int tam = 0;

    for (int i = 0; i < 100; i++) {
        if (filmes[i].status == 1 && strcmp(filmes[i].codigo_filme, "0") != 0) {
            copia[tam++] = filmes[i];
        }
    }

    qsort(copia, tam, sizeof(Filme), comparar_alugueis);

    printf("\n=== FILMES MAIS ALUGADOS ===\n");
    for (int i = 0; i < tam; i++) {
        printf("\n==== %dº %s ====\n", i + 1, copia[i].titulo);
        printf("Codigo: %s\n", copia[i].codigo_filme);
        printf("Disponiveis: %d\n", copia[i].quantidade_disponivel);
        printf("Alugueis: %d\n", copia[i].n_alugueis);
        printf("Valor: R$%.2f\n", copia[i].preco_aluguel);
    }
}

int comparar_devolucoes(const void *a, const void *b) {
    Filme *f1 = (Filme *)a;
    Filme *f2 = (Filme *)b;
    return f2->n_devolucoes - f1->n_devolucoes;
}


void listarMaisDevolvidos(Filme *filmes, int tamanho) {
    Filme copia[100]; 
    int tam = 0;

    for (int i = 0; i < tamanho; i++) {
        if (filmes[i].status == 1 && strcmp(filmes[i].codigo_filme, "0") != 0) {
            copia[tam++] = filmes[i];
        }
    }

    qsort(copia, tam, sizeof(Filme), comparar_devolucoes);

    printf("\n=== FILMES MAIS DEVOLVIDOS ===\n");
    if (tam == 0) {
        printf("Nenhum filme ativo para listar.\n");
    } else {
        for (int i = 0; i < tam; i++) {
            printf("\n==== %dº %s ====\n", i + 1, copia[i].titulo);
            printf("Codigo: %s\n", copia[i].codigo_filme);
            printf("Disponiveis: %d\n", copia[i].quantidade_disponivel);
            printf("Devolucoes: %d\n", copia[i].n_devolucoes);
            printf("Valor: R$%.2f\n", copia[i].preco_aluguel);
        }
    }
}


void extratoFinanceiro(Filme *filmes, int tamanho) {
    float total_arrecadado = 0.0;
    
    for (int i = 0; i < tamanho; i++) {
    
        if (filmes[i].status == 1 && strcmp(filmes[i].codigo_filme, "0") != 0) {
             total_arrecadado += (filmes[i].n_alugueis * filmes[i].preco_aluguel);
        }
    }
    printf("\n=== EXTRATO FINANCEIRO ===\n");
    printf("Total arrecadado com alugueis: R$%.2f\n", total_arrecadado);
}


void listarEstoque(Filme *filmes, int tamanho) {
    printf("\n=== FILÇMES DISPONIVEIS EM ESTOQUE ===\n");
    int count_disponiveis = 0;
    for (int i = 0; i < tamanho; i++) {
        if (filmes[i].status == 1 && strcmp(filmes[i].codigo_filme, "0") != 0 && filmes[i].quantidade_disponivel > 0) {
            printf("\n==== %s ====\n", filmes[i].titulo);
            printf("Codigo: %s\n", filmes[i].codigo_filme);
            printf("Disponiveis: %d\n", filmes[i].quantidade_disponivel);
            printf("Valor: R$%.2f\n", filmes[i].preco_aluguel);
            count_disponiveis++;
        }
    }
    if (count_disponiveis == 0) {
        printf("Nenhum filme disponivel em estoque no momento.\n");
    }
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
    int tamanho_array_filmes = 100; 

    while (1) {
        do {
            printf("\n=== Bem vindo a locadora da UFRPE ===\n");
            printf("[1] - Adicionar filme\n");
            printf("[2] - Remover filme\n");
            printf("[3] - Listar filmes\n");
            printf("[4] - Alugar filme\n");
            printf("[5] - Devolver filme\n");
            printf("[6] - Filmes Mais Alugados\n"); 
            printf("[7] - Filmes Mais Devolvidos\n");
            printf("[8] - Extrato Financeiro\n");    
            printf("[9] - Listar Estoque Disponivel\n");
            printf("[10] - Sair\n");
            printf(">>> ");
            scanf("%d", &opcao);
            getchar();
        } while (opcao < 1 || opcao > 10); 

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
                ListarMaisAlugados(filmes);
                break;
            case 7:
                listarMaisDevolvidos(filmes, tamanho_array_filmes); 
                break;
            case 8:
                
                printf("\n=== EXTRATO FINANCEIRO ===\n");
                printf("Total arrecadado com alugueis: R$%.2f\n", extrato);
                
                break;
            case 9:
                listarEstoque(filmes, tamanho_array_filmes); 
                break;
            case 10: 
                printf("Extrato final: R$ %.2f\n", extrato); 
                printf("Saindo...\n");
                return 0;
        }
    }
}