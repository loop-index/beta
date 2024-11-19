#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

// #ifndef TEST
string get_input() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);
    return input;
}
// #endif

vector<string> split(string input) {
    vector<string> tokens;
    char *token = strtok(&input[0], " ");
    while (token != NULL) {
        tokens.push_back(token);
        token = strtok(NULL, " ");
    }
    return tokens;
}

double add(double a, double b) {
    return a + b;
}

double plus_op(double a, double b) {
    return add(a, b);
}

double minus_op(double a, double b) {
    // TODO: Implement this function
    return add(a, b);
}

int get_random_num() {
    return rand();
}


int count_leading_zeroes(int value) {

#ifdef __aarm__ // Only for arm
    // return __builtin__arm_clz(value); // This is natively mapped by GCC
    if (value == 0) {
        throw("0 is not allowed. Result is undefined");
    }
        return __builtin_clzll(value);

    // return the trailing 0s instead for non-arm machine
    return __builtin_ctz(value);
#endif
}


double calculator() {
    vector<string> tokens = split(get_input());
    double a = stod(tokens[0]);
    double b = stod(tokens[2]);
    string op = tokens[1];
    double result = 0;

    if (op == "+") {
        result = plus_op(a, b);
    }
    else if (op == "-") {
        result = minus_op(a, b);
    }

    return result;
}

#ifndef TEST
int main() {
    double result = calculator();
    cout << "Result: " << result << endl;
    return 0;
}
#endif