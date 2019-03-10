#include "ParkedCar.h"

ParkedCar::ParkedCar(string make, string model, string color, int licenseNumber) {
    setMake(make);
    setModel(model);
    setColor(color);
    setLicenseNumber(licenseNumber);
    setMinutesParked(0);
}

const string &ParkedCar::getMake() const {
    return make;
}

void ParkedCar::setMake(const string &make) {
    ParkedCar::make = make;
}

const string &ParkedCar::getModel() const {
    return model;
}

void ParkedCar::setModel(const string &model) {
    ParkedCar::model = model;
}

const string &ParkedCar::getColor() const {
    return color;
}

void ParkedCar::setColor(const string &color) {
    ParkedCar::color = color;
}

int ParkedCar::getLicenseNumber() const {
    return licenseNumber;
}

void ParkedCar::setLicenseNumber(int licenseNumber) {
    ParkedCar::licenseNumber = licenseNumber;
}

int ParkedCar::getMinutesParked() const {
    return minutesParked;
}

void ParkedCar::setMinutesParked(int minutesParked) {
    ParkedCar::minutesParked = minutesParked;
}
