#include "ParkedCar.cpp"
#include "ParkingMeter.cpp"
#include "PoliceOfficer.cpp"

int main(){
    ParkedCar* car1 = new ParkedCar("Honda", "2019", "White", 9271349);
    ParkingMeter* meter1 = new ParkingMeter();
    meter1->setMinutesPurchased(60);
    car1->setMinutesParked(408);
    ParkedCar* car2 = new ParkedCar("Tesla", "2019", "Red", 4387813);
    ParkingMeter* meter2 = new ParkingMeter();
    meter2->setMinutesPurchased(120);
    car2->setMinutesParked(239);
    PoliceOfficer* officer = new PoliceOfficer("John Smith", 492874);
    officer->checkParkedCar(*car1, *meter1);
    cout << endl;
    officer->checkParkedCar(*car2, *meter2);
};

