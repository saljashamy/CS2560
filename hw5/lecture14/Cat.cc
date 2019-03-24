#include <cstdio>
#include <string>
#include "Animal.cc"

class Cat: public Animal{
    int petted;
public:
    Cat(std::string n): Animal(n, "cat", "meow"), petted(0){
        printf("Cat Constructed \n");
    }
    ~Cat(){
        printf("Cat Destructed\n");
    };
    int pet(){ return ++petted; }
    virtual std::string move(){ return "Cat_Move"; }
    std::string snap(){ return "Cat_Snap"; }
};