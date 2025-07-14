#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
int tam = 2, id = 1;

typedef struct
{
    char nome[10];
    float defesa; // 0 a 10
    float ataque; // 0 a 10
    float vida; // 0 a 100
    float precisao;
    int id; 
}Jogador;

Jogador times[2][4]; // criando times, linhas = time, colunas = jogadores.

void criarJogador(Jogador *a,int i, int c, int id) // funcao de cirando jogador e printando os atributos
{
    printf("==== time%i: jogador %i ====\n", i+1, id);

    a->ataque = 5 + rand()%6;
    a->defesa = 5 + rand()%5;
    a->vida = 70 + rand()%31;
    a->id = id;
    a->precisao = 1 - (a->vida * a->ataque)/4000;
    printf("ataque do jogador: %.1f\n", a->ataque);
    printf("defesa do jogador: %.1f\n", a->defesa);
    printf("vida do jogador: %.1f\n", a->vida);
    printf("==========================\n");
}

void criar_times()  // funcao para criar os times
{
    for (int i = 0 ; i < tam ; i++)
        {
            printf("====== TIME %i ======\n", i +1);
            printf("\n");
            for(int c = 0; c < tam + 2  ; c++)
                {
                    criarJogador(&times[i][c], i, c, id);
                    id++;
                }
            printf("\n\n");
        }
}
void listar_oponentes(int i)  // cfuncao para listar os oponentes
{   
    printf("====== oponentes ======\n");
    if (i == 0)
    {
        for (int k = 1 ; k == 1; k++)
            {
                for(int c = 0 ; c < tam + 2 ; c++)
                    {
                        printf("vida do jogador %i : %.2f\n", times[k][c].id, times[k][c].vida);
                    }
            }
    }

    else
    {
        for (int k = 0 ; k == 0; k++)
            {
                for(int c = 0 ; c < tam + 2 ; c++)
                    {
                        printf("vida do jogador %i : %.2f\n", times[k][c].id, times[k][c].vida);
                    }
            }
    }
}

int acertou_golpe(Jogador *a)// funcao para calcular a precisao do jogador
{
    a->precisao = (a->ataque * 0.05 + a->defesa * 0.04 + a->vida * 0.001); //opitei por fazer esse calculo da precisao pois deixa o jogo priorizar mais todos os atributos do proprio jogador.
    if (a->vida <= 0 ){a->precisao = 0;}
    else if (a->precisao < 0.1) {a->precisao = 0.1;}
    else if (a->precisao > 0.9) {a->precisao = 0.9;}

    float prob = (float)(rand() % 100) / 100.0f; // erro da prob sempre ser 0.
    if (a->precisao > prob)
    {return 1;}
        
    else{return 0;}
}

float atacar(Jogador *ataque, Jogador *defesa) {
    float dano_calculado = ataque->ataque / (defesa->defesa/10.0);
    defesa->vida = defesa->vida - dano_calculado;
    if (defesa->vida <= 0) {
        defesa->vida = 0;
    }
    return dano_calculado;
}

int time_morto() // funcao para verificar se qualqet time esta morto
{
    for (int i = 0; i < 2; i++) {
        int mortos = 0;
        for (int c = 0; c < tam + 2; c++) {
            if (times[i][c].vida <= 0)
                mortos++;
        }
        if (mortos == tam + 2)
        {return i + 1;}
    }
    return -1;
}
int time_vencedor()
{   
    int vencedor = time_morto();
    if ( vencedor == 1 ) {return 2;}
    if ( vencedor == 2 ) {return 1;}
}


void jogar(int *vez_de_jogar)
{
    int oponente, timemorto = time_morto(), vida_inimigo_antes_golpe;
    
    if (*vez_de_jogar == 0) // linha time 1 comeca
        {
            for(int i = 0 ; i == 0 ; i++)
                {
                    printf("\n\n====== VEZ DO TIME %i ======\n\n", i+1);
                    listar_oponentes(i);
                    printf("\n\n");
                    for (int c = 0 ; c < tam + 2 ; c++)
                    {
                        printf("O jogador %i vai tentar atacar, precisao: %.2f\n", times[i][c].id, times[i][c].precisao);
                        do{
                            oponente= rand() % 4;
                            timemorto = time_morto();
                        }while(times[1][oponente].vida <= 0 && timemorto == -1);

                        int acertou = acertou_golpe(&times[i][c]);
                        if (times[i][c].vida <= 0)
                            {
                                printf("O jogador %i esta morto\n\n", times[i][c].id);
                            }
                        else if (acertou == 1 && times[i][c].vida > 0  && times[1][oponente].vida > 0)
                        {    
                            vida_inimigo_antes_golpe = times[1][oponente].vida;
                            float dano = atacar(&times[i][c], &times[1][oponente]);
                            printf("jogador %i atacou o jogador %i, dano: %.2f\n", times[i][c].id, times[1][oponente].id, dano);
                            timemorto = time_morto();
                        }
                        else{printf("O jogador %i errou o ataque\n", times[i][c].id);}
                        printf("\n\n\n\n");
                    }
                    printf("Nova vida dos oponentes:\n");
                    listar_oponentes(i);

                }
            *vez_de_jogar = 1;
        }

        else // linha 1 comeca
        {
            for(int i = 1 ; i == 1 ; i++)
                    {
                        printf("\n\n====== VEZ DO TIME %i ======\n\n", i+1);
                        listar_oponentes(i);
                        printf("\n\n");
                        for (int c = 0 ; c < tam + 2 ; c++)
                        {
                            printf("O jogador %i vai tentar atacar, precisao: %.2f\n", times[i][c].id, times[i][c].precisao);
                            do{
                                oponente= rand() % 4;
                                timemorto = time_morto();
                            }while(times[0][oponente].vida <= 0 && timemorto == -1);

                            int acertou = acertou_golpe(&times[i][c]);
                            if (times[i][c].vida <= 0)
                            {
                                printf("O jogador %i esta morto\n\n", times[i][c].id);
                            }
                            else if (acertou == 1 && times[i][c].vida > 0 && times[0][oponente].vida > 0)
                            {
                                vida_inimigo_antes_golpe = times[0][oponente].vida;
                                float dano = atacar(&times[i][c], &times[0][oponente]);
                                printf("jogador %i atacou o jogador %i, dano: %.2f\n\n\n", times[i][c].id, times[0][oponente].id, dano);
                                timemorto = time_morto();
                            }                                
                            else
                            {
                                printf("O jogador %i errou o ataque\n", times[i][c].id);
                                printf("\n\n\n\n");
                            }
                        }
                        printf("Nova vida dos oponentes:\n");
                        listar_oponentes(i);
                    }
            *vez_de_jogar = 0;
        }
}

int main(void){
    srand(time(NULL));
    int tempo = 1, i = 0 , vez_de_jogar = rand() % 2, oponente;
    char _;
    printf("====== INICIO DO JOGO ======\n");
    printf("=-=-=- Final Fantasy 1 =-=-=-\n");
    printf("aperte ENTER para iniciar.\n>>>");
    scanf("%c", &_);
    printf("\n\nCriando times...Aguarde\n\n");
    sleep(tempo);
    criar_times();
    printf("\n\nSorteando time inicial...Aguarde.\n\n");
    sleep(tempo);
    printf("O time %i comeca jogando, carregando...\n\n", vez_de_jogar + 1);
    sleep(tempo);
    
    

    printf("\n\n\n\n");

    int timemorto = -1;
    
    while (1)          //loop que so quebra se todos de alguma linha estiverem mortos
    {
        jogar(&vez_de_jogar);

        timemorto = time_morto();
        if (timemorto != -1)
            {
                break;
            }
    }

    printf("\n\n\n\n====== FIM DO JOGO ======\n");
    int vencedor = time_vencedor();
    printf("O time %i venceu pois todos os lutadores do time inimigo morreram!\n", vencedor);
    


    return 0;
}