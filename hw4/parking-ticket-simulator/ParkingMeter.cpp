#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(){
    setMinutesPurchased(0);
}

void ParkingMeter::setMinutesPurchased(int minutesPurchased) {
    ParkingMeter::minutesPurchased = minutesPurchased;
}

int ParkingMeter::getMinutesPurchased() const {
    return minutesPurchased;
}