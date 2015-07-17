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

using namespace std;

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
    //x = copy(b, e, x);

    if(n == 0){                                             //no shifts, just return a copy of it
        copy(b, e, x);
        return x;
    }

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

    //shift wont matter if:
    if(distance(b, e) <= n){
        *x = 0;
        ++x;
        return x;
    }

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




    int carry = 0;
    while(b2 != e2 && b1 != e1){                        //b2 and e2 should be the smaller value

            int temp = *b2 + *b1 + carry;

            //set carry

            carry = temp / 10;

            *x = temp % 10;

        ++x;    
        ++b2;
        ++b1;
    }

    //so when we break out fo here is when we have nothing else left to add together and we just drop down teh values + caarry

    while(b1 != e1){

        int temp = *b1 + carry; 

        *x = temp % 10;

        carry = temp / 10;

        ++b1;
        ++x;
    }

    while(b2 != e2){

        int temp = *b2 + carry; 

        *x = temp % 10;

        carry = temp / 10;

        ++b2;
        ++x;
    }

    *x = carry;

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

    int borrow = 0;
    while(b2 != e2){

        int temp = *b1 - *b2 + borrow;

        if(temp < 0){
            borrow = -1;
            temp += 10;                     //this makes it positive
        }
        else{
            borrow = 0;
        }

        *x = temp;

        ++x;
        ++b2;
        ++b1;
    }

    //the lower size digits stops

    while(b1 != e1){

        *x = *b1 + borrow;
        borrow = 0;
        ++b1;
        ++x;
    }




    return x;
}
    

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
    
    int carry = 0;
    FI x_temp;

    while(b1 != e1){                  //LOOPS THROUGH THE FIRST VALUE

        x_temp = x;
        II2 b2_temp = b2;
        
        while(b2_temp != e2){               //loops throug the second value

            *x_temp = ((*b1 * *b2_temp) + carry + *x_temp);    //gets the 10s digit
            carry = *x_temp / 10;                                //gets the carry
            *x_temp %= 10;
            ++x_temp;
            ++b2_temp;
        }

        ++x;  
        ++b1;                              
     }
     *x_temp = carry;
  
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

       // assert(rsize != 0);
       // assert(lsize != 0);

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

        return true;}

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

        if(lhs == 0 && rhs == 0){
            return false;
        }

        if(lhs == rhs){
            return false;
        }

        //takes care of opposite signs
        if(rsign ^ lsign){
            return lsign;
        }

        
        //gets here if both signs are positive or negative

        //iterators
        typename C::const_iterator it_lhs = lhs._x.begin();
        typename C::const_iterator it_rhs = rhs._x.begin();

        if(lhs._x.size() != rhs._x.size())
            final_result = lhs._x.size() < rhs._x.size();
        else {

            //iterate through, cmp each value
            while(it_lhs != lhs._x.end()){

                if(*it_rhs > *it_lhs){
                    final_result = true;
                }
                else if(*it_lhs > *it_rhs){
                    final_result = false;
                }
                ++it_lhs;
                ++it_rhs;
            }  
        }

        if(lsign && rsign)
            final_result = !final_result;

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

        if(rhs.sign == true){                               //outputs the negative if negative
            lhs << "-"; 
        }

        // //output the container of rhs
        // for(int i = rsize-1 ; i >= 0; --i){
        //     lhs << rhs._x[i];
        // }

        auto b = rhs._x.end();
        while(b != rhs._x.begin()){
            --b;
            lhs << *b;
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
        bool positive;

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
            sets sign, and pushes it onto container
         */
        Integer (int value) {

            size = 0;

            if(value > 0){
                sign = false;
            }
            else if(value < 0){
                sign = true;
                value = -value;                                    
            }

            if(value == 0){
                sign = false;
                _x.push_back(0);
                ++size;
            }
      
            while(value > 0){  
                int sig_digit = value % 10;
                _x.push_back(sig_digit);
                ++size;

                value = value / 10;
            }

            _x.resize(size);
            assert(valid());}

        /**
         * checks to see if value is anything other than and int
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            //takes in a string, then use that value

            //if "-555"
            string::const_iterator begin = value.begin();
            string::const_iterator end = value.end(); 

            if(*begin == '-'){
                sign = true;
                ++begin;
            }
            else{
                sign = false;
            }


            while(end != begin){
                --end;
                char c = *end - '0';
                
                if(c > 9 || c < 0)
                    throw std::invalid_argument("Not a valid number.");

                _x.push_back(*end - '0');
            }

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

            //sign not equal + - and - +

            //should we resize


            Integer temp1 = *this;
            temp1.abs();
            Integer temp2 = rhs;
            temp2.abs();

            //same sign
            if(this->sign == rhs.sign){

                this->_x.resize(this->_x.size() + 1);

                plus_digits(temp1._x.begin(), temp1._x.end(), rhs._x.begin(), rhs._x.end(), this->_x.begin());

                //keep the sign
            }
            else{

                this->_x.resize(this->_x.size() + 1);

                if(temp1 > temp2){

                    minus_digits(temp1._x.begin(), temp1._x.end(), temp2._x.begin(), temp2._x.end(), this->_x.begin());

                    //keep sign
                }
                else if(temp1 < temp2){

                    minus_digits(temp2._x.begin(), temp2._x.end(), temp1._x.begin(), temp1._x.end(), this->_x.begin());

                    sign = !sign;
                }

                else if(temp1 == temp2){
                    //same value, opposite sign = 0

                    *this = 0;
                }

            }

            typename C::iterator it = --_x.end();                   //make an iterator pointing to the end fo the vector
                while(*it == 0) {                           //it iterates backwards from end <- (since our n# is backward)
                    if(it == _x.begin()) break;
                it = _x.erase(it);                      //erases taht location if 0, then stops when it fits the front fo teh result
                --it;
            }




            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * subtract rhs from the value
         */
        Integer& operator -= (const Integer& rhs) {
 
            Integer temp1 = *this;
            temp1.abs();
            Integer temp2 = rhs;
            temp2.abs();

            this->_x.resize(this->_x.size() + 1);

            if(this->sign ^ rhs.sign){                              //opposite sign

                plus_digits(temp1._x.begin(), temp1._x.end(), rhs._x.begin(), rhs._x.end(), this->_x.begin());

            }

            //both equal sign
            else{

                if(temp2 > temp1){

                    minus_digits(temp2._x.begin(), temp2._x.end(), temp1._x.begin(), temp2._x.end(), this->_x.begin());
                    sign = !sign;
                }
                else{
                    minus_digits(temp1._x.begin(), temp1._x.end(), temp2._x.begin(), temp2._x.end(), this->_x.begin());
                }
            }


            typename C::iterator it = --_x.end();                   //make an iterator pointing to the end fo the vector
            while(*it == 0) {                           //it iterates backwards from end <- (since our n# is backward)
                if(it == _x.begin()) break;
                it = _x.erase(it);                      //erases taht location if 0, then stops when it fits the front fo teh result
            --it;
            }

            return *this;
        }

        // -----------
        // operator *=
        // -----------

        /**
         * multiply the value by the ths
         */
        Integer& operator *= (const Integer& rhs) {

            Integer x(*this);                       //copy
            _x.resize(rhs._x.size() + this->_x.size());
            std::fill(_x.begin(), _x.end(), 0);
            multiplies_digits(x._x.begin(),x._x.end(), rhs._x.begin(), rhs._x.end(), this->_x.begin());

            this->sign ^= rhs.sign;

            typename C::iterator it = --_x.end();                   //make an iterator pointing to the end fo the vector
            while(*it == 0) {                           //it iterates backwards from end <- (since our n# is backward)
                if(it == _x.begin()) break;
                it = _x.erase(it);                      //erases taht location if 0, then stops when it fits the front fo teh result
                --it;
            }
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {

            Integer this_copy = *this;
            this_copy.abs();
            Integer rhs_copy = rhs;
            rhs_copy.abs();

            bool new_sign = this->sign;

            *this = 0;

            while(this_copy >= rhs_copy){
                this_copy -= rhs_copy;
                ++*this;
            }

            sign = new_sign ^ rhs.sign;

            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * takes the value this and modulo's and set its equal to thsi
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            
            Integer this_copy = *this;
            this_copy.abs();
            Integer rhs_copy = rhs;
            rhs_copy.abs();

            bool new_sign = this->sign;

            while(this_copy >= rhs_copy){
                this_copy -= rhs_copy;
            }

            *this = this_copy;

            sign = new_sign ^ rhs.sign;

            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * shifts the value this to the left n times
         */
        Integer& operator <<= (int n) {
            //cout << "This is size: " << size << end;;

            if(n < 0){
                throw std::invalid_argument("Shift value cannot be < 0.");
            }

            if(n == 0){
                return *this;
            }

            if(*this == 0){
                return *this;
            }

            //new contianer
            C newresult(this->size + n + 1);

            typename C::iterator it;

            it = shift_left_digits(this->_x.begin(), this->_x.end(), n, newresult.begin());

            int new_size = it - newresult.begin();

            //set size
            this->size = new_size;
            this->_x = newresult;
            this->_x.resize(new_size);

            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         *  shifts the value this to the right n times
         */
        Integer& operator >>= (int n) {
            //cout << "This is size: " << size << end;;

            if(n < 0){
                throw std::invalid_argument("Shift value cannot be < 0.");
            }

            if(n == 0){
                return *this;
            }

            if(*this == 0){
                return *this;
            }

            //new contianer
            C newresult(this->size + n + 1);

            typename C::iterator it;

            it = shift_right_digits(this->_x.begin(), this->_x.end(), n, newresult.begin());

            int new_size = it - newresult.begin();

            //set size
            this->size = new_size;
            this->_x = newresult;
            this->_x.resize(new_size);            

            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * Takes the absolute value of this
         */
        Integer& abs () {
            sign = false;

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


            Integer result(*this);
            int exp_counter = 2;

            if(e == 0){
                *this = 1;
                return *this;
            }

            if(e == 1){
                return *this;
            }

            while( exp_counter <= e){
                *this *= result;
                ++exp_counter;
            }
            
            return *this;}};

#endif // Integer_h
