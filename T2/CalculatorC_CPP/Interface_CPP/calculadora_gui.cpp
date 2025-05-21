#include <gtkmm.h>
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <cmath>
#include "calculator.h"

class CalculatorGUI : public Gtk::Window {
public:
    CalculatorGUI() {
        set_title("Interface Calculadora C++");
        set_default_size(300, 400);

        main_box.set_orientation(Gtk::Orientation::VERTICAL);
        set_child(main_box);

        entry.set_editable(false);
        entry.set_margin(5);
        main_box.append(entry);

        grid.set_column_spacing(5);
        grid.set_row_spacing(5);
        grid.set_margin(5);
        main_box.append(grid);

        const std::vector<std::vector<std::string>> buttons = {
            { "7", "8", "9", "/" },
            { "4", "5", "6", "*" },
            { "1", "2", "3", "-" },
            { "0", ".", "=", "+" },
            { "sin", "cos", "tan", "C" },
            { "log", "sqrt", "(", ")" }
        };

        for (size_t row = 0; row < buttons.size(); ++row) {
            for (size_t col = 0; col < buttons[row].size(); ++col) {
                auto button = Gtk::make_managed<Gtk::Button>(buttons[row][col]);
                button->set_hexpand();
                button->set_vexpand();
                button->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &CalculatorGUI::on_button_clicked), buttons[row][col]));
                grid.attach(*button, col, row);
            }
        }
    }

private:
    Gtk::Box main_box{Gtk::Orientation::VERTICAL};
    Gtk::Entry entry;
    Gtk::Grid grid;

    std::string current_input;
    Calculator calc;
    
    // Check if input is a scientific function
    bool is_scientific_function(const std::string& str) {
        return str == "sin" || str == "cos" || str == "tan" || 
               str == "log" || str == "sqrt";
    }

    void on_button_clicked(const std::string& label) {
        try {
            if (label == "C") {
                // Clear the input and display
                current_input.clear();
                entry.set_text("");
                return;
            }

            if (label == "=") {
                if (current_input.empty()) {
                    return;
                }
                
                // Parse and evaluate the expression
                double result = parseExpression(current_input);
                std::ostringstream oss;
                oss << result;
                entry.set_text(oss.str());
                current_input = oss.str(); // Set current input to the result for continued calculations
                return;
            }

            // For scientific functions, auto-add open parenthesis
            if (is_scientific_function(label)) {
                current_input += label + "(";
            } else {
                current_input += label;
            }
            entry.set_text(current_input);
        } catch (const std::exception& e) {
            entry.set_text(e.what());
            current_input.clear();
        }
    }

    // Enhanced expression parser using shunting yard algorithm
    double parseExpression(const std::string& expr) {
        std::stack<double> values;
        std::stack<std::string> operators;
        std::string current_token;
        bool reading_number = false;
        
        for (size_t i = 0; i < expr.length(); i++) {
            char c = expr[i];
            
            // Handle numbers (including decimals)
            if (std::isdigit(c) || c == '.') {
                if (!reading_number) {
                    current_token.clear();
                    reading_number = true;
                }
                current_token += c;
                continue;
            } else if (reading_number) {
                values.push(std::stod(current_token));
                reading_number = false;
            }
            
            // Handle scientific functions (sin, cos, etc.)
            if (std::isalpha(c)) {
                std::string func;
                while (i < expr.length() && std::isalpha(expr[i])) {
                    func += expr[i++];
                }
                i--; // Adjust index since we incremented one too far
                operators.push(func);
                continue;
            }
            
            // Handle operators and parentheses
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                std::string op(1, c);
                
                while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(op)) {
                    applyOperator(values, operators);
                }
                
                operators.push(op);
            } else if (c == '(') {
                operators.push("(");
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != "(") {
                    applyOperator(values, operators);
                }
                
                if (!operators.empty() && operators.top() == "(") {
                    operators.pop(); // Remove the "("
                    
                    // If there's a function before the opening parenthesis, apply it
                    if (!operators.empty() && is_scientific_function(operators.top())) {
                        applyOperator(values, operators);
                    }
                }
            }
        }
        
        // Handle the last number if there is one
        if (reading_number) {
            values.push(std::stod(current_token));
        }
        
        // Apply any remaining operators
        while (!operators.empty()) {
            applyOperator(values, operators);
        }
        
        if (values.empty()) {
            throw std::runtime_error("Expressão inválida");
        }
        
        return values.top();
    }
    
    // Helper function to apply an operator to the top values in the stack
    void applyOperator(std::stack<double>& values, std::stack<std::string>& operators) {
        std::string op = operators.top();
        operators.pop();
        
        // Handle unary operators (scientific functions)
        if (op == "sin" || op == "cos" || op == "tan" || op == "log" || op == "sqrt") {
            if (values.empty()) {
                throw std::runtime_error("Expressão inválida para função " + op);
            }
            double operand = values.top();
            values.pop();
            
            if (op == "sin") values.push(calc.sen(operand));
            else if (op == "cos") values.push(calc.cos(operand));
            else if (op == "tan") values.push(calc.tan(operand));
            else if (op == "log") values.push(calc.log(operand));
            else if (op == "sqrt") values.push(calc.raiz(operand));
        } 
        // Handle binary operators
        else {
            if (values.size() < 2) {
                throw std::runtime_error("Expressão inválida para operador " + op);
            }
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            
            if (op == "+") values.push(calc.soma(a, b));
            else if (op == "-") values.push(calc.sub(a, b));
            else if (op == "*") values.push(calc.mult(a, b));
            else if (op == "/") values.push(calc.div(a, b));
        }
    }
    
    // Get operator precedence for the shunting yard algorithm
    int getPrecedence(const std::string& op) {
        if (op == "+" || op == "-") return 1;
        if (op == "*" || op == "/") return 2;
        if (is_scientific_function(op)) return 3;
        return 0; // For "(" or unknown operators
    }
};

class MyApp : public Gtk::Application {
protected:
    MyApp() : Gtk::Application("org.gtkmm.calculadora") {}

    void on_activate() override {
        auto janela = new CalculatorGUI();
        add_window(*janela);
        janela->show();
    }

public:
    static Glib::RefPtr<MyApp> create() {
        return Glib::RefPtr<MyApp>(new MyApp());
    }
};

int main(int argc, char* argv[]) {
    auto app = MyApp::create();
    return app->run(argc, argv);
}