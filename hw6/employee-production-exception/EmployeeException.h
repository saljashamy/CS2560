#ifndef EMPLOYEEEXCEPTION_H
#define EMPLOYEEEXCEPTION_H

#include <exception>

class EmployeeException : public std::exception { 

    const char * msg; 
    EmployeeException() {};    

public: 
    explicit EmployeeException(const char * s) throw() : msg(s) { } 
    virtual const char * what() const throw() { return msg; } 
};

#endif