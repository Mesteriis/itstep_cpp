#include <iostream>

#include "module 2 - Data type/DataType.h"
#include "module 3 - Conditions/Conditions.h"
#include "module 5 - Array/Array.h"


int main(){
    auto *data_type = new DataType;
    data_type->case_1();

    auto * conditions = new Conditions;
    conditions->case_1();

    auto arr = new Array;
    arr->case_1();
    arr->case_2();


    return EXIT_SUCCESS;
}