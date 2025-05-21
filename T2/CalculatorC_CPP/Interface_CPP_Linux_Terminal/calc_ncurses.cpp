#include <ncurses.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <stdexcept>

// Classe Calculadora com métodos básicos e avançados
class Calculadora {
public:
    double soma(double a, double b) { return a + b; }
    double subtracao(double a, double b) { return a - b; }
    double multiplicacao(double a, double b) { return a * b; }
    double divisao(double a, double b) {
        if (b == 0) throw std::runtime_error("Divisão por zero!");
        return a / b;
    }
    double potencia(double a, double b) { return std::pow(a, b); }
    double raiz(double a) {
        if (a < 0) throw std::runtime_error("Raiz de número negativo!");
        return std::sqrt(a);
    }
    double modulo(double a, double b) {
        if (b == 0) throw std::runtime_error("Módulo por zero!");
        return std::fmod(a, b);
    }
    double logaritmo(double a) {
        if (a <= 0) throw std::runtime_error("Logaritmo de número não positivo!");
        return std::log10(a);
    }
};

// Função para capturar número do usuário
double capturarNumero(const char* mensagem, int linha) {
    char input[100];
    echo();
    nocbreak();
    mvprintw(linha, 2, "%s", mensagem);
    getnstr(input, sizeof(input) - 1);
    noecho();
    cbreak();

    char* endptr;
    double valor = strtod(input, &endptr);
    if (endptr == input || *endptr != '\0') {
        throw std::runtime_error("Entrada inválida!");
    }
    return valor;
}

// Função para mostrar menu com destaque na opção selecionada
void mostrarMenu(int highlight) {
    const char* opcoes[] = {
        "Soma (+)",
        "Subtração (-)",
        "Multiplicação (*)",
        "Divisão (/)",
        "Potência (^)",
        "Raiz (s)",
        "Módulo (%)",
        "Logaritmo (l)",
        "Seno (sin)",
        "Cosseno (cos)",
        "Histórico",
        "Limpar Histórico",
        "Sair"
    };
    int n_opcoes = sizeof(opcoes) / sizeof(opcoes[0]);

    clear();
    mvprintw(1, 2, "Calculadora NCurses - Use as setas e Enter para selecionar");
    for (int i = 0; i < n_opcoes; i++) {
        if (i == highlight) {
            attron(A_REVERSE);
            mvprintw(3 + i, 4, "%s", opcoes[i]);
            attroff(A_REVERSE);
        } else {
            mvprintw(3 + i, 4, "%s", opcoes[i]);
        }
    }
    refresh();
}

int main() {
    Calculadora calc;
    std::vector<std::string> historico;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    int escolha = 0;
    int n_opcoes = 13;
    bool sair = false;

    while (!sair) {
        mostrarMenu(escolha);

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                escolha = (escolha - 1 + n_opcoes) % n_opcoes;
                break;
            case KEY_DOWN:
                escolha = (escolha + 1) % n_opcoes;
                break;
            case '\n':
            case KEY_ENTER:
            {
                if (escolha == 12) { // Sair
                    sair = true;
                    break;
                }

                double a, b, resultado = 0;
                bool erro = false;
                std::string registro;

                try {
                    if (escolha == 5) { // Raiz
                        a = capturarNumero("Digite o número: ", 16);
                        resultado = calc.raiz(a);
                        registro = "Raiz(" + std::to_string(a) + ") = " + std::to_string(resultado);
                    } else if (escolha == 7) { // Logaritmo
                        a = capturarNumero("Digite o número: ", 16);
                        resultado = calc.logaritmo(a);
                        registro = "Log(" + std::to_string(a) + ") = " + std::to_string(resultado);
                    } else if (escolha == 8) { // Seno
                        a = capturarNumero("Digite o ângulo (graus): ", 16);
                        resultado = std::sin(a * M_PI / 180.0);
                        registro = "Sin(" + std::to_string(a) + "°) = " + std::to_string(resultado);
                    } else if (escolha == 9) { // Cosseno
                        a = capturarNumero("Digite o ângulo (graus): ", 16);
                        resultado = std::cos(a * M_PI / 180.0);
                        registro = "Cos(" + std::to_string(a) + "°) = " + std::to_string(resultado);
                    } else if (escolha == 10) { // Mostrar histórico
                        clear();
                        mvprintw(1, 2, "Acessando o histórico amigo? Tá com alzheimer ou só gosta de fingir que não lembra do que fez?");
                        int linhaHist = 3;
                        if (historico.empty()) {
                            mvprintw(linhaHist++, 2, "Nenhum cálculo ainda.");
                        } else {
                            for (const auto& item : historico) {
                                if (linhaHist > LINES - 2) {
                                    mvprintw(linhaHist++, 2, "-- Pressione qualquer tecla para continuar --");
                                    getch();
                                    clear();
                                    linhaHist = 3;
                                }
                                mvprintw(linhaHist++, 2, "%s", item.c_str());
                            }
                        }
                        mvprintw(linhaHist + 1, 2, "Pressione qualquer tecla para voltar...");
                        getch();
                        break;
                    } else if (escolha == 11) { // Limpar histórico
                        historico.clear();
                        clear();
                        mvprintw(10, 2, "Histórico limpo!");
                        mvprintw(12, 2, "Pressione qualquer tecla para continuar...");
                        getch();
                        break;
                    } else { // Operações binárias
                        a = capturarNumero("Digite o primeiro número: ", 16);
                        b = capturarNumero("Digite o segundo número: ", 17);
                        switch (escolha) {
                            case 0: resultado = calc.soma(a, b); registro = std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(resultado); break;
                            case 1: resultado = calc.subtracao(a, b); registro = std::to_string(a) + " - " + std::to_string(b) + " = " + std::to_string(resultado); break;
                            case 2: resultado = calc.multiplicacao(a, b); registro = std::to_string(a) + " * " + std::to_string(b) + " = " + std::to_string(resultado); break;
                            case 3: resultado = calc.divisao(a, b); registro = std::to_string(a) + " / " + std::to_string(b) + " = " + std::to_string(resultado); break;
                            case 4: resultado = calc.potencia(a, b); registro = std::to_string(a) + " ^ " + std::to_string(b) + " = " + std::to_string(resultado); break;
                            case 6: resultado = calc.modulo(a, b); registro = std::to_string(a) + " % " + std::to_string(b) + " = " + std::to_string(resultado); break;
                        }
                    }
                } catch (std::exception& e) {
                    erro = true;
                    clear();
                    mvprintw(16, 2, "Erro: %s", e.what());
                }

                if (!erro && escolha != 10 && escolha != 11) {
                    clear();
                    mvprintw(16, 2, "Resultado: %.4f", resultado);
                    historico.push_back(registro);
                }
                if (escolha != 10 && escolha != 11) {
                    mvprintw(18, 2, "Pressione qualquer tecla para continuar...");
                    getch();
                }
            }
            break;
            default:
                break;
        }
    }

    endwin();
    return 0;
}
