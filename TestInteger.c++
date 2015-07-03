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

#include "gtest/gtest.h"

#include "TestInteger.h"

using namespace std;

// -------
// TestInteger
// -------

/** structure
TEST(PFDFixture,matrix_fill_zero_1){
	ostringstream w;
	vector<vector<int> > testmatrix(2, vector<int>(2)); 

	for(int i = 0; i < 2; ++i){

		for(int j = 0; j < 2; ++j){

			testmatrix[i][j] = 1;
		}
	}

	testmatrix = matrix_fill_zero(2, testmatrix);
	print_matrix(w, testmatrix);

	ASSERT_EQ("(0)(0)\n(0)(0)\n", w.str());
 **/

	// ------------
	// operator >>=
	// ------------




	//the return type to be int or Integer class defined

	// ---
	// abs
	// ---
	TEST(IntegerFixture, abs1){
		int temp = 1;

		int result = temp.abs();

		ASSERT_EQ(result, 1);
	}

	TEST(IntegerFixture, abs2){
		int temp = -1;

		int result = temp.abs();

		ASSERT_EQ(result, 1);
	}
	
	TEST(IntegerFixture, abs3){
		int temp = 0;

		int result = temp.abs();

		ASSERT_EQ(result, 0);
	}



	// ---
	// pow
	// ---
	TEST(IntegerFixture, pow1){
		int temp = 2;
		int  power = 2;

		int result = temp.pow(power);

		ASSERT_EQ(result, 4);
	}

		TEST(IntegerFixture, pow2){
		int temp = 5;
		int  power = 0;

		int result = temp.pow(power);

		ASSERT_EQ(result, 1);
	}

		TEST(IntegerFixture, pow3){
		int temp = 0;
		int  power = 10;

		int result = temp.pow(power);

		ASSERT_EQ(result, 0);
	}