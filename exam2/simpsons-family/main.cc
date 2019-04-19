#include <string>
#include <iostream>
#include "Parent.cc"
#include "Child.cc"

//6
void printInfo(const Human & h){
    std::cout << "name: " << h.getName() << std::endl;
    std::cout << "age: " << h.getAge() << std::endl;
    std::cout << "sex: " << h.getSex() << std::endl;
}

int main(){
    //1a
    Parent p1("March", 34, 'f');
    Parent p2("Homer", 36, 'm');
    //1b
    Child c1("Lisa", 12, 'f', "March", "Homer");
    Child c2("Bart", 10, 'm', "March", "Homer");
    Child c3("Maggie", 3, 'f', "March", "Homer");
   //1c
    p1.setChild(c1);
    p1.setChild(c2);
    p1.setChild(c3);
    p2.setChild(c1);
    p2.setChild(c2);
    p2.setChild(c3);
    //2
    std::cout << "Bart's allowance: " << c2.getAllowance() << std::endl;
    //3
    p2.setChildAllowance(5, c2);
    //4
    std::cout << "Bart's allowance: " << c2.getAllowance() << std::endl;
    //5
    std::cout << "\nBart's Parents: " << std::endl;
    c2.printParent();
    //8
    std::cout << "\nMarch Info: " << std::endl;
    printInfo(p1);
    std::cout << "\nLisa Info: " << std::endl;
    printInfo(c1);
    return 0;
}