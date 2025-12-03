#pragma once

#include "expr.hpp"
#include "../storage/storage.hpp"

class Func_Def : public Expr {
private:
    std::string func_name;
    std::string body;
    int num_args;

    void define();

public:
    Func_Def(std::string str);
    void print(int n = 0) const;
    Result eval() const;
};