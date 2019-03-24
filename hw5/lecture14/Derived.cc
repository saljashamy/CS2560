#include <iostream>
#include "Base.cc"

class Derived : public Base{
public:
    Derived()
    {
        std::cout << "Constructing derived \n";
    }
    ~Derived()
    {
        std::cout << "Destructing derived \n";
    }
};