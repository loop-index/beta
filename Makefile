CPPUTEST_HOME = /usr
CPPFLAGS += -I$(CPPUTEST_HOME)/include
LDFLAGS += -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

all: build

build: calc.cpp
	g++ -o calc calc.cpp

test: tests.cpp calc_tests.cpp
	g++ -o calc tests.cpp calc_tests.cpp $(CPPFLAGS) $(LDFLAGS) -DTEST

coverage: tests.cpp calc_tests.cpp
	g++ -o calc tests.cpp calc_tests.cpp $(CPPFLAGS) $(LDFLAGS) -DTEST --coverage -O0
	-./calc -c -ojunit
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage

run: build
	./calc

clean:
	rm -f calc
	rm -f *.gcda *.gcno *.info
	rm -rf coverage