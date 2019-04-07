#include <iostream>
#include "PrimeNumberGeneration.h"
#include <algorithm>
#include <math.h>

PrimeNumberGeneration::PrimeNumberGeneration(int n){
    PrimeNumberGeneration::numbers = new std::vector<int>();
    addNumbers(n);
    printPrimes();
}

void PrimeNumberGeneration::addNumbers(int n){
    for(int i = 2; i <= n; i++){
        PrimeNumberGeneration::numbers->push_back(i);
    }
}

void PrimeNumberGeneration::isPrime(int n){
    int sqrtN = (int) sqrt(n);
    for(int i = 2; i <= sqrtN; i++){
        if(n%i == 0){
            return;
        } 
    }
    std::cout << n << std::endl;
}

void PrimeNumberGeneration::printPrimes(){
    for_each(PrimeNumberGeneration::numbers->begin(), PrimeNumberGeneration::numbers->end(), isPrime);
}

int main(){
    PrimeNumberGeneration p(100);
    return 0;
}