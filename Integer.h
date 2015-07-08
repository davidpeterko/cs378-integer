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

/* our own function */
template <typename II>
void reverse_num (II b, II e) {
    while ((b != e) && (b != --e)) {
        std::swap(*b, *e);
        ++b;
    }
}

 
template <typename II, typename OI>
OI copy_reverse (II b, II e, OI x) {
    int size = e - b;
    assert(size >= 0);
    while (b != e) {
        --size;
        *(x + size) = *b;
        ++b;
    }
    return x;
}


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


    //check the signs!

    int lengthII1 = e1 - b1;    
    int lengthII2 = e2 - b2;
    if (lengthII1 < lengthII2)
        x =  plus_digits(b2, e2, b1, e1, x);
    else {
            int sum = 0; 
            int size = 0;
            while (lengthII2 != 0) {
                --lengthII1;
                --lengthII2;
                // Add the least significant numbers first.
                sum += *(b1 + lengthII1) + *(b2 + lengthII2);
                // Put the mod of the sum into the output.
                *x = sum % 10;
                // Have sum contain the remainder.
                sum /= 10;
                ++x;
                ++size;
                
            }
            // Add left over digits from the larger number.
            while (lengthII1 != 0) {
                --lengthII1;
                sum += *(b1 + lengthII1);
                *x = sum % 10;
               // cout << *x << endl;
                sum /= 10;
                ++x;
                ++size;
            }
            // Add left over remainder.
            if (sum != 0) {
                *x = sum;
               // cout << *x << endl;
                ++x;
                ++size;
            }
            // The digits are placed into x backwards; reverse list.
            reverse_num(x - size, x);
        }



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

    int lengthII1 = e1 - b1;
    int lengthII2 = e2 - b2;
    if (*b2 == 0 && lengthII2 == 1) {
    	while (b1 != e1) {
                *x = *b1;
                ++x;
                ++b1;
            }
        }
    else if (lengthII2 > lengthII1) 
    	x = minus_digits(b2, e2, b1, e1, x);
    else {
    	int temp1[20000];
    	int temp2[20000];
    	copy_reverse(b1, e1, temp1);
    	copy_reverse(b2, e2, temp2);
    	int i1 = 0;
    	int i2 = 0;
    	int diff = 0; 
    	int size = 0;
    	int num1 = 0;
    	int num2 = 0;
    	bool zero_remainder = false;

            while (i2 < lengthII2) {
                num1 += temp1[i1];
                num2 = temp2[i2];
                // If the sum of num1 is negative, roll over to 9
                if (num1 == -1) {
                    num1 = 9;
                    zero_remainder = true;
                }
                // If num1 is less than num2 add 10 to num1
                if (num1 < num2)
                    num1 += 10;
                diff = num1 - num2;
                // If the last number diff is 0 don't copy it to x
                if (diff == 0 && i1 == (lengthII1 - 1)) 
                    --size;
                else {
                    *x = diff % 10;
                    //cout << *x << endl;
                    ++x;
                }
                // Account for negative diff
                if (num1 >= 10 || zero_remainder) {
                    num1 = -1;
                    zero_remainder = false;
                }
                else 
                    num1 = 0; 
                ++i1;
                ++i2;
                ++size;
            }
            // Minus extra digits from the first number
            while (i1 < lengthII1) {
                num1 += temp1[i1];
                // If the last number diff is 0 don't copy it to x.
                if (num1 == 0 && i1 == (lengthII1 - 1)) {
                }
                else {
                    *x = num1;
                    //cout << *x << endl;
                    ++size;
                    ++x;
                } 
                num1 = 0;
                ++i1;
            }
            // The digits are placed into x backwards; reverse list.
            reverse_num(x - size, x);
        }
    return x;

    /* notes:
    If both signs are positive, the answer will be positive.
    Example: 14 - (-6) = 14 + 6 = 20
    If both signs are negative, the answer will be negative.
    Example: -14 - (+6) = -14 - 6 = -20
    If the signs are different subtract the smaller absolute value from the larger absolute value. The sign will be the sign of the integer that produced the larger absolute value. 
    Example: 14 - (+6) = 14 - 6 = 8 
    Example: -14 - (-6) = -14 + 6 = -8
    */


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

    //copies of b and 2
    vector<int> num1;
    vector<int> num2;
    vector<int> result;


    while(b1 != e1){
        num1.push_back(*b1);
        ++b1;
    }

    while(b2 != e2){
        num2.push_back(*b2);
        ++b2;
    }

   //int digit_counter = 0;
    result.resize(num1.size() + num2.size());

   // reverse(num1.begin(), num1.end());
    //reverse(num2.begin(), num2.end());
    int num_digits = 0;

    for(int i = 0; i < (int)num1.size(); i++){

        int carry = 0;
        int k = i;

        for(int j = 0; j < (int)num2.size(); j++){

            int temp = (num1[i])*(num2[j]) + carry + result[k];

            carry = temp/10;
            result[k] = temp%10;
            num_digits++;
            k++;
        }

        if(carry != 0){
            result[k] = carry;
            num_digits++;
        }
    }

    result.resize(num_digits);

    /*
    // Copy from our temp container to the result
    for (int i = (int)result.size()-1; i >= 0; i--)
    {
        *x = result[i];
        ++x;
    }
    */
    
    for(int i = 0; (int)i < result.size(); i++){
        *x = result[i];
        cout << "This value is *x: " << *x << endl;
        ++x;
    }
    
    
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

        if(rhs.sign == true){                               //outputs the negative if negative
            lhs << "-"; 
        }

        //output the container of rhs
        for(int i = rsize-1 ; i >= 0; --i){
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
            int size = value.size();

            //if "-555"
            if(value[0] == '-'){
                _x.resize(size - 1);
                sign = true;


                for(int i = 1; i < size; ++i){
                    int spot = i - 1;
                    
                    if(isdigit(value[i])){
                        //its a real digit value
                        _x[spot] = value[i] - '0';
                    }
                    else if(!isdigit(value[i])){
                        throw std::invalid_argument("Not a valid integer digit.");
                    }    
                }
            }
            else{//positive
                _x.resize(size);
                sign = false;
                for(int i = 0; i < size; ++i){

                    if(isdigit(value[i])){
                        //its a ral digit value
                        _x[i] = value[i] - '0';
                    }
                    else if(!isdigit(value[i])){
                        throw std::invalid_argument("Not a valid integer digit.");
                    }
                }
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
            //result need to be big enough



            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * subtract rhs from the value
         */
        Integer& operator -= (const Integer& rhs) {




            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * multiply the value by the ths
         */
        Integer& operator *= (const Integer& rhs) {

            //check signs
            //negative * negative, should be positive, so this->sign shoudl be false;
            //if rhs->sign is negative, then this is positive, so this->true

            //make your iterators, then call multiplies digits, thenr esize your container 

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

            if(*this == 0){                     //0 mod x = 0
                return *this;
            }

            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * shifts the value this to the left n times
         */
        Integer& operator <<= (int n) {

            int size = this->_x.size();
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

            //resize container;

            this->_x.resize(size + n);

            //shift here

            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         *  shifts the value this to the right n times
         */
        Integer& operator >>= (int n) {
            
            int size = this->_x.size();
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

            if(n > size){                               //shifting more times than the size itself
                this->_x.clear();                        //empty container
                this->_x.push_back(0);
            }

            //resize container;

            this->_x.resize(this->_x.size() - n);

            //shift here

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
            if(this->sign){
                this->sign = false;
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




            return *this;}};

#endif // Integer_h
