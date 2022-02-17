//
// Created by Alexander Meshcheryakov on 18.12.2021.
//

#ifndef TEST_HOME_ACCOUNTING_H
#define TEST_HOME_ACCOUNTING_H
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

struct Operation {
    time_t time_stamp;
    bool is_income;
    double _sum;
    int cat;

};

vector<Operation> load_from_file(vector<Operation> &arr_operations, string file_path);

bool save_to_file(vector<Operation> &arr_operations, string file_path);

double balance(vector<Operation> &arr_operations, int time_stamp = 0);

bool input_operation(vector<Operation> &arr_operations);

time_t convert_data_to_ts(int day, int month, int year);

vector<string> split(string str, string delimiter = ".");

int main() {
    vector<Operation> arr_operations;
    string file_path = "/Applications/devs/projects/work/itstep/cpp/std/itstep_cpp";
    load_from_file(arr_operations, file_path);
    cout << time(nullptr) << endl;
    string input;
    cin >> input;
    auto t = split(input);
    while (input_operation(arr_operations)) {}
    if (save_to_file(arr_operations, file_path)) {
        cout << "Data saved!" << endl;
    } else {
        cout << "Data NOT saved!" << endl;
    }

    return 0;
}

vector<Operation> load_from_file(vector<Operation> &arr_operations, string file_path) {
    ifstream file(file_path);

    if (file.is_open()) {
        Operation o;
        while (file >> o.time_stamp >> o.is_income >> o._sum >> o.cat) {
            arr_operations.push_back(o);
        }
        file.close();
    } else if (file.bad()) {
        ofstream file;
        file.open(file_path);
        file.close();
    }
    return arr_operations;
}

bool save_to_file(vector<Operation> &arr_operations, string file_path) {
    ofstream file(file_path);
    if (file.is_open()) {
        for (auto i: arr_operations) {
            file << i.time_stamp << " "
                 << i.is_income << " "
                 << i._sum << " "
                 << i.cat << endl;
        }
        file << endl;
        file.close();
        return true;
    }
    return false;
}

double balance(vector<Operation> &arr_operations, int time_stamp) {
    double balance = 0.;
    for (auto i: arr_operations) {
        if (time_stamp != 0) {
            if (i.time_stamp <= time_stamp) {
                if (i.is_income) {
                    balance += i._sum;
                } else {
                    balance -= i._sum;
                }
            }
        } else {
            if (i.is_income) {
                balance += i._sum;
            } else {
                balance -= i._sum;
            }
        }
    }
    return balance;
}

bool input_operation(vector<Operation> &arr_operations) {
    Operation op{};
    cout << "Введите дату, тип, сумму и категорию через пробел: \n";
    string tsh;
    cin >> tsh >> op.is_income >> op._sum >> op.cat;
    auto t = split(tsh);
    op.time_stamp = convert_data_to_ts(std::stoi(t[0]),std::stoi(t[1]),std::stoi(t[2]));
    if (op._sum == 0) return false;
    arr_operations.push_back(op);
    return true;
}

time_t convert_data_to_ts(int day, int month, int year) {
    struct tm timeinfo;
    int hour = 0, min = 0, sec = 0;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;    //months since January - [0,11]
    timeinfo.tm_mday = day;          //day of the month - [1,31]
    timeinfo.tm_hour = hour;         //hours since midnight - [0,23]
    timeinfo.tm_min = min;          //minutes after the hour - [0,59]
    timeinfo.tm_sec = sec;          //seconds after the minute - [0,59]
    return mktime(&timeinfo);
}

vector<string> split(string str, string delimiter) {
    size_t pos;
    assert(str.rfind(delimiter) + delimiter.size() != delimiter.size());
    if (str.rfind(delimiter) + delimiter.size() != delimiter.size()) {
        str += delimiter;
    }
    std::vector<string> set;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        set.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
    assert(set.size() > 0);
    return set;
}


class home_accounting {

};


#endif //TEST_HOME_ACCOUNTING_H
