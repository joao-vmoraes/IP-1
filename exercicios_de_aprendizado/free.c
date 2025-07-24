#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int* p = NULL;
    p = (int*) malloc(sizeof(int));
    *p = 999;
    printf("%p", p);
    printf("\n%i", *p);
    free(p); // limpando a memoria
    p = NULL; // limpando o ponteiro, recomendado!
    
}