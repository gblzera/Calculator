#include <ncurses.h>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

class Calculadora {
public:
    double soma(double a, double b) { return a + b; }
    double subtracao(double a, double b) { return a - b; }
    double multiplicacao(double a, double b) { return a * b; }
    double divisao(double a, double b) {
        if (b == 0) throw std::runtime_error("Divisao por zero!");
        return a / b;
    }
    double potencia(double a, double b) { return std::pow(a, b); }
    double raiz(double a) {
        if (a < 0) throw std::runtime_error("Raiz de numero negativo!");
        return std::sqrt(a);
    }
    double modulo(double a, double b) {
        if (b == 0) throw std::runtime_error("Modulo por zero!");
        return std::fmod(a, b);
    }
};

std::vector<std::vector<std::string>> botoes = {
    {"C", "CE", "%", "del"},
    {"1/x", "x²", "SqRt", "/"},
    {"7", "8", "9", "*"},
    {"4", "5", "6", "-"},
    {"1", "2", "3", "+"},
    {"±", "0", ".", "="}
};

std::string input = "";
std::string operacao = "";
double valorAnterior = 0;
bool novoNumero = true;

void desenharCalculadora(int linhaSel, int colSel) {
    clear();
    mvprintw(1, 5, "Calculadora NCurses - Estilo Windows");
    mvprintw(3, 5, "+------------------------+");
    mvprintw(4, 5, "|%22s |", input.c_str());
    mvprintw(5, 5, "+------------------------+");

    int y = 7;
    for (size_t i = 0; i < botoes.size(); ++i) {
        int x = 5;
        for (size_t j = 0; j < botoes[i].size(); ++j) {
            if ((int)i == linhaSel && (int)j == colSel) attron(A_REVERSE);
            mvprintw(y, x, "[ %3s ]", botoes[i][j].c_str());
            if ((int)i == linhaSel && (int)j == colSel) attroff(A_REVERSE);
            x += 7;
        }
        y += 2;
    }
    refresh();
}

void processarEntrada(const std::string& btn, Calculadora& calc) {
    try {
        if (btn == "C") {
            input = "";
            operacao = "";
            valorAnterior = 0;
        } else if (btn == "CE") {
            input = "";
        } else if (btn == "←" && !input.empty()) {
            input.pop_back();
        } else if (btn == "+" || btn == "-" || btn == "*" || btn == "/") {
            if (!input.empty()) {
                valorAnterior = std::stod(input);
                operacao = btn;
                input = "";
            }
        } else if (btn == "=") {
            if (!input.empty() && !operacao.empty()) {
                double atual = std::stod(input);
                if (operacao == "+") input = std::to_string(calc.soma(valorAnterior, atual));
                else if (operacao == "-") input = std::to_string(calc.subtracao(valorAnterior, atual));
                else if (operacao == "*") input = std::to_string(calc.multiplicacao(valorAnterior, atual));
                else if (operacao == "/") input = std::to_string(calc.divisao(valorAnterior, atual));
                operacao = "";
                novoNumero = true;
            }
        } else if (btn == "%") {
            if (!input.empty()) {
                double v = std::stod(input);
                input = std::to_string(v / 100.0);
            }
        } else if (btn == "x²") {
            if (!input.empty()) {
                double v = std::stod(input);
                input = std::to_string(calc.potencia(v, 2));
            }
        } else if (btn == "√x") {
            if (!input.empty()) {
                double v = std::stod(input);
                input = std::to_string(calc.raiz(v));
            }
        } else if (btn == "1/x") {
            if (!input.empty()) {
                double v = std::stod(input);
                if (v == 0) throw std::runtime_error("Divisao por zero!");
                input = std::to_string(1.0 / v);
            }
        } else if (btn == "±") {
            if (!input.empty()) {
                double v = std::stod(input);
                input = std::to_string(-v);
            }
        } else {
            if (novoNumero) {
                input = btn;
                novoNumero = false;
            } else {
                input += btn;
            }
        }
    } catch (std::exception& e) {
        input = "Erro";
        novoNumero = true;
    }
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    Calculadora calc;
    int linha = 0, coluna = 0;

    bool sair = false;
    desenharCalculadora(linha, coluna);
    while (!sair) {
        int ch = getch();
        switch (ch) {
            case KEY_UP: linha = (linha - 1 + botoes.size()) % botoes.size(); break;
            case KEY_DOWN: linha = (linha + 1) % botoes.size(); break;
            case KEY_LEFT: coluna = (coluna - 1 + botoes[linha].size()) % botoes[linha].size(); break;
            case KEY_RIGHT: coluna = (coluna + 1) % botoes[linha].size(); break;
            case '\n':
            case KEY_ENTER:
                processarEntrada(botoes[linha][coluna], calc);
                break;
            case 'q': sair = true; break;
        }
        desenharCalculadora(linha, coluna);
    }

    endwin();
    return 0;
}
