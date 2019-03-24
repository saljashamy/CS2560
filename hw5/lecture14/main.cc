#include <string>
#include "Animal.cc"
#include "Dog.cc"
#include "Cat.cc"
#include "Donkey.cc"
#include "Pig.cc"
#include "Derived.cc"

std::string displayName(const Animal & A){
    return A.name();
}

int main(int argc, char **argv){
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    Donkey donk("Eeyore");

    printf("%s\n", displayName(d).c_str());
    printf("%s\n", displayName(c).c_str());
    printf("%s\n", displayName(p).c_str());
    printf("%s\n", displayName(donk).c_str());

    printf("%s\n", d.snap().c_str());
    printf("%s\n", d.Animal::snap().c_str());
    printf("%s\n", c.snap().c_str());
    printf("%s\n", c.Animal::snap().c_str());
    printf("%s\n", p.snap().c_str());
    printf("%s\n", p.Animal::snap().c_str());
    printf("%s\n", donk.snap().c_str());
    printf("%s\n", donk.Animal::snap().c_str());

    printf("%s\n", d.move().c_str());
    printf("%s\n", c.move().c_str());
    printf("%s\n", p.move().c_str());
    printf("%s\n", donk.move().c_str());

    d.speak();
    c.speak();
    p.speak();
    donk.speak();

    printf("the dog has been walked %d times\n", d.walk()); 
    printf("the cat has been petted %d times\n", c.pet());
    printf("the pig has been fed %d times\n", p.feed());  
    printf("the donkey has been carried %d times\n", donk.carry()); 

    Derived *derived = new Derived();
    Base *base = derived;
    delete base;
    return 0;
}