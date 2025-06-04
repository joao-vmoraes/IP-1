#include <stdio.h>
#include <strings.h>

int main() {
    char frase[101];
    int leitor, escritor;

    printf("Digite uma frase (ate 100 caracteres): ");
    fgets(frase, 101, stdin);

    escritor = 0;
    for (leitor = 0; frase[leitor] != '\0'; leitor++) {
        if (frase[leitor] != ' ') {
            frase[escritor] = frase[leitor];
            escritor++;
        }
    }
    frase[escritor] = '\0';

    printf("Frase sem espacos: %s", frase);

    return 0;
}