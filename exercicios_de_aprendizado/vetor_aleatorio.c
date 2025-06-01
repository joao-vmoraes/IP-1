//faça um vetor real de 5 elementos e eles sejam aleatorios usando laços de repetiçaõ

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    srand(time(NULL));
    int inteiros[5];

    printf("=====Vetor Aleatório=====");
    for(int indice = 0; indice <= 4 ; indice ++)
    {
        inteiros[indice] = rand() % 10;
        printf("\n %i é o número de posicao: %i°" , inteiros[indice], indice + 1);
    }

    return 0;
}