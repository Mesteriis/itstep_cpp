#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
//
// Created by Alexander Meshcheryakov on 16.11.2021.
//

#include "Array.h"

void Array::case_1() {
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

void Array::case_2() {
    const int pod = 4;
    const int floor = 5;
    const int kv = 2;
    const int dom[pod][floor][kv] = {
            {{5, 8}, {7, 10}, {3, 5}, {6, 7}, {3, 8}},
            {{7, 4}, {1, 5},  {2, 3}, {2, 3}, {5, 1}},
            {{2, 5}, {1, 4},  {3, 6}, {2, 7}, {3, 1}},
            {{3, 2}, {5, 2},  {3, 4}, {6, 4}, {3, 0}}
    };
    std::cout << "Что хозяин надобно: \n";
    std::cout << "\t1- Кол - во жильцов и кол-во соседей\n";
    std::cout << "\t2- Кол-во жильцов в подъезде\n";
    std::cout << "\t3- Определить номер кв многодетных\n";
    std::cout << "\n\t0- выйти из программы\n";
    int input = 0;
    std::cout << "\tСделайте выбор";
    do {
        std::cin >> input;
        if (input > 0 && input <= 3) {
            break;
        } else if (input == 0) { return; }
        else {
            std::cout << "Не верный выбор";
        }

    } while (true);
    switch (input) {
        case 1: {
            // а) по выбранному номеру квартиры определить количество
            // жильцов, а также их соседей проживающих на одном этаже;

            int p, f, k;
            std::cout << "введите подъезд этаж квартиру ";
            std::cout << "Подъест ";
            std::cin >> p;
            std::cout << "Этаж ";
            std::cin >> f;
            std::cout << "Кв ";
            std::cin >> k;
            --p;
            --f;
            --k;
            std::cout << "Жильцы квартиры " << dom[p][f][k] << " Соседи "
                      << dom[p][f][(k == 1) ? 0 : 1];
            break;
        }
        case 2: {
            // б) определить суммарное количество жильцов для каждого подъезда;
            int arr[4] = {0, 0, 0, 0};
            for (int i = 0; i < floor; ++i) {
                arr[0] += dom[0][i][0] + dom[0][i][1];
                arr[1] += dom[1][i][0] + dom[1][i][1];
                arr[2] += dom[2][i][0] + dom[2][i][1];
                arr[3] += dom[3][i][0] + dom[3][i][1];
            }
            for (int i = 0; i < 4; ++i) {
                std::cout << "В подъезде номер " << i + 1 << " жильцов " << arr[i];
            }
            break;
        }
        case 3: {
            // в) определить номера квартир, где живут многодетные семьи.
            // Условно будем считать таковыми, у которых количество членов
            // семьи превышает пять человек.
            int count = 1;
            for (int p = 0; p < 4; p++) {
                for (int f = 0; f < 5; f++) {
                    for (int k = 0; k < 2; k++) {
                        if (dom[p][f][k] > 5) {
                            std::cout << "Многодетная квартира номер " << count
                                      << " Координаты [" << p << "][" << f << "][" << k << "]" << std::endl;
                        }
                        count++;
                    }
                }
            }
            break;
        }
    }
}

void Array::case_3() {
//    Написать, программу, которая вычисляет при- быль фирмы за 6 месяцев. Пользователь вводит прибыль фирмы за каждый месяц.
    const size_t len = 6;
    int arr[len];
    long long int sum = 0;
    for (size_t i = 0; i < len; i++){
        std::cout << "Введите сумму за " << i << ": " << std::endl;
        std::cin >> arr[i];
        sum+= arr[i];
    }
    std::cout << sum << std::endl;
}

void Array::case_4() {
    const size_t len = 10;
    int arr[len] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = len - 1; i >= 0; i--) {
        std::cout << arr[i] << ", ";
    }
}

void Array::case_5() {
//    Пользователь вводит длину сторон пятиуголь- ника, каждая сторона заноситься в массив, необходимо вычислить периметр пятиугольника (периметр — сумма всех сторон).
    const size_t len = 5;
    long long int arr[len];
//    for (size_t i = 0; i < len; i++){
//        std::cin >> arr[i];
//    }
    for (auto & i : arr)
        std::cin >> i;
//  Цылы на 134 и на 137 одинаковы
    long long int sum = 0;
    for (auto i : arr)
        sum+=i;

    std::cout << sum << std::endl;
}

void Array::case_6() {
//    Пользователь вводит прибыль фирмы за год (12 месяцев). Необходимо определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль была минимальна.
    const size_t len = 12;
    int arr[len];

    for (auto & i : arr)
        std::cin >> i;
    int min_index = 1;
    int min_value = arr[0];
    int max_index = 1;
    int max_value = arr[0];
    int count = 1;
    for (auto i : arr){
        if (i < min_value){
            min_value = i;
            min_index = count;
        }
        if (i > max_value){
            max_value = i;
            max_index = count;
        }
        count++;
    }
    std::cout << "min_value: " << min_value << " min_index: " << min_index
    << " max_value: " << max_value << " min_index: " << max_index << std::endl;
}

#pragma clang diagnostic pop