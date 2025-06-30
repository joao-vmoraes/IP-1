#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int l ,c;
    
    printf("Qual a quantidade de linhas e colunas(formato: linha coluna): ");
    scanf("%i %i", &l, &c);
    int matriz[l][c];
    printf("\n");


    for(int linha = 0 ; linha < l ; linha++){
        for(int coluna = 0 ; coluna < c ; coluna++){
            matriz[linha][coluna] = rand() % 10;
        }
    }

    for(int linha = 0 ; linha < l ; linha++){
        for(int coluna = 0 ; coluna < c ; coluna++){
            printf("%i ", matriz[linha][coluna]);
        }
        printf("\n");
    }

}
