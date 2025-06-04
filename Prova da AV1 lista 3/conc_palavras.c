#include <stdio.h>
#include <string.h>

int main() {
    char primeira_string[202];
    char segunda_string[101];

    printf("Digite a primeira string: ");
    fgets(primeira_string, 202, stdin);

    printf("Digite a segunda string: ");
    fgets(segunda_string, 101, stdin);

    primeira_string[strcspn(primeira_string, "\n")] = '\0';

    strcat(primeira_string, segunda_string);

    printf("\nString concatenada: %s", primeira_string);

    return 0;
}