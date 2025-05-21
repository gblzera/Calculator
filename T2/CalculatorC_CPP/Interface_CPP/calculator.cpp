#include "calculator.h"
#include <cmath>
#include <stdexcept>

double Calculator::opBin(double a, double b, char op, double(*func)(double, double)) {
    if (op == '/' && b == 0.0)
        throw std::runtime_error("Divisão por zero!");
    return func(a, b);
}

double Calculator::opUn(double a, char op, double(*func)(double)) {
    return func(a);
}

double Calculator::soma(double a, double b) { return opBin(a, b, '+', [](double x, double y) { return x + y; }); }
double Calculator::sub(double a, double b) { return opBin(a, b, '-', [](double x, double y) { return x - y; }); }
double Calculator::mult(double a, double b) { return opBin(a, b, '*', [](double x, double y) { return x * y; }); }
double Calculator::div(double a, double b) { return opBin(a, b, '/', [](double x, double y) { return x / y; }); }

double Calculator::sen(double a) { return opUn(a, 'S', [](double x) { return std::sin(x * M_PI / 180); }); }
double Calculator::cos(double a) { return opUn(a, 'C', [](double x) { return std::cos(x * M_PI / 180); }); }
double Calculator::tan(double a) { return opUn(a, 'T', [](double x) { return std::tan(x * M_PI / 180); }); }

double Calculator::log(double a) {
    if (a <= 0.0)
        throw std::runtime_error("Logaritmo de valor não positivo!");
    return std::log10(a);
}

double Calculator::raiz(double a) {
    if (a < 0.0)
        throw std::runtime_error("Raiz quadrada de valor negativo!");
    return std::sqrt(a);
}
