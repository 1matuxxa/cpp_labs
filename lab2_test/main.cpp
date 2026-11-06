#include <iostream>
#include <fstream>
#include <windows.h>
#include "tasks.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int x = 0;
    while (true) {
        std::cout << "Введите номер задания: (0 - выход) ";
        while (!(std::cin >> x)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Введите число! ";
        }
        if (x == 0) break;

        switch(x) {
            case 1: {
                std::ifstream fin_v("in1_v.txt");
                std::ifstream fin_d("in1_d.txt");
                std::ifstream fin_l("in1_l.txt");
                std::ofstream fout("out1.txt");

                if (!fin_v.is_open() || !fin_d.is_open() || !fin_l.is_open()) {
                    std::cout << "Файлы не найдены\n";
                    break;
                }

                std::vector<int> v((std::istream_iterator<int>(fin_v)),
                 std::istream_iterator<int>());
                std::deque<int> d((std::istream_iterator<int>(fin_d)),
                 std::istream_iterator<int>());
                std::list<int> l((std::istream_iterator<int>(fin_l)),
                 std::istream_iterator<int>());

                task1(v);
                task1(d);
                task1(l);

                std::copy(v.begin(), v.end(), std::ostream_iterator<int>(fout, " "));
                fout << "\n";
                std::copy(d.begin(), d.end(), std::ostream_iterator<int>(fout, " "));
                fout << "\n";
                std::copy(l.begin(), l.end(), std::ostream_iterator<int>(fout, " "));
                fout << "\n";
                std::cout << "Результат записан в out1.txt\n";
                break;
            }

            case 2: {
                std::ifstream fin_v("in2_v.txt");
                std::ifstream fin_l("in2_l.txt");
                std::ofstream fout("out2.txt");
                
                if (!fin_v.is_open() || !fin_l.is_open()) {
                    std::cout << "Файлы не найдены\n";
                    break;
                }

                std::vector<int> v((std::istream_iterator<int>(fin_v)),
                 std::istream_iterator<int>());
                std::list<int> l((std::istream_iterator<int>(fin_l)),
                 std::istream_iterator<int>());
                task2(v, l);

                std::copy(l.begin(), l.end(), std::ostream_iterator<int>(fout, " "));
                fout << "\n";
                std::cout << "Результат записан в out2.txt\n";
                break;
            }

            case 3: {
                std::ifstream fin_d("in3_d.txt");
                std::ofstream fout("out3.txt");

                if (!fin_d.is_open()) {
                    std::cout << "Файлы не найдены\n";
                    break;
                }

                std::deque<int> d((std::istream_iterator<int>(fin_d)),
                 std::istream_iterator<int>());
                task3(d);

                std::copy(d.begin(), d.end(), std::ostream_iterator<int>(fout, " "));
                fout << "\n";
                std::cout << "Результат записан в out3.txt\n";
                break;
            }

            case 4: {
                std::vector<double> v;
                inputContainer(v, 2, false);
                if (v.empty()) break;
                task4(v);
                break;
            }

            case 5: {
                std::list<int> l;
                inputContainer(l, 2, false);
                if (l.empty()) break;
                task5(l);
                std::cout << "l: ";
                for (int el : l) std::cout << el << ' ';
                std::cout << "\n";
                break;
            }

            case 6: {
                std::vector<int> v;
                inputContainer(v, 2, false);
                if (v.empty()) break;
                if (v.size() % 2 != 0) {
                    std::cout << "Размер должен быть четным!\n";
                    break;
                }
                task6(v);
                std::cout << "v: ";
                for (int el : v) std::cout << el << ' ';
                std::cout << "\n";
                break;
            }

            case 7: {
                std::deque<std::string> d;
                inputContainer(d, 2, false);
                if (d.empty()) break;
                task7(d);
                std::cout << "d: ";
                for (const auto& word : d) std::cout << word << ' ';
                std::cout << "\n";
                break;
            }

            case 8: {
                std::list<int> l;
                std::vector<double> v;
                inputContainer(l, 2, false);
                if (l.empty()) break;
                task8(l, v);
                std::cout << "v: ";
                for (double el : v) std::cout << el << ' ';
                std::cout << "\n";
                break;
            }

            case 9: {
                std::vector<int> v0;
                std::cout << "Введите вектор v0:\n ";
                inputContainer(v0, 1, false);
                if (v0.empty()) break;
                
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
                if (v.empty()) break;
                task10(v);
                break;
            }

            default:
                std::cout << "Нет такого задания\n";
                break;
        }
    }
    return 0;
}