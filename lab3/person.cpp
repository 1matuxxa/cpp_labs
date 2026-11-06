#include "person.h"
#include <iostream>

Person::Person(const std::string& name, int height) 
    : name(name), height(height) {}

void Person::print() const {
    std::cout << toString() << "\n";
}

std::string Person::toString() const {
    return name + ", рост: " + std::to_string(height);
}