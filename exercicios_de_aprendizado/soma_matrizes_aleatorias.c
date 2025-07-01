#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int matriz1[6][6], matriz2[6][6], matriz3[6][6];
    srand(time(NULL));

    /*matriz1*/
    for(int linha = 0 ; linha < 6 ; linha++){
        for(int coluna = 0 ; coluna < 6 ; coluna++){
            matriz1[linha][coluna] = rand() % 10;
        }
    }

    /*matriz 2*/
    for(int linha = 0 ; linha < 6 ; linha++){
        for(int coluna = 0 ; coluna < 6 ; coluna++){
            matriz2[linha][coluna] = rand() % 10;
        }
    }

    /*matriz 3 soma da 1° e 2°*/
    for(int linha = 0 ; linha < 6 ; linha++){
        for (int coluna = 0 ; coluna < 6 ; coluna++){
            matriz3[linha][coluna] = matriz1[linha][coluna] + matriz2[linha][coluna];
        }
    }
    
    /*impressao de todas as matrizes*/
    /*matriz 1 */
    
    printf("=== Matriz 1 ===\n");
    for(int linha = 0 ; linha < 6 ; linha++){
        for(int coluna = 0 ; coluna < 6 ; coluna++){
            printf("%i ", matriz1[linha][coluna]) ;
        }
        printf("\n");
    }
    printf("\n");
    
    /*matriz 2*/
    printf("=== Matriz 2 ===\n");
    for(int linha = 0 ; linha < 6 ; linha++){
        for(int coluna = 0 ; coluna < 6 ; coluna++){
            printf("%i ", matriz2[linha][coluna]) ;
        }
        printf("\n");
    }
    printf("\n");
    
    /*matriz 3*/
    printf("=== Matriz 3 (soma) ===\n");
    for(int linha = 0 ; linha < 6 ; linha++){
        for(int coluna = 0 ; coluna < 6 ; coluna++){
            printf("%2i  ", matriz3[linha][coluna]) ;
        }
        printf("\n");
    }
    printf("\n");
}