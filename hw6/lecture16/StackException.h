#include <iostream> 

#include <string> 

#include <exception> 

//constexpr, C++11, is like const but can apply to functions and constructors  

//means the value is constant and if possible computed at compile time    

constexpr int nums[] = { 1, 2, 3, 4, 5 }; 

//constexpr makes strs a const pointer.  

//The const in const char * makes strs point to const char 

constexpr const char * strs[] = { "one", "two", "three", "four", "five" }; 

//******** START HEADER FILE HERE  ************* 

// simple exception class  inherit from standard exception class 

class StackExeption : public std::exception { 

    const char * msg; 

    StackExeption() {};    // no default constructor 

public: 

    //explicit means argument value must be assigned with constructor only!  

    //exception specification  

    //throw() means that if an exception is thrown call std::unexpected   

    explicit StackExeption(const char * s) throw() : msg(s) { } 

    virtual const char * what() const throw() { return msg; } 

};