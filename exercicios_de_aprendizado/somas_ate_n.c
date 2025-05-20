#include <stdio.h>

int main(){
    int n, soma = 0;

    printf("Escolha um numero n, que eu somarei de 1 até n: ");
    scanf("%i", &n);

    for (int inicio = 1; inicio <= n ; inicio++)
    {
        soma = soma + inicio;
    }
    printf("a soma de 1 até %i é igual a: %i", n, soma);
}