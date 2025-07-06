#include <stdio.h>
#include <string.h>

typedef struct
{
    char numero_conta[10];
    float saldo;
    
}Conta;

int main()
{
    int continuar = 1, tam = 3, achado = 0;
    Conta contas[tam];
    int opcao;
    
    
    for(int indice = 0 ; indice < tam ; indice++){
        printf("Crie o numero da %i° conta: ", indice);
        scanf("%s", contas[indice].numero_conta);
        getchar();
        
        printf("Qual o saldo dessa conta: ");
        scanf("%f", &contas[indice].saldo);
        getchar();
    }
    
    while(continuar == 1){
        printf("\n=== Banco da UFRPE ===\n");
        printf("O que voce quer fazer: \n");
        printf("[1] Creditar [2] Debitar  [3] listar contas  [4] sair\n");
        printf("> ");
        scanf("%i", &opcao);
        
        char numero[10];
        float valor;
        
        switch(opcao)
        {
            case 1:
                printf("\nQual o numero da conta que voce quer transferir: ");
                scanf("%s", numero);
                printf("\nQual o valor que voce quer transferir: R$");
                scanf("%f", &valor);
            
                for(int indice = 0 ; indice < tam ; indice++)
                {
                    if(strcmp(numero, contas[indice].numero_conta) == 0 )
                    {
                        contas[indice].saldo += valor; 
                        achado = 1;
                        printf("\nMSG: A o credito de R$%.2f da conta de numero %s foi enviado com sucesso!", valor, numero);
                    }
                }
                if (achado == 0)
                {
                    printf("\nMSG: A conta com o numero %s nao existe!", numero);
                }
                achado = 0;
            
                break;
            case 2:
                printf("\nQual o numero da conta que voce quer receber o dinheiro: ");
                scanf("%s", numero);
                printf("\nQual o valor que voce quer receber");
                scanf("%f", &valor);
                
                for(int indice = 0 ; indice < tam ; indice ++)
                {
                    if(strcmp(numero, contas[indice].numero_conta) == 0){
                        contas[indice].saldo -= valor;
                        achado = 1;
                        printf("\nMSG: A o debito de R$%.2f da conta de numero %s foi recebido com sucesso!", valor, numero);
                    }
                }
                
                if (achado == 0)
                {
                    printf("\nMSG: A conta com o numero %s nao existe!", numero);
                }
                achado = 0;
                
                break;
            case 3:
                for(int indice = 0 ; indice < tam ; indice++)
                {
                    printf("\nNumero da conta: %s   Saldo: %.2f", contas[indice].numero_conta, contas[indice].saldo);
                }
                break;
            case 4:
                printf("\nAte logo!");
                return 0 ;
                break;
            default:
                break;
        }
        
    }
    return 0;
}