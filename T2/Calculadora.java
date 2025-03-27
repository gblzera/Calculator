package calculadora;

import java.util.Locale;
import java.util.Scanner;

public class Calculadora {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        System.out.println("bem vindo a calculadora em java");
        int x;
        do {
            System.out.println("escolha uma opçao");
            System.out.println("soma: 1");
            System.out.println("subtraçao: 2");
            System.out.println("multiplicaçao: 3");
            System.out.println("divisao: 4");
            System.out.println("sair: 0");
            System.out.println("opçao: ");
            x = sc.nextInt();

            if (x >= 1 && x <= 4) {
                System.out.println("entre com o primeiro valor: ");
                double num1 = sc.nextDouble();
                System.out.println("entre com o segundo valor");
                double num2 = sc.nextDouble();
                double resultado = 0;

                switch (x) {
                    case 1:
                        resultado = num1 + num2;
                        break;
                    case 2:
                        resultado = num1 - num2;
                        break;
                    case 3:
                        resultado = num1 * num2;
                        break;
                    case 4:
                        if (num2 == 0) {
                            System.out.println("nao é possivel dividr por zero, por favor escolha outro valor");
                            continue;
                        }
                        resultado = num1 / num2;
                        break;
                }
                System.out.println("resultado: "+String.format("%.2f",resultado));
            } else if (x != 0) {
                System.out.println("opçao invalida tente novamente");
            }
        }
        while (x != 0);
        System.out.println("calculadora encerrada, Obrigado!");
        sc.close();
    }
}
