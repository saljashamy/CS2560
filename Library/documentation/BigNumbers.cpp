/**
 * @file BigNumbers.cpp
 * @author Saif Aljashamy
 * @brief Stores integers in string format with arithmetic operations addition, subtraction, multiplication, division and modulo. 
 * See gtest: @see BigNumbersTest.cpp
 * @mainpage BigNumbers Documentation
 *  Library stores integers in string format with arithmetic operations addition, subtraction, multiplication, division and modulo.  
 *  Files: @see BigNumbers.h, BigNumbers.cpp, BigNumbersTest.cpp
 */

#include "BigNumbers.h"
#include <iostream>
#include <cmath>

#define toDigit(c) (c - '0')  /**< Char digit to int */



BigNumbers::BigNumbers(){}

BigNumbers::BigNumbers(std::string input){
    if(input[0] == '-'){
        negative = true;
        input = input.substr(1);
    }
    else if(input[0] == '+'){
        input = input.substr(1);
    }
    for(char d : input){
        number.push_back(d);
    }
}

/**
	Adds two BigNumbers with + operator
    @param this left operand
	@param r right operand 
	@returns Left operand plus right operands
*/
BigNumbers BigNumbers::operator+(const BigNumbers & r)
{
    std::string rsum, lsum, sum;
    BigNumbers lhs(this->toString());               
    BigNumbers rhs = BigNumbers(r.toString());       

    if(lhs.negative && !rhs.negative){
        lhs.negative = false;
        return rhs - lhs;
    }
    else if(!lhs.negative && rhs.negative){
        rhs.negative = false;
        return lhs - rhs;
    }

    if(rhs.getSize() > lhs.getSize()){
        BigNumbers temp(lhs.toString());
        lhs = rhs;
        rhs = temp;
    }

    int j = rhs.getSize() - 1;
    for(int i = lhs.getSize() - 1; i >= lhs.getSize() - rhs.getSize(); i--){
        short add = toDigit(lhs.number[i]) + toDigit(rhs.number[j]);
        if(add > 9){
            rsum = std::to_string(add % 10) + rsum;
            if(i != 0) {
                if (toDigit(lhs.number[i - 1]) != 9) {
                    lhs.number[i - 1] = lhs.number[i - 1] + 1;
                } else {
                    int k = i - 1;
                    while (k >= 0 && toDigit(lhs.number[k]) == 9) {
                        lhs.number[k] = '0';
                        k--;
                    }
                    if (k < 0) {
                        lhs.number.push_front('1');
                        i++;
                    } else {
                        lhs.number[k] = lhs.number[k] + 1;
                    }
                }
            }
            else{
                lhs.number.push_front('1');
            }
        }
        else{
            rsum = std::to_string(add) + rsum;
        }
        j--;
    }

    for(int i = 0; i < lhs.getSize() - rhs.getSize(); i++){
        lsum = lsum + lhs.number[i];
    }

    sum = lsum + rsum;
    if(lhs.negative && rhs.negative){
        sum = "-" + sum;
    }
    return BigNumbers(sum);
}

/**
	Substracts two BigNumbers with - operator
    @param this left operand
	@param r right operand 
	@returns Left operand minus right operand
*/
BigNumbers BigNumbers::operator-(const BigNumbers & r)
{
    std::string rdiff, ldiff, diff;
    BigNumbers lhs(this->toString());
    BigNumbers rhs = BigNumbers(r.toString());
    if(lhs.negative && !rhs.negative){
        BigNumbers temp = BigNumbers("-" + rhs.toString());
        return lhs + temp;
    }
    else if(!lhs.negative && rhs.negative){
        BigNumbers temp = BigNumbers(rhs.toString());
        temp.negative = false;
        return lhs + temp;
    }

    BigNumbers temp;
    bool swap = false;
    if(rhs > lhs){
        BigNumbers temp(lhs.toString());
        lhs = rhs;
        rhs = temp;
        swap = true;
    }

    std::string result;
    int j = rhs.getSize() - 1;
    for(int i = lhs.getSize() - 1; i >= lhs.getSize() - rhs.getSize(); i--){
        if(toDigit(lhs.number[i]) < toDigit(rhs.number[j])){
            int k = i-1;
            while(toDigit(lhs.number[k]) == 0){
                lhs.number[k] = '9';
                k--;
            }
            lhs.number[k] -= 1;
            rdiff = std::to_string((10 + toDigit(lhs.number[i])) - toDigit(rhs.number[j])) + rdiff;
        }
        else{
            rdiff = std::to_string(toDigit(lhs.number[i]) - toDigit(rhs.number[j])) + rdiff;
        }
        j--;
    }

    for(int i = 0; i < lhs.getSize() - rhs.getSize(); i++){
        ldiff = ldiff + lhs.number[i];
    }

    diff = ldiff + rdiff;
    if(swap){
        diff = "-" + diff;
    }
    return BigNumbers(diff);
}

/**
	Multiply two BigNumbers with + operator
    @param this left operand
	@param r right operand 
	@returns Left operand multiply right operands
*/
BigNumbers BigNumbers::operator*(const BigNumbers &r) {
    std::string rmul, lmul, mul;
    BigNumbers lhs(this->toString());
    BigNumbers rhs = BigNumbers(r.toString());

    BigNumbers temp;
    if(rhs > lhs){
        BigNumbers temp(lhs.toString());
        lhs = rhs;
        rhs = temp;
    }

    std::string minus;
    if((!lhs.negative && rhs.negative) || (lhs.negative && !rhs.negative)){
        minus = '-';
    }
    else if((lhs.negative && rhs.negative) || (!lhs.negative && !rhs.negative)){
        minus = "";
    }
    rhs.negative = false;
    lhs.negative = false;

    BigNumbers result("0");
    int z = 0;
    for(int i = rhs.getSize()-1; i >= 0; i--){
        int mul = toDigit(rhs.number[i]);
        BigNumbers sum("0");
        for(int j = 0; j < mul ; j++){
            sum = sum + lhs;
        }
        std::string temp = sum.toString();
        for(int j = 0; j < z; j++){
            temp = temp + '0';
        }
        result = BigNumbers(temp) + result;
        z++;
    }

    return BigNumbers(minus + result.toString());
}

/**
	Divide two BigNumbers with / operator
    @param this left operand
	@param r right operand 
	@returns Left operand divide right operands
*/
BigNumbers BigNumbers::operator/(const BigNumbers &r){
    BigNumbers lhs(this->toString());
    BigNumbers rhs = BigNumbers(r.toString());

    std::string minus;
    if((lhs.negative && !rhs.negative) || (!lhs.negative && rhs.negative)){
        minus = "-";
    }
    else if((!lhs.negative && !rhs.negative) || (lhs.negative && rhs.negative)){
        minus = "";
    }
    lhs.negative = false;
    rhs.negative = false;

    if(rhs > lhs){
        return BigNumbers("0");
    }
    else if (lhs == rhs) {
        return BigNumbers(minus + "1");
    }

    BigNumbers result("0");
    BigNumbers count("0");
    while(lhs > result){
        count = count + BigNumbers("1");
        result = rhs * count;
    }
    count = count + BigNumbers("-1");

    return BigNumbers(minus + count.toString());
}

/**
	Modulo two BigNumbers with % operator
    @param this left operand
	@param r right operand 
	@returns Left operand modulo right operands
*/
BigNumbers BigNumbers::operator%(const BigNumbers &r){
    BigNumbers lhs(this->toString());
    BigNumbers rhs = BigNumbers(r.toString());

    std::string minus;
    if((lhs.negative && !rhs.negative) || (!lhs.negative && rhs.negative)){
        minus = "-";
    }
    else if((!lhs.negative && !rhs.negative) || (lhs.negative && rhs.negative)){
        minus = "";
    }
    lhs.negative = false;
    rhs.negative = false;

    if(rhs > lhs || rhs == BigNumbers("0")){
        return lhs;
    }
    else if(rhs == lhs || rhs == BigNumbers("1")){
        return BigNumbers("0");
    }

    std::string result = (lhs - ((lhs / rhs) * rhs)).toString();
    while(result[0] == '0'){
        result = result.substr(1);
    }

    return BigNumbers(minus + result);
}

/**
	Compare two BigNumbers with > operator
    @param this left operand
	@param r right operand 
	@returns True or false 
*/
bool operator>(const BigNumbers& lhs, const BigNumbers& rhs){
    if(lhs.getSize() > rhs.getSize()){
        return true;
    }
    else if (lhs.getSize() < rhs.getSize()){
        return false;
    }
    else{
        for(int i = 0; i < lhs.getSize(); i++){
            if(toDigit(lhs.number[i]) > toDigit(rhs.number[i])){
                return true;
            }
            else if(toDigit(lhs.number[i]) < toDigit(rhs.number[i])){
                return false;
            }
        }
    }
}

/**
	Compare two BigNumbers with == operator
    @param this left operand
	@param r right operand 
	@returns True or false 
*/
bool operator==(const BigNumbers& lhs, const BigNumbers& rhs){
    if(lhs.toString() == rhs.toString()){
        return true;
    }
    else{
        return false;
    }
}

/**
	@returns Number of digits
*/
int const BigNumbers::getSize() const{
    return number.size();
}

/**
	@returns String format of integer
*/
std::string BigNumbers::toString() const{
    std::string out;
    if(negative){
        out += '-';
    }
    for(char d : number){
        if(d != '\0'){
            out += d;
        }
        else{
            return out;
        }
    }
    return out;
}