#include <stdio.h>

int main(void){
    char letra = 'c';

    while(letra != 'x')
    {
    printf("Escolha uma letra (x para parar): ");
    scanf(" %c", &letra);

    }
    printf("FIM");
    return 0;
}