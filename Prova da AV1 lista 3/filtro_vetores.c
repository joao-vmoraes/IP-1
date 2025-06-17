 //dois vetores aleatorios mesmos tamanhos, o primeiro tem que ser impar, o segundo tem que ser par, e o terceiro o filtro deles

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    
    int impar[5], numero_aleatorio;
    int par[5],indice_resto = 0;
    int resto[10];
    
    for(int indice = 0; indice < 5; indice++)//impares
    {
        numero_aleatorio = rand() % 50;
        
        if(numero_aleatorio % 2 == 1 )
        {
            impar[indice] = numero_aleatorio; 
        }
        else
        {
            impar[indice] = 0;
            resto[indice_resto] = numero_aleatorio;
            indice_resto++;
        }
    }
    
    //pares
    for(int indice = 0; indice < 5; indice++)
    {
        numero_aleatorio = rand() % 50;
        
        if (numero_aleatorio % 2 == 0)
        {
            par[indice] = numero_aleatorio;
        }
        else
        {
            par[indice] = 0;
            resto[indice_resto] = numero_aleatorio;
            indice_resto++;
        }
    }
    

    //print dos vetores
    //vetor impar
    printf("Vetor impar: ");
    for(int indice = 0; indice < 5; indice++)
    {
        printf("%i " , impar[indice]);
    }
    //vetor par
    printf("\n===============================");
    printf("\n");
    printf("Vetor par  : ");
    for(int indice = 0; indice < 5; indice++)
    {
        printf("%i ", par[indice]);
    }
    //vetor aleatorio
    printf("\n================================");
    printf("\n");
    printf("Vetor resto: ");
    for(int indice = 0;indice < indice_resto; indice++)
    {
        printf("%i ", resto[indice]);
    }
    
}