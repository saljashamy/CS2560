#include "Date.h"

int main(){
    Date d;
    Date d1;
    Date d2;
    
    for(int i = 0 ; i < 3; i++){
        std::cin >> d;
        std::cout << "\n" << d;
        std::cout << "adding day" << std::endl;
        ++d;
        std::cout << d << "\n" << std::endl;
    }

    for(int i = 0 ; i < 3; i++){
        std::cin >> d;
        std::cout << "\n" << d;
        std::cout << "subtracting day" << std::endl;
        --d;
        std::cout << d << "\n" << std::endl;
    }
    
    for(int i = 0; i < 3; i++){ 
        std::cin >> d1;
        std::cin >> d2;
        std::cout << "\n " << d2 << "-" << d1;
        std::cout << d2 - d1 << " days " << "\n" << std::endl; 
    }

    return 0;
} 