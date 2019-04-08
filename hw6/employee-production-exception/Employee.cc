#include <iostream>
#include <time.h>
#include "Employee.h"
#include "EmployeeException.h"


Employee::Employee(std::string name, int idNumber, int day, int month, int year) {
    setName(name);
    setIdNumber(idNumber);
    setDate(day, month, year);
}

const std::string & Employee::getName() const {
    return name;
}

void Employee::setName(const std::string &name) {
    Employee::name = name;
}

int Employee::getIdNumber() const {
    return idNumber;
}

void Employee::setIdNumber(int idNumber) {
    if(idNumber < 0 || idNumber > 9999){
        throw new EmployeeException("InvalidEmployeeNumber");
    }
    Employee::idNumber = idNumber;
}

void Employee::setDate(int day, int month, int year){
    Employee::date = new Date(day, month, year);
}

Date* Employee::getDate(){
    return date;
}

void Employee::printEmployeeInfo(){
    std::cout << "employee name: " << Employee::name << std::endl 
              << "employee id: " << Employee::idNumber << std::endl
              << "hire date: " << Employee::date->getMonth() << "/" << Employee::date->getDay() << "/" << Employee::date->getYear() << std::endl;
}
