#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& name, int height);

    void print() const;
    std::string toString() const;

private:
    std::string name;
    int height;
};

#endif