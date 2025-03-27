#include <iostream>

int main() {
    double num1, num2, resultado;
    char operador;

    std::cout << "Digite a operação (ex: 5 + 3): ";
    std::cin >> num1 >> operador >> num2;

    switch (operador) {
        case '+': resultado = num1 + num2; break;
        case '-': resultado = num1 - num2; break;
        case '*': resultado = num1 * num2; break;
        case '/': 
            if (num2 != 0) resultado = num1 / num2;
            else {
                std::cout << "Erro: divisão por zero.\n";
                return 1;
            }
            break;
        default: 
            std::cout << "Operador inválido.\n";
            return 1;
    }

    std::cout << "Resultado: " << resultado << std::endl;
    return 0;
}
