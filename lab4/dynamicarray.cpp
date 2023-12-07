#include <iostream>

struct DynamicArray
{
    int *value;
    int arrLength = 0;
    int arrCapacity = 0;

    DynamicArray(int);

    void coutValues();
};