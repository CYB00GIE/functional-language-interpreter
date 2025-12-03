#pragma once

#include <unordered_map>
#include <string>
#include "../behavior/behavior.hpp"

class Storage {
private:
    static std::unordered_map<std::string, Behavior*> map;

public:
    static void startUp();
    static void insert(const std::string& func_name, Behavior&& behavior);
    static Behavior* find(const std::string& func_name);
    static void clear();
    static void printContents();
    ~Storage();
};
