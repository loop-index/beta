#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include <string>
using namespace std;

/* GetInput test
#ifdef TEST
string get_input() {
    // return "2 - 1";
    return mock().actualCall("get_input").returnStringValue();
}

TEST(Calculator, get_input) {
    mock().expectOneCall("get_input").andReturnValue("hello world!");

    CHECK_EQUAL(std::string("hello world!"), get_input());
}
#endif
 */

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



// Why we mock part1. (Uncertain value)
// There's no way to consistently test add_two_random() without seeding.
// In a larger project, or depending on the case, seeding may not be an option
// So we can mock the function itself and have it return an expected value.
TEST(Calculator, SporadicValue) {
    // int a = add_two_random(); // There's no way to know what a's value is. Random value
    // ulong b = square_randomNumber(); // There's no way to check this

    mock().expectOneCall("add_two_random").andReturnValue(15);

    // So instead, we mock get_random_num (Assuming it does its job correctly)
    // And then provide a **valid** result from a.
    int randomReturn = mock().actualCall("add_two_random").returnIntValue();
    CHECK_EQUAL(15,randomReturn);

    std::cout << "Checking square_randomReturn with \
generated_expected_random_value of " << randomReturn << '\n'; 
    CHECK_EQUAL(225, square_randomNumber(randomReturn));

}

/* TEST(Calculator, hardwareSpecific) {
    // Our architecture is x86 so the function call won't work. So we
    // mock the function 
    // int thirty_one_zeroes = count_leading_zeroes(1);

    mock().expectNCalls(3,"count_leading_zeroes").andReturnValue(31);


    CHECK_EQUAL(31, count_leading_zeroes(1));
    CHECK_EQUAL(0, count_leading_zeroes(-1));
    

}  */

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