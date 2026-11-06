#include "department.h"
#include "employee.h"
#include <iostream>

Department::Department(const std::string& name) 
    : name(name), manager(nullptr) {}

void Department::setManager(Employee* manager) {
    this->manager = manager;
}

void Department::addEmployee(Employee* employee) {
    employees.push_back(employee);
    employee->setDepartment(this);
}

std::string Department::getName() const { 
    return name; 
}

Employee* Department::getManager() const { 
    return manager; 
}

const std::vector<Employee*>& Department::getEmployees() const { 
    return employees; 
}

void Department::print() const {
    std::cout << "Отдел: " << name << "\n";
}