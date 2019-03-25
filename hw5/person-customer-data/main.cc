#include <iostream>
#include "CustomerData.cc"

int main(int argc, char **argv){
    CustomerData c("John", "Smith", "1234 Street Ave", "Springville", "CA", "12345", "(123)456-7890", 1, true);
    std::cout << "customer data" << std::endl;
    std::cout << "first name: " << c.getFirstName() << std::endl;
    std::cout << "last name: " << c.getLastName() << std::endl;
    std::cout << "address: " << c.getAddress() << std::endl;
    std::cout << "city: " << c.getCity() << std::endl;
    std::cout << "zipcode: " << c.getZip() << std::endl;
    std::cout << "state: " << c.getState() << std::endl;
    std::cout << "customer number: " << c.getCustomerNumber() << std::endl;
    std::cout << "mailing list: " << ((c.getMailingList())?("Yes"):("No")) << std::endl;
    return 0;
}