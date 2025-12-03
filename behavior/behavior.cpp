#include "behavior.hpp"
#include "../expr/func_call.hpp"
#include "../result/result.hpp"


Behavior::Behavior(const std::string& _func_name, int _num_args, const std::string& _body) :
        func_name(_func_name), num_args(_num_args), body(_body) {}

void Behavior::modify_body(int i, const std::vector<Expr*>& args) {
    std::string newBody;

    for (int j = 0; j < i; j++) {
        newBody += body[j];
    }

    newBody += args[body[i + 1] - '0']->getExpr();

    int body_len = body.length();

    for (int j = i + 2; j < body_len; j++) {
        newBody += body[j];
    }

    body = newBody;
}

Result Behavior::execute(const std::vector<Expr*>& args) {
    if ((body[0] >= '0' && body[0] <= '9') || body[0] == '-') {
        Num_Expr result(body);
        return result.get_number();
    }
    
    if (args.size() < num_args) {
        std::string errorMsg = "Wrong number of arguments passed to " + func_name;
        return Result(errorMsg);
    }

    std::vector<Expr*> evaluated_args;

    for (Expr* arg : args) {
        Result argEval = arg->eval();
        if (argEval.is_number()) {
            evaluated_args.push_back(new Num_Expr(arg->eval().num));
        }
        else if (argEval.is_list()) {
            std::string ls = "list(";
            for (auto iter = argEval.list.begin(); iter != argEval.list.end(); iter++) {
                if (iter != argEval.list.begin()) {
                    ls += ", ";
                }
                ls += *iter;
            }
            evaluated_args.push_back(new Expr(ls));
        }
        else {
            evaluated_args.push_back(new Expr(argEval.msg));
        }
    }
    
    std::string temp = body;
    
    int body_len = body.length();
    for (int i = 0; i < body_len; i++) {
        if (body[i] == '#') {
            modify_body(i, evaluated_args);
            body_len = body.length();
        }
    }

    Func_Call call(body);

    body = temp;

    while(!evaluated_args.empty()) {
        delete evaluated_args.back();
        evaluated_args.pop_back();
    }

    return call.eval();
}

int Behavior::getNumArgs() const {
    return num_args;
}

std::string Behavior::getFuncName() const {
    return func_name;
}

void Behavior::printName() {
    std::cout << func_name << std::endl;
}

void Behavior::printBody() {
    std::cout << body << std::endl;
}