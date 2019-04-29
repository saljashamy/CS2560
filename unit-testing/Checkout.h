#ifndef UNIT_TESTING_CHECKOUT_H
#define UNIT_TESTING_CHECKOUT_H

#include <string>
#include <map>

class Checkout {
public:
    Checkout();
    virtual ~Checkout();

    void addItemPrice(std::string item, int price);
    void addItem(std::string item);
    void addDiscount(std::string item, int nbrOfItem, int discountPrice);
    int calculateTotal();
protected:
    struct Discount{
        int nbrOfItems;
        int discountPrice;
    };
    std::map<std::string, int> prices;
    std::map<std::string, Discount> discounts;
    std::map<std::string, int> items;
    int total;

    void calculateItem(std::string item, int itemCnt );
    void calculateDiscount(std::string item, int itemCnt, Discount discount);
};


#endif
