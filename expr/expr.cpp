#include "expr.hpp"
#include <iostream>
#include "../result/result.hpp"

Expr::Expr(std::string str) : expr(str) {}

std::string Expr::getExpr() {
    return expr;
}

Result Expr::eval() const {
    return Result(expr);
}

void Expr::print(int n) const {
    std::cout << '>';
    for (int i = 0; i < n; i++) {
        std::cout << ' ';
    }

    std::cout << "String: " << expr;
}