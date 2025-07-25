#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

  int* p = malloc(sizeof(int)); //reservando 4 bytes na memoria, = 1 int
  *p = 10;
  p = realloc(p, 10 * sizeof(int)); //realocando para 40 bytes na memoria, agora o total sao de 10 int
  p = realloc(p, 5 * sizeof(int)); //realocando para 20 bytes na memoria, agora o total sao de 5 int

return 0;
    
}