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

// TEST(Calculator, Plus) {
//     double a = 1;
//     double b = 2;
//     double expected = 3;
//     double result = plus_op(a, b);
//     CHECK_EQUAL(expected, result);
// }

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