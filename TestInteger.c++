// ------------------
// cs378-pfd/PFD.c++
// Copyright (C) 2015
// David Peter Ko
// Julio Maldonado
// ------------------

// -------
// Defines
// -------

// --------
// Includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <algorithm> //alg
#include "gtest/gtest.h"
#include "Integer.h"

using namespace std;

// -------
// TestInteger
// -------

// -----------------
// shift_left_digits
// -----------------
	TEST(IntegerFixture, shift_left_digits1){
		int first[] = {1, 2, 3};
		int answer[] = {0, 0, 0, 1, 2, 3};

		int result[10];

		int* it = shift_left_digits(first, first + 3, 3, result);
		
		ASSERT_EQ(6, it - result);

		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
		ASSERT_EQ(*(answer+2), *(result+2));
		ASSERT_EQ(*(answer+3), *(result+3));
		ASSERT_EQ(*(answer+4), *(result+4));
		ASSERT_EQ(*(answer+5), *(result+5));
	}

	TEST(IntegerFixture, shift_left_digits2){
		int first[] = {1, 2, 3};
		int answer[] = {0, 0, 1, 2, 3};

		int result[10];

		int* it = shift_left_digits(first, first + 3, 2, result);
		
		ASSERT_EQ(5, it - result);

		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
		ASSERT_EQ(*(answer+2), *(result+2));
		ASSERT_EQ(*(answer+3), *(result+3));
		ASSERT_EQ(*(answer+4), *(result+4));
	}

	TEST(IntegerFixture, shift_left_digits3){
		int first[] = {1, 2, 3};
		int answer[] = {0, 1, 2};

		int result[10];

		int* it = shift_left_digits(first, first + 2, 1, result);
		
		ASSERT_EQ(3, it - result);

		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
		ASSERT_EQ(*(answer+2), *(result+2));
	}



// ------------------
// shift_right_digits
// ------------------

	TEST(IntegerFixture, shift_right_digits1){
		int first[] = {1, 2, 3, 4};
		int answer[] = {4};

		int result[10];

		int* it = shift_right_digits(first, first + 4, 3, result);
		ASSERT_EQ(1, it - result);
		ASSERT_EQ(*answer, *result);
	}

	TEST(IntegerFixture, shift_right_digits2){
		int first[] = {1, 2, 3, 4};
		int answer[] = {0};

		int result[10];

		int* it = shift_right_digits(first, first + 3, 3, result);
		ASSERT_EQ(1, it - result);
		ASSERT_EQ(*answer, *result);
	}

	TEST(IntegerFixture, shift_right_digits3){
		int first[] = {1, 2, 3, 4};
		int answer[] = {1, 2, 3, 4};

		int result[10];

		int* it = shift_right_digits(first, first + 3, 0, result);
		ASSERT_EQ(3, it - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
		ASSERT_EQ(*(answer+2), *(result+2));
	}



// -----------
// plus_digits
// -----------
	TEST(IntegerFixture, plus_digits1){
		int first[] = {1, 0};
		int second[] = {1, 2};

		int answer[] = {2, 2};

		int result[10];

		int* p = plus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(2, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
	}

	TEST(IntegerFixture, plus_digits2){
		int first[] = {2, 2};
		int second[] = {1, 2};

		int answer[] = {3, 4};

		int result[10];

		int* p = plus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(2, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
	}


	TEST(IntegerFixture, plus_digits3){
		int first[] = {6};
		int second[] = {1, 2};

		int answer[] = {1, 8};

		int result[10];

		int* p = plus_digits(first, first + 1, second, second + 2, result);

		ASSERT_EQ(2, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
	}

	TEST(IntegerFixture, plus_digits4){
		int first[] = {5, 1, 9};
		int second[] = {1, 5, 2};

		int answer[] = {6, 7, 1};

		int result[10];

		int* p = plus_digits(first, first+ + 3, second, second + 3, result);

		ASSERT_EQ(3, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
		ASSERT_EQ(*(answer+2), *(result+2));
	}


// ------------
// minus_digits
// ------------
	TEST(IntegerFixture, minus_digits1){
		int first[] = {1, 4};
		int second[] = {1, 2};

		int answer[] = {2};

		int result[10];

		int* p = minus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(1, p - result);
		ASSERT_EQ(*(answer), *(result));
	}

	TEST(IntegerFixture, minus_digits2){
		int first[] = {2, 2};
		int second[] = {1, 2};

		int answer[] = {1, 0};

		int result[10];

		int* p = minus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(2, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
	}


	TEST(IntegerFixture, minus_digits3){
		int first[] = {5, 6, 7};
		int second[] = {9, 9};

		int answer[] = {4, 6, 8};

		int result[10];

		int* p = minus_digits(first, first + 3, second, second + 2, result);

		ASSERT_EQ(3, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
		ASSERT_EQ(*(answer+2), *(result+2));
	}

	TEST(IntegerFixture, minus_digits4){
		int first[] = {5, 1, 9};
		int second[] = {1, 5, 2};

		int answer[] = {3, 6, 7};

		int result[10];

		int* p = minus_digits(first, first+ + 3, second, second + 3, result);

		ASSERT_EQ(3, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
		ASSERT_EQ(*(answer+2), *(result+2));
	}


	TEST(IntegerFixture, minus_digits5){
		int first[] = {1, 0, 0};
		int second[] = {5, 0};

		int answer[] = {5, 0};

		int result[10];

		int* p = minus_digits(first, first + 3, second, second + 2, result);

		ASSERT_EQ(2, p - result);
		ASSERT_EQ(*(answer), *(result));
		ASSERT_EQ(*(answer+1), *(result+1));
	}

// ---------------
// multiply_digits
// ---------------
	TEST(IntegerFixture, multiply_digits1){
		int first[] = {1, 2};
		int second[] = {3};

		int answer[] {3 ,6};

		int result[10];

		multiplies_digits(first, first + 2, second, second + 1, result);

		//ASSERT_EQ(2, p - result);
		ASSERT_EQ(*answer, *result);
		ASSERT_EQ(*(result+1), *(answer+1));
	}

	TEST(IntegerFixture, multiply_digits2){
		int first[] = {1, 1};
		int second[] = {1, 1};

		int answer[] {1, 2, 1};

		int result[10];

		multiplies_digits(first, first + 2, second, second + 2, result);

		//ASSERT_EQ(3, p - result);
		ASSERT_EQ(*answer, *result);
		ASSERT_EQ(*(result+1), *(answer+1));
		ASSERT_EQ(*(result+2), *(answer+2));
	}


	TEST(IntegerFixture, multiply_digits3){
		int first[] = {9};
		int second[] = {2};

		int answer[] {8, 1};

		int result[10];

		multiplies_digits(first, first + 1, second, second + 1, result);

		//ASSERT_EQ(2, p - result);
		ASSERT_EQ(*answer, *result);
		ASSERT_EQ(*(result+1), *(answer+1));
	}


// --------------
// divides_digits
// --------------

//***********************************//
//**************INTEGER**************//
//***********************************//



// -------------------
// integer constructor
// -------------------
	TEST(IntegerFixture, constructor1){
		Integer<int> value(55);
		Integer<int> real = 55;

		ASSERT_EQ(value, real);
	}

	TEST(IntegerFixture, constructor2){
		Integer<int> value("0");

		ASSERT_EQ(value, 0);
	}


	TEST(IntegerFixture, constructor3){
		Integer<int> value("-1");

		ASSERT_EQ(value, -1);
	}

	TEST(IntegerFixture, constructor4){
		Integer<int> value(944);

		ASSERT_EQ(value, 944);
	}

	TEST(IntegerFixture, constructor5){
		Integer<int> value(123);

		ASSERT_EQ(value, 123);
	}

	TEST(IntegerFixture, constructor6){
		Integer<int> value(-6);

		ASSERT_EQ(value, -6);
	}


// ------
// negate
// ------
	TEST(IntegerFixture, negate1){
		Integer<int> temp = 100;
		Integer<int> neg = -temp;

		ASSERT_EQ(-100, neg);
	}

	TEST(IntegerFixture, negate2){
		Integer<int> temp = -100;
		Integer<int> neg = -temp;

		ASSERT_EQ(100, neg);
	}

	TEST(IntegerFixture, negate3){
		Integer<int> temp = 5;
		Integer<int> neg = -temp;

		ASSERT_EQ(-5, neg);
	}

	TEST(IntegerFixture, negate4){
		Integer<int> temp = 994682;
		Integer<int> neg = -temp;

		ASSERT_EQ(-994682, neg);
	}

// -------------
// pre-increment
// -------------
	TEST(IntegerFixture, preincre1){
		Integer<int> temp = 1;
		++temp;

		ASSERT_EQ(2, temp);
	}

	TEST(IntegerFixture, preincre2){
		Integer<int> temp = 5;
		++temp;

		ASSERT_EQ(6, temp);
	}

	TEST(IntegerFixture, preincre3){
		Integer<int> temp = 0;
		++temp;

		ASSERT_EQ(1, temp);
	}

// --------------
// post-increment
// --------------
	TEST(IntegerFixture, postincre1){
		Integer<int> temp = 1;
		Integer<int> result = temp++;

		ASSERT_EQ(1, result);
	}

	TEST(IntegerFixture, postincre2){
		Integer<int> temp = 100;
		Integer<int> result = temp++;

		ASSERT_EQ(100, result);
	}

	TEST(IntegerFixture, postincre3){
		Integer<int> temp = 0;
		Integer<int> result = temp++;

		ASSERT_EQ(0, result);
	}

// -------------
// pre-decrement
// -------------
	/*
	TEST(IntegerFixture, predecre1){
		Integer<int> temp = 1;
		--temp;

		ASSERT_EQ(0, temp);
	}

	TEST(IntegerFixture, predecre2){
		Integer<int> temp = 100;
		--temp;

		ASSERT_EQ(99, temp);
	}

	TEST(IntegerFixture, predecre3){
		Integer<int> temp = 10;
		--temp;

		ASSERT_EQ(9, temp);
	}


// --------------
// post-decrement
// --------------
	TEST(IntegerFixture, postdecre1){
		Integer<int> temp = 1;
		Integer<int> result = temp--;

		ASSERT_EQ(1, result);
	}

	TEST(IntegerFixture, postdecre2){
		Integer<int> temp = 100;
		Integer<int> result = temp--;

		ASSERT_EQ(100, result);
	}

	TEST(IntegerFixture, postdecre3){
		Integer<int> temp = 0;
		Integer<int> result = temp--;

		ASSERT_EQ(0, result);
	}
	*/
// ------
// equals
// ------
	TEST(IntegerFixture, equals1){
		Integer<int> first = 55;
		Integer<int> second = 55;

		ASSERT_EQ(first, second);
	}

	TEST(IntegerFixture, equals2){
		Integer<int> first = -44;
		Integer<int> second = -44;

		ASSERT_EQ(first, second);
	}

	TEST(IntegerFixture, equals3){
		Integer<int> first = 1;
		Integer<int> second = 1;

		ASSERT_EQ(first, second);
	}


// --
// +=
// --
	TEST(IntegerFixture, plusequals1){
		Integer<int> first = 1;
		Integer<int> second = 2;

		first += second;

		Integer<int> result = 3;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, plusequals2){
		Integer<int> first = 50;
		Integer<int> second = 10;

		first += second;

		Integer<int> result = 60;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, plusequals3){
		Integer<int> first = 5;
		Integer<int> second = 3;

		first += second;

		Integer<int> result = 8;

		ASSERT_EQ(first, 8);
	}
	

/*
// --
// -=
// --
	TEST(IntegerFixture, minusequals1){
		Integer<int> first = 7;
		Integer<int> second = 5;

		first -= second;

		Integer<int> result = 5;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, minusequals2){
		Integer<int> first = 3;
		Integer<int> second = 2;

		first -= second;

		Integer<int> result = 1;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, minusequals3){
		Integer<int> first = 200;
		Integer<int> second = 100;

		first -= second;

		Integer<int> result = 100;

		ASSERT_EQ(first, result);
	}

	
/*
// -
// <
// -
	TEST(IntegerFixture, less1){
		Integer<int> first = 50;
		Integer<int> second = 50;

		ASSERT_EQ(false, (first < second));
	}

	TEST(IntegerFixture, less2){
		Integer<int> first = 1;
		Integer<int> second = 2;

		ASSERT_EQ(true, (first < second));
	}

	TEST(IntegerFixture, less3){
		Integer<int> first = 2;
		Integer<int> second = 1;

		ASSERT_EQ(false, (first < second));
	}



// -
// >
// - 
	TEST(IntegerFixture, greater1){
		Integer<int> first = 50;
		Integer<int> second = 50;

		ASSERT_FALSE(first > second);
	}

	TEST(IntegerFixture, greater2){
		Integer<int> first = 5;
		Integer<int> second = 10;

		ASSERT_FALSE(first > second);
	}

	TEST(IntegerFixture, greater3){
		Integer<int> first = 2;
		Integer<int> second = 1;

		ASSERT_TRUE(first > second);
	}

*/

// --
// *=
// --
	TEST(IntegerFixture, mult1){
		Integer<int> first = 4;
		Integer<int> second = 3;

		first *= second;

		Integer<int> result = 12;

		ASSERT_EQ(first, 12);
	}

	TEST(IntegerFixture, mult2){
		Integer<int> first = 1;
		Integer<int> second = 1;

		first *= second;

		Integer<int> result = 1;

		ASSERT_EQ(first, 1);
	}

	TEST(IntegerFixture, mult3){
		Integer<int> first = 3;
		Integer<int> second = 3;

		first *= second;

		Integer<int> result = 45;

		ASSERT_EQ(first, 9);
	}


/*

// --
// /=
// --
	TEST(IntegerFixture, div1){
		Integer<int> first = 4;
		Integer<int> second = 2;

		first /= second;

		Integer<int> result = 2;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, div2){
		Integer<int> first = 45;
		Integer<int> second = 15;

		first /= second;

		Integer<int> result = 3;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, div3){
		Integer<int> first = 1;
		Integer<int> second = 1;

		first /= second;

		Integer<int> result = 1;

		ASSERT_EQ(first, result);
	}
	
*/
/*
// --
// %=
// --
	TEST(IntegerFixture, mod1){
                Integer<int> first = 0;
                Integer<int> second = 2;

                first %= second;

                ASSERT_EQ(first, 0);
        }

        TEST(IntegerFixture, mod2){
                Integer<int> first = 45;
                Integer<int> second = 40;

                first %= second;

                ASSERT_EQ(first, 5);
        }

        TEST(IntegerFixture, mod3){
                Integer<int> first = 15;
                Integer<int> second = 4;

                first %= second;

                ASSERT_EQ(first, 3);
        }
       
*/
// ---
// <<=
// ---
	TEST(IntegerFixture, shift_left_equal1){
        Integer<int> first = 9;
        Integer<int> result = 9;

		first <<=0;

        ASSERT_EQ(first, result);
        }

	TEST(IntegerFixture, shift_left_equal2){
        Integer<int> first = 999;
        Integer<int> result = 999000;
                
        first <<=3;

        ASSERT_EQ(first, result);
        }
	
	TEST(IntegerFixture, shift_left_equal3){
        Integer<int> first = 9999;
        Integer<int> result = 9999000;
                
        first <<=3;

        ASSERT_EQ(first, result);
        }



// ---
// >>=
// ---
	TEST(IntegerFixture, shift_right_equal1) {
	    Integer<int> a = 12000;
	    Integer<int> c = 12;

   	    a >>= 3;

   	    ASSERT_EQ(a, c);
	}

	TEST(IntegerFixture, shift_right_equal2) {
	    Integer<int> a(5000);
	    Integer<int> c(5);

	    a >>= 3;

  	  ASSERT_EQ(a, c);
	}

	TEST(IntegerFixture, shift_right_equal3) {
	    Integer<int> a = 111;
	    Integer<int> c = 111;

	    a >>= 0;

	    ASSERT_EQ(a, c);
	}


// ---
// abs
// ---
	TEST(IntegerFixture, abs1){
		Integer<int> temp = 1;
		Integer<int>& result = temp.abs();

		ASSERT_EQ(result, 1);
	}

	TEST(IntegerFixture, abs2){
		Integer<int> temp = -1;
		Integer<int>& result = temp.abs();

		ASSERT_EQ(result, 1);
	}
	
	TEST(IntegerFixture, abs3){
		Integer<int> temp = 0;
		Integer<int>& result = temp.abs();

		ASSERT_EQ(result, 0);
	}


/*
// ---
// pow
// ---
	TEST(IntegerFixture, pow1){
		Integer<int> temp = 4;
		int  power = 2;

		Integer<int>& result = temp.pow(power);

		ASSERT_EQ(result, 16);
	}

	TEST(IntegerFixture, pow2){
		Integer<int> temp = 2;
		int  power = 2;

		Integer<int>& result = temp.pow(power);

		ASSERT_EQ(result, 4);
	}	

	TEST(IntegerFixture, pow3){
		Integer<int> temp = 3;
		int  power = 3;

		Integer<int>& result = temp.pow(power);

		ASSERT_EQ(result, 27);
	}	


*/