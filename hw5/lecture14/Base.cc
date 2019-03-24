#include <iostream>

class Base{
    public: 
    Base()
    {
        std::cout << "Constructing base \n";
    }
    virtual ~Base()
    {
        std::cout << "Destructing base \n";
    }
};