#include <stdio.h>
#include <math.h>

int main(){
    int raio, x_centro, y_centro, x_ponto, y_ponto, escolha;
    
    while (escolha = 1)
    {
        printf("==================\n");
        printf("Escolha os valores do raio, posição x e posição y do centro da circunferencia \n (no formato:r x y): ");
        scanf(" %i %i %i",&raio, &x_centro, &y_centro);
        
        printf("\n==================\n");
        printf("Agora escolha ums posição x e uma y de um ponto qualquer e eu falarei se esta dentro da circunferencia\n (no formato:x y): ");
        scanf(" %i %i", &x_ponto, &y_ponto);

        float distancia = sqrt(pow(x_centro - x_ponto, 2) + pow(y_centro - y_ponto, 2));
        
        if (distancia <= raio)
        {
            printf("O ponto (%i,%i) esta dentro da circunferencia, e a distancia até o centro é de %.2f", x_ponto,  y_ponto, distancia);
        }
        
        else
        {
            printf("O ponto (%i,%i) esta fora da circunferencia, e a distancia até o centro é de %.2f", x_ponto,  y_ponto, distancia);
        }

        printf("Deseja continuar novamente? ([1] = sim / [2 = não ]) : ");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
            continue;
            break;
        
        default:
            printf("Até logo!");
            return 0;
        }
    }
    }