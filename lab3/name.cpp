#include "name.h"
#include <iostream>

Name::Name(const std::string& firstName, const std::string& lastName,
    const std::string& middleName) 
    : firstName(firstName), lastName(lastName), middleName(middleName) {}

Name::Name(const std::string& firstName, const std::string& lastName) 
    : Name(firstName, lastName, "") {}

Name::Name(const std::string& firstName) 
    : Name(firstName, "", "") {}

void Name::print() const {
    std::cout << toString() << "\n";
}

std::string Name::toString() const {
    std::string result = "";
    if (!lastName.empty()) {
        result += lastName + " ";
    }
    if (!firstName.empty()) {
        result += firstName + " ";
    }
    if (!middleName.empty()) {
        result += middleName + " ";
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}