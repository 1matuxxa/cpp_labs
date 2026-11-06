#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

class Department;

class Employee {
public:
    explicit Employee(const std::string& name);

    void setDepartment(Department* department);
    
    std::string getName() const;
    Department* getDepartment() const;

    void print() const;
    std::vector<Employee*> getDepartmentEmployees() const;

private:
    std::string name;
    Department* department;
};

#endif