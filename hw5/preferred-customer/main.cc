#include <iostream>
#include "PreferredCustomer.cc"

int main(int argc, char **argv){
    try{
        PreferredCustomer c("John", "Smith", "1234 Street Ave", "Springville", "CA", "12345", "(123)456-7890", 1, true, -1000);
    }
    catch(PurchaseAmountException *e){ 
        std::cout << e->what() << std::endl;
    }
    try{
        PreferredCustomer c("John", "Smith", "1234 Street Ave", "Springville", "CA", "12345", "(123)456-7890", 1, true, 500);
        std::cout << "customer data" << std::endl;
        std::cout << "first name: " << c.getFirstName() << std::endl;
        std::cout << "last name: " << c.getLastName() << std::endl;
        std::cout << "address: " << c.getAddress() << std::endl;
        std::cout << "city: " << c.getCity() << std::endl;
        std::cout << "zipcode: " << c.getZip() << std::endl;
        std::cout << "state: " << c.getState() << std::endl;
        std::cout << "customer number: " << c.getCustomerNumber() << std::endl;
        std::cout << "mailing list: " << ((c.getMailingList())?("Yes"):("No")) << std::endl;
        std::cout << "purchase amount: $" << c.getPurchaseAmount() << std::endl;
        std::cout << "discount level: " << c.getDiscountLevel() << "%" << std::endl;
        c.setPurchaseAmount(1000);
        std::cout << "purchase amount: $" << c.getPurchaseAmount() << std::endl;
        std::cout << "discount level: " << c.getDiscountLevel() << "%" << std::endl;
        c.setPurchaseAmount(1500);
        std::cout << "purchase amount: $" << c.getPurchaseAmount() << std::endl;
        std::cout << "discount level: " << c.getDiscountLevel() << "%" << std::endl;
        c.setPurchaseAmount(2000);
        std::cout << "purchase amount: $" << c.getPurchaseAmount() << std::endl;
        std::cout << "discount level: " << c.getDiscountLevel() << "%" << std::endl;
    }
    catch(PurchaseAmountException *e){ 
        std::cout << e->what() << std::endl;
    }
    return 0;
}