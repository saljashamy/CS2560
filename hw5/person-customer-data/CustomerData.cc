#include <string>
#include "PersonData.cc"

class CustomerData : public PersonData{
private:
    int customerNumber;
    bool mailingList;
public:
    CustomerData(std::string f, std::string l, std::string a, std::string c, std::string s, std::string z, std::string p, int cN, bool m)
        : PersonData(f, l, a, c, s, z, p), customerNumber(cN), mailingList(m){
    }
    const int &getCustomerNumber() const {
        return customerNumber;
    }

    void setCustomerNumber(const int customerNumber) {
        CustomerData::customerNumber = customerNumber;
    }

    const bool &getMailingList() const {
        return mailingList;
    }

    void setMailingList(const bool mailingList) {
        CustomerData::mailingList = mailingList;
    }
};