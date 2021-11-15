cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(itstep_cpp main.cpp haeders.h "module 5 - Array/case_1.cpp" "module 5 - Array/case_2.cpp"
        "module 3 - If, switch/case_1.cpp")