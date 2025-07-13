#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void repetir_char(char c, int v)
{
    for (int i = 0; i < v; i++)
        {
            printf("%c", c);
        }
}

int main(){
    int v;
    char n;
    printf("Digite um numero: ");
    scanf("%d", &v);
    printf("Digite um caracter: ");
    scanf(" %c", &n);
    repetir_char(n, v);
}