#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(void){
    int tam = 3;
    float salarios[tam] , maior_salario = INT_MIN, menor_salario = INT_MAX;

    char nomes[tam][15], nome_menor_salario[15], nome_maior_salario[15];

    for(int linha = 0 ; linha < tam ; linha++){
        printf("\nQual o nome do %i funcionario; ", linha + 1);
        fgets(nomes[linha], 15 , stdin);

        printf("Qual o salario do %i funcionario: R$", linha + 1);
        scanf("%f", &salarios[linha]);
        getchar();

        if(salarios[linha] > maior_salario){
            maior_salario = salarios[linha];
            strcpy(nome_maior_salario, nomes[linha]);
        }
        if(salarios[linha] < menor_salario){
            menor_salario = salarios[linha];
            strcpy(nome_menor_salario, nomes[linha]);
        }
    }

    printf("O nome da pessoa que possui o maior salario é %sE ela possui: R$%.2f\n", nome_maior_salario, maior_salario);
    printf("O nome da pessoa que possui o menor salario é %sE ela possui: R$%.2f", nome_menor_salario, menor_salario);
}