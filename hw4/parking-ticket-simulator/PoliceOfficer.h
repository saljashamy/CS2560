#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H
#include <string>
#include "ParkedCar.h"
#include "ParkingMeter.h"

using namespace std;

class PoliceOfficer
{
private:
    string name;
    int badgeNumber;

public:
    PoliceOfficer(string, int);
    void setName(const string &);
    const string &getName() const;
    void setBadgeNumber(int);
    int getBadgeNumber() const;
    void checkParkedCar(ParkedCar&, ParkingMeter&);
};
#endif