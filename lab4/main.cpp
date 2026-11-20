#include <iostream>
#include <string>
#include "time.h"

int main() {
    bool isRunning = false;
    int userChoice = 0;
    const std::string hint = "using the spacebar: \n";
    isRunning = true;

    while (isRunning) {
        std::cout << "\n";
        std::cout << "1. Hours/minutes -\n";
        std::cout << "2. Hours/minutes +\n";
        std::cout << "3. Adding minutes to time\n";
        std::cout << "4. One minute removal\n";
        std::cout << "5. bool/short int checker\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose the task number: ";
        while (!(std::cin >> userChoice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Error. Please provide a task number (0-5) \n";
        }
        std::cout << "\n";;

        switch (userChoice) {
            case 0: {
                std::cout << "Exit \n";
                isRunning = false;
                break;
            }
            case 1: {
                Time t1, t2;
                std::cout << "Type 1st time " << hint;
                std::cin >> t1;
                std::cout << "Type 2st time " << hint;
                std::cin >> t2;
                std::cout << "Result: " << t1-t2 << "\n";
                break;
            }
            case 2: {
                Time t1, t2;
                std::cout << "Type 1st time: " << hint;
                std::cin >> t1;
                std::cout << "Type 2st time: " << hint;
                std::cin >> t2;
                
                std::cout << "Result: " << t1+t2 << "\n";
                break;
            }
            case 3: {
                Time t1;
                int add_mins;
                std::cout << "Type your time: " << hint;
                std::cin >> t1;
                std::cout << "Type the amount of minutes: \n";
                while (true) {
                    if (!(std::cin >> add_mins)) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                    }
                    if (add_mins < 0) { 
                        std::cout << "Error. Amount of minutes "
                        " cannot be negative! \n";
                        continue;
                    }
                    break;
                }
                std::cout << "Result: " << (t1 + static_cast<unsigned int>(add_mins)) << "\n";
                break;
            }
            case 4: {
                Time t1;
                std::cout << "Type your time: " << hint;
                std::cin >> t1;

                Time post_dec = t1--;
                std::cout << "After t1--: " << post_dec <<
                " and the updated time: " << t1 << "\n";
                Time pre_dec = --t1;
                std::cout << "After --t1: " << pre_dec << "\n";
                break;
            }
            case 5: {
                Time t1;
                std::cout << "Type your time: " << hint;
                std::cin >> t1;

                short int hours_only = static_cast<short int>(t1);
                std::cout << "Explicit adduction to short int: " <<
                hours_only << "\n";

                bool is_valid = t1;
                std::cout << "Unexplicit adduction to bool: " <<
                (is_valid ? "TRUE (time != 00:00)" : "FALSE (time = 00:00)") <<
                "\n";
                break;
            }
            default: {
                std::cout << "Pick a number between 0 and 5! \n";
                break;
            }
        }
    }
    return 0;
}