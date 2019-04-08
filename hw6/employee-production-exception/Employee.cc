#include <iostream>
#include <time.h>
#include "Employee.h"


Employee::Employee(std::string name, int idNumber, int day, int month, int year) {
    Employee::name = name;
    Employee::idNumber = idNumber;
    Employee::date = new Date(day, month, year);
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
