#ifndef PARENT_CC
#define PARENT_CC

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Human.cc"
#include "Child.cc"

class Parent: public Human{
private:
    std::vector<std::string> children;
    Parent();
public:
    Parent(const std::string & n, const int a, const char s): Human(n, a, s){}
    void printChild(){
        for (std::string i: children)
            std::cout << i << ' ';
            std::cout << std::endl;
    }
    void setChild(Child c){
        children.push_back(c.getName());
    }
    void setChildAllowance(int a, Child & c){
        if(std::find(children.begin(), children.end(), c.getName()) != children.end()) {
            c.setAllowance(a);
        }
    }
};

#endif