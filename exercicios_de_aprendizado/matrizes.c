#include <stdio.h>
#include <string.h>

int main(void){
    int numeros [3][3];
    char nome[4][11];

    printf("Digite um numero: ");
    scanf("%i", &numeros[0][0]);
    getchar();

    printf("Seu numero foi: %i", numeros[0][0]);

    printf("Muito bem! Agora escreva seu primeiro nome: ");
    fgets(nome[0] /*para pegar a primeira linha*/, 11 , stdin);

    printf("Muito bem! Agora escreva seu segundo nome: ");
    fgets(nome[1] /*para pegar a segunda linha*/, 11 , stdin);

    printf("Seu primeiro e segundo nome é %s %s", nome[0], nome[1]);
    return 0;
}