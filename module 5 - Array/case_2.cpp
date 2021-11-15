//
// Created by Alexander Meshcheryakov on 15.11.2021.
//
#include "../haeders.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"

void array_case_2() {
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
                                      << " Координаты " << p << f << k << std::endl;
                        }
                        count++;
                    }
                }
            }
            break;
        }
    }
}

#pragma clang diagnostic pop