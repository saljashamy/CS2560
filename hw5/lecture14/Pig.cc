#include <cstdio>
#include <string>
#include "Animal.cc"

class Pig: public Animal{
    int fed;
public:
    Pig(std::string n): Animal(n, "pig", "oink"), fed(0){
        printf("Pig Constructed \n");
    }
    ~Pig(){
        printf("Pig Destructed\n");
    };
    int feed(){ return ++fed; }
    virtual std::string move(){ return "Pig_Move"; }
    std::string snap(){ return "Pig_Snap"; }
};