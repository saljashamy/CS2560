#include "PatientAccount.cpp"
#include <map>

class Pharmacy{
public:
    Pharmacy(){};
    std::map<std::string, double> p = {{"acyclovir", 69.17}, {"diclofenac", 8.87}, {"ibuprofen", 306.6}, {"naproxen", 143.62}, {"oxazepam", 80.60}};
    void addCharge(PatientAccount & pa, double medicineCost){
        pa.updateFees(medicineCost);
    }
}pharmacy;