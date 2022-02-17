cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(itstep_cpp main.cpp
        "module 5 - Array/Array.cpp" "module 5 - Array/Array.h"
        "module 3 - Conditions/Conditions.cpp" "module 3 - Conditions/Conditions.h"
        "module 2 - Data type/DataType.cpp" "module 2 - Data type/DataType.h"
        "module 10 - Struct/kinopoisk.cpp" "module 10 - Struct/kinopoisk.h"
        "libs/json.hpp" "libs/md5.h" "libs/md5.cpp" )