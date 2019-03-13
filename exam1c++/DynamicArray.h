#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray{
    private:
    float* arr;
    int size;

    public:
    DynamicArray(int);
    ~DynamicArray();
    void setFloat(float, int);
    float getFloat(int);
    float highestValue();
    float lowestValue();
};

#endif