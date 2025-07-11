#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float soma(float numero1, float numero2)
{
    float resultado  = numero1 + numero2;
    return resultado;
}

float sub(float numero1, float numero2)
{
    float resultado  = numero1 - numero2;
    return resultado;
}

float multiplicacao(float numero1, float numero2)
{
    float resultado  = numero1 * numero2;
    return resultado;
}

float divisao(float numero1, float numero2)
{
    float resultado  = numero1 / numero2;

    if (numero2 == 0){
        printf("ERRO: divisao por zero\n");
    }
    else {
        return resultado;
    }
}

int main(){
    int    continuar = 1;
    float numero1, numero2;
    char operador;

    while (continuar == 1){
        printf("\n=== CALCULADORA ===\n");
        printf("faca seu calculo:\n");
        printf(">>> ");
        getchar();
        scanf("%f %c %f", &numero1, &operador, &numero2);


        switch (operador)
        {
        case '+':
            printf(" %.2f ", soma(numero1 , numero2));
            break;
        case '-':
            printf(" %.2f ", sub(numero1 , numero2));
            break;
        case '*':
            printf(" %.2f ", multiplicacao(numero1 , numero2));
            break;
        case '/':
            printf(" %.2f ", divisao(numero1 , numero2));
            break;

        default:
            break;
        }
        printf("\nDeseja continuar? [1- sim / 2 - nao] ");
        scanf("%i", &continuar);
    }

    return  0;
}