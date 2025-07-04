#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int tam = 10;
    int matriz[tam][tam], azul= 0, verde=0, amarelo=0, vermelho=0;

    for(int linha = 0 ; linha < tam ; linha++){
        for(int coluna = 0 ; coluna < tam ; coluna++){
            matriz[linha][coluna] = (rand() % 4) + 1;

            switch (matriz[linha][coluna])
            {
            case 1:
                azul++;
                break;
            case 2:
                verde++;
                break;
            case 3:
                amarelo++;
                break;
            case 4:
                vermelho++;
                break;
            default:
                break;
            }
        }
    }

    /*impressao da matriz*/
    for(int linha = 0 ; linha < tam ; linha++){
        for (int coluna = 0 ; coluna < tam ; coluna++){
            printf("%i ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nO jogo teve um total de:\nAzuis: %i\nVerdes: %i\nAmarelos: %i\nVermelhos: %i\n", azul, verde, amarelo, vermelho);
}