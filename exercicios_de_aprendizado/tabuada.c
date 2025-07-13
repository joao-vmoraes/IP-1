#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void tabuada(int n1)
{
    for ( int i = 1; i < 11 ; i++)
        {
            printf("%i x %i = %i\n", n1, i, n1*i);
        }
}

int main(){
    int numero;
    printf("Digite um numero: ");
    scanf("%i", &numero);
    
    tabuada(numero);
}