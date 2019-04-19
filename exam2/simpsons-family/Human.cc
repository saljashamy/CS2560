#ifndef HUMANCC
#define HUMANCC

#include <cstdio>
#include <string>

class Human{
    std::string name;
    int age;
    char sex;
    Human();
protected:
    Human(const std::string & n, const int a, const char s):
    name(n), age(a), sex(s){}
    virtual ~Human(){
    };
public:
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Human::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Human::age = age;
    }

    char getSex() const {
        return sex;
    }

    void setSex(char sex) {
        Human::sex = sex;
    }
};

#endif