#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL));

    int numero = rand() % 11;
    printf("Seu numero foi: %i ", numero);
}