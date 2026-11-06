#include "employee.h"
#include "department.h"
#include <iostream>

Employee::Employee(const std::string& name) 
    : name(name), department(nullptr) {}

void Employee::setDepartment(Department* department) {
    this->department = department;
}

std::string Employee::getName() const { 
    return name; 
}

Department* Employee::getDepartment() const { 
    return department; 
}

void Employee::print() const {
    if (!department) {
        std::cout << name << " не привязан к отделу.\n";
        return;
    }
    
    if (department->getManager() == this) {
        std::cout << name << " начальник отдела " 
        << department->getName() << "\n";
    } else {
        std::string managerName = department->getManager() 
        ? department->getManager()->getName() : "Не назначен";
        std::cout << name << " работает в отделе " << department->getName() 
                  << ", начальник которого " << managerName << "\n";
    }
}

std::vector<Employee*> Employee::getDepartmentEmployees() const {
    if (department) {
        return department->getEmployees();
    }
    return {};
}