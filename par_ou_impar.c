#include <stdio.h>

int main(void){
    printf("Escolha um número e eu direi se é par ou impar: ");
    int numero;
    scanf("%i", &numero);

    if (numero % 2 == 0)
    {
        printf("O número %i é par", numero);
    }

    else
    {
        printf("O número %i é impar", numero);
    }

    return 0;
}