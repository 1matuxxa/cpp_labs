#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <windows.h>
#include "utils.h"
#include "name.h"
#include "person.h"
#include "employee.h"
#include "department.h"
#include "gun.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    bool isRunning = false;
    int userChoice = 0;

    isRunning = true;

    while (isRunning) {
        std::cout << "1. (Сущности: ФИО* и рост)\n";
        std::cout << "2. (Сотрудники и Отделы)\n";
        std::cout << "3. (Список коллег)\n";
        std::cout << "4. (Имена)\n";
        std::cout << "5. (Пистолет)\n";
        std::cout << "0. Выход\n";
        std::cout << "\n";
        
        userChoice = ReadInt("Выберите номер задания (0-5): ");
        std::cout << "\n";

        switch (userChoice) {
            case 1: {
                int count = 0;
                std::string personName = "";
                int personHeight = 0;
                std::vector<Person> peopleList;

                std::cout << "Задание 1. ФИО и рост\n";
                count = ReadInt("Сколько людей создать? ");
                
                for (int i = 0; i < count; ++i) {
                    std::cout << "\nЧeлoвeк " << i + 1 << ":\n";
                    personName = ReadString("Введите имя: ");
                    personHeight = ReadInt("Введите рост (в см): ");
                    peopleList.emplace_back(personName, personHeight);
                }

                std::cout << "\nСписок созданных людей:\n";
                for (const auto& person : peopleList) {
                    person.print();
                }
                break;
            }
            case 2: {
                std::string deptName = "";
                int count = 0;
                std::string empName = "";
                int managerIndex = 0;
                std::vector<std::unique_ptr<Employee>> employeeList;

                std::cout << "Задание 2. Сотрудники/отделы\n";
                deptName = ReadString("Введите название отдела: ");
                Department dept(deptName);
                
                count = ReadInt("Сколько сотрудников в отделе? ");

                for (int i = 0; i < count; ++i) {
                    std::cout << "\nСотрудник " << i + 1 << ":\n";
                    empName = ReadString("Введите фамилию: ");
                    
                    employeeList.push_back(std::make_unique<Employee>(empName));
                    dept.addEmployee(employeeList.back().get());
                }

                if (!employeeList.empty()) {
                    std::cout << "\nВсего сотрудников: " << employeeList.size()
                    << ". Кто будет начальником?\n";
                    for (size_t i = 0; i < employeeList.size(); ++i) {
                        std::cout << i + 1 << ". "
                        << employeeList[i]->getName() << "\n";
                    }
                    
                    managerIndex = ReadInt("Введите номер сотрудника: ");
                    managerIndex -= 1;
                    
                    if (managerIndex >= 0 && managerIndex 
                        < static_cast<int>(employeeList.size())) {
                        dept.setManager(employeeList[managerIndex].get());
                    } else {
                        std::cout << "Неверный номер. Отдел без начальника\n";
                    }
                }

                std::cout << "\nИнформация о сотрудниках\n";
                for (const auto& emp : employeeList) {
                    emp->print();
                }
                break;
            }
            case 3: {
                std::string deptName = "";
                int count = 0;
                std::string empName = "";
                int targetIndex = 0;
                std::vector<std::unique_ptr<Employee>> employeeList;

                std::cout << "Задание 3. Список коллег\n";
                deptName = ReadString("Введите название отдела: ");
                Department dept(deptName);
                
                count = ReadInt("Сколько сотрудников? ");

                for (int i = 0; i < count; ++i) {
                    std::cout << "\nСотрудник " << i + 1 << ":\n";
                    empName = ReadString("Введите фамилию: ");
                    
                    employeeList.push_back
                    (std::make_unique<Employee>(empName));
                    dept.addEmployee(employeeList.back().get());
                }

                if (!employeeList.empty()) {
                    std::cout << "\nЧьих коллег запросить?\n";
                    for (size_t i = 0; i < employeeList.size(); ++i) {
                        std::cout << i + 1 << ". " <<
                        employeeList[i]->getName() << "\n";
                    }
                    
                    targetIndex = ReadInt("Введите номер сотрудника: ");
                    targetIndex -= 1;
                    
                    if (targetIndex >= 0 &&
                        targetIndex < static_cast<int>(employeeList.size())) {
                        std::cout << "\nСписок коллег через сотрудника: " <<
                         employeeList[targetIndex]->getName() << ":\n";
                        for (const auto* colleague : employeeList[targetIndex]
                            ->getDepartmentEmployees()) {
                            std::cout << "- " << colleague->getName() << "\n";
                        }
                    } else {
                        std::cout << "Неверный номер сотрудника\n";
                    }
                }
                break;
            }
            case 4: {
                int count = 0;
                int mode = 0;
                std::string firstName = "";
                std::string lastName = "";
                std::string middleName = "";
                std::vector<Name> namesList;

                std::cout << "Задание 4. Создание ФИО\n";
                count = ReadInt("Сколько имен? ");
                
                for (int i = 0; i < count; ++i) {
                    std::cout << "\nИмя " << i + 1 << ":\n";
                    mode = ReadInt("Как создать имя? (1 - Имя,"
                        " 2 - Имя и Фамилия, 3 - ФИО): ");
                    
                    if (mode == 1) {
                        firstName = ReadString("Имя: ");
                        namesList.emplace_back(firstName);
                    } else if (mode == 2) {
                        firstName = ReadString("Имя: ");
                        lastName = ReadString("Фамилия: ");
                        namesList.emplace_back(firstName, lastName);
                    } else if (mode == 3) {
                        firstName = ReadString("Имя: ");
                        lastName = ReadString("Фамилия: ");
                        middleName = ReadString("Отчество: ");
                        namesList.emplace_back(firstName, lastName, middleName);
                    } else {
                        std::cout << "Неверный выбор. Имя пропущено\n";
                    }
                }

                std::cout << "\nСписок созданных имен:\n";
                for (const auto& nameObj : namesList) {
                    nameObj.print();
                }
                break;
            }
            case 5: {
                int ammoCount = 0;
                int shotsFired = 0;

                std::cout << "Задание 5. Пистолет\n";
                ammoCount = ReadInt("Сколько патронов зарядить?: ");
                Gun gun(ammoCount);
                
                shotsFired = ReadInt("Сколько раз нажать на курок?: ");
                std::cout << "\nСтреляем! \n";
                
                for (int i = 0; i < shotsFired; ++i) {
                    std::cout << "Выстрел " << i + 1 << ": ";
                    gun.shoot();
                }
                
                std::cout << "\nИтог: ";
                gun.print();
                break;
            }
            case 0: {
                std::cout << "Выход из программы\n";
                isRunning = false; 
                break;
            }
            default: {
                std::cout << "Ошибка! Введи число от 0 до 5\n";
                break;
            }
        }
    }

    return 0;
}