#include <iostream>
#include "ParkingTicket.h"

using namespace std;

ParkingTicket::ParkingTicket(ParkedCar &car, ParkingMeter &meter, PoliceOfficer &officer){
    printCarInfo(car);
    calculatePrintFine(car, meter);
    printOfficerInfo(officer);
}


void ParkingTicket::printCarInfo(ParkedCar& car){
    cout << "Car make: " << car.getMake() << endl;
    cout << "Car model: " << car.getModel() << endl;
    cout << "Car color: " << car.getColor() << endl;
    cout << "Car license number: " << to_string(car.getLicenseNumber()) << endl;
}

void ParkingTicket::calculatePrintFine(ParkedCar &car, ParkingMeter &meter){
    int purchasedMinutes = meter.getMinutesPurchased();
    int parkedMinutes = car.getMinutesParked();
    int expiredMinutes = parkedMinutes - purchasedMinutes;
    cout << "Purchased minutes: " << purchasedMinutes << endl;
    cout << "Parked minutes: " << parkedMinutes << endl;
    cout << "Expired minutes: " << expiredMinutes << endl;
    int fine = 25;
    expiredMinutes -= 60;
    double expiredHours = expiredMinutes/60.0;
    fine += (expiredHours > 0) ? (10*(int(expiredHours) + 1)) : 0;
    cout << "First hour $25 and $10/hour after" << endl;
    cout << "Fine: $" << fine << endl;
}

void ParkingTicket::printOfficerInfo(PoliceOfficer &officer){
    cout << "Officer name: " << officer.getName() << endl;
    cout << "Badge number: " << officer.getBadgeNumber() << endl;
}