#include <stdio.h>
#include <string.h>

int main() {
    printf("====JOGO DA FORCA===\n\n");

    char palavra_secreta[] = "secreto";
    int tamanho_palavra = strlen(palavra_secreta), tentativas_restantes = 6, letras_acertadas = 0, i, acerto;
    char palavra_mostrada[tamanho_palavra * 2 + 1];
    char letra_digitada;

    for (i = 0; i < tamanho_palavra; i++) {
        palavra_mostrada[i * 2] = '_';
        palavra_mostrada[i * 2 + 1] = ' ';
    }
    palavra_mostrada[tamanho_palavra * 2] = '\0';

    while (tentativas_restantes > 0 && letras_acertadas < tamanho_palavra) {
        printf("Palavra: %s\n", palavra_mostrada);
        printf("Tentativas restantes: %d\n", tentativas_restantes);
        printf("Digite uma letra: ");
        scanf(" %c", &letra_digitada);

        acerto = 0;
        for (i = 0; i < tamanho_palavra; i++) {
            char char_secreto = palavra_secreta[i];
            char char_digitado = letra_digitada;

            if (char_secreto >= 'A' && char_secreto <= 'Z') {
                char_secreto += 32;
            }
            if (char_digitado >= 'A' && char_digitado <= 'Z') {
                char_digitado += 32;
            }

            if (char_secreto == char_digitado) {
                if (palavra_mostrada[i * 2] == '_') {
                    palavra_mostrada[i * 2] = palavra_secreta[i];
                    letras_acertadas++;
                }
                acerto = 1;
            }
        }

        if (acerto == 0) {
            tentativas_restantes--;
            printf("Letra incorreta!\n");
        }
        
        printf("\n-----------------\n");
    }

    if (letras_acertadas == tamanho_palavra) {
        printf("Parabens! Voce acertou a palavra: %s\n", palavra_secreta);
    } else {
        printf("Voce perdeu! A palavra secreta era: %s\n", palavra_secreta);
    }

    return 0;
}