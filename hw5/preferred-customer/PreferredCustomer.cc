#include <string>
#include <utility>
#include "../person-customer-data/CustomerData.cc"
#include "PurchaseAmountException.cc"

class PreferredCustomer : public CustomerData, public std::exception{
private:
    const std::pair<double, double> dl1;
    const std::pair<double, double> dl2;
    const std::pair<double, double> dl3;
    const std::pair<double, double> dl4;
    double purchaseAmount;
    double discountLevel;
public:
    PreferredCustomer(std::string f, std::string l, std::string a, std::string c, std::string s, std::string z, std::string p, int cN, bool m, double pA)
        : CustomerData(f, l, a, c, s, z, p, cN, m), dl1(500, 5), dl2(1000, 6), dl3(1500, 7), dl4(2000, 10){
        setPurchaseAmount(pA);
    }
    const double &getPurchaseAmount() const {
        return purchaseAmount;
    }

    void setPurchaseAmount(const double purchaseAmount) {
        if(purchaseAmount < 0){
            throw new PurchaseAmountException("InvalidPurchaseAmount");
        }
        PreferredCustomer::purchaseAmount = purchaseAmount;
        if(purchaseAmount < std::get<0>(dl1)){
            setDiscountLevel(0);
        }
        else if(purchaseAmount < std::get<0>(dl2)){
            setDiscountLevel(std::get<1>(dl1));
        }
        else if(purchaseAmount < std::get<0>(dl3)){
            setDiscountLevel(std::get<1>(dl2));
        }
        else if(purchaseAmount < std::get<0>(dl4)){
            setDiscountLevel(std::get<1>(dl3));
        }
        else{
            setDiscountLevel(std::get<1>(dl4));
        }
    }
    const double &getDiscountLevel() const {
        return discountLevel;
    }

    void setDiscountLevel(const double discountLevel) {
        PreferredCustomer::discountLevel = discountLevel;
    }
};