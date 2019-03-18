#include <iostream>
#include "PatientAccount.cpp"
#include "Surgery.cpp"
#include "Pharmacy.cpp"

int main(){
    int days = 0;
    std::cout << "Patient Account" << std::endl;
    std::cout << "enter days in hospital: ";
    std::cin >> days;
    PatientAccount pa(days);
    std::cout << "hospital stay charge: $" << pa.patientFees << std::endl;

    std::cout << "\nadd surgery:" << std::endl;
    for(auto const &e : surgery.s){
        std::cout << "    " << e.first << std::endl;
    }
    std::string select = "";
    std::cin >> select;
    std::cout << "surgery charge: $" << surgery.s.at(select) << std::endl;
    surgery.addCharge(pa, surgery.s.at(select));

    std::cout << "\nadd pharmacy:" << std::endl;
    for(auto const &e : pharmacy.p){
        std::cout << "    " << e.first << std::endl;
    }
    select = "";
    std::cin >> select;
    std::cout << "pharmacy charge: $" << pharmacy.p.at(select) << std::endl;
    pharmacy.addCharge(pa, pharmacy.p.at(select));

    std::cout << "\ntotal cost: $" << pa.patientFees << std::endl;


    return 0;
}