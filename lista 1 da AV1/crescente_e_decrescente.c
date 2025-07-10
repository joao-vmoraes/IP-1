///Implemente um programa que receba um número inteiro n e imprima uma sequência de
//números de 1 a n, mas alternando entre crescente e decrescente.

#include <stdio.h>

int main(){
    int numero, menor = 1;

    printf("Escolha um numero: ");
    scanf("%i", &numero);
    int numero_provisorio = numero;

    for(int quantidade = 1; quantidade <= numero_provisorio; quantidade++)
    {

        if (quantidade % 2 == 0){
            printf("\n%i", numero);
            numero--;

        }

        else{
            printf("\n%i", menor);
            menor++;

        }
    }
}