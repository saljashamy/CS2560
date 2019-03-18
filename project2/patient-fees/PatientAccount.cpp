#ifndef PATIENTACCOUNT_CPP
#define PATIENTACCOUNT_CPP

#include <iostream>

class PatientAccount{
private:
    const double dailyRate = 500;
    int daysHospital;
public:
    double patientFees;
    PatientAccount(){};
    PatientAccount(int d): daysHospital(d){
        updateFees(daysHospital*dailyRate);
    }
    void updateFees(double fee){
        PatientAccount::patientFees = PatientAccount::patientFees + fee;
    }
};

#endif