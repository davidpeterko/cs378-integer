// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector

// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
FI shift_left_digits (II b, II e, int n, FI x) {
                                                            //n is the number of times you shift?
    assert(n >= 0);                                         //n must be greater than or equal to 0, cant shift by negative value

    //copy over

    x = copy(b, e, x);

    while( n > 0){                                          //fill front run with 0s
        *x = 0;                                             //then pick up where x left off 
        ++x;                                                //in the next while loop below
        --n;
    }

    while(b != e){                                          //while the beginning != end        
        *x = *b;                                            //the place at x in FI is now the value at II b
        ++x;                                                //move the FI and II forward until its finished transferred
        ++b;
    }

    return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
FI shift_right_digits (II b, II e, int n, FI x) {

    assert( n >= 0);

    //copy over
    //x = copy(b, e, x);

    while(n > 0){
        ++b;                                                //increment b to the place to the rightside
        --n;                                                //so we can fill with 0 and then copy over    
    }

    while( b != e){
        *x = *b;
        ++b;
        ++x;
    }

    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {


    //check the signs!







    return x;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {

    //make copies of the iterators?
    //use b1 e1 b2 e2 to iteratur thru the containers
    //x to output with forward iterator


    /*
If both signs are positive, the answer will be positive.
Example: 14 - (-6) = 14 + 6 = 20
If both signs are negative, the answer will be negative.
Example: -14 - (+6) = -14 - 6 = -20
If the signs are different subtract the smaller absolute value from the larger absolute value. The sign will be the sign of the integer that produced the larger absolute value. 
Example: 14 - (+6) = 14 - 6 = 8 
Example: -14 - (-6) = -14 + 6 = -8


    */
    return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    return x;}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    return x;}


/* -------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------*/


// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * lhs = left hand side, rhs = right handside
     * this operator == checks if the 2 containers are equal size and values
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {

        int rsize = rhs._x.size();
        int lsize = lhs._x.size();

        assert(rsize != 0);
        assert(lsize != 0);

        //check container sizes
        if(rsize != lsize){
            //lhs size not equal to rhs size
            return false;
        }

        //check for negative value
        if(lhs.sign != rhs.sign){
            //signs not equal
            return false;
        }

        //check values

        //iterators
        typename C::const_iterator it_lhs = lhs._x.begin();
        typename C::const_iterator it_rhs = rhs._x.begin();

        while(it_lhs != lhs._x.end() && it_rhs != rhs._x.end()){

            if(*it_rhs != *it_lhs){
                return false;
            }

            ++it_rhs;
            ++it_lhs;
        }

        //check if operators equal to end?

        return false;}

    // -----------
    // operator !=
    // -----------

    /**
     * check to see if the values are no equal
     * uses the == operator function form above implementation
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * < operator
     * returns true if all elements lhs < rhs are greater, false otherwise
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {

        bool final_result = false;

        int rsize = rhs._x.size();
        int lsize = lhs._x.size();

        assert(rsize != 0);
        assert(lsize != 0);

        bool rsign = rhs.sign;
        bool lsign = lhs.sign;

        if(rsign == true && lsign == false){
            return false;
        }

        if(rsign == false && lsign == true){
            return true;
        }

        if(rsign == true && lsign == true){

        }

        if(rsign == false && lsign == false){

            if(rsize > lsize){                      //rhs size > lhs size
                return true;
            }
            else if(lsize > rsize){                 //rhs size < lhs size
                return false;
            }
        }

        if(rsign == true && lsign == true){

            if(rsize > lsize){                      //as per negative
                return false;                       
            }
            if(lsize > rsize){
                return true;
            }
        }

        //iterators
        typename C::const_iterator it_lhs = lhs._x.begin();
        typename C::const_iterator it_rhs = rhs._x.begin();

        //iterate through, cmp each value
        while(it_lhs != lhs._x.end() && it_rhs != rhs._x.end()){

            if(*it_rhs > *it_lhs){
                final_result = true;
            }
            else if(*it_lhs > *it_rhs){
                return false;
            }

        }

        return final_result;}

    // -----------
    // operator <=
    // -----------

    /**
     * checks if rhs is greater than or equal to lhs
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * checks if rhs is less than lhs
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * checks if rhs is less than or equal to lhs
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * returns lhs + rhs
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * returns lhs - rhs
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * returns lhs * rhs, multiply
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * return division of lhs / rhs
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
            
        if(rhs == 0){
            throw std::invalid_argument("RHS value cannot be 0.");
        }

        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * returns modulo lhs % rhs
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
            
        if(rhs <= 0){
            throw std::invalid_argument("RHS value cannot be <= 0.");
        }

        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * left shift lhs, by rhs 
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        
        if(rhs < 0){
            throw std::invalid_argument("RHS value cannot be < 0.");
        }

        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * right shift lhs, by rhs
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        
        if(rhs < 0){
            throw std::invalid_argument("RHS value cannot be < 0");
        }

        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * output stream, << denotes a rhs value going to the lhs output holder
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {

        int rsize = rhs._x.size();

        //output the container of rhs
        for(int i = 0; i < rsize; ++i){
            lhs << rhs._x[i];
        }

        return lhs;}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * takes the abs value of the x value passed
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * takes a vlaue x, and raises it to the value e
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {

        if(x == 0 && e == 0){
            throw std::invalid_argument("Both values cannot be 0.");
        }

        if(e < 0){
            throw std::invalid_argument("Exponent value cannot be < 0.");
        }

        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container
        bool sign;  //if this is true, then the value is negative
        int size;    //size of container


    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            // <your code>
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * creates a Integer object initiated with value 
         */
        Integer (int value) {
            // <your code>
            assert(valid());}

        /**
         * checks to see if value is anything other than and int
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            // <your code>
            if (!valid())
                throw std::invalid_argument("Integer::Integer()");}

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * subtraction or negate?
         */
        Integer operator - () const {

            Integer value = *this;
            bool value_sign = value.sign;

            if(value_sign){
                value.sign = false;
            }
            else if(!value_sign){
                value.sign = true;
            }

            //what does this do exactly?
            // x = 5
            //-x = -5
            // x = -1
            // -x = 1

            return value;}

        // -----------
        // operator ++
        // -----------

        /**
         * pre-increment of the object that is passed by the function
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * post-increment of the object that is passed by the function
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * pre-decrement of the object that is passed by the function
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * post-decrement of the object that is passed by the function
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * adds the rhs value to this
         */
        Integer& operator += (const Integer& rhs) {

            *this = *this + rhs._x;

            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * subtract rhs from the value
         */
        Integer& operator -= (const Integer& rhs) {

            *this = *this - rhs._x;

            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * multiply the value by the ths
         */
        Integer& operator *= (const Integer& rhs) {

            *this = *this * rhs._x;

            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {

            if(rhs == 0){
                throw std::invalid_argument("Cannot divide by zero.");
            }

            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * takes the value this and modulo's and set its equal to thsi
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            
            if(rhs <= 0){
                throw std::invalid_argument("RHS cannot be <= 0.");
            }

            

            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * shifts the value this to the left n times
         */
        Integer& operator <<= (int n) {

            for(int i = 0; i < n; ++i){
                *this = *this << 1;
            }

            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         *  shifts the value this to the right n times
         */
        Integer& operator >>= (int n) {

            for(int i = 0; i < n; ++i){
                *this = *this >> 1;
            }

            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * Takes the absolute value of this
         */
        Integer& abs () {

            //swap signs
            if(this.sign){
                this.sign = false;
            }

            return *this;
        }

        // ---
        // pow
        // ---

        /**
         * power
         * this takes in a value e to be the power and takes the value to that power.
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {

            if(*this == 0 && e == 0){
                throw std::invalid_argument("Received 0 values.");
            }

            if(e < 0){
                throw std::invalid_argument("Received e < 0");
            }

            //the code should be more complex to handle bigger values of e

            return *this;}};

#endif // Integer_h