// -----------------------------------
// projects/c++/integer/RunInteger.c++
// Copyright (C) 2015
// Glenn P. Downing
// -----------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <deque>    // deque
#include <ctime>

#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;

    
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;

    {

    clock_t start = clock();

    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    clock_t end = clock();
    cout << "2^4423 - 1 = " << n << endl;
    double duration = (end - start) *1000 / (double) CLOCKS_PER_SEC;
    cout << "duration: " << duration << endl << endl;
    }

    {
    clock_t start = clock();
    const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
    clock_t end = clock();
    cout << "2^4423 - 1 = " << n << endl;
    double duration = (end - start) *1000 / (double) CLOCKS_PER_SEC;
    cout << "duration: " << duration << endl << endl;
    }

    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min
    
    cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

    {
    clock_t start = clock();
    const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    clock_t end = clock();
    cout << "2^132049 - 1 = " << n << endl;
    double duration = (end - start) *1000 / (double) CLOCKS_PER_SEC;
    cout << "duration: " << duration << endl << endl;
    }
    cout << "Done." << endl;
    

    return 0;}