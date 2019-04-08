#include <iostream>
#include <time.h>
#include "ProductionWorker.h"
#include "EmployeeException.h"


ProductionWorker::ProductionWorker(std::string name, int idNumber, int day, int month, int year, int shift, double hourlyRate): Employee(name, idNumber, day, month, year){
    setShift(shift);
    setHourlyRate(hourlyRate);
}

int ProductionWorker::getShift() const {
    return shift;
}

void ProductionWorker::setShift(int shift) {
    if(shift != 1 && shift != 2){
        throw new EmployeeException("InvalidShift");
    }
    ProductionWorker::shift = shift;
}

double ProductionWorker::getHourlyRate() const {
    return hourlyRate;
}

void ProductionWorker::setHourlyRate(double hourlyRate) {
   if(hourlyRate < 0){
       throw new EmployeeException("InvalidPayRate");
   }
   ProductionWorker::hourlyRate = hourlyRate;
}

void ProductionWorker::printProductionWorkerInfo(){
    printEmployeeInfo();
    std::cout << "shift: " << ((getShift() == 1)?("day"):("night")) << std::endl 
              << "hourly rate: $" << getHourlyRate() << std::endl;
}

int main(){
    try{
        std::cout << "construct Employee with idNumber = -1" << std::endl;
        Employee e1("John", -1, 7, 4, 2019);
        e1.printEmployeeInfo();
    } catch(EmployeeException *e){
        std::cout << e->what() << std::endl;
    }

    try{
        std::cout << "construct ProductionWorker with shift = 0" << std::endl;
        ProductionWorker pw1("Richard", 2, 7, 4, 2019, 0, 20.25);
        pw1.printProductionWorkerInfo();
    } catch(EmployeeException *e){
        std::cout << e->what() << std::endl;
    }

    try{
        std::cout << "construct ProductionWorker with hourlyRate = -1" << std::endl;
        ProductionWorker pw1("Richard", 2, 7, 4, 2019, 2, -1);
        pw1.printProductionWorkerInfo();
    } catch(EmployeeException *e){
        std::cout << e->what() << std::endl;
    }

    try{
        std::cout << "construct Employee with idNumber = 1" << std::endl;
        Employee e1("John", 1, 7, 4, 2019);
        e1.printEmployeeInfo();
    } catch(EmployeeException *e){
        std::cout << e->what() << std::endl;
    }

    try{
        std::cout << "construct ProductionWorker with shift= 2 and hourlyRate = 20.25" << std::endl;
        ProductionWorker pw1("Richard", 2, 7, 4, 2019, 2, 20.25);
        pw1.printProductionWorkerInfo();
    } catch(EmployeeException *e){
        std::cout << e->what() << std::endl;
    }
}