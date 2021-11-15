//
// Created by Alexander Meshcheryakov on 15.11.2021.
//
#include "../haeders.h"


void array_case_1() {
    const int length = 10;
    const int arr[length] = {10, 13, -3, 34, -45, 60, 12, 70, 81, 19};
    int negative = 0;
    int positive = 0;
    for (int i: arr) {
        if (!negative && i < 0)
            negative = i;

        if (!positive && i > 0)
            positive = i;

        if (positive && negative)
            break;
    }
    std::cout << "negative: " << negative << ", and positive: " << positive << std::endl;
}