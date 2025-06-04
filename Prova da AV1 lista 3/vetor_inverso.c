#include <stdio.h>

int main(){
    int vetor[5], numero, indice;

    for(int indice = 0; indice < 5 ; indice++)
    {
        printf("Escolha um numero: ");
        scanf("%i", &numero);
        vetor[indice] = numero;
    } 

    for (; indice != 0; indice --)
    {
        printf("%i,", vetor[indice]);
    }

    return 0;
}