#include "DynamicArray.h"
#include <limits>

using namespace std;

DynamicArray::DynamicArray(int n){
    size = n;
    arr = new float[size];
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
}

DynamicArray::~DynamicArray(){
    delete [] arr;
}

void DynamicArray::setFloat(float value, int i){
    arr[i] = value;
}

float DynamicArray::getFloat(int i){
    return arr[i];
}

float DynamicArray::lowestValue(){
    float min = numeric_limits<float>::max();
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

float DynamicArray::highestValue(){
    float max = numeric_limits<float>::min();
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}