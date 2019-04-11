//TEMPLATE with function 
//Templates allow us to tell compiler at compile time to generate the  
//function with the type specified. However we only write the code once 
//No need for function overloading all types!!! 

#include <iostream> 
#include <string>
//T is a generic type that will be defined later 

template <typename T>               //we could have more then 1 typename so the letter T is arbitray ex: ,typename X 
T maxof(const T & a, const T & b) {     
    return (a > b ? a : b);         //ternary operator 
} 

int main() {     
    //try adding a new type string. 
    std::string c = "seven"; 
    std::string d = "nine";
    //Note it will compares the string because string class has overloaded operator ">" 
    std::cout << "max is " << maxof<std::string>(c, d) << std::endl;      
    return 0; 
} 