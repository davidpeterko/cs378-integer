FILES :=									\
	.travis.yml								\
	integer-tests/dpk326-RunInteger.out		\
	integer-tests/dpk326-TestInteger.c++	\
	integer-tests/dpk326-TestInteger.out	\
	Integer.h 								\
	Integer.log								\
	html									\
	RunInteger.c++ 							\
	RunInteger.out							\
	TestInteger.c++							\
	TestInteger.out							\


ifeq ($(CXX), clang++)
    COVFLAGS := --coverage
    GCOV     := gcov-4.6
else
    CXX      := g++-4.8
    COVFLAGS := -fprofile-arcs -ftest-coverage
    GCOV     := gcov-4.8
endif

CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread
VALGRIND := valgrind

all: RunInteger TestInteger

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunInteger

config:
	git config -l

test: 
	RunInteger.out	TestInteger.out

integer-tests:
	git clone https://github.com/cs378-summer-2015/integer-tests

html: 
	Doxygen Integer.h RunInteger.c++ TestInteger.c++
	doxygen Doxyfile

Integer.log:
	git log > Integer.log

Doxyfile:
	doxygen -g

RunInteger: Integer.h RunInteger.c++
	$(CXX) $(CXXFLAGS) RunInteger.c++ -o RunInteger

RunInteger.out: RunInteger
	./RunInteger > RunInteger.out
	cat RunInteger.out

TestInteger: Integer.h RunInteger.c++ TestInteger.c++
	$(CXX) $(COVFLAGS) $(CXXFLAGS) Integer.h RunInteger.c++ TestInteger.c++ -o TestInteger $(LDFLAGS)

TestInteger.out: TestInteger
	$(VALGRIND) ./TestInteger  >  TestInteger.out 2>&1
	$(GCOV) -b RunInteger.c++  >> TestInteger.out
	$(GCOV) -b TestInteger.c++ >> TestInteger.out
	cat TestInteger.out
