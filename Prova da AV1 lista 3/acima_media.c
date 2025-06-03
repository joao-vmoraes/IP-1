#include <stdio.h>

int main(){
    int vetor[5], numero, indice, acima_media = 0;
    float media = 0;

    for( indice = 0; indice < 5 ; indice++)
    {
        printf("Escolha um numero: ");
        scanf("%i", &numero);
        vetor[indice] = numero;
        media += vetor[indice];
    }

    media = media / indice;

    for(int indice = 0 ; indice < 5 ; indice++)
    {
        if(vetor[indice] > media){
            acima_media++;
        }
    }

    printf("a media foi: %.2f  e a quantidade de numeros acima dela foi: %i ", media, acima_media);
}