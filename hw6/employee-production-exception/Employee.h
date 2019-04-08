#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"


class Employee{
    private:
    std::string name;
    int idNumber;
    Date *date;

public:
    Employee(std::string, int, int, int, int);
    const std::string & getName() const;
    void setName(const std::string &);
    int getIdNumber() const;
    void setIdNumber(int);
    const std::string & getDate() const;
    void setDate(const std::string &);
    void setDate(int, int, int);
    Date* getDate();
    void printEmployeeInfo();
};

#endif