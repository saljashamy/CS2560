#ifndef CHILDCC
#define CHILDCC

#include <iostream>
#include <string>
#include <vector>
#include "Human.cc"

class Child: public Human{
private:
    std::string momName;
    std::string dadName;
    int allowance;
    Child();
public:
    Child(const std::string & n, const int a, const char s, const std::string & m, const std::string & d): Human(n, a, s), momName(m), dadName(d), allowance(0){}
    const std::string &getMomName() const {
        return momName;
    }

    void setMomName(const std::string &momName) {
        Child::momName = momName;
    }

    const std::string &getDadName() const {
        return dadName;
    }

    void setDadName(const std::string &dadName) {
        Child::dadName = dadName;
    }

    int getAllowance() const {
        return allowance;
    }
    void setAllowance(int allowance) {
        Child::allowance = allowance;
    }
    void printParent(){
        std::cout << "mom: " << getMomName() << std::endl;
        std::cout << "dad: " << getDadName() << std::endl;
    }
};

#endif