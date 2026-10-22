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
    if (c.empty()) {
        return;
    }
    c.front() *= 2;
    c.back() *= 2;
    auto it = c.begin();
    std::advance(it, c.size() /2);
    *it *= 2;
}

void task2(std::vector<int>& v, std::list<int>& l) {
    if (v.size() < 5 || l.size() < 5) {
        return;
    }
    l.insert(std::next(l.begin(), 5),
        std::make_reverse_iterator(v.begin() + 5),
        std::make_reverse_iterator(v.begin()));
}

void task3(std::deque<int>& d) {
    if (d.size() < 4 || d.size() % 4 != 0) {
        return;
    }
    std::size_t n = d.size();
    auto i = d.begin();
    for (std::size_t k = 0; k < n / 4; ++k) {
        i = d.erase(++i);
    }
}

void task4(const std::vector<double>& v) {
    if (v.size() < 2) {
        return;
    }
    std::size_t idx = 0;
    std::remove_copy_if(v.begin(), v.end(),
    std::ostream_iterator<double>(std::cout, " "),
    [&idx](double) { 
        return idx++ % 2 == 0;
    });
    std::cout << '\n';
}

void task5(std::list<int>& l) {
    auto itNeg = std::find_if(l.begin(), l.end(),
        [](int x) {
            return x < 0;
        });
    auto rPos = std::find_if(l.rbegin(), l.rend(),
        [](int x) {
            return x > 0;
        });
    if (itNeg == l.end() || rPos == l.rend()) {
        return;
    }
    l.insert(std::next(itNeg), 0);
    l.insert((++rPos).base(), 0);
}

void task6(std::vector<int>& v) {
    if (v.size() < 2 || v.size() % 2 != 0) {
        return;
    }
    auto mid = v.begin();
    std::advance(mid, v.size() / 2);
    std::vector<int> v0(mid, v.end());
    std::remove_copy_if(v0.begin(), v0.end(),
        std::inserter(v, v.begin()),
        [](int x) {
            return x <= 0;
        });
}

void task7(std::deque<std::string>& d) {
    std::sort(d.begin(), d.end(),
        [](const std::string& a, const std::string& b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            }
            return a < b;
        });
}

void task8(const std::list<int>& l, std::vector<double>& v) {
    if (l.empty()) {
        return;
    }
    std::adjacent_difference(l.begin(), l.end(),
        std::back_inserter(v),
        [](int a, int b) {
            return (a + b) / 2.0;
        });
    if (!v.empty()) {
        v.erase(v.begin());
    }
}

int task9(const std::vector<int>& v0, const std::vector<std::vector<int>>& allV) {
    std::set<int> set0(v0.begin(), v0.end());
    int count = 0;
    for (const auto& vi : allV) {
        std::set<int> setVi(vi.begin(), vi.end());
        if (std::includes(setVi.begin(), setVi.end(), set0.begin(), set0.end())) {
            ++count;
        }
    }
    return count;
}

void task10(const std::vector<std::string>& v) {
    std::map<char, std::size_t> m;
    for (auto it = v.begin(); it != v.end(); ++it) {
        m[(*it)[0]] += (*it).size();
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " " << it->second << '\n';
    }
}

int main() {
    int x = 0;
    while (true) {
        std::cout << "Введите номер задания: (0 - выход) ";
        while (!(std::cin >> x)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Введите число! ";
        }
        if (x == 0) {
            break;
        }
        switch(x) {
            case 1: {
                std::vector<int> v;
                std::deque<int> d;
                std::list<int> l;
                inputContainer(v, 3, true);
                inputContainer(d, 3, true);
                inputContainer(l, 3, true);

                if (!v.empty()) {
                    task1(v);
                    std::cout << "v: ";
                    for (int el : v) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
            } else {
                std::cout << "Вектор не заполнен\n";
            }
                if (!d.empty()) {
                    task1(d);
                    std::cout << "d: ";
                    for (int el : d) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
            } else {
                std::cout << "Дек не заполнен\n";
            }
                if (!l.empty()) {
                    task1(l);
                    std::cout << "l: ";
                    for (int el : l) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
            } else {
                std::cout << "Список не заполнен\n";
            }
                break;
            }

            case 2: {
                std::vector<int> v;
                std::list<int> l;
                inputContainer(v, 5, false);
                inputContainer(l, 5, false);
                if (v.empty() || l.empty()) {
                    break;
                }
                task2(v, l);
                std::cout << "l: ";
                for (int el : l) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
                break;
            }

            case 3: {
                std::deque<int> d;
                inputContainer(d, 4, false);
                if (d.empty()) {
                    break;
                }
                if (d.size() % 4 != 0) {
                    std::cout << "Размер дека должен быть кратен 4!\n";
                    break;
                }
                task3(d);
                std::cout << "d: ";
                for (int el : d) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
                break;
            }

            case 4: {
                std::vector<double> v;
                inputContainer(v, 2, false);
                if (v.empty()) {
                    break;
                }
                task4(v);
                break;
            }

            case 5: {
                std::list<int> l;
                inputContainer(l, 2, false);
                if (l.empty()) {
                    break;
                }
                task5(l);
                std::cout << "l: ";
                for (int el : l) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
                break;
            }

            case 6: {
                std::vector<int> v;
                inputContainer(v, 2, false);
                if (v.empty()) {
                    break;
                }
                if (v.size() % 2 != 0) {
                    std::cout << "Размер должен быть четным!\n";
                    break;
                }
                task6(v);
                std::cout << "v: ";
                for (int el : v) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
                break;
            }

            case 7: {
                std::deque<std::string> d;
                inputContainer(d, 2, false);
                if (d.empty()) {
                    break;
                }
                task7(d);
                std::cout << "d: ";
                for (const auto& word : d) {
                    std::cout << word << ' ';
                }
                std::cout << "\n";
                break;
            }

            case 8: {
                std::list<int> l;
                std::vector<double> v;
                inputContainer(l, 2, false);
                if (l.empty()) {
                    break;
                }
                task8(l, v);
                std::cout << "v: ";
                for (double el : v) {
                    std::cout << el << ' ';
                }
                std::cout << "\n";
                break;
            }

            case 9: {
                std::vector<int> v0;
                std::cout << "Введите вектор v0:\n ";
                inputContainer(v0, 1, false);
                if (v0.empty()) {
                    break;
                }
                std::cout << "Введите N: ";
                int n = 0;
                while (!(std::cin >> n)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Введите число! ";
                }
                if (n <= 0) {
                    std::cout << "N должно быть больше нуля!\n";
                    break;
                }
                std::vector<std::vector<int>> allV;
                for (int i = 0; i < n; ++i) {
                    std::cout << "Введите вектор V " << i + 1 << " :\n";
                    std::vector<int> vi;
                    inputContainer(vi, static_cast<int>(v0.size()), false);
                    allV.push_back(vi);
                }

                int count = task9(v0, allV);
                std::cout << "Подходящих векторов: " << count << '\n';
                break;
            }
            
            case 10: {
                std::vector<std::string> v;
                inputContainer(v, 1, false);
                if (v.empty()) {
                    break;
                }
                task10(v);
                break;
            }

            default: {
                std::cout << "Нет такого задания\n";
                break;
            }
        }
    }
}
