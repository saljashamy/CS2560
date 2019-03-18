#include "PatientAccount.cpp"
#include <map>

class Surgery{
public:
    std::map<std::string, double> s = {{"blepharoplasty", 2828}, {"csection", 6700}, {"liposuction",  2884}, {"rhinoplasty", 4306}, {"tonsillectomy", 5442}};
    void addCharge(PatientAccount & pa, double surgeryCost){
        pa.updateFees(surgeryCost);
    }
}surgery;