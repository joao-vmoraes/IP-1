#include <stdio.h>

int main(void){
    int escolha_menu;


    while (1)
    {
        printf("=-=-=-=-=-=-=-=-=--=-=-=-=-");
        printf("\nEscolha uma ação: ");
        printf("\n1. Saldo em conta corrente");
        printf("\n2. Extrato bancário");
        printf("\n3. Sacar dinheiro");
        printf("\n4. Transferência");
        printf("\n5. Sair\n ");
        scanf("%i", &escolha_menu);

        switch(escolha_menu)
        {
            case 1:
                printf("=-=-=-=-=-=-=-=-=--=-=-=-=-");
                printf("\nR$10,00\n");
                break;
            case 2:
                printf("=-=-=-=-=-=-=-=-=--=-=-=-=-");
                printf("\n- R$ 90,00\n");
                printf("\n+ R$ 100,00\n");
                break;
            case 3:
                printf("=-=-=-=-=-=-=-=-=--=-=-=-=-");
                printf("\nSaque de R$10,00 realizado!\n");
                break;
            case 4:
                printf("=-=-=-=-=-=-=-=-=--=-=-=-=-");
                printf("\nPix de R$10,00 Feito com sucesso!\n");
                break;
            default:
            printf("=-=-=-=-=-=-=-=-=--=-=-=-=-");
            printf("\nAté logo!");
            return 0;
        }   
    }


}