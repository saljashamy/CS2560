#include <iostream> 

#include <typeinfo> 

#include <string> 

int main() { 

    int i = 47; 

    const char * cstr = "this is a c-string"; 

    const std::string sclass = std::string("this is a string class string"); 

    auto x = "this is a c-string"; //figure it out based on assignment value 

    decltype(x) y;              //convert to the type of x  

    auto z = 55; 

    std::cout << "type of i is " << typeid(i).name() << std::endl; 

    std::cout << "type of cstr is " << typeid(cstr).name() << std::endl; 

    std::cout << "type of sclass is " << typeid(sclass).name() << std::endl; 

    std::cout << "type of x is " << typeid(x).name() << std::endl; 

    std::cout << "type of y is " << typeid(y).name() << std::endl; 

    std::cout << "type of z is " << typeid(z).name() << std::endl; 

    return 0; 

} 