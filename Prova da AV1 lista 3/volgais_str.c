#include <stdio.h>
#include <strings.h>

int main() {
    char str[101];
    int vogais = 0;
    int indice;

    printf("Digite uma string (ate 100 caracteres): ");
    fgets(str, 101, stdin);

    for (indice = 0; str[indice] != '\0'; indice++) {
        if (str[indice] == 'a' || str[indice] == 'e' || str[indice] == 'i' || str[indice] == 'o' || str[indice] == 'u' ||
            str[indice] == 'A' || str[indice] == 'E' || str[indice] == 'I' || str[indice] == 'O' || str[indice] == 'U') {
            vogais++;
        }
    }

    printf("O numero de vogais na string e: %i\n", vogais);

    return 0;
}