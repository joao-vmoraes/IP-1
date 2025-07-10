#include <math.h>
#include <stdio.h>

int main(){
    int idade, valor ,  continuar = 1, opcao_bebida, opcao_cerveja, quantidade, preco, valor_total_cliente = 0, valor_total_dia = 0, opcao_whisky, opcao_vodka, opcao_cachaca, cancelar_cliente;
    
    //PERGUNTANDO IDADE PARA PROSSEGUIR
    printf("\n===NOVO CLIENTE===");
    printf("\nMe diga a sua idade antes de prosseguirmos: ");
    scanf("%i", &idade);
    
    while (idade < 18){
        printf("\nVocê é menor de idade,proxímo cliente, qual a sua idade?: ");
        scanf("%i", &idade);
    }//while idade invalida
    
    //menu de bebidas e loop se o cliente quiser levar mais bebidas, se cancelar mostrar total e encerrar programa
    while (continuar == 1){
        //menu de bebidas
        printf("\n=======MENU DE BEBIDAS=========");
        printf("\n======DESCONTOS:=====");
        printf("\n======+5 unidades 10====");
        printf("\n======+50 unidades 30====");
        printf("\n======+100 unidades 35====");
        printf("\n======Valor do cliente:  R$%i====", valor_total_cliente);
        printf("\n======Valor do dia:      R$%i====", valor_total_dia);
        printf("\n[1] Cerveja");
        printf("\n[2] Whisky");
        printf("\n[3] Cachaça");
        printf("\n[4] Vodka");
        printf("\nEscolha: ");
        scanf("%i", &opcao_bebida);

        if (opcao_bebida == 1){
            printf("\n==== MENU DE CERVEJAS ====");
            printf("\n[1] Itaipava  R$7,00");
            printf("\n[2] Brahma    R$8,00");
            printf("\n[3] Heineken  R$9,00");
            printf("\nEscolha: ");
            scanf("%i", &opcao_cerveja);

            switch (opcao_cerveja)
            {
            case 1: //itaipava
                preco = 7;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            case 2://BRAHMA 8 REAIS
                preco = 8;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
                
            case 3:
                //HEINEKEN 9 REAIS
                preco = 9;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            default:
                break;

            
            }//switch opcao cerveja
        }//if opcao_bebida == 1
        else if (opcao_bebida == 2){
            printf("\n==== MENU DE WHISKY ====");
            printf("\n[1] Johnnie Walker  R$90,00");
            printf("\n[2] Jim Beam        R$80,00");
            printf("\n[3] Jack Daniel's   R$100,00");
            printf("\nEscolha: ");
            scanf("%i", &opcao_whisky);

            switch (opcao_whisky)
            {
            case 1: //Johnnie Walker
                preco = 90;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            case 2://Jim Beam        R$80,00
                preco = 80;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
                
            case 3:
                //Jack Daniel's   R$100,00
                preco = 100;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            default:
                break;

            
            }//switch opcao whisky
        }//if opcao_bebida == 2

        else if (opcao_bebida == 3){
            printf("\n==== MENU DE CACHAÇA ====");
            printf("\n[1] Cachaça Sagatiba      R$50,00");
            printf("\n[2] Cachaça Engasga Gato  R$40,00");
            printf("\n[3] Cachaça Salinas       R$30,00");
            printf("\nEscolha: ");
            scanf("%i", &opcao_cachaca);

            switch (opcao_cachaca)
            {
            case 1: //Cachaça Sagatiba      R$50,00
                preco = 50;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            case 2://Cachaça Engasga Gato  R$40,00
                preco = 40;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
                
            case 3:
                //Cachaça Salinas       R$30,00
                preco = 30;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            default:
                break;
            }//switch opcao cachaca
        }//if opcao_bebida == 3

        else if (opcao_bebida == 4){
            printf("\n==== MENU DE VODKA ====");
            printf("\n[1] Smirnoff      R$60,00");
            printf("\n[2] Grey Goose    R$40,00");
            printf("\n[3] Ciroc         R$70,00");
            printf("\nEscolha: ");
            scanf("%i", &opcao_vodka);

            switch (opcao_vodka)
            {
            case 1: //Smirnoff      R$60,00
                preco = 60;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            case 2://Grey Goose    R$40,00
                preco = 40;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
                
            case 3:
                //Ciroc         R$70,00
                preco = 70;
                printf("\nEscolha a quantidade: ");
                scanf("%i", &quantidade);
                
                while (quantidade < 1){
                    printf("\nEscolha a quantidade válida: ");
                    scanf("%i", &quantidade);
                }
                ///CONDICIONAIAS DAS QUANTIDADES
                if (quantidade > 100){
                    valor = preco * quantidade * 0.65;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 50){
                    valor = quantidade * preco * 0.70;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else if (quantidade > 5){
                    valor = quantidade * preco * 0.90;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }

                else{
                    valor = quantidade * preco;
                    valor_total_cliente = valor_total_cliente + valor;
                    valor_total_dia = valor_total_dia + valor;
                }
                break;
            default:
                break;
            }//switch opcao vodka
        }//if opcao_bebida == 4

        printf("\nDeseja encerrar o pedido desse cliente? [1] = não [2] = sim: ");
        scanf("%i", &cancelar_cliente);
        switch (cancelar_cliente)
        {
            case 1:
                break;
            default:
                printf("\nO valor total deu R$%i,obrigado pela preferencia!", valor_total_cliente);
                valor_total_cliente = 0;

                printf("\nVocê deseja encerrar o dia de trabalho?");
                printf("\n[1] NÃO");
                printf("\n[2] SIM");
                printf("\nEscolha: ");
                scanf("%i", &continuar);

                switch (continuar)
                {
                    case 2:
                        printf("\n======FIM DE TRABALHO=====");
                        printf("\nHoje o total de vendas foi de R$%i", valor_total_dia);
                        return 0;
            
                    default:
                        //PERGUNTANDO IDADE PARA PROSSEGUIR
                        printf("\n===NOVO CLIENTE===");
                        printf("\nMe diga a sua idade antes de prosseguirmos: ");
                        scanf("%i", &idade);
    
                        while (idade < 18){
                            printf("\nVocê é menor de idade,proxímo cliente, qual a sua idade?: ");
                            scanf("%i", &idade);
                        }//while idade invalida
                        break;
                }
                
        }//switch cancelar cliente
        
    }//while de &continuar

}//main