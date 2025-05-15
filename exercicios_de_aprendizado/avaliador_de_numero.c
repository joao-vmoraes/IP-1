#include <stdio.h>


int main(void){

    float numero;

    printf("Escolha um número qualquer: ");
    scanf("%f", &numero);

    if (numero < 0)
    {
        printf("%f é menor que 0.", numero);
    }

    if (numero ==0)
    {
        printf("0 é igual a zero");
    }

    if (numero > 0)
    {
        printf("%f é maior que 0.", numero);
    }

    return 0;
}