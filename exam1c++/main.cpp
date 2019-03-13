#include<iostream>
#include<string>
#include "DynamicArray.cpp"


using namespace std;

int main(){
    int n; 
    cout << "Size: ";
    cin >> n;
    DynamicArray *test = new DynamicArray(n);
    test->setFloat(124.168, 0);
    test->setFloat(-54.25, 1);
    test->setFloat(0,2);
    cout << test->getFloat(2) << endl;
    cout << test->highestValue() << endl;
    cout << test->lowestValue() << endl;

    return 0;

}