#include "num_expr.hpp"
#include "../result/result.hpp"

void Num_Expr::to_num() {
    num = 0;
    int point_cnt = 0;
    int expr_len = expr.length();

    for (int i = 0; i < expr_len; i++) {
        if (i == 0 && expr[i] == '-') {
            continue;
        }
        if ((expr[i] < '0' || expr[i] > '9') && expr[i] != '.') {
            std::cout << "Invalid expression!\nThe deduced type of the expression was a number\nExpression found: " << expr << std::endl;
            num = 0;
            return;
        }
        if (expr[i] == '.') {
            if (++point_cnt > 1) {
                std::cout << "Invalid expression!\nThe deduced type of the expression was a number\nExpression found: " << expr << std::endl;
                num = 0;
                return;
            }
        }
        if (expr[i] == '-' && i > 0) {
            std::cout << "Invalid expression!\nThe deduced type of the expression was a number\nExpression found: " << expr << std::endl;
            num = 0;
            return;
        }
    }

    num = std::stod(expr);
}

Num_Expr::Num_Expr(std::string str) : Expr(str) {
    to_num();
}

Num_Expr::Num_Expr(double n) : Expr(""), num(n) {
    expr = std::to_string(num);
}

Result Num_Expr::eval() const {
    return Result(num);
}

double Num_Expr::get_number() const {
    return num;
}

void Num_Expr::print(int n) const {
    std::cout << '>';
    for (int i = 0; i < n; i++) {
        std::cout << ' ';
    }
    std::cout << "Number: " << num << std::endl;
}

