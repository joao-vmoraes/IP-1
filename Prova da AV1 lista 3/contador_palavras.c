#include <stdio.h>
#include <strings.h>

int main() {
    char frase[101];
    int indice = 0, contador_palavras = 0, fora_da_palavra = 1;

    printf("Digite uma frase para contar as palavras: ");
    fgets(frase, 101, stdin);

    while (frase[indice] != '\0') {
        if (frase[indice] == ' ' || frase[indice] == '\n' || frase[indice] == '\t') {
            fora_da_palavra = 1;
        } else {
            if (fora_da_palavra == 1) {
                contador_palavras++;
                fora_da_palavra = 0;
            }
        }
        indice++;
    }

    printf("O numero de palavras na frase e: %i\n", contador_palavras);

    return 0;
}