#include <string>

class PersonData{
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;
public:
    PersonData(std::string f, std::string l, std::string a, std::string c, std::string s, std::string z, std::string p)
        : firstName(f), lastName(l), address(a), city(c), state(s), zip(z), phone(p){
    }
    const std::string &getLastName() const {
        return lastName;
    }

    void setLastName(const std::string &lastName) {
        PersonData::lastName = lastName;
    }

    const std::string &getFirstName() const {
        return firstName;
    }

    void setFirstName(const std::string &firstName) {
        PersonData::firstName = firstName;
    }

    const std::string &getAddress() const {
        return address;
    }

    void setAddress(const std::string &address) {
        PersonData::address = address;
    }

    const std::string &getCity() const {
        return city;
    }

    void setCity(const std::string &city) {
        PersonData::city = city;
    }

    const std::string &getState() const {
        return state;
    }

    void setState(const std::string &state) {
        PersonData::state = state;
    }

    const std::string &getZip() const {
        return zip;
    }

    void setZip(const std::string &zip) {
        PersonData::zip = zip;
    }

    const std::string &getPhone() const {
        return phone;
    }

    void setPhone(const std::string &phone) {
        PersonData::phone = phone;
    }
};