//Crie um programa que pede ao usuário um número X, e imprima o
//X-ésimo valor da sequência.

#include <stdio.h>

int main(){
    int n1 = 0, n2 = 1, n3 = 0, numero, contador = 1;

    //pedindo o x-ésimo valor
    printf("Escolha o x-ésimo valor da sequencia de Fibonacci: ");
    scanf("%i", &numero);

    while(contador <= numero)
    {
        printf("\n%i", n1);
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
        contador++;
    }
}