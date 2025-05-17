package calculadora.entities;

public class OperacoesMatematicas {
    public static double somar(double a, double b){
        return a + b;
    }

    public static double subtrair(double a, double b){
        return a - b;
    }

    public static double multiplicar(double a, double b){
        return a * b;
    }

    public static double dividir(double a, double b) throws ArithmeticException{
        if (b == 0){
            throw new ArithmeticException("Nao é possivel dividir por zero");
        }
        return a /b;
    }
}
