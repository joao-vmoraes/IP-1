#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    int len, indice, palindromo = 1;

    printf("Digite uma string (ate 100 caracteres): ");
    fgets(str, 101, stdin);

    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    for (indice = 0; indice < len / 2; indice++) {
        if (str[indice] != str[len - 1 - indice]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo && len > 0) {
        printf("A string e um palindromo.\n");
    } else {
        printf("A string nao e um palindromo.\n");
    }

    return 0;
}