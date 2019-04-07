#ifndef PRIMENUMBERGENERATION_H
#define PRIMENUMBERGENERATION_H

#include <vector>

class PrimeNumberGeneration{
    private:
    std::vector<int> *numbers;
    public:
    PrimeNumberGeneration(int);
    void addNumbers(int);
    void printPrimes();
    static void isPrime(int);
};

#endif