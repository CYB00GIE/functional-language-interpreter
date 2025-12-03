#include <iostream>
#include <string>
#include "func_def.hpp"
#include "../behavior/behavior.hpp"
#include "../result/result.hpp"

void Func_Def::define() {
    std::string curr_expr;

    int expr_len = expr.length();

    for (int i = 0; i < expr_len; i++) {
        if (expr[i] == '<') {
            i++;
            if (expr[i] == '-' && func_name.empty()) {
                func_name = curr_expr;
                curr_expr.clear();
            }
            else {
                std::cout << "Invalid expression!\nThe \"<\" is an invalid symbol unless used as \"<-\" for function definition\n";
                return;
            }
        }
        else if (expr[i] == ' ') {
            continue;
        }
        else {
            if (expr[i] == '#') {
                if (expr[i + 1] >= '0' && expr[i + 1] <= '9') {
                    num_args = std::max(num_args, expr[i + 1] - '0' + 1);
                }
                else {
                    std::cout << "Invalid expression!\nThe symbol \'#\' should be followed by an integer between 0 and 9\n";
                }
            }
            curr_expr += expr[i];
        }
    }

    body = curr_expr;
}

Func_Def::Func_Def(std::string str) : Expr(str) {
    num_args = 0;
    define();
}

void Func_Def::print(int n) const {
    std::cout << "> ";
    for (int i = 0; i < n; i++) {
        std::cout << ' ';
    }
    std::cout << "Function definition: " << func_name << std::endl;
    std::cout << "Defined body: " << body << std::endl;
}

Result Func_Def::eval() const {
    Storage::insert(func_name, Behavior(func_name, num_args, body));
    return Result(" ");
}