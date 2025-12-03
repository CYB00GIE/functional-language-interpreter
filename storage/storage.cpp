#include "storage.hpp"
#include "../behavior/predefined_functions.cpp"


std::unordered_map<std::string, Behavior*> Storage::map;

void Storage::startUp() {
    map.insert({"id", new Id()});
    map.insert({"add", new Add()});
    map.insert({"sub", new Sub()});
    map.insert({"mul", new Mul()});
    map.insert({"div", new Div()});
    map.insert({"pow", new Pow()});
    map.insert({"sqrt", new Sqrt()});
    map.insert({"sin", new Sin()});
    map.insert({"cos", new Cos()});
    map.insert({"eq", new Eq()});
    map.insert({"le", new Le()});
    map.insert({"nand", new Nand()});
    map.insert({"if", new If()});
    map.insert({"list", new List()});
    map.insert({"head", new Head()});
    map.insert({"tail", new Tail()});
    map.insert({"map", new Map()});
    map.insert({"filter", new Filter()});
}

void Storage::insert(const std::string& func_name, Behavior&& behavior) {
    map.insert({func_name, new Behavior(behavior.func_name, behavior.num_args, behavior.body)});
}

Behavior* Storage::find(const std::string& func_name) {
    if (map.find(func_name) != map.end()) {
        return map.find(func_name)->second;
    }
    else {
        return nullptr;
    }
}

void Storage::clear() {
    for (std::pair<std::string, Behavior*> pair : map) {
        delete pair.second;
    }
    map.clear();
}

void Storage::printContents() {
    for (std::pair<std::string, Behavior*> pair : map) {
        pair.second->printName();
    }
}

Storage::~Storage() {
    clear();
}