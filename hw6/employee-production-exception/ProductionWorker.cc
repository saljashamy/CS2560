#include <iostream>
#include <time.h>
#include "ProductionWorker.h"


ProductionWorker::ProductionWorker(std::string name, int idNumber, int day, int month, int year, int shift, double hourlyRate): Employee(name, idNumber, day, month, year){
    setShift(shift);
    setHourlyRate(hourlyRate);

}

int ProductionWorker::getShift() const {
    return shift;
}

void ProductionWorker::setShift(int shift) {
   ProductionWorker::shift = shift;
}

double ProductionWorker::getHourlyRate() const {
    return hourlyRate;
}

void ProductionWorker::setHourlyRate(double hourlyRate) {
   ProductionWorker::hourlyRate = hourlyRate;
}

void ProductionWorker::printProductionWorkerInfo(){
    printEmployeeInfo();
    std::cout << "shift: " << ((getShift() == 1)?("day"):("night")) << std::endl 
              << "hourly rate: $" << getHourlyRate() << std::endl;
}

int main(){
    ProductionWorker pw1("Richard", 2, 7, 4, 2019, 1, 20.25);
    pw1.printProductionWorkerInfo();
}