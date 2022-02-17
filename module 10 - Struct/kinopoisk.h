//
// Created by Alexander Meshcheryakov on 06.12.2021.
//

#ifndef TEST_KINOPOISK_H
#define TEST_KINOPOISK_H
#include <string>
#include <map>
#include <vector>
#include <iostream>


std::map<std::string, std::string> dict_mpaa_rate;
struct Auctor {
    int pk;
    std::string name;
    std::string last_name;
    std::string so_name;
};
struct Gen {
    int pk;
    std::string name;
    std::string rate;
};
struct Film {
    int pk;
    std::string name;

};

class kinopoisk {
    void test(){

    }
};


#endif //TEST_KINOPOISK_H
