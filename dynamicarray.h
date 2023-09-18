#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


#include <cstddef>
class DynamicArray
{
public:
    DynamicArray();

private:
    int *data;
    size_t size;
};

#endif // DYNAMICARRAY_H
