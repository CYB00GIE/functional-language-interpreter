#pragma once

#include "../expr/num_expr.hpp"
#include "../expr/func_call.hpp"
#include "../expr/func_def.hpp"
#include "../result/result.hpp"

class Parser {
private:
    Expr* expr;

public:
    Parser(const std::string& str);
    Result eval() const;
    void print() const;
    ~Parser();
};