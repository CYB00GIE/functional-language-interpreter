#include "parser.hpp"

Parser::Parser(const std::string& str) {
    expr = nullptr;
    if ((str[0] >= '0' && str[0] <= '9') || str[0] == '-') {
        expr = new Num_Expr(str);
    }
    else {
        int str_len = str.length();
        for (int i = 0; i < str_len; i++) {
            if (str[i] == '<' && str[i + 1] == '-') {
                expr = new Func_Def(str);
            }
        }
    }
    if (expr == nullptr) {
        expr = new Func_Call(str);
    }
}

Result Parser::eval() const {
    return expr->eval();
}

void Parser::print() const {
    expr->print();
}

Parser::~Parser() {
    delete expr;
}