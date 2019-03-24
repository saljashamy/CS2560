#ifndef ANIMAL_CC
#define ANIMAL_CC

#include <cstdio>
#include <string>

class Animal{
    std::string _name;
    std::string _type;
    std::string _sound;
    Animal(){};
protected:
    Animal(const std::string & n, const std::string & t, const std::string & s)
        : _name(n), _type(t), _sound(s){
        printf("Animal Constructed\n");
    }
    ~Animal(){
        printf("Animal Destructed\n");
    };
public:
    void speak() const;
    const std::string & name() const { return _name; }
    const std::string & type() const { return _type; }
    const std::string & sound() const { return _sound; }
    std::string snap(){ return "Animal_Snap"; }
    virtual std::string move() = 0;
};

void Animal::speak() const{
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

#endif