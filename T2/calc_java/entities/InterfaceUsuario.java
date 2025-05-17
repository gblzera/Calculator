package calculadora.entities;

import java.util.InputMismatchException;
import java.util.Locale;
import java.util.Scanner;

public class InterfaceUsuario {
    private Scanner scanner;
    private HistoricoOperacoes historico;

    private static final int SOMA = 1;
    private static final int SUBTRACAO = 2;
    private static final int MULTIPLICACAO = 3;
    private static final int DIVISAO = 4;
    private static final int HISTORICO = 5;
    private static final int LIMPAR_HISTORICO = 6;
    private static final int SAIR = 0;

    public InterfaceUsuario() {
        Locale.setDefault(Locale.US);
        scanner = new Scanner(System.in);
        historico = new HistoricoOperacoes();
    }

    public void iniciar(){
        System.out.println("Bem vindo a calculadora");
        exibirMenu();
    }

    public void exibirMenu(){
        int opcao;
        do{
            System.out.println("Menu principal");
            System.out.println(SOMA + "- Soma");
            System.out.println(SUBTRACAO + "- Subtraçao");
            System.out.println(MULTIPLICACAO + "- Multiplicaçao");
            System.out.println(DIVISAO + "- Divisao");
            System.out.println(HISTORICO + "- ver Historico");
            System.out.println(LIMPAR_HISTORICO + "- Lipar historico");
            System.out.println(SAIR + "- Sair");
            System.out.println("escolha a opçao");

            try{
                opcao = scanner.nextInt();
                scanner.nextLine();

                switch (opcao){
                    case SOMA:
                        realizarOperacao(opcao);
                        break;
                    case SUBTRACAO:
                        realizarOperacao(opcao);
                        break;
                    case MULTIPLICACAO:
                        realizarOperacao(opcao);
                        break;
                    case DIVISAO:
                        realizarOperacao(opcao);
                        break;
                    case HISTORICO:
                        historico.exibirHistorico();
                        break;
                    case LIMPAR_HISTORICO:
                        historico.limparHistorico();
                        break;
                    case SAIR:
                        System.out.println("Calculadora encerrada");
                        break;
                    default:
                        System.out.println("opçao invalida. tente novamente");
                }
            }catch (InputMismatchException e){
                System.out.println("[ERROR] -> digite um numero valido");
                scanner.nextLine();
                opcao = -1;
            }
        }while (opcao != SAIR);
        scanner.close();
    }

    private void realizarOperacao(int operacao){
        try{
            System.out.println("entre com o primeiro numero: ");
            double num1 = scanner.nextDouble();
            System.out.println("entre com o segundo numero: ");
            double num2 = scanner.nextDouble();
            scanner.nextLine();

            double resultado = 0;
            String simboloOperacao = "";
            String nomeOperacao = "";

            switch (operacao){
                case SOMA:
                    resultado = OperacoesMatematicas.somar(num1 , num2);
                    simboloOperacao = " + ";
                    nomeOperacao = "Soma";
                    break;
                case SUBTRACAO:
                    resultado = OperacoesMatematicas.subtrair(num1, num2);
                    simboloOperacao = " - ";
                    nomeOperacao = "Subtraçao";
                    break;
                case MULTIPLICACAO:
                    resultado = OperacoesMatematicas.multiplicar(num1, num2);
                    simboloOperacao = " * ";
                    nomeOperacao = "multiplicaçao";
                    break;
                case DIVISAO:
                    resultado = OperacoesMatematicas.dividir(num1, num2);
                    simboloOperacao = " ÷ ";
                    nomeOperacao = "divisao";
                    break;
                default:
                    System.out.println("operaçao invalida");
            }

            //formatar operaçao para o historico
            String operacaoFormatada = String.format("%.2f%s%.2f = %.2f (%s)", num1, simboloOperacao, num2,resultado, nomeOperacao);

            //adcionar ao historico

            historico.adcionarOperacoes(operacaoFormatada);
            System.out.println("resultado: "+resultado);
        } catch (InputMismatchException e){
            System.out.println("[ERROR]-> valor invalido. Digite um numero");
            scanner.nextLine();
        }catch (ArithmeticException e){
            System.out.println("[ERROR]-> "+e.getMessage());
        }
    }
}
