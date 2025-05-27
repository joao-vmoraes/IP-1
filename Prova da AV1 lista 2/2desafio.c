//caixa de caixa eletronico
#include <stdio.h>

int main(void){
    int  nota_de100 = 0, nota_de50=0, nota_de20=0, nota_de10=0, nota_de5=0, nota_de2=0, moeda_de1=0, moeda_de50=0, moeda_de10=0, moeda_de01=0;
    float dinheiro;
      

    printf("\nEscolha o valor do saque: ");
    scanf(" %f", &dinheiro);

    int resto = dinheiro * 100;

    while(resto > 0){

        if(resto - 10000 >= 0){
            resto -= 10000;
            nota_de100 += 1;}
        
        else if(resto - 5000 >= 0){
            resto -= 5000;
            nota_de50 += 1;}

        else if(resto - 2000 >= 0){
            resto -= 2000;
            nota_de20 += 1;}
        
        else if(resto - 1000 >= 0){
            resto -= 1000;
            nota_de10 += 1;}

        else if(resto - 500 >= 0){
            resto -= 500;
            nota_de5 += 1;}

        else if(resto - 200 >= 0){
            resto -= 200;
            nota_de2 += 1;}

        else if(resto - 100 >= 0){
            resto -= 100;
            moeda_de1 += 1;}

        else if(resto - 50 >= 0){
            resto -= 50;
            moeda_de50 += 1;}

        else if(resto - 10 >= 0){
            resto -= 10;
            moeda_de10 += 1;}

        else if(resto - 1 >= 0){
            resto -= 1;
            moeda_de01 += 1;}
        
    }
    printf("\n==================CAIXA====================");
    printf("\nNotas de R$100,00: \t%i",nota_de100);
    printf("\nNotas de R$50,00: \t%i",nota_de50);
    printf("\nNotas de R$20,00: \t%i",nota_de20);
    printf("\nNotas de R$10,00: \t%i",nota_de10);
    printf("\nNotas de R$5,00 :\t%i",nota_de5);
    printf("\nNotas de R$2,00 : \t%i",nota_de2);
    printf("\nMoedas de R$1,00: \t%i",moeda_de1);
    printf("\nMoedas de R$0,50: \t%i",moeda_de50);
    printf("\nMoedas de R$0,10: \t%i",moeda_de10);
    printf("\nMoedas de R$0,01: \t%i",moeda_de01);


}