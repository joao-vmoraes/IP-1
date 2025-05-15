#include <stdio.h>
#include <math.h>

int main(){
    int  idade, opcao_bebida, opcao_cerveja, opcao_whisky, opcao_vodka, quantidade, continuar = 1;
    float preco;

    ///PERGUNTANDO IDADE
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\nMe diga a sua idade: ");
    scanf("%i", &idade);

    while(idade < 18)
    {
        printf("Você é menor de idade! Mete o fora!");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\nMe diga a sua idade: ");
        scanf("%i", &idade);
    }


    while(continuar == 1)
    {
        
        

        //HORA DO MENU
        printf("=====MENU DE BEBIDAS===");
        printf("\n[1] Cerveja");
        printf("\n[2] Whisky");
        printf("\n[3] Vodka");
        printf("\nEscolha: ");
        scanf(" %i", &opcao_bebida);

        //condicional para cada bebida

        //CERVEJA MENU
        if (opcao_bebida == 1)
        {
            printf("===MENU DE CERVEJAS===");
            printf("\n[1] Itaipava  R$8,00");
            printf("\n[2] Brahma    R$7,00");
            printf("\n[3] Heineken  R$9,00");
            printf("\nEscolha: ");
            scanf("%i", &opcao_cerveja);

            switch(opcao_cerveja)
            {
                case 1: // OPÇÂO ITAIPAVA
                printf("\nSelecione a quantidade de x: ");
                scanf("%i", &quantidade);
                while (quantidade < 1)
                {
                    printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                    scanf("%i", &quantidade);
                }
                preco = 8;
                if (0 < quantidade && quantidade < 5){
                    printf("\nVocê comprou %i Itaipavas, valor total: R$%.2f", quantidade,quantidade * preco);}

                else if (4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Itaipavas, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                else if (49 < quantidade && quantidade < 100){
                    printf("\nVocê comprou %i Itaipavas, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 0.7);}

                else  if (99 < quantidade ){
                    printf("\nVocê comprou %i Itaipavas, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 0.65);}
                break;

                //OPÇÂO BRAHMA
                case 2:
                printf("\nSelecione a quantidade de x: ");
                scanf("%i", &quantidade);
                while (quantidade < 1)
                {
                    printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                    scanf("%i", &quantidade);
                }
                preco = 7;
                if (0 < quantidade && quantidade < 5){
                    printf("\nVocê comprou %i Brahmas, valor total: R$%.2f", quantidade,quantidade * preco);}

                else if (4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Brahmas, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                else if (49 < quantidade && quantidade < 100){
                    printf("\nVocê comprou %i Brahmas, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                else if (99 < quantidade ){
                    printf("\nVocê comprou %i Brahmas, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                
                break;

                ///OPCAO HEINEKEN
                case 3:
                printf("\nSelecione a quantidade de Heineken: ");
                scanf("%i", &quantidade);
                while (quantidade < 1)
                {
                    printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                    scanf("%i", &quantidade);
                }
                preco = 9;
                if (0 < quantidade && quantidade < 5){
                    printf("\nVocê comprou %i Heinekens, valor total: R$%.2f", quantidade,quantidade * preco);}

                else if (4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Heinekens, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                else if (49 < quantidade && quantidade < 100){
                    printf("\nVocê comprou %i Heinekens, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                else if (99 < quantidade ){
                    printf("\nVocê comprou %i Heinekens, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                break;
                }}

        ///MENU DE WHISKY AGORAAAAAAA
        else if (opcao_bebida == 2)
        {
            printf("\n===MENU DE WHISKY===");
            printf("\n[1] Johnnie Walker Red Label      R$150,00");
            printf("\n[2] Johnnie Walker Black Label    R$200,00");
            printf("\n[3] Whisky Jack Daniels           R$170,00");
            printf("\nEscolha: ");
            scanf("%i", &opcao_whisky);

            ///RED LABELLLLLL
            switch(opcao_whisky)
            {
                case 1:
                    printf("\nSelecione a quantidade de Red Label: ");
                    scanf("%i", &quantidade);
                    while (quantidade < 1)
                    {
                        printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                        scanf("%i", &quantidade);
                    }
                    preco = 150;
                    if (0 < quantidade && quantidade < 5){
                        printf("\nVocê comprou %i Red Labels, valor total: R$%.2f", quantidade,quantidade * preco);}

                    else if(4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Red Labels, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                    else if (49 < quantidade && quantidade < 100){
                        printf("\nVocê comprou %i Red Labels, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                    else if (99 < quantidade ){
                        printf("\nVocê comprou %i Red Labels, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                    break;
            
                    //BLACK LABELLLL
                case 2:
                    printf("\nSelecione a quantidade de Black Labels: ");
                    scanf("%i", &quantidade);
                    while (quantidade < 1)
                    {
                        printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                        scanf("%i", &quantidade);
                    }
                    preco = 200;
                    if (0 < quantidade && quantidade < 5){
                        printf("Você comprou %i Black Labels, valor total: R$%.2f", quantidade,quantidade * preco);}

                    else if(4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Black Labels, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                    else if (49 < quantidade && quantidade < 100){
                        printf("\nVocê comprou %i Black Labels, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                    else if (99 < quantidade ){
                        printf("\nVocê comprou %i Black Labels, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                    break;
                
                //JACK DANIELSS's
                case 3:
                    printf("\nSelecione a quantidade de Jack Daniel's: ");
                    scanf("%i", &quantidade);
                    while (quantidade < 1)
                    {
                        printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                        scanf("%i", &quantidade);
                    }
                    preco = 200;
                    if (0 < quantidade && quantidade < 5){
                        printf("\nVocê comprou %i Jack Daniel's, valor total: R$%.2f", quantidade,quantidade * preco);}

                    else if(4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Jack Daniel's, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                    else if (49 < quantidade && quantidade < 100){
                        printf("\nVocê comprou %i Jack Daniel's, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                    else if (99 < quantidade ){
                        printf("\nVocê comprou %i Jack Daniel's, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                    break;
        }
        }
        
        ///MENU DE VODKAAAAAAA
        else if (opcao_bebida == 3)
        {
            printf("\n===MENU DE VODKA===");
            printf("\n[1] Smirnoff          R$50,00");
            printf("\n[2] Ciroc             R$80,00");
            printf("\n[3] ketel One         R$60,00");
            printf("\nEscolha: ");
            scanf("%i", &opcao_vodka);

            ///OPÇÕES DE VODKAAA
            switch(opcao_vodka) {
            case 1:
                printf("\nSelecione a quantidade de Smirnoffs: ");
                scanf("%i", &quantidade);
                while (quantidade < 1)
                {
                printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                    scanf("%i", &quantidade);
                }
                preco = 50;
                if (0 < quantidade && quantidade < 5){
                    printf("\nVocê comprou %i Smirnoffs, valor total: R$%.2f", quantidade,quantidade * preco);}

                else if(4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Smirnoffs, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                else if (49 < quantidade && quantidade < 100){
                    printf("\nVocê comprou %i Smirnoffs, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                else if (99 < quantidade ){
                    printf("\nVocê comprou %i Smirnoffs, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                break;

                ////OPÇÃO DE CIROCSS
                case 2:
                printf("\nSelecione a quantidade de Cirocs: ");
                scanf("%i", &quantidade);
                while (quantidade < 1)
                {
                printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                    scanf("%i", &quantidade);
                }
                preco = 80;
                if (0 < quantidade && quantidade < 5){
                    printf("\nVocê comprou %i Cirocs, valor total: R$%.2f", quantidade,quantidade * preco);}

                else if(4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i Cirocs, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                else if (49 < quantidade && quantidade < 100){
                    printf("\nVocê comprou %i Cirocs, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                else if (99 < quantidade ){
                    printf("\nVocê comprou %i Cirocs, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                break;


                case 3:
                printf("\nSelecione a quantidade de ketel One's: ");
                scanf("%i", &quantidade);
                while (quantidade < 1)
                {
                printf("\nPara de graça e fala serio, escolha uma quantidade valida: ");
                    scanf("%i", &quantidade);
                }
                preco = 60;
                if (0 < quantidade && quantidade < 5){
                    printf("\nVocê comprou %i ketel One's, valor total: R$%.2f", quantidade,quantidade * preco);}

                else if(4 < quantidade && quantidade < 50){
                    printf("\nVocê comprou %i ketel One's, valor total: R$%.2f (10/100 de desconto)", quantidade,(quantidade * preco) * 0.9);}

                else if (49 < quantidade && quantidade < 100){
                    printf("\nVocê comprou %i ketel One's, valor total: R$%.2f (30/100 de desconto)", quantidade,(quantidade * preco) * 70/100);}

                else if (99 < quantidade ){
                    printf("\nVocê comprou %i ketel One's, valor total: R$%.2f (35/100 de desconto)", quantidade,(quantidade * preco) * 65/100);}
                break;
                }
        }
    printf("\nDeseja fazer uma nova compra? [1] Sim / [2] Não : ");
    scanf("%i", &continuar);}

    }


