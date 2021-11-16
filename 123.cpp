//
// Created by Александр Мещеряков on 06.11.2021.
//
int foo() {
//                                    5%2==0
    enum countries {
        USA = 1,
        RUS = 7,
        UR = 3,
        URA = 4
    };
    int rus = 7;
    countries c_in = countries(rus);
    switch (c_in) {
        case USA: {
            break;
        }
        case RUS:
            break;
        case UR:
            break;
        case URA:
            break;
        default:
            break;
    }
}
