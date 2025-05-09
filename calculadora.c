#include <stdio.h>

int main(void){
    int n1,n2;
    char op;

    while (1)
    {
        printf("\nEsolha os numeros(no formato:n1 n2): ");
        scanf("%i  %i", &n1,&n2);

        printf("\nEscolha o operador(+ - / *  digite 0 para parar): ");
        scanf(" %c",&op);

        switch(op)
        {
            case '+':
                printf("%i + %i = %i", n1,n2, n1 + n2);
                break;
            case '-':
                printf("%i - %i = %i", n1,n2, n1 - n2);
                break;
            case '*':
                printf("%i * %i = %i", n1,n2, n1 * n2);
                break;
            case '/':
                printf("%i / %i = %i", n1,n2, n1 / n2);
                break;
            default:
                return 0;
        }
    }


    return 0;
}