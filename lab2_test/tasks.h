#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
#include <map>

template<typename Container>
void inputContainer(Container& c, int minSize, bool requireOdd) {
    using T = typename Container::value_type;
    int numElements = 0;
    std::cout << "Введите кол-во элементов: ";
    while (!(std::cin >> numElements)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Введи число! ";
    }

    bool valid = numElements >= minSize &&
     (!requireOdd || numElements % 2 != 0);
    if (valid) {
        for (int i = 0; i < numElements; i++) {
            T x{};
            std::cout << "Введите " << i << " элемент: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Введите число! ";
            }
            c.push_back(x);
        }
    } else {
        std::cout << "Ошибка! Элементов должно быть >= " << minSize
                  << (requireOdd ? " и нечётное" : "") << "\n";
    }
}

template<typename Container>
void task1(Container& c) {
    if (c.empty()) return;
    c.front() *= 2;
    c.back() *= 2;
    auto it = c.begin();
    std::advance(it, c.size() / 2);
    *it *= 2;
}

void task2(std::vector<int>& v, std::list<int>& l);
void task3(std::deque<int>& d);
void task4(const std::vector<double>& v);
void task5(std::list<int>& l);
void task6(std::vector<int>& v);
void task7(std::deque<std::string>& d);
void task8(const std::list<int>& l, std::vector<double>& v);
int task9(const std::vector<int>& v0, const std::vector<std::vector<int>>& allV);
void task10(const std::vector<std::string>& v);