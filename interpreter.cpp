#include <string>
#include <iostream>
#include <fstream>
#include "expr/expr.hpp"
#include "expr/num_expr.hpp"
#include "expr/func_call.hpp"
#include "expr/func_def.hpp"
#include "result/result.hpp"
#include "parser/parser.hpp"

void interpreter(std::istream& stream) {
    Storage::startUp();

    std::string input;

    std::getline(stream, input);

    while(input != "exit" && stream) {
        if (input == "") {
            continue;
        }

        Parser p(input);

        std::cout << "> ";

        p.eval().print();

        std::getline(stream, input);
    }

    Storage::clear();
}

int main() {
    std::cout << "Would you like to use a file as an input for the program?\nType \"Y\" for yes or \"n\" for no: " << std::endl;
    char c;
    std::cin >> c;
    std::cin.ignore();

    if (c == 'Y') {
        std::cout << "Please enter the relative path (from the current directory) and name of the file in the following format:\n<dir1>/<dir2>/.../<dirn>/<filename>" << std::endl;
        std::string filePath;
        std::getline(std::cin, filePath);
        std::ifstream file;
        std::cout << "Opening " + filePath << std::endl; 
        file.open(filePath);
        std::cout << "Reading from " + filePath << std::endl;
        interpreter(file);
    }
    else if (c == 'n') {
        std::cout << "Reading from the standard input" << std::endl;
        interpreter(std::cin);
    }
    else {
        std::cout << "Invalid character used!\nFinishing the execution..." << std::endl;
    }

    return 0;
}