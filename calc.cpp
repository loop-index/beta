#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#ifdef TEST
string get_input() {
    // return "2 - 1";
    return mock().actualCall("get_input").returnStringValue();
}
#else
string get_input() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);
    return input;
}
#endif

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
    return a - b;
}

double plus_op(double a, double b) {
    return add(a, b);
}

double minus_op(double a, double b) {
    // TODO: Implement this function
    return add(a, b);
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