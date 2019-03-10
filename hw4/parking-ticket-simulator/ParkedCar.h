#ifndef PARKEDCAR_H
#define PARKEDCAR_H
#include <string>
using namespace std;

class ParkedCar
{
private:
    string make;
    string model;
    string color;
    int licenseNumber;
    int minutesParked;
public:
    ParkedCar(string, string, string, int);
    const string &getMake() const;
    void setMake(const string &make);
    const string &getModel() const;
    void setModel(const string &model);
    const string &getColor() const;
    void setColor(const string &color);
    int getLicenseNumber() const;
    void setLicenseNumber(int licenseNumber);
    int getMinutesParked() const;
    void setMinutesParked(int minutesParked);
};
#endif