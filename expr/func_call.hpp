#pragma once

#include <vector>
#include "expr.hpp"

class Func_Call : public Expr {
private:
    std::string func_name;
    std::vector<Expr*> arguments;

    void add_arg(const std::string& arg);
    void to_func();

public:
    Func_Call(std::string _expr);
    void print(int n = 0) const;
    Result eval() const;
    ~Func_Call();
};