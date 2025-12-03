#include "behavior.hpp"
#include <iostream>
#include <cmath>
#include <limits.h>
#include <forward_list>
#include "../result/result.hpp"
#include "../storage/storage.hpp"

class Id : public Behavior {
public:
    Id() : Behavior("id", 1) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 1) {
            return args[0]->eval();
        }
        else {
            return Result("Wrong number of arguments passed to id()");
        }
    }
};

class Add : public Behavior {
public:
    Add() : Behavior("add", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The first argument of add() is not a number");
            }
            
            if (!arg1.is_number()) {
                return Result("The second argument of add() is not a number");
            }

            return arg0.num + arg1.num;
        }
        else  {
            Result res("Wrong number of arguments passed to add()");
            return res;
        }
    }
};

class Sub : public Behavior {
public:
    Sub() : Behavior("sub", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The first argument of sub() is not a number");
            }
            
            if (!arg1.is_number()) {
                return Result("The second argument of sub() is not a number");
            }
    
            return arg0.num - arg1.num;
        }
        else  {
            return Result("Wrong number of arguments passed to sub()");
        }
    }
};

class Mul : public Behavior {
public:
    Mul() : Behavior("mul", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The first argument of mul() is not a number");
            }

            if (!arg1.is_number()) {
                return Result("The second argument of mul() is not a number");
            }
    
            return arg0.num * arg1.num;
        }
        else  {
            return Result("Wrong number of arguments passed to mul()");
        }
    }
};

class Div : public Behavior {
public:
    Div() : Behavior("div", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The first argument of div() is not a number");
            }
            
            if (!arg1.is_number()) {
                return Result("The second argument of div() is not a number");
            }

            if (arg1.num == 0) {
                return Result("Division by 0");
            }
    
            return arg0.num / arg1.num;
        }
        else  {
            return Result("Wrong number of arguments passed to div()");
        }
    }
};

class Pow : public Behavior {
public:
    Pow() : Behavior("pow", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The first argument of pow() is not a number");
            }
            
            if (!arg1.is_number()) {
                return Result("The second argument of pow() is not a number");
            }
    
            return pow(args[0]->eval().num, args[1]->eval().num);
        }
        else  {
            return Result("Wrong number of arguments passed to pow()");
        }
    }
};

class Sqrt : public Behavior {
public:
    Sqrt() : Behavior("sqrt", 1) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 1) {
            Result arg0 = args[0]->eval();

            if (!arg0.is_number()) {
                return Result("The argument of sqrt() is not a number");
            }

            return sqrt(arg0.num);
        }
        else  {
            return Result("Wrong number of arguments passed to sqrt()");
        }
    }
};

class Sin : public Behavior {
public:
    Sin() : Behavior("sin", 1) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 1) {
            Result arg0 = args[0]->eval();

            if (!arg0.is_number()) {
                return Result("The argument of sin() is not a number");
            }

            return sqrt(arg0.num);
        }
        else  {
            return Result("Wrong number of arguments passed to sin()");
        }
    }
};

class Cos : public Behavior {
public:
    Cos() : Behavior("cos", 1) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 1) {
            Result arg0 = args[0]->eval();

            if (!arg0.is_number()) {
                return Result("The argument of cos() is not a number");
            }

            return sqrt(arg0.num);
        }
        else  {
            return Result("Wrong number of arguments passed to cos()");
        }
    }
};

class Eq : public Behavior {
public:
    Eq() : Behavior("eq", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The first argument of eq() is not a number");
            }
            
            if (!arg1.is_number()) {
                return Result("The second argument of eq() is not a number");
            }
    
            return arg0.num == arg1.num;
        }
        else  {
            return Result("Wrong number of arguments passed to eq()");
        }
    }
};

class Le : public Behavior {
public:
    Le() : Behavior("le", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The first argument of le() is not a number");
            }
            
            if (!arg1.is_number()) {
                return Result("The second argument of le() is not a number");
            }
    
            return arg0.num <= arg1.num;
        }
        else  {
            return Result("Wrong number of arguments passed to le()");
        }
    }
};

class Nand : public Behavior {
public:
    Nand() : Behavior("nand", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg0 = args[0]->eval();
            Result arg1 = args[1]->eval();

            if (!arg0.is_number()) {
                return Result("The second first of nand() is not a number");
            }
            
            if (!arg1.is_number()) {
                return Result("The second argument of nand() is not a number");
            }
    
            return !(arg0.num != 0 && arg1.num != 0);
        }
        else  {
            return Result("Wrong number of arguments passed to nand()");
        }
    }
};

class If : public Behavior {
public:
    If() : Behavior("if", 3) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 3) {
            Result arg0 = args[0]->eval();

            if (!arg0.is_number()) {
                if (arg0.is_list()) {
                    return Result("The first argument of if() was evaluated to a list when it should be a number");
                }
                return Result("The first argument of if() is not a number");
            }

            if (arg0.num) {
                Result arg1 = args[1]->eval();

                if (!arg1.is_number() && !arg1.is_list()) {
                    return arg1.msg;
                }

                if (arg1.is_number()) {
                    return arg1.num;
                }
                else {
                    return arg1.list;
                }
                
            }
            else {
                Result arg2 = args[2]->eval();

                if (!arg2.is_number() && !arg2.is_list()) {
                    return arg2.msg;
                }

                if (arg2.is_number()) {
                    return arg2.num;
                }
                else {
                    return arg2.list;
                }
            }
        }
        else  {
            return Result("Wrong number of arguments passed to if()");
        }
    }
};

class List : public Behavior {
public:
    List() : Behavior("list", INT_MAX) {}

    Result execute(const std::vector<Expr*>& args) {
        std::forward_list<double> result;
        auto cur = result.before_begin();

        for (Expr* arg : args) {
            result.insert_after(cur, arg->eval().num);
            cur++;
        }

        return result;
    }
};

class Head : public Behavior {
public:
    Head() : Behavior("head", 1) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 1) {
            Result arg0 = args[0]->eval();

            if (!arg0.is_list()) {
                return Result("The argument to head() is not a list!");
            }
            
            return arg0.list.front();
        }
        else {
            return Result("Wrong number of arguments passed to head()!");
        }
    }
};

class Tail : public Behavior {
public:
    Tail() : Behavior("tail", 1) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 1) {
            Result arg0 = args[0]->eval();

            if (!arg0.is_list()) {
                return Result("The argument to tail() is not a list!");
            }

            arg0.list.pop_front();
            
            return arg0.list;
        }
        else {
            return Result("Wrong number of arguments passed to tail()!");
        }
    }
};

class Map : public Behavior {
public:
    Map() : Behavior("map", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg1 = args[1]->eval();
            if (!arg1.is_list()) {
                return Result("The second argument of map() is not a list!");
            }

            std::forward_list<double> res;
            auto iterRes = res.before_begin();

            Behavior* function = Storage::find(args[0]->getExpr());

            if (function == nullptr) {
                return Result("The function passed to map() was not found!"), 1;
            }

            if (function->getNumArgs() != 1) {
                return Result("The function passed to map() is not applicable to the list!");
            }

            std::vector<Expr*> argToPass;


            for (double listElement : arg1.list) {                
                argToPass.push_back(new Num_Expr(listElement));

                Result functionRes = function->execute(argToPass);

                if (!functionRes.is_number()) {
                    std::string errorMsg = "Error while applying " + function->getFuncName() + " to " + argToPass[0]->getExpr();
                    delete argToPass.back();
                    return Result(errorMsg);
                }

                res.insert_after(iterRes, functionRes.num);
                iterRes++;

                delete argToPass[0];
                argToPass.pop_back();
            }

            return res;
            
        }
        else {
            return Result("Wrong number of arguments passed to map()");
        }
    }
};

class Filter : public Behavior {
public:
    Filter() : Behavior("filter", 2) {}

    Result execute(const std::vector<Expr*>& args) {
        if (args.size() == 2) {
            Result arg1 = args[1]->eval();
            if (!arg1.is_list()) {
                return Result("The second argument of filter() is not a list!");
            }

            std::forward_list<double> res;
            auto iterRes = res.before_begin();

            Behavior* function = Storage::find(args[0]->getExpr());

            if (function == nullptr) {
                return Result("The function passed to filter() was not found!");
            }

            if (function->getNumArgs() > 1) {
                return Result("The function passed to filter() is not applicable to the list!");
            }

            std::vector<Expr*> argToPass;


            for (double listElement : arg1.list) {
                argToPass.push_back(new Num_Expr(listElement));

                Result functionRes = function->execute(argToPass);

                if (!functionRes.is_number()) {
                    std::string errorMsg = "Error while applying " + function->getFuncName() + " to " + argToPass[0]->getExpr();
                    delete argToPass[0];
                    return Result(errorMsg);
                }

                if (functionRes.num) {
                    res.insert_after(iterRes, argToPass[0]->eval().num);
                    iterRes++;
                }

                delete argToPass[0];
                argToPass.pop_back();
            }

            return res;
            
        }
        else {
            return Result("Wrong number of arguments passed to filter()");
        }
    }
}; 