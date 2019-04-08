#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.cc"
#include <string>

class ProductionWorker : public Employee {
    private:
    int shift;
    double hourlyRate;

    public:
    ProductionWorker(std::string, int, int, int, int, int, double);
    void setShift(int);
    int getShift() const;
    void setHourlyRate(double);
    double getHourlyRate() const;
    void printProductionWorkerInfo();
};

#endif
