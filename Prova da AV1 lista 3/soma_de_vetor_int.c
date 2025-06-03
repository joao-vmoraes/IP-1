#include <stdio.h>

int main(){
    int vetor[10];
    int numero, soma = 0;

    for(int indice = 0 ; indice <= 9 ; indice++)
    {
        printf("Digite o numero de posição %i° : ", indice  + 1);
        scanf(" %i", &numero);
        vetor[indice] = numero;
        soma += numero;
    }
    printf("================");
    printf("\n Soma dos elementos do Vetor: %i", soma);
}