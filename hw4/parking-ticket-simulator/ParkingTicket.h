#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H
#include <string>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

using namespace std;

class ParkingTicket
{
private:
    void printCarInfo(ParkedCar&);
    void calculatePrintFine(ParkedCar&, ParkingMeter&);
    void printOfficerInfo(PoliceOfficer&);
public:
    ParkingTicket(ParkedCar&, ParkingMeter&, PoliceOfficer&);
};
#endif