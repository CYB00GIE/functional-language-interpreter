#pragma once

#include <string>

class Result;

class Expr {
protected:
    std::string expr;

public:

    Expr(std::string str = "");
    std::string getExpr();

    virtual Result eval() const;
    virtual void print(int n = 0) const;
    virtual ~Expr() {};
};