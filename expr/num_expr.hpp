#pragma once

#include <iostream>
#include "expr.hpp"

class Num_Expr : public Expr {
private:
    double num;

    void to_num();

public:
    Num_Expr(std::string str);
    Num_Expr(double n);
    void print(int n = 0) const;
    double get_number() const;
    Result eval() const;
};