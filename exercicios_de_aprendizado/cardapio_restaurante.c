#include <stdio.h>

int main(void){
    int codigo, quantidade, valor, valor_final = 0;


    while (1)
    {
        printf("\n-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=");
        printf("\nEscolha o seu pedido:");
        printf("\nCachorro  Quente /// codigo: 100 /// valor = R$ 5,00");
        printf("\nGuarana         ///  codigo: 200 /// valor = R$ 4,00");
        printf("\nPastel de frango///  codigo: 300 /// valor = R$ 6,00");
        printf("\nCoxinha         ///  codigo: 400  /// valor = R$ 5,00");
        printf("\n-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\nCarrinho: R$%i,00",valor_final);
        printf("\nDigite o codigo do pedido(000 para pedir a conta) : ");
        scanf(" %i", &codigo);

        switch(codigo)
        {
            case 100:
                valor = 5;
                printf("\nEscolha a quantidade: ");
                scanf(" %i", &quantidade);
                valor_final = valor_final + (valor * quantidade);
                break;
            case 200:
                valor = 4;
                printf("\nEscolha a quantidade: ");
                scanf(" %i", &quantidade);
                valor_final = valor_final + (valor * quantidade);
                break;
            case 300:
                valor = 6;
                printf("\nEscolha a quantidade: ");
                scanf(" %i", &quantidade);
                valor_final = valor_final + (valor * quantidade);
                break;
            case 400:
                valor = 5;
                printf("\nEscolha a quantidade: ");
                scanf(" %i", &quantidade);
                valor_final = valor_final + (valor * quantidade);
                break;
            default:
                printf("\nO valor final foi de R$%i,00",valor_final);
                return 0;
        }
    }
}