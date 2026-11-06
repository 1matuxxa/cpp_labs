#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>

class Employee;

class Department {
public:
    explicit Department(const std::string& name);

    void setManager(Employee* manager);
    void addEmployee(Employee* employee);

    std::string getName() const;
    Employee* getManager() const;
    const std::vector<Employee*>& getEmployees() const;

    void print() const;

private:
    std::string name;
    Employee* manager;
    std::vector<Employee*> employees;
};

#endif