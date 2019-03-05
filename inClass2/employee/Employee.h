#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee{
    private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    Employee(string, int, string, string);
    Employee(string, int);
    Employee();
    const string & getName() const;
    void setName(const string &);
    int getIdNumber() const;
    void setIdNumber(int);
    const string & getDepartment() const;
    void setDepartment(const string &);
    const string& getPosition() const;
    void setPosition(const string &position);
};

#endif