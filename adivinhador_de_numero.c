#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void){
    srand(time(NULL));

    int tentativas = 0,  chute, numero = rand() % 101;

    while (1)
    {
        printf("=======================================\n");
        printf("Tente adivinhar um numero entre 0 a 100: \n");
        scanf("%i", &chute);

        if (chute == numero)
        {
            tentativas++;
            printf("=======================================\n");
            printf("Parabens! Voce acertou, o numero escolhido foi %i,e voce acertou em %i tentativas!", numero, tentativas);
            break;
        }

        else if (chute > numero)
        {
            tentativas++;
            printf("=======================================\n");
            printf("O numero %i é maior que o número sorteado, tente novamente!\n", chute);
            printf("Numero de tentativas: %i\n",tentativas);
        }

        else if (chute < numero)
        {
            tentativas++;
            printf("=======================================\n");
            printf("O numero %i é menor que o numero sorteado,tente novamente!\n", chute);
            printf("Numero de tentativas: %i\n",tentativas);
        }
    }





}