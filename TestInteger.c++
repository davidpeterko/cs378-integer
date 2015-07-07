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

		int output[10];

		int* it = shift_left_digits(first, first + 3, 3, output);
		ASSERT_EQ(6, it - output);
		//ASSERT_EQ(output, second);
	}

	TEST(IntegerFixture, shift_left_digits2){
		int first[] = {1, 2, 3};

		int output[10];

		int* it = shift_left_digits(first, first + 3, 2, output);
		ASSERT_EQ(5, it - output);
		//ASSERT_EQ(output, second);
	}

	TEST(IntegerFixture, shift_left_digits3){
		int first[] = {1, 2, 3};

		int output[10];

		int* it = shift_left_digits(first, first + 3, 1, output);
		ASSERT_EQ(4, it - output);
		//ASSERT_EQ(output, second);
	}



// ------------------
// shift_right_digits
// ------------------

	TEST(IntegerFixture, shift_right_digits1){
		int first[] = {1, 2, 3, 4};

		int output[10];

		int* it = shift_right_digits(first, first + 4, 3, output);
		ASSERT_EQ(1, it - output);
		//ASSERT_EQ(output, second);
	}

	TEST(IntegerFixture, shift_right_digits2){
		int first[] = {1, 2, 3, 4};

		int output[10];

		int* it = shift_right_digits(first, first + 3, 3, output);
		ASSERT_EQ(1, it - output);
		//ASSERT_EQ(output, second);
	}

	TEST(IntegerFixture, shift_right_digits3){
		int first[] = {1, 2, 3, 4};

		int output[10];

		int* it = shift_right_digits(first, first + 1, 0, output);
		ASSERT_EQ(1, it - output);
		//ASSERT_EQ(output, second);
	}



// -----------
// plus_digits
// -----------
	TEST(IntegerFixture, plus_digits1){
		int first[] = {1, 0};
		int second[] = {1, 2};

		int answer[] = {2, 2};

		int result[10];

		plus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(*result, *answer);
	}

	TEST(IntegerFixture, plus_digits2){
		int first[] = {2, 2};
		int second[] = {1, 2};

		int answer[] = {3, 4};

		int result[10];

		plus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(*result, *answer);
	}


	TEST(IntegerFixture, plus_digits3){
		int first[] = {6};
		int second[] = {1, 2};

		int answer[] = {1, 8};

		int result[10];

		plus_digits(first, first + 1, second, second + 2, result);

		ASSERT_EQ(*result, *answer);
	}

	TEST(IntegerFixture, plus_digits4){
		int first[] = {5, 1, 9};
		int second[] = {1, 5, 2};

		int answer[] = {6, 7, 1};

		int result[10];

		plus_digits(first, first+ + 3, second, second + 3, result);

		ASSERT_EQ(*result, *answer);
	}


// ------------
// minus_digits
// ------------
	TEST(IntegerFixture, minus_digits1){
		int first[] = {1, 4};
		int second[] = {1, 2};

		int answer[] = {2};

		int result[10];

		minus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(*result, *answer);
	}

	TEST(IntegerFixture, minus_digits2){
		int first[] = {2, 2};
		int second[] = {1, 2};

		int answer[] = {1, 0};

		int result[10];

		minus_digits(first, first + 2, second, second + 2, result);

		ASSERT_EQ(*result, *answer);
	}


	TEST(IntegerFixture, minus_digits3){
		int first[] = {5, 6, 7};
		int second[] = {9, 9};

		int answer[] = {4, 6, 8};

		int result[10];

		minus_digits(first, first + 3, second, second + 2, result);

		ASSERT_EQ(*result, *answer);
	}

	TEST(IntegerFixture, minus_digits4){
		int first[] = {5, 1, 9};
		int second[] = {1, 5, 2};

		int answer[] = {6, 7, 1};

		int result[10];

		minus_digits(first, first+ + 3, second, second + 3, result);

		ASSERT_EQ(*result, *answer);
	}

// ---------------
// multiply_digits
// ---------------

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
		Integer<int> real(0);

		ASSERT_EQ(value, real);
	}


	TEST(IntegerFixture, constructor3){
		Integer<int> value("-1");

		ASSERT_EQ(value, -1);
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
		Integer<int> temp = 1100;
		Integer<int> neg = temp;

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
		Integer<int> result = ++temp;

		ASSERT_EQ(2, result);
	}

	TEST(IntegerFixture, preincre2){
		Integer<int> temp = 100;
		Integer<int> result = ++temp;

		ASSERT_EQ(101, result);
	}

	TEST(IntegerFixture, preincre3){
		Integer<int> temp = 0;
		Integer<int> result = ++temp;

		ASSERT_EQ(1, result);
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
	TEST(IntegerFixture, predecre1){
		Integer<int> temp = 1;
		Integer<int> result = --temp;

		ASSERT_EQ(0, result);
	}

	TEST(IntegerFixture, predecre2){
		Integer<int> temp = 100;
		Integer<int> result = --temp;

		ASSERT_EQ(99, result);
	}

	TEST(IntegerFixture, predecre3){
		Integer<int> temp = 10;
		Integer<int> result = --temp;

		ASSERT_EQ(9, result);
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

// ------
// equals
// ------
	TEST(IntegerFixture, equals1){
		const Integer<int> first = 55;
		const Integer<int> second = 55;

		ASSERT_EQ(first, second);
	}

	TEST(IntegerFixture, equals2){
		const Integer<int> first = -44;
		const Integer<int> second = -44;

		ASSERT_EQ(first, second);
	}

	TEST(IntegerFixture, equals3){
		const Integer<int> first = 1;
		const Integer<int> second = 1;

		ASSERT_EQ(first, second);
	}

// --
// +=
// --
	TEST(IntegerFixture, plusequals1){
		Integer<int> first = 1;
		Integer<int> second = 2;

		first += second;

		const Integer<int> result = 3;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, plusequals2){
		Integer<int> first = 10;
		Integer<int> second = 5;

		first += second;

		const Integer<int> result = 15;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, plusequals3){
		Integer<int> first = 50;
		Integer<int> second = 100;

		first += second;

		const Integer<int> result = 150;

		ASSERT_EQ(first, result);
	}

// --
// -=
// --
	TEST(IntegerFixture, minusequals1){
		Integer<int> first = 10;
		Integer<int> second = 5;

		first -= second;

		const Integer<int> result = 5;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, minusequals2){
		Integer<int> first = 3;
		Integer<int> second = 2;

		first -= second;

		const Integer<int> result = 1;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, minusequals3){
		Integer<int> first = 50;
		Integer<int> second = 100;

		first -= second;

		const Integer<int> result = -50;

		ASSERT_EQ(first, result);
	}

// -
// <
// -
	TEST(IntegerFixture, less1){
		Integer<int> first = 50;
		Integer<int> second = 50;

		ASSERT_FALSE(first < second);
	}

	TEST(IntegerFixture, less2){
		Integer<int> first = 1;
		Integer<int> second = 2;

		ASSERT_TRUE(first < second);
	}

	TEST(IntegerFixture, less3){
		Integer<int> first = 2;
		Integer<int> second = 1;

		ASSERT_FALSE(first < second);
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

// --
// *=
// --
	TEST(IntegerFixture, mult1){
		Integer<int> first = 4;
		Integer<int> second = 3;

		first *= second;

		Integer<int> result = 12;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, mult2){
		Integer<int> first = 1;
		Integer<int> second = 1;

		first *= second;

		Integer<int> result = 1;

		ASSERT_EQ(first, result);
	}

	TEST(IntegerFixture, mult3){
		Integer<int> first = 15;
		Integer<int> second = 3;

		first *= second;

		Integer<int> result = 45;

		ASSERT_EQ(first, result);
	}

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
		Integer<int> first = 15;
		Integer<int> second = 3;

		first /= second;

		Integer<int> result = 5;

		ASSERT_EQ(first, result);
	}

// --
// %=
// --
	TEST(IntegerFixture, mod1){
                Integer<int> first = 4;
                Integer<int> second = 2;

                first %= second;

                Integer<int> result = 0;

                ASSERT_EQ(first, result);
        }

        TEST(IntegerFixture, mod2){
                Integer<int> first = 45;
                Integer<int> second = 40;

                first %= second;

                Integer<int> result = 5;

                ASSERT_EQ(first, result);
        }

        TEST(IntegerFixture, mod3){
                Integer<int> first = 15;
                Integer<int> second = 4;

                first %= second;

                Integer<int> result = 3;

                ASSERT_EQ(first, result);
        }

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
	    Integer<int> a("999999999999");
	    Integer<int> c("9");

	    a >>= 11;

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


