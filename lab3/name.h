#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
public:
    explicit Name(const std::string& firstName);
    Name(const std::string& firstName, const std::string& lastName);
    Name(const std::string& firstName, const std::string& lastName,
        const std::string& middleName);

    void print() const;
    std::string toString() const;

private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
};

#endif