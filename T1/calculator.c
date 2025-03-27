#include <stdio.h>

int main() {
    double num1, num2, resultado;
    char operador;

    printf("Digite a operação (ex: 2 + 5):");
    scanf("%lf %c %lf", &num1, &operador, &num2);

    switch(operador){
        case '+': resultado = num1 + num2; break;
        case '-': resultado = num1 - num2; break;
        case '*': resultado = num1 * num2; break;
        case '/':
            if (num2 != 0) resultado = num1 / num2;
            else{
                printf("Erro: divisão por zero.\n");
                return 1;
            }
            break;
        default:
            printf("Operador Invalido.\n");
            return 1;
    }

    printf("Resultado: %.2lf\n", resultado);
    return 0;
}