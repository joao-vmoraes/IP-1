#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

// variáveis
int dimensao_mundo = 10; 
int dimensao_escola = 3;
int vida_maxima = 100;
int raiva_minima = 60;

char mapaEscola[3][3];
char mapaMundo[10][10];

int elevenL, elevenC;
int willL, willC;
int portalL, portalC;
int portalAtivo = 0;
int portalEscolaL, portalEscolaC;
int vida = 100;
int raiva = 0;
int willSalvo = 0;
int demodogsExtras = 0;

void limpa_tela() {
    printf("\033[2J\033[H");
}

void limpa_buffer() //FUNCAO QUE O GP[T DISSE PARA LIMPAR BUFFER DE ENTRADAA DO FGETS
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float distancia(int l1, int c1, int l2, int c2) {
    return sqrt((l2 - l1)*(l2 - l1) + (c2 - c1)*(c2 - c1));
}

void mostrar_escola() {
    limpa_tela();
    printf("=== VIDA: %i ==== RAIVA: %i ===\n\n", vida, raiva);

    for (int i = 0; i < dimensao_escola; i++) {
        for (int j = 0; j < dimensao_escola; j++) {
            if (i == elevenL && j == elevenC) {
                printf(" E ");
            } else if (i == portalEscolaL && j == portalEscolaC) {
                printf(" P ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

void mostrar_mundo() {
    limpa_tela();
    printf("=== VIDA: %i === RAIVA: %i ===\n\n", vida, raiva);

    for (int i = 0; i < dimensao_mundo; i++) {
        for (int j = 0; j < dimensao_mundo; j++) {
            if (i == elevenL && j == elevenC) {
                printf(" E ");
            } else if (!willSalvo && i == willL && j == willC) {
                printf(" W ");
            } else if (portalAtivo && i == portalL && j == portalC) {
                printf(" P ");
            } else {
                switch (mapaMundo[i][j]) {
                    case 'T': printf(" T "); break;
                    case 'C': printf(" C "); break;
                    case 'H': printf(" H "); break;
                    case 'D': printf(" D "); break;
                    case 'M': printf(" M "); break;
                    case '_': printf(" - "); break;
                    default: printf(" ? "); break;
                }
            }
        }
        printf("\n");
    }
}

void posicionar_portal_escola() {
    int l, c;
    do {
        l = rand() % dimensao_escola;
        c = rand() % dimensao_escola;
    } while (l == elevenL && c == elevenC);

    portalEscolaL = l;
    portalEscolaC = c;
}

void limpar_mapa(char mapa[10][10], int tamanho, char caractere) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            mapa[i][j] = caractere;
        }
    }
}

void popular_mapa(char mapa[10][10], int tamanho, char simbolo, int quantidade) {
    for (int i = 0; i < quantidade;) {
        int l = rand() % tamanho;
        int c = rand() % tamanho;
        if (mapa[l][c] == '_' && (l != elevenL || c != elevenC) && (l != willL || c != willC) && (l != portalL || c != portalC)) {
            mapa[l][c] = simbolo;
            i++;
        }
    }
}

void adicionar_demogorgon_proximo(int l, int c, int raio) {
    for (int tentativas = 0; tentativas < 50; tentativas++) {
        int nl = l + (rand() % (2 * raio + 1)) - raio;
        int nc = c + (rand() % (2 * raio + 1)) - raio;

        if (nl >= 0 && nl < dimensao_mundo && nc >= 0 && nc < dimensao_mundo &&
            mapaMundo[nl][nc] == '_' && (nl != elevenL || nc != elevenC)) {
            mapaMundo[nl][nc] = 'D';
            return;
        }
    }
}

void mover_will() {
    int direcoes[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int d = rand() % 4;
    int novaL = willL + direcoes[d][0];
    int novaC = willC + direcoes[d][1];

    if (novaL >= 0 && novaL < dimensao_mundo && novaC >= 0 && novaC < dimensao_mundo && mapaMundo[novaL][novaC] == '_') {
        willL = novaL;
        willC = novaC;
        printf("Will se moveu para (%i, %i).\n", willL, willC);
    } else {
        printf("Will está bloqueado.\n");
    }
}

void abrir_portal_mundo() {
    if (portalAtivo) {
        return;
    }
    while (1) {
        int l = rand() % dimensao_mundo;
        int c = rand() % dimensao_mundo;
        if (mapaMundo[l][c] == '_' && (l != elevenL || c != elevenC) && (l != willL || c != willC)) {
            mapaMundo[l][c] = 'P';
            portalL = l;
            portalC = c;
            portalAtivo = 1;
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    printf("== Stranger Things - Jogo da Eleven ==\n");
    printf("Pressione ENTER para comecar...\n");
    limpa_buffer();

    elevenL = rand() % dimensao_escola;
    elevenC = rand() % dimensao_escola;

    posicionar_portal_escola();

    // Fase 1: Escola
    while (1) {
        mostrar_escola();

        if (elevenL == portalEscolaL && elevenC == portalEscolaC) {
            int tentativa_raiva = rand() % 101;

            printf("Tentando abrir o portal... RAIVA: %i\n", tentativa_raiva);

            if (tentativa_raiva >= raiva_minima) {
                portalAtivo = 1;
                printf("Portal aberto! Indo para o mundo invertido... (Pressione ENTER)\n");
                limpa_buffer(); // Garante que o ENTER anterior não seja lido
                break;
            } else {
                vida -= 20;
                printf("Raiva insuficiente. Perdeu 20 de vida. Agora: %i\n", vida);
                posicionar_portal_escola();

                if (vida <= 0) {
                    printf("\nEleven morreu. Fim de jogo.\n");
                    return 0;
                }
            }
        }

        printf("Mover (WASD):\n>>>  ");
        char mov;
        scanf(" %c", &mov);
        limpa_buffer();
        mov = toupper(mov);

        if (mov == 'Q') {
            printf("Saindo...\n");
            return 0;
        }

        int novaL = elevenL;
        int novaC = elevenC;

        if (mov == 'W') novaL--;
        else if (mov == 'S') novaL++;
        else if (mov == 'A') novaC--;
        else if (mov == 'D') novaC++;
        else {
            printf("Movimento invalido.\n");
            continue;
        }

        if (novaL >= 0 && novaL < dimensao_escola && novaC >= 0 && novaC < dimensao_escola) {
            elevenL = novaL;
            elevenC = novaC;
        } else {
            printf("Nao pode passar. Parede.\n");
        }

        if (rand() % 100 < 20) {
            vida -= 5;
            printf("Cansaco... perdeu 5 de vida.\n");
        }

        if (vida <= 0) {
            printf("\nEleven morreu. Fim de jogo.\n");
            return 0;
        }
    }

    // Fase 2: Mundo Invertido
    portalAtivo = 0;
    willSalvo = 0;
    demodogsExtras = 0;

    printf("\n== FASE 2: Resgate no Mundo Invertido ==\n");
    printf("Objetivo: Encontre Will ('W'), depois o portal ('P') para escapar. Cuidado com Demogorgons ('D')!\n");
    printf("Pressione ENTER para comecar...\n");
    limpa_buffer();

    limpar_mapa(mapaMundo, dimensao_mundo, '_');

    elevenL = rand() % dimensao_mundo;
    elevenC = rand() % dimensao_mundo;

    int dist_min_will = 4;
    do {
        willL = rand() % dimensao_mundo;
        willC = rand() % dimensao_mundo;
    } while (distancia(elevenL, elevenC, willL, willC) < dist_min_will);

    popular_mapa(mapaMundo, dimensao_mundo, 'T', 10); //arvoré
    popular_mapa(mapaMundo, dimensao_mundo, 'C', 5); //carro
    popular_mapa(mapaMundo, dimensao_mundo, 'H', 5); // casa abandonada
    popular_mapa(mapaMundo, dimensao_mundo, 'D', 4); //demorgorgon
    popular_mapa(mapaMundo, dimensao_mundo, 'M', 10);

    while (1) {
        mostrar_mundo();

        if (!willSalvo && !demodogsExtras) {
            if (distancia(elevenL, elevenC, willL, willC) < 3.0) {
                printf("Alerta! Mais Demogorgons apareceram!\n");
                adicionar_demogorgon_proximo(elevenL, elevenC, 1);
                adicionar_demogorgon_proximo(elevenL, elevenC, 1);
                demodogsExtras = 1;
            }
        }

        if (!willSalvo && elevenL == willL && elevenC == willC) {
            willSalvo = 1;
            printf("Will encontrado! Agora, encontre o portal para fugir!\n");
            abrir_portal_mundo();
        }

        if (willSalvo && elevenL == portalL && elevenC == portalC && portalAtivo) {
            mostrar_mundo();
            printf("\nEleven e Will escaparam! Vida restante: %i\n", vida);
            printf("Fim de Jogo. Voce Venceu!\n");
            break;
        }

        printf("Mover (WASD): \n>>> ");
        char mov_fase2;
        scanf(" %c", &mov_fase2);
        limpa_buffer();
        mov_fase2 = toupper(mov_fase2);

        if (mov_fase2 == 'Q') {
            printf("Saindo...\n");
            break;
        }

        int novaL = elevenL;
        int novaC = elevenC;

        if (mov_fase2 == 'W') novaL--;
        else if (mov_fase2 == 'S') novaL++;
        else if (mov_fase2 == 'A') novaC--;
        else if (mov_fase2 == 'D') novaC++;
        else {
            printf("Movimento invalido.\n");
            continue;
        }

        if (novaL >= 0 && novaL < dimensao_mundo && novaC >= 0 && novaC < dimensao_mundo) {
            char elemento_no_destino = mapaMundo[novaL][novaC];

            if (elemento_no_destino == '_') {
                elevenL = novaL;
                elevenC = novaC;
            } else if (elemento_no_destino == 'M') {
                vida += 5;
                if (vida > vida_maxima) {
                    vida = vida_maxima;
                }
                mapaMundo[novaL][novaC] = '_';
                elevenL = novaL;
                elevenC = novaC;
                printf("Panqueca! +5 Vida.\n");
            } else if (elemento_no_destino == 'D') {
                vida -= 10;
                mapaMundo[novaL][novaC] = '_';
                elevenL = novaL;
                elevenC = novaC;
                printf("Demogorgon! Perdeu 10 de vida.\n");
            } else if (elemento_no_destino == 'P' && willSalvo) {
                elevenL = novaL;
                elevenC = novaC;
            } 
            else {
                printf("Obstaculo! Nao pode passar.\n");
            }
        } 
        else {
            printf("limite do mundo!\n");
        }

        if (!willSalvo) {
            mover_will();
        }

        if (vida <= 0) {
            printf("\nEleven morreu. Fim de jogo.\n");
            break;
        }
    }

    return 0;
}