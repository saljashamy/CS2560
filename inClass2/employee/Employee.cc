#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(string name, int idNumber, string department, string position) {
    Employee::name = name;
    Employee::idNumber = idNumber;
    Employee::department = department;
    Employee::position = position;
}

Employee::Employee(string name, int idNumber) {
    Employee::name = name;
    Employee::idNumber = idNumber;
    Employee::department = "";
    Employee::position = "";
}

Employee::Employee() {
    Employee::name = "";
    Employee::idNumber = 0;
    Employee::department = "";
    Employee::position = "";
}

const string & Employee::getName() const {
    return name;
}

void Employee::setName(const string &name) {
    Employee::name = name;
}

int Employee::getIdNumber() const {
    return idNumber;
}

void Employee::setIdNumber(int idNumber) {
    Employee::idNumber = idNumber;
}

const string & Employee::getDepartment() const {
    return department;
}

void Employee::setDepartment(const string &department) {
    Employee::department = department;
}

const string& Employee::getPosition() const {
    return position;
}

void Employee::setPosition(const string &position) {
    Employee::position = position;
}