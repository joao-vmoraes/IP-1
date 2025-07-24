#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

int* a = NULL;
  a = (int*) malloc(5 * sizeof(int));
for (int i = 0; i < 5; i++)
    {
    a[i] = i;
    printf("%i\n", a[i]);
    }
}