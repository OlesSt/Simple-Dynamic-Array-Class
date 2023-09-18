#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


#include <cstddef>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(size_t capacity);
    DynamicArray(DynamicArray const &d);

    void operator=(DynamicArray const &d);

    void add(int element);
    void insert(int element, int index);
    void print() const;

    int getCapacity() const;
    int getElement(int index) const;

private:
    int *m_data;
    int m_nextIndex;
    int m_capacity; // total size of the array
};

#endif // DYNAMICARRAY_H
