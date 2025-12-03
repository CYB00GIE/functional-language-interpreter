#include "result.hpp"
#include <iostream>

bool Result::is_number() const {
    return isNum;
}

bool Result::is_list() const {
    return msg == "" && !isNum;
}

Result::Result(const std::string& str) {
    msg = str;
    isNum = false;
}

Result::Result(double n) {
    num = n;
    isNum = true;
}

Result::Result(const std::forward_list<double>& l) {
    list = l;
    isNum = false;
}


void Result::print() const {
    if (is_list()) {
        std::cout << '[';
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            if (iter != list.begin()) {
                std::cout << ", ";
            }
            std::cout << *iter;
        }
        std::cout << ']' << std::endl;
    }
    else if (is_number()) {
        std::cout << num << std::endl;
    }
    else {
        std::cout << msg << std::endl;
    }
}
