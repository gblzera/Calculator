/*
 * Calculadora Avançada em C++
 * 
 * Recursos:
 * - Interface orientada a objetos
 * - Operações básicas e avançadas
 * - Histórico de operações com vector
 * - Tratamento de exceções
 * - Sobrecarga de operadores
 * - Templates para operações genéricas
 */

 #include <iostream>
 #include <vector>
 #include <cmath>
 #include <string>
 #include <stdexcept>
 #include <limits>
 #include <iomanip>
 
 // Classe operação matemática
 class Operacao {
 private:
     double num1;
     double num2;
     char operador;
     double resultado;
 
 public:
     Operacao(double n1, double n2, char op, double res) 
         : num1(n1), num2(n2), operador(op), resultado(res) {}
 
     std::string toString() const {
         std::stringstream ss;
         ss << std::fixed << std::setprecision(2);
 
         if (operador == 's') { 
             ss << "√" << num1 << " = " << resultado;
         } 
         else if (operador == 'l') { 
             ss << "log(" << num1 << ") = " << resultado;
         }
         else {
             ss << num1 << " " << operador << " " << num2 << " = " << resultado;
         }
         
         return ss.str();
     }
 };
 
 // Classe para representar uma calculadora científica
 class Calculadora {
 private:
     std::vector<Operacao> historico;
     
     // Template para operação binária básica
     template<typename Func>
     double operacaoBinaria(double a, double b, char op, Func operacao) {
         double resultado = operacao(a, b);
         historico.emplace_back(a, b, op, resultado);
         return resultado;
     }
     
     // Template para operação unária
     template<typename Func>
     double operacaoUnaria(double a, char op, Func operacao) {
         double resultado = operacao(a);
         historico.emplace_back(a, 0, op, resultado);
         return resultado;
     }
 
 public:
     // Operações básicas com sobrecarga de operadores
     double operator+(const std::pair<double, double>& nums) {
         return operacaoBinaria(nums.first, nums.second, '+', 
             [](double a, double b) { return a + b; });
     }
     
     double operator-(const std::pair<double, double>& nums) {
         return operacaoBinaria(nums.first, nums.second, '-', 
             [](double a, double b) { return a - b; });
     }
     
     double operator*(const std::pair<double, double>& nums) {
         return operacaoBinaria(nums.first, nums.second, '*', 
             [](double a, double b) { return a * b; });
     }
     
     double operator/(const std::pair<double, double>& nums) {
         if (nums.second == 0) {
             throw std::invalid_argument("Erro: Divisão por zero!");
         }
         return operacaoBinaria(nums.first, nums.second, '/', 
             [](double a, double b) { return a / b; });
     }
     
     double potencia(double base, double expoente) {
         return operacaoBinaria(base, expoente, '^', 
             [](double a, double b) { return std::pow(a, b); });
     }
     
     double raizQuadrada(double num) {
         if (num < 0) {
             throw std::domain_error("Erro: Não é possível calcular raiz quadrada de número negativo no conjunto dos reais!");
         }
         return operacaoUnaria(num, 's', [](double a) { return std::sqrt(a); });
     }
     
     double modulo(double a, double b) {
         if (b == 0) {
             throw std::invalid_argument("Erro: Divisão por zero!");
         }
         return operacaoBinaria(a, b, '%', 
             [](double a, double b) { return std::fmod(a, b); });
     }
     
     double logaritmo(double num) {
         if (num <= 0) {
             throw std::domain_error("Erro: Logaritmo só é definido para números positivos!");
         }
         return operacaoUnaria(num, 'l', [](double a) { return std::log10(a); });
     }
     
     double seno(double angulo) {
         // Convertendo para radianos se estiver em graus
         double rad = angulo * M_PI / 180.0;
         return operacaoUnaria(angulo, 'S', [rad](double) { return std::sin(rad); });
     }
     
     double cosseno(double angulo) {
         // Convertendo para radianos se estiver em graus
         double rad = angulo * M_PI / 180.0;
         return operacaoUnaria(angulo, 'C', [rad](double) { return std::cos(rad); });
     }
     
     void exibirHistorico() const {
         std::cout << "\n===== HISTÓRICO DE OPERAÇÕES =====\n";
         
         if (historico.empty()) {
             std::cout << "Nenhuma operação registrada.\n";
             return;
         }
         
         for (size_t i = 0; i < historico.size(); i++) {
             std::cout << "[" << (i + 1) << "] " << historico[i].toString() << "\n";
         }
     }
     
     void limparHistorico() {
         historico.clear();
         std::cout << "Histórico limpo com sucesso!\n";
     }
 };
 
 // limpa tela
 void limparTela() {
     #ifdef _WIN32
     system("cls");
     #else
     system("clear");
     #endif
 }
 
 // menu
 void exibirMenu() {
     std::cout << "\n===== CALCULADORA AVANÇADA EM C++ =====\n";
     std::cout << "1. Soma (+)\n";
     std::cout << "2. Subtração (-)\n";
     std::cout << "3. Multiplicação (*)\n";
     std::cout << "4. Divisão (/)\n";
     std::cout << "5. Potência (^)\n";
     std::cout << "6. Raiz Quadrada (√)\n";
     std::cout << "7. Módulo/Resto (%)\n";
     std::cout << "8. Logaritmo (log10)\n";
     std::cout << "9. Seno (sin)\n";
     std::cout << "10. Cosseno (cos)\n";
     std::cout << "11. Ver Histórico\n";
     std::cout << "12. Limpar Histórico\n";
     std::cout << "0. Sair\n";
     std::cout << "Escolha uma opção: ";
 }
 
 int main() {
     Calculadora calc;
     int opcao;
     double num1, num2, resultado;
     
     do {
         limparTela();
         exibirMenu();
         
         if (!(std::cin >> opcao)) {
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cout << "Entrada inválida! Por favor, digite um número.\n";
             std::cout << "Pressione Enter para continuar...";
             std::cin.get();
             continue;
         }
         
         try {
             switch (opcao) {
                 case 1: 
                     std::cout << "Digite o primeiro número: ";
                     std::cin >> num1;
                     std::cout << "Digite o segundo número: ";
                     std::cin >> num2;
                     resultado = calc + std::make_pair(num1, num2);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                     
                 case 2: 
                     std::cout << "Digite o primeiro número: ";
                     std::cin >> num1;
                     std::cout << "Digite o segundo número: ";
                     std::cin >> num2;
                     resultado = calc - std::make_pair(num1, num2);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                     
                 case 3: 
                     std::cout << "Digite o primeiro número: ";
                     std::cin >> num1;
                     std::cout << "Digite o segundo número: ";
                     std::cin >> num2;
                     resultado = calc * std::make_pair(num1, num2);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                     
                 case 4: 
                     std::cout << "Digite o primeiro número: ";
                     std::cin >> num1;
                     std::cout << "Digite o segundo número: ";
                     std::cin >> num2;
                     resultado = calc / std::make_pair(num1, num2);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                     
                 case 5: 
                     std::cout << "Digite a base: ";
                     std::cin >> num1;
                     std::cout << "Digite o expoente: ";
                     std::cin >> num2;
                     resultado = calc.potencia(num1, num2);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                     
                 case 6: 
                     std::cout << "Digite o número: ";
                     std::cin >> num1;
                     resultado = calc.raizQuadrada(num1);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                     
                 case 7: 
                     std::cout << "Digite o dividendo: ";
                     std::cin >> num1;
                     std::cout << "Digite o divisor: ";
                     std::cin >> num2;
                     resultado = calc.modulo(num1, num2);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                 
                 case 8: 
                     std::cout << "Digite o número (base 10): ";
                     std::cin >> num1;
                     resultado = calc.logaritmo(num1);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                 
                 case 9: 
                     std::cout << "Digite o ângulo em graus: ";
                     std::cin >> num1;
                     resultado = calc.seno(num1);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                 
                 case 10: 
                     std::cout << "Digite o ângulo em graus: ";
                     std::cin >> num1;
                     resultado = calc.cosseno(num1);
                     std::cout << "Resultado: " << resultado << "\n";
                     break;
                     
                 case 11: 
                     calc.exibirHistorico();
                     break;
                     
                 case 12: 
                     calc.limparHistorico();
                     break;
                     
                 case 0: 
                     std::cout << "Saindo da calculadora...\n";
                     break;
                     
                 default:
                     std::cout << "Opção inválida. Tente novamente.\n";
             }
         }
         catch (const std::exception& e) {
             std::cout << e.what() << "\n";
         }
         
         if (opcao != 0) {
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cout << "\nPressione Enter para continuar...";
             std::cin.get();
         }
         
     } while (opcao != 0);
     
     return 0;
 }