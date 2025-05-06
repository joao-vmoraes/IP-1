#include <stdio.h>
#include <math.h>

int main(void){
    float tempc;

    printf("Digite a temperatura em C para F: ");
    scanf("%f", &tempc);

    printf("A temperatura %fC e igual a %fF.", tempc, 1.8 * tempc + 32 );


    return 0;
}