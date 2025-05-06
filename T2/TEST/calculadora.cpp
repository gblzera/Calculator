// calculadora.cpp
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <emscripten/bind.h>

using namespace emscripten;

class Operacao {
public:
    double num1, num2, resultado;
    char operador;

    Operacao(double n1, double n2, char op, double res)
        : num1(n1), num2(n2), operador(op), resultado(res) {}

    std::string toString() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2);

        if (operador == 's') {
            ss << "√" << num1 << " = " << resultado;
        } else if (operador == 'l') {
            ss << "log(" << num1 << ") = " << resultado;
        } else {
            ss << num1 << " " << operador << " " << num2 << " = " << resultado;
        }

        return ss.str();
    }
};

class Calculadora {
private:
    std::vector<Operacao> historico;

    template<typename Func>
    double operacaoBinaria(double a, double b, char op, Func f) {
        double res = f(a, b);
        historico.emplace_back(a, b, op, res);
        return res;
    }

    template<typename Func>
    double operacaoUnaria(double a, char op, Func f) {
        double res = f(a);
        historico.emplace_back(a, 0, op, res);
        return res;
    }

public:
    double soma(double a, double b) {
        return operacaoBinaria(a, b, '+', [](double x, double y) { return x + y; });
    }

    double subtracao(double a, double b) {
        return operacaoBinaria(a, b, '-', [](double x, double y) { return x - y; });
    }

    double multiplicacao(double a, double b) {
        return operacaoBinaria(a, b, '*', [](double x, double y) { return x * y; });
    }

    double divisao(double a, double b) {
        if (b == 0) throw std::invalid_argument("Divisão por zero!");
        return operacaoBinaria(a, b, '/', [](double x, double y) { return x / y; });
    }

    double potencia(double a, double b) {
        return operacaoBinaria(a, b, '^', [](double x, double y) { return std::pow(x, y); });
    }

    double raizQuadrada(double a) {
        if (a < 0) throw std::domain_error("Raiz de número negativo!");
        return operacaoUnaria(a, 's', [](double x) { return std::sqrt(x); });
    }

    double modulo(double a, double b) {
        if (b == 0) throw std::invalid_argument("Divisão por zero!");
        return operacaoBinaria(a, b, '%', [](double x, double y) { return std::fmod(x, y); });
    }

    double logaritmo(double a) {
        if (a <= 0) throw std::domain_error("Logaritmo de valor não positivo!");
        return operacaoUnaria(a, 'l', [](double x) { return std::log10(x); });
    }

    double seno(double angulo) {
        return operacaoUnaria(angulo, 'S', [=](double) { return std::sin(angulo * M_PI / 180); });
    }

    double cosseno(double angulo) {
        return operacaoUnaria(angulo, 'C', [=](double) { return std::cos(angulo * M_PI / 180); });
    }

    std::vector<std::string> getHistorico() const {
        std::vector<std::string> h;
        for (const auto& op : historico) {
            h.push_back(op.toString());
        }
        return h;
    }

    void limparHistorico() {
        historico.clear();
    }
};

EMSCRIPTEN_BINDINGS(calculadora_module) {
    class_<Calculadora>("Calculadora")
        .constructor<>()
        .function("soma", &Calculadora::soma)
        .function("subtracao", &Calculadora::subtracao)
        .function("multiplicacao", &Calculadora::multiplicacao)
        .function("divisao", &Calculadora::divisao)
        .function("potencia", &Calculadora::potencia)
        .function("raizQuadrada", &Calculadora::raizQuadrada)
        .function("modulo", &Calculadora::modulo)
        .function("logaritmo", &Calculadora::logaritmo)
        .function("seno", &Calculadora::seno)
        .function("cosseno", &Calculadora::cosseno)
        .function("getHistorico", &Calculadora::getHistorico)
        .function("limparHistorico", &Calculadora::limparHistorico);

    register_vector<std::string>("VectorString");
}
