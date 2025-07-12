#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}Ponto;

float distancia_ponto_centro( Ponto p , Ponto c)
{
    return sqrt(pow(p.x - c.x , 2) + pow(p.y - c.y , 2 ));
}

int verificar_ponto(Ponto p, Ponto c, float raio)
{
    if (distancia_ponto_centro(p , c ) > raio)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    Ponto ponto1, pontocentro;
    float raio;

    printf("Digite o x do centro: ");
    scanf("%f", &pontocentro.x);
    printf("Digite o y do centro: ");
    scanf("%f", &pontocentro.y);

    printf("Digite o x do ponto: ");
    scanf("%f", &ponto1.x);
    printf("Digite o y do ponto: ");
    scanf("%f", &ponto1.y);
    
    printf("Digite o raio: ");
    scanf("%f", &raio);

    float distancia = distancia_ponto_centro(ponto1 , pontocentro );
    int resultado = verificar_ponto(ponto1 , pontocentro , raio);

    if(resultado == 1)
    {
        printf("O ponto esta fora da circunferencia\n");
    }
    else
    {
        printf("O ponto esta dentro da circunferencia\n");
    }
        
    return 0;
}