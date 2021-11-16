//
// Created by Александр Мещеряков on 03.11.2021.
//

#include <iostream>

int main() {
    bool _bool = true;

    char _char = 'a';
    char16_t _char16_t = 'a';
    char32_t _char32_t = 'a';

    short shot_int = 32767;
    unsigned short u_shot_int = 65535;
    int integer = 32767;
    long long_integer = 2_147_483_647;
    long long ll_integer = 9223372036854775807;
    unsigned long long ull_integer = 18446744073709551615;
    size_t size_t_int = 0;

    float _float = 0.1;
    double _double = 0.1;
    long double _long_d = 0.1;

    std::cout << "_bool: " << _bool << " size: " << sizeof(_bool) << " byte"
              << " value. true/false 1/0\n";

    std::cout << "_char: " << _char << " size: " << sizeof(_char) << " byte"
              << " value. -128 to 127 or 0 to 255 \n";
    std::cout << "_char16_t: " << _char16_t << " size: " << sizeof(_char16_t) << " byte"
              << " value. 0 to 65 535\n";
    std::cout << "_char32_t: " << _char32_t << " size: " << sizeof(_char32_t) << " byte"
              << " value. 0 to 4 294 967 295\n";

    std::cout << "shot_int: " << shot_int << " size: " << sizeof(shot_int) << " byte"
              << " value. min -32768 max 32767\n";
    std::cout << "u_shot_int: " << u_shot_int << " size: " << sizeof(u_shot_int) << " byte"
              << " value. min 0 max 65535\n";
    std::cout << "integer: " << integer << " size: " << sizeof(integer) << " byte"
              << "(4b) value. min −2 147 483 648  max 2 147 483 647 or (2b) –32768 до 32767\n";
    std::cout << "long_integer: " << long_integer << " size: " << sizeof(long_integer) << " byte"
              << " value. min −2 147 483 648 max 2 147 483 647\n";
    std::cout << "ll_integer: " << ll_integer << " size: " << sizeof(ll_integer) << " byte"
              << " value. min −9 223 372 036 854 775 808 max +9 223 372 036 854 775 807\n";
    std::cout << "ull_integer: " << ull_integer << " size: " << sizeof(ull_integer) << " byte"
              << " value. min 0 max 18 446 744 073 709 551 615\n";
    std::cout << "size_t_int: " << size_t_int << " size: " << sizeof(size_t_int) << " byte"
              << " value. OS requires\n";

    std::cout << "_float: " << _float << " size: " << sizeof(_float) << " byte"
              << " value. +/- 3.4E-38\n";
    std::cout << "_double: " << _double << " size: " << sizeof(_double) << " byte"
              << " value. +/- 1.7E-308\n";
    std::cout << "_long_d: " << _long_d << " size: " << sizeof(_long_d) << " byte"
              << " value.  OS requires\n";

    void *_void;
    auto _auto;
    _auto = "auto";

    int scan;
    printf("printf");
    scanf("%d", &scan);


    int value = 5;
    auto *ptr = &value;

    std::cout << value << '\n';
    std::cout << ptr << '\n';

    class test {
    public:
        int test_1 = 1;
        unsigned int test_2 = 1;
        unsigned long long test_3 = 1;
    };
    test t;
    auto *ptr_class = new test;
    std::cout << "size class 3 int: " << sizeof(t) << " byte" <<std::endl;
    std::cout << "size ptr_class 3 int: " << sizeof(ptr_class) << " byte" <<std::endl;
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    std::cout << "a " << a << std::endl;
    std::cout << "b " << b << std::endl;
    std::cout << "a*b " << a * b << std::endl;
    std::cout << "a+b " << a + b << std::endl;
    std::cout << "a-b " << a - b << std::endl;

    char _c;
    std::cin >> _c;
    std::cout << "_c " << _c;
    for (int i= 0; i<255; i++){
        std::cout << i << " - " << (char) i << " ";
        if (i%10 == 0){
            std::cout << std::endl;
        }
    }
    return 0;
}