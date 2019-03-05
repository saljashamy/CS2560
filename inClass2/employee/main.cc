#include <iostream>
#include "Employee.h"

using namespace std;

void printEmployeeInfo(Employee &e){
    cout << endl;
    cout << "employee name: " << e.getName() << endl;
    cout << "employee id number: " << e.getIdNumber() << endl;
    cout << "employee deparment: " << e.getDepartment() << endl;
    cout << "employee position: " << e.getPosition() << endl;
}

int main() {
    Employee* e1 = new Employee("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee* e2 = new Employee("Mark Jones", 39119);
    e2->setDepartment("IT");
    e2->setPosition("Programmer");
    Employee* e3 = new Employee();
    e3->setName("Joy Rogers");
    e3->setIdNumber(81774);
    e3->setDepartment("Manufacturing");
    e3->setPosition("Engineer");
    printEmployeeInfo(*e1);
    printEmployeeInfo(*e2);
    printEmployeeInfo(*e3);
    return 0;
}