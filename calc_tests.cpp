#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include <string>
using namespace std;

#ifdef TEST
// string get_input() {
//     // return "2 - 1";
//     return mock().actualCall("get_input").returnStringValue();
// }
#endif

#include "calc.cpp"

TEST_GROUP(Calculator) {
    void setup() {
    }

    void teardown() {
        mock().clear();
    }
};

TEST(Calculator, Plus) {
    double a = 1;
    double b = 2;
    double expected = 3;
    double result = plus_op(a, b);
    CHECK_EQUAL(expected, result);
}

int add_two_random() {
    return (get_random_num() % INT32_MAX / 2) + get_random_num();
}

int mocked_addTwo() {
    return mock().actualCall("add_two_random").returnIntValue();
}

// Why we mock part1. (Uncertain value)
TEST(Calculator, SporadicValue) {
    // int a = get_random_num();   // I have no idea what a is
    // int b = get_random_num();   // I have no idea what b is
    // int c = add_two_random();

    mock().expectOneCall("add_two_random");

    // So instead, we mock get_random_num (Assuming it does its job correctly)
    // And then provide a **valid** result from a.
    mock().expectOneCall("mocked_addTwo").andReturnValue(37);

    int results = mocked_addTwo();
    std::cout << "This is result: " << results <<"\n\n\n"; 
    CHECK_EQUAL(37,results);

}

TEST(Calculator, hardwareSpecific) {
    // Our architecture is x86 so the function call won't work. So we
    // mock the function 
    // int thirty_one_zeroes = count_leading_zeroes(1);

    mock().expectOneCall("count_leading_zeroes").andReturnValue(31);

    int thirty_one_zeroes = count_leading_zeroes(1);

    CHECK_EQUAL(31, thirty_one_zeroes);
}

// TEST(Calculator, Minus) {
//     double a = 2;
//     double b = 1;
//     double expected = 1;
//     double result = minus_op(a, b);
//     CHECK_EQUAL(expected, result);
// }

// TEST(Calculator, Calculator) {
//     // mock().expectOneCall("get_input").andReturnValue("2 + 1");

//     double expected = 3;
//     double result = calculator();
//     CHECK_EQUAL(expected, result);

//     // mock().checkExpectations();
// }