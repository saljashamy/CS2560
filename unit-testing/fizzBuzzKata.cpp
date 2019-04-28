#include <iostream>
#include <gtest/gtest.h>

bool isMultiple(int value, int base){
    return (0 == (value % base));
}

std::string fizzBuzz(int value){
    if(isMultiple(value, 3) && isMultiple(value, 5)){
        return "FizzBuzz";
    }
    if(isMultiple(value, 3)){
        return "Fizz";
    }
    if(isMultiple(value, 5)){
        return "Buzz";
    }
    return std::to_string(value);
}

void checkFizzBuzz(int value, std::string expectedResult){
    std::string result = fizzBuzz(value);
    ASSERT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(FizzBuzzTest, canCallFizzBuzz){
    std::string result = fizzBuzz(1);
}

TEST(FizzBuzzTest, return1With1PassedIn){
    std::string result = fizzBuzz(1);
    checkFizzBuzz(1, "1");
}

TEST(FizzBuzzTest, return2With2PassedIn){
    std::string result = fizzBuzz(2);
    checkFizzBuzz(2, "2");
}


TEST(FizzBuzzTest, returnFizzWith3PassedIn){
    std::string result = fizzBuzz(3);
    checkFizzBuzz(3, "Fizz");
}

TEST(FizzBuzzTest, returnBuzzWith5PassedIn){
    std::string result = fizzBuzz(5);
    checkFizzBuzz(5, "Buzz");
}

TEST(FizzBuzzTest, returnFizzWith6PassedIn){
    std::string result = fizzBuzz(6);
    checkFizzBuzz(6, "Fizz");
}

TEST(FizzBuzzTest, returnBuzzWith10PassedIn){
    std::string result = fizzBuzz(10);
    checkFizzBuzz(10, "Buzz");
}

TEST(FizzBuzzTest, returnFizzBuzzWith15PassedIn){
    std::string result = fizzBuzz(15);
    checkFizzBuzz(15, "FizzBuzz");
}


