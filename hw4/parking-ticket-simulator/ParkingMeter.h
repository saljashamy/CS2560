#ifndef PARKINGMETER_H
#define PARKINGMETER_H
#include <string>

using namespace std;

class ParkingMeter {
private:
    int minutesPurchased;
public:
    ParkingMeter();
    int getMinutesPurchased() const;
    void setMinutesPurchased(int minutesPurchased);
};

#endif