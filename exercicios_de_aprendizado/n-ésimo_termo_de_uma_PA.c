//somas dos termos de uma pa
#include <stdio.h>

int main(void){
    int a1, n, razao, escolha;
    while(1)
    {
        printf("\n===Analizador de PA===");
        printf("\nEscolha o primeiro termo: ");
        scanf(" %i", &a1);

        printf("\nEscolha o n-ésimo termo que você quer saber: ");
        scanf(" %i", &n);
        
        printf("\nEscolha agora a razão da PA: ");
        scanf(" %i", &razao);
        
        int an = a1 + (n - 1) * razao;
        printf("O valor do termo de posição %i° é %i", n, an);

        printf("\nDeseja fazer uma nova análise?\n [1] = sim, [2] = não  : ");
        scanf(" %i", &escolha);
        switch(escolha){
            case 2:
                return 0;
            default:
                break;
        }

    }
}