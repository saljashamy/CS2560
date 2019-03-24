#include <cstdio>
#include <string>
#include "Animal.cc"

class Donkey: public Animal{
    int carried;
public:
    Donkey(std::string n): Animal(n, "donkey", "hee-haw"), carried(0){
        printf("Donkey Constructed \n");
    }
    ~Donkey(){
        printf("Donkey Destructed\n");
    };
    int carry(){ return ++carried; }
    virtual std::string move(){ return "Donkey_Move"; }
    std::string snap(){ return "Donkey_Snap"; }
};