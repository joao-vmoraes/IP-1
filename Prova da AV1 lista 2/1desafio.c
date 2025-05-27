#include <stdio.h>

int main(void){
    int raiz, sub = 0, numero;

    printf("\nEscolha um número e eu direi a raiz dele: ");
    scanf(" %i" , &numero);
    
    int numero_base = numero;

    for(int impar = 1 ; numero > 0 ; impar += 2){
        numero_base = numero_base - impar;
        sub ++;

        if (numero_base < 0){
            printf("\nA raiz de %i esta entre %i e %i", numero , (sub - 1), sub);
            break;}
        
        else if(numero_base == 0){
            printf("\nA raiz de %i é %i", numero, sub);
            break;}
        
    }
    if (numero == 0){
            printf("A raiz de 0 é 0");}
        
    else if(numero < 0){
            printf("O número não possui raiz quadrada real.");}
}