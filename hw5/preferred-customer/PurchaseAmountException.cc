#include <exception>

class PurchaseAmountException: public std::exception{

    const char * msg; 
    PurchaseAmountException() {};    

public: 
    explicit PurchaseAmountException(const char * s) throw() : msg(s) { } 
    virtual const char * what() const throw() { return msg; } 
};

