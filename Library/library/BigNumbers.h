/**
 * @file BigNumbers.h
 * @author Saif Aljashamy
 * @brief Stores integers in string format with arithmetic operations addition, subtraction, multiplication, division and modulo. 
 * See implementation: @see BigNumbers.cpp
 */

#include <deque>
#include <string>


class BigNumbers{
public:
    std::deque<char> number;       /**< Store string digits in char deque*/
    bool negative = false;         /**< True if integer is negative*/

    BigNumbers();                   /**< Default constructor*/
    BigNumbers(std::string);        /**< String integer constructor*/

    int const getSize() const;     

    BigNumbers operator+(const BigNumbers &rhs);    /**< Addition operator */
    BigNumbers operator-(const BigNumbers &rhs);    /**< Substraction operator */
    BigNumbers operator*(const BigNumbers &rhs);    /**< Multiplication operator */
    BigNumbers operator/(const BigNumbers &rhs);    /**< Division operator */
    BigNumbers operator%(const BigNumbers &rhs);    /**< Modulo operator */
    friend bool operator>(const BigNumbers& lhs, const BigNumbers& rhs);    /**< Greater than operator */
    friend bool operator==(const BigNumbers& lhs, const BigNumbers& rhs);   /**< equality operator */

    std::string toString() const;    
};
