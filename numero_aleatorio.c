#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL));
    
    printf("Vou sortear um numero para voce!");

    int numero = rand() % 11;
    printf("Seu numero foi: %i ", numero);
}