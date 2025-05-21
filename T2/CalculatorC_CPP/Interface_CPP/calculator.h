#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    double opBin(double a, double b, char op, double(*func)(double, double));
    double opUn(double a, char op, double(*func)(double));

    double soma(double a, double b);
    double sub(double a, double b);
    double mult(double a, double b);
    double div(double a, double b);

    double sen(double a);
    double cos(double a);
    double tan(double a);
    double log(double a);
    double raiz(double a);
};

#endif
