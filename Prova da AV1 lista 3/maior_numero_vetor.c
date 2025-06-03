#include <stdio.h>

int main(){
    int numero, maior, menor,  maior_posicao, menor_posicao,  vetor[8], indice = 0;

    for(indice = 0 ; indice < 8 ; indice++)
    {
        printf("Escolha um numero para a posicao %i°: ", indice + 1);
        scanf(" %i", &numero);
        vetor[indice] = numero;

        if (indice == 0)
        {
            maior = vetor[indice];
            maior_posicao = indice + 1;
            menor = vetor[indice];
            menor_posicao = indice + 1;
        }
        else{
            if(vetor[indice] > maior){
                maior = vetor[indice];
                maior_posicao = indice + 1;
            }
            else if (vetor[indice] < menor)
            {
                menor = vetor[indice];
                menor_posicao = indice + 1;
            }
        }
    }

    printf("\nO maior numero foi: %i  e estava na %i° posicao ." , maior, maior_posicao);
    printf("\nO menor numero foi: %i  e estava na %i° posicao ." , menor, menor_posicao);
    return 0;
}