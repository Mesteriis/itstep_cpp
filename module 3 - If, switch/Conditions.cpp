//
// Created by Alexander Meshcheryakov on 16.11.2021.
//

#include "Conditions.h"

void Conditions::case_1() {
    std::string str;
    std::cin >> str;
    int a;
    int b;
    enum actions {
        ADDITION = '+',
        SUBTRACTION = '-',
        MULTIPLICATION = '*',
        SEGMENTATION = '/'
    };
    std::string tmp = "";
    actions action;

    for (char i : str) {
        if (isdigit(i) || i == '.') {
            tmp += i;
        } else if (i == '/' || i == '*' || i == '+' || i == '-') {
            action = actions(i);
            a = std::stoi(tmp);
            tmp = "";
        } else if (i == '=') {
            b = std::stoi(tmp);
            switch (action) {
                case ADDITION:
                    std::cout << a + b << std::endl;
                    break;
                case SUBTRACTION:
                    std::cout << a - b << std::endl;
                    break;
                case MULTIPLICATION:
                    std::cout << a * b << std::endl;
                    break;
                case SEGMENTATION:
                    std::cout << a / b << std::endl;
                    break;
            }
        } else {
            std::cout << "Action not found"  << std::endl;
        }
    }
}
