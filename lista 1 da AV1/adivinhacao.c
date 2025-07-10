#include <stdio.h>

int main(){
    int tentativas = 15, restantes = 3, acertou;
    char c1, c2, c3, chute;

    printf("\nEscolha 3 caracteres(alfabéticos) para seu amigo tentar adivinhar\n(formato: c1 c2 c3): ");
    scanf(" %c %c %c", &c1, &c2, &c3);

    while(1)
    {
        printf("\n==============");
        printf("\nTentativas restantes: %i", tentativas);
        printf("\nCaracteres Restantes: %i", restantes);
        printf("\nEscolha uma tentativa: ");
        scanf(" %c", &chute);
        tentativas--;
        
        if  (chute == c1)
        {
            c1 = 0;
            printf ("\nVoce acertou!");
            restantes--;
            acertou = 1;
        }
        
        if  (chute == c2)
        {
            c2 = 0;
            printf ("\nVoce acertou!");
            restantes--;
            acertou = 1;
        }
        
        if  (chute == c3)
        {
            c3 = 0;
            printf ("\nVoce acertou!");
            restantes--;
            acertou = 1;
        }
        
        if (acertou == 0)
        {
            printf("\nVocê errou!"); 
        }
        
        if (restantes == 0){
            printf("\n==============");
            printf("\nVocê ganhou o jogo!  Parabens");
            printf("\n==============");
            return 0;
        }
        
        else if( tentativas == 0)
        {
            printf("\n==============");
            printf("\nSuas tentativas acabaram, voce perdeu!");
            printf("\n==============");
            return 0;
        }

        acertou = 0;

    }
}