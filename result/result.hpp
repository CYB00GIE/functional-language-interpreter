#pragma once

#include <string>
#include <forward_list>

struct Result {
    std::string msg;
    double num;
    bool isNum;
    std::forward_list<double> list;

    Result(const std::string& str = "");
    Result(double n);
    Result(const std::forward_list<double>& l);


    bool is_number() const;
    bool is_list() const;

    void print() const;

};