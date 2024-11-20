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


/// @brief Generates a random number
int get_random_num() {
    return rand();
}

/// @brief Squares the provided number. If no parameter provided or provided
/// @brief value is 0, gets a random value and squares it.
unsigned long square_randomNumber(int val = 0) {
    if (val == 0)
        int val = get_random_num();

    return val * val;
}

#ifdef __arm__ // Only for arm
#endif
/// @brief Counts the leading zeroes of the provided value
/// @return Returns -1 on x86 and an actual count on x84
int count_leading_zeroes(int value) {

    // return __builtin__arm_clz(value); // This is natively mapped by GCC
    if (value == 0) {
        throw("0 is not allowed. Result is undefined");
    }
        return __builtin_clzll(value);

    // return the trailing 0s instead for non-arm machine
    return __builtin_ctz(value);

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

#ifdef __arm__ // hardware specific instruction
#endif

//////////////////////////////////////////////////
/// Assume this section is hardware dependant ////
//////////////////////////////////////////////////

int count_set_bits(int value) {
    return __builtin_popcount(value);  // Real implementation that we're mocking in the test
}


void fun_function(int value)
{
    // Call to real count_set_bits function (mocked in tests)
    int result = count_set_bits(value);
    std::cout << "set bits for " << value << " is: " << result << '\n';
}

//////////////////////////////////////////////////
///          End hardware dependacy           ////
//////////////////////////////////////////////////

#ifndef TEST
int main() {
    double result = calculator();
    cout << "Result: " << result << endl;
    return 0;
}
#endif