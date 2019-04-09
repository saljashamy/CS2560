#include <iostream>
#include <string>

template <typename T>               
T minimum(const T & a, const T & b) {     
    return (a < b ? a : b);         
} 

template <typename T>               
T maximum(const T & a, const T & b) {     
    return (a > b ? a : b);         
} 

int main(){
    int a1 = -1;
    int b1 = 1;

    std::cout << "maximum of " << a1 << " and " << b1 << ": " << maximum<int>(a1, b1) << std::endl;
    std::cout << "minimum of " << a1 << " and " << b1 << ": " << minimum<int>(a1, b1) << std::endl;

    float a2 = -0.184932;
    float b2 = -0.2543789;

    std::cout << "maximum of " << a2 << " and " << b2 << ": " << maximum<float>(a2, b2) << std::endl;
    std::cout << "minimum of " << a2 << " and " << b2 << ": " << minimum<float>(a2, b2) << std::endl;

    char a3 = 'a';
    char b3 = 'A';

    std::cout << "maximum of " << a3 << " and " << b3 << ": " << maximum<char>(a3, b3) << std::endl;
    std::cout << "minimum of " << a3 << " and " << b3 << ": " << minimum<char>(a3, b3) << std::endl;

    std::string a4 = "zero";
    std::string b4 = "one";

    std::cout << "maximum of " << a4 << " and " << b4 << ": " << maximum<std::string>(a4, b4) << std::endl;
    std::cout << "minimum of " << a4 << " and " << b4 << ": " << minimum<std::string>(a4, b4) << std::endl;

}