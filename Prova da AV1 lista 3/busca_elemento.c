#include <stdio.h>

int main(){
    int vetor[10], numero, indice, indentificador, igualdade = 0;

    for(indice = 0 ; indice < 10; indice ++)
    {
        printf("Escolha um numero: ");
        scanf("%i", &numero);
        vetor[indice] = numero;
    }

    printf("Escolha um numero para verificar se esta no vetor: ");
    scanf("%i", &indentificador);

    for(indice = 0; indice < 10; indice++)
    {
        if(vetor[indice] == indentificador)
        {
            printf("O numero %i foi encontrado na posicao : %i°", indentificador, indice + 1);
            igualdade = 1;
            break;
        }
        
    }
    if (igualdade == 0){
        printf(" o numero %i nao foi encontrado no vetor!", indentificador);
    }

    return 0;
}