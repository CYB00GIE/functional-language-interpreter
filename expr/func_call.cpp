#include <vector>
#include <iostream>
#include <unordered_map>
#include "func_call.hpp"
#include "num_expr.hpp"
#include "func_def.hpp"
#include "../result/result.hpp"

void Func_Call::add_arg(const std::string& arg) {
    if ((arg[0] >= '0' && arg[0] <= '9') || arg[0] == '-') {
        arguments.push_back(new Num_Expr(arg));
        return;
    }
    else {
        for (char c : arg) {
            if (c == '(') {
                arguments.push_back(new Func_Call(arg));
                return;
            }
        }
        arguments.push_back(new Expr(arg));
    }
}

void Func_Call::to_func() {
    std::string curr_expr; // either the function name or one of the arguments reprsented as a string
    int cnt_open_paren = 1;
    for (char c : expr) {
        if (c == ' ') {
            continue;
        }
        if (func_name.empty() && c != '(') {
            curr_expr += c;
        }
        else {
            if (func_name.empty()) {
                func_name = curr_expr;
                curr_expr.clear();
                continue;
            }

            switch (c) {
                case '(' : {
                            cnt_open_paren++;
                            curr_expr += c;
                            break;
                        }
                case ')' : {
                            cnt_open_paren--;
                            curr_expr += c;
                            break;
                        }
                case ',' : {
                            if (curr_expr.empty()) {
                               //throw "Invalid argument list! The function contains an empty argument!";
                            }
                            if (cnt_open_paren == 1) {
                                add_arg(curr_expr);
                                curr_expr.clear();
                                break;
                            }
                        }
                default : curr_expr += c;
            }
        }
    }

    if (!curr_expr.empty() && curr_expr != ")") {
        curr_expr.pop_back(); // remove the right paren from the last argument
        add_arg(curr_expr);
    }
}

Func_Call::Func_Call(std::string str) : Expr(str) {
    to_func();
}

void Func_Call::print(int n) const {
    std::cout << "> ";
    for (int i = 0; i < n; i++) {
        std::cout << ' ';
    }
    std::cout << "Function call: " << func_name << std::endl;
    for (int i = 0; i < arguments.size(); i++) {
        arguments[i]->print(n + 1);
        std::cout << std::endl;
    }
}

Result Func_Call::eval() const {
    Behavior* func_behavior = Storage::find(func_name);

    if (func_behavior) {
        Result result = func_behavior->execute(arguments);

        if (result.is_list()) {
            return result.list;
        }
        else if (result.is_number()) {
            return result.num;
        }
        else {
            return result.msg;
        }
    }
    else {
        return Result(func_name + "() was not found!");
    }
}

Func_Call::~Func_Call() {
    while (!arguments.empty()) {
        delete arguments.back();
        arguments.pop_back();
    }
}