#pragma once

#include <string>
#include <vector>
#include "../expr/num_expr.hpp"

class Behavior {
private:
    std::string body;

    void modify_body(int i, const std::vector<Expr*>& args); // deletes #num from position i in the body of the function and replaces it with args[num] where num is an integer

protected:
    std::string func_name;
    int num_args;

public:
    Behavior(const std::string& _func_name, int num_args, const std::string& _body = "");
    virtual Result execute(const std::vector<Expr*>& _args);
    int getNumArgs() const;
    std::string getFuncName() const;
    void printName();
    void printBody();
    virtual ~Behavior() {}

    friend class Storage;
};