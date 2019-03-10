#include "PoliceOfficer.h"
#include "ParkingTicket.cpp"

PoliceOfficer::PoliceOfficer(string name, int badgeNumber){
    setName(name);
    setBadgeNumber(badgeNumber);
}

void PoliceOfficer::checkParkedCar(ParkedCar& car, ParkingMeter& meter){
    if(car.getMinutesParked() > meter.getMinutesPurchased()){
        new ParkingTicket(car, meter, *this);
    }
}

const string &PoliceOfficer::getName() const {
    return name;
}

void PoliceOfficer::setName(const string &name) {
    PoliceOfficer::name = name;
}

int PoliceOfficer::getBadgeNumber() const {
    return badgeNumber;
}

void PoliceOfficer::setBadgeNumber(int badgeNumber) {
    PoliceOfficer::badgeNumber = badgeNumber;
}