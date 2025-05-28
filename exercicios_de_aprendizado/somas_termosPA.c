//aplicativo de soma de termos de uma PA
#include <stdio.h>
int main(void){
    float a1,an,n, continuar = 2;


    while (continuar == 2){
        printf("\n=======SOMADOR=DE=TERMOS=======");
        printf("\nEscolha o primeiro termo ,ultimo termo e a quantidade de termos da sua PA\n (formato:a1 an n) : ");
        scanf(" %f %f %f", &a1, &an, &n);

        float soma = (a1 + an) * n / 2;
        printf("\nA soma dos termos dessa PA é: %.2f", soma);

        printf("\nVocê deseja encerrar o programa?([1] = SIM / [2] = NÃO) :");
        scanf(" %f", &continuar);
    }
    printf("Programa ecncerrado! Volte mais tarde!");
    return 0;
}