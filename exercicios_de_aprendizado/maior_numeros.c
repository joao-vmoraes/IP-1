#include <stdio.h>

int main(void){
    int n1, n2;
    printf("Escolha um número: ");
    scanf("%i", &n1);
    
    printf("Escolha mais um número: ");
    scanf("%i", &n2);
    
    if(n1 > n2)
    {
        printf("%i é maior que %i", n1,n2);
    }

    else if(n1 == n2)
    {
        printf("Os números sao iguais");
    }

    else
    {
        printf("%i é maior que %i",n2,n1);
    }
    return 0;
}