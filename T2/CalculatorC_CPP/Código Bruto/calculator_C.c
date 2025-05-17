/*
 * Calculadora Avançada em C
 * 
 * Recursos:
 * - Menu interativo
 * - Operações básicas (adição, subtração, multiplicação, divisão)
 * - Operações avançadas (potência, raiz quadrada, módulo)
 * - Histórico de operações
 * - Utilização de estruturas e ponteiros
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
 
 #define MAX_HISTORICO 10
 #define BUFFER_SIZE 100
 
 // Estrutura operações
 typedef struct {
     double num1;
     double num2;
     char operador;
     double resultado;
 } Operacao;
 
 // Estrutura calculadora
 typedef struct {
     Operacao historico[MAX_HISTORICO];
     int contagem_historico;
 } Calculadora;
 
 // Inicializador
 void inicializar_calculadora(Calculadora *calc) {
     calc->contagem_historico = 0;
 }
 
 // Registra operação histórico
 void registrar_operacao(Calculadora *calc, double num1, double num2, char operador, double resultado) {
     if (calc->contagem_historico < MAX_HISTORICO) {
         Operacao nova_op = {num1, num2, operador, resultado};
         calc->historico[calc->contagem_historico++] = nova_op;
     } else {
         for (int i = 0; i < MAX_HISTORICO - 1; i++) {
             calc->historico[i] = calc->historico[i + 1];
         }
         
         Operacao nova_op = {num1, num2, operador, resultado};
         calc->historico[MAX_HISTORICO - 1] = nova_op;
     }
 }
 
 // Mostrar historico
 void exibir_historico(Calculadora *calc) {
     printf("\n===== HISTÓRICO DE OPERAÇÕES =====\n");
     
     if (calc->contagem_historico == 0) {
         printf("Nenhuma operação registrada.\n");
         return;
     }
     
     for (int i = 0; i < calc->contagem_historico; i++) {
         Operacao op = calc->historico[i];
         
         if (op.operador == 's') { // sqrt
             printf("[%d] √%.2f = %.2f\n", i + 1, op.num1, op.resultado);
         } else {
             printf("[%d] %.2f %c %.2f = %.2f\n", i + 1, op.num1, op.operador, op.num2, op.resultado);
         }
     }
 }
 
 // screen clear
 void limpar_tela() {
     #ifdef _WIN32
     system("cls");
     #else
     system("clear");
     #endif
 }
 
 // Menu 
 void exibir_menu() {
     printf("\n===== CALCULADORA AVANÇADA EM C =====\n");
     printf("1. Soma (+)\n");
     printf("2. Subtração (-)\n");
     printf("3. Multiplicação (*)\n");
     printf("4. Divisão (/)\n");
     printf("5. Potência (^)\n");
     printf("6. Raiz Quadrada (√)\n");
     printf("7. Módulo/Resto (%%)\n");
     printf("8. Ver Histórico\n");
     printf("9. Limpar Histórico\n");
     printf("0. Sair\n");
     printf("Escolha uma opção: ");
 }
 
 int main() {
     Calculadora calc;
     inicializar_calculadora(&calc);
     
     int opcao;
     double num1, num2, resultado;
     char operador;
     char buffer[BUFFER_SIZE];
     
     do {
         limpar_tela();
         exibir_menu();
         
         // Captura segura da opção
         if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
             printf("Erro na leitura.\n");
             continue;
         }
         opcao = atoi(buffer);
         
         switch (opcao) {
             case 1: 
                 printf("Digite o primeiro número: ");
                 scanf("%lf", &num1);
                 printf("Digite o segundo número: ");
                 scanf("%lf", &num2);
                 resultado = num1 + num2;
                 operador = '+';
                 printf("Resultado: %.2f\n", resultado);
                 registrar_operacao(&calc, num1, num2, operador, resultado);
                 break;
                 
             case 2: 
                 printf("Digite o primeiro número: ");
                 scanf("%lf", &num1);
                 printf("Digite o segundo número: ");
                 scanf("%lf", &num2);
                 resultado = num1 - num2;
                 operador = '-';
                 printf("Resultado: %.2f\n", resultado);
                 registrar_operacao(&calc, num1, num2, operador, resultado);
                 break;
                 
             case 3: 
                 printf("Digite o primeiro número: ");
                 scanf("%lf", &num1);
                 printf("Digite o segundo número: ");
                 scanf("%lf", &num2);
                 resultado = num1 * num2;
                 operador = '*';
                 printf("Resultado: %.2f\n", resultado);
                 registrar_operacao(&calc, num1, num2, operador, resultado);
                 break;
                 
             case 4: 
                 printf("Digite o primeiro número: ");
                 scanf("%lf", &num1);
                 printf("Digite o segundo número: ");
                 scanf("%lf", &num2);
                 
                 if (num2 == 0) {
                     printf("Erro: Divisão por zero!\n");
                 } else {
                     resultado = num1 / num2;
                     operador = '/';
                     printf("Resultado: %.2f\n", resultado);
                     registrar_operacao(&calc, num1, num2, operador, resultado);
                 }
                 break;
                 
             case 5: 
                 printf("Digite a base: ");
                 scanf("%lf", &num1);
                 printf("Digite o expoente: ");
                 scanf("%lf", &num2);
                 resultado = pow(num1, num2);
                 operador = '^';
                 printf("Resultado: %.2f\n", resultado);
                 registrar_operacao(&calc, num1, num2, operador, resultado);
                 break;
                 
             case 6: 
                 printf("Digite o número: ");
                 scanf("%lf", &num1);
                 
                 if (num1 < 0) {
                     printf("Erro: Não é possível calcular raiz quadrada de número negativo no conjunto dos reais.\n");
                 } else {
                     resultado = sqrt(num1);
                     operador = 's'; // 's' de square root
                     printf("Resultado: %.2f\n", resultado);
                     registrar_operacao(&calc, num1, 0, operador, resultado);
                 }
                 break;
                 
             case 7: 
                 printf("Digite o dividendo: ");
                 scanf("%lf", &num1);
                 printf("Digite o divisor: ");
                 scanf("%lf", &num2);
                 
                 if (num2 == 0) {
                     printf("Erro: Divisão por zero!\n");
                 } else {
                     resultado = fmod(num1, num2);
                     operador = '%';
                     printf("Resultado: %.2f\n", resultado);
                     registrar_operacao(&calc, num1, num2, operador, resultado);
                 }
                 break;
                 
             case 8: 
                 exibir_historico(&calc);
                 break;
                 
             case 9:
                 calc.contagem_historico = 0;
                 printf("Histórico limpo com sucesso!\n");
                 break;
                 
             case 0: 
                 printf("Saindo da calculadora...\n");
                 break;
                 
             default:
                 printf("Opção inválida. Tente novamente.\n");
         }
         
         // Limpar buffer
         while (getchar() != '\n');
         
         if (opcao != 0) {
             printf("\nPressione Enter para continuar...");
             getchar();
         }
         
     } while (opcao != 0);
     
     return 0;
 }