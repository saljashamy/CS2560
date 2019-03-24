#include <cstdio>
#include <string>
#include "Animal.cc"

class Dog: public Animal{
    int walked;
public:
    Dog(std::string n): Animal(n, "dog", "woof"), walked(0){
        printf("Dog Constructed \n");
    }
    ~Dog(){
        printf("Dog Destructed\n");
    };
    int walk(){ return ++walked; }
    std::string snap(){ return "Dog_Snap"; }
    virtual std::string move(){ return "Dog_Move"; }
};