// ------------------
// cs378-pfd/PFD.c++
// Copyright (C) 2015
// David Peter Ko
// Josh Gutierrez
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
		const int first[] = {1, 2, 3, };
		const int second[] = {1, 2, 3, 0, 0, 0};

		int output[10];

		const int* it = shift_left_digits(first, first + 3, 3, output);
		ASSERT_EQ(4, it - output);
		ASSERT_EQ(output, second);
	}


// ------------------
// shift_right_digits
// ------------------

	TEST(IntegerFixture, shift_right_digits1){
		const int first[] = {1, 2, 3, 4};
		const int second[] = {1};

		int output[6];

		const int* it = shift_right_digits(first, first + 4, 3, output);
		ASSERT_EQ(1, it - output);
		ASSERT_EQ(output, second);
	}

// -----------
// plus_digits
// -----------

// ------------
// minus_digits
// ------------

// --------------
// divides_digits
// --------------

// -----------
// plus_digits
// -----------

//***********************************//
//**************INTEGER**************//
//***********************************//


// -------------------
// integer constructor
// -------------------
	TEST(IntegerFixture, constructor1){
		const Integer<int> value("-1");
		Integer<int> real = -1;

		ASSERT_EQ(value, real);
	}

	TEST(IntegerFixture, constructor2){
		const Integer<int> value("55");
		Integer<int> real = 55;

		ASSERT_EQ(value, real);
	}

	TEST(IntegerFixture, constructor3){
		const Integer<int> value("0");
		Integer<int> real = 0;

		ASSERT_EQ(value, real);
	}

	TEST(IntegerFixture, constructor4){
		try{
			const Integer<int> value("dddd");
			ASSERT_TRUE(false);
		}
		catch(std::invalid_argument& e){
			std::cout << e.what() << "bad value" << std::endl;
		}
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

		first = second;

		Integer<int> result = 5;

		ASSERT_EQ(first, result);
	}

// --
// %=
// --
	TEST(IntegerFixture, mad1){
                Integer<int> first = 4;
                Integer<int> second = 2;

                first /= second;

                Integer<int> result = 0;

                ASSERT_EQ(first, result);
        }

        TEST(IntegerFixture, mad2){
                Integer<int> first = 45;
                Integer<int> second = 40;

                first /= second;

                Integer<int> result = 5;

                ASSERT_EQ(first, result);
        }

        TEST(IntegerFixture, mod3){
                Integer<int> first = 15;
                Integer<int> second = 4;

                first = second;

                Integer<int> result = 3;

                ASSERT_EQ(first, result);
        }

// ---
// <<=
// ---

// ---
// >>=
// ---

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


