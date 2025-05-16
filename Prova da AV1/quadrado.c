//desenhar um quadrado de lado x e suas diagonais
//linha = l, coluna = c
#include <stdio.h>

int main(){
    int lado;
    
    printf("Escolha o lado de um quadrado: ");
    scanf("%i", &lado);
    

    for (int c = 1; c <= lado; c++)
    {   
        for ( int l = 1; l <= lado; l++)
            {
                if (c == 1 ||  l == 1 || l == lado  || c == lado  || l == c || l + c == lado + 1) // tive que pesquisar sobre essa propriedade da diagonal secundaria  ' l + c = lado + 1 '
                {
                    printf("[]");
                }
                
                else
                {
                    printf("  ");
                }
            }
        printf("\n");
    }
}