#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    float media;
    int idade;
}Aluno;

Aluno preenche_aluno(){
    char nome[30];
    Aluno aluno;

    printf("\nDigite o nome do aluno: ");
    scanf("%s", nome);
    strcpy(aluno.nome, nome);
    printf("Digite a idade do aluno: ");
    scanf("%i", &aluno.idade);
    printf("Digite a media do aluno: ");
    scanf("%f", &aluno.media);

    return aluno;

}

int main(void){

    Aluno aluno = preenche_aluno();
    printf("O aluno %s, de %i anos, tem media %.2f\n", aluno.nome, aluno.idade, aluno.media);

    return 0;
}