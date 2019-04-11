// simple fixed-size LIFO, Last In First Out, stack template 
#include <iostream>
#include <string>
#include "StackException.h"

template <typename T> 

class Stack { 

private: 
    //can be reused by multiple instances 
    static const int defaultSize = 10;   
    static const int maxSize = 1000; 
    int _size;      //current number of items in stack 
    int _top;       // 
    T * stackPtr;    
public: 
    explicit Stack(int s = defaultSize); 
    ~Stack() { delete[] stackPtr; } //prevent memory leak by deleting dynamic memory 
    T & push(const T &); 
    T & pop(); 
    bool isEmpty() const { return _top < 0; } 
    bool isFull() const { return _top >= _size - 1; } 
    int top() const { return _top; } 
    int size() const { return _size; } 
}; 

template <typename T> 

Stack<T>::Stack(int s) { 
    if (s > maxSize || s < 1) throw StackExeption("invalid stack size"); 
    else _size = s; 
    stackPtr = new T[_size]; 
    _top = -1; //because it is upside down index 0 is bottom point below 
} 

template <typename T> 

T & Stack<T>::push(const T & i) { 
    if (isFull()) throw StackExeption("stack full"); 
    return stackPtr[++_top] = i; //increment and push hence first would be [0] 
} 

template <typename T> 

T & Stack<T>::pop() { 
    if (isEmpty()) throw StackExeption("stack empty"); 
    return stackPtr[_top--]; 
} 

int main() { 
    try { 
        Stack<int> si(5); 
        std::cout << "si size: " << si.size() << std::endl; 
        std::cout << "si top: " << si.top() << std::endl; 
        //c++11 range based for loop  increment through nums with index i 
        for (int i : nums) { 
            si.push(i); 
        } 
        std::cout << "si top after pushes: " << si.top() << std::endl; 
        std::cout << "si is " << (si.isFull() ? "" : "not ") << "full" << std::endl; 
        while (!si.isEmpty()) { 
            std::cout << "popped " << si.pop() << std::endl; 
        } 
    } 
    catch (StackExeption & e) { 
        std::cout << "Stack error: " << e.what() << std::endl; 
    } 

    try { 
        Stack<std::string> ss(5); 
 
        std::cout << "ss size: " << ss.size() << std::endl; 
        std::cout << "ss top: " << ss.top() << std::endl; 
 
        for (const char * s : strs) { 
            ss.push(s); 
        } 
 
        std::cout << "ss top after pushes: " << ss.top() << std::endl; 
        std::cout << "ss is " << (ss.isFull() ? "" : "not ") << "full" << std::endl; 

        while (!ss.isEmpty()) { 
            std::cout << "popped " << ss.pop() << std::endl; 
        } 
    }
    catch (StackExeption & e) { 
        std::cout << "Stack error: " << e.what() << std::endl; 
    } 
    return 0; 
} 
