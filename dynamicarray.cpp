#include "dynamicarray.h"
#include <iostream>

DynamicArray::DynamicArray()
{
    m_data = new int[5];
    m_nextIndex = 0;
    m_capacity = 5;
}

DynamicArray::DynamicArray(size_t capacity)
{
    m_data = new int[capacity];
    m_nextIndex = 0;
    m_capacity = capacity;

}

DynamicArray::DynamicArray(const DynamicArray &d)
{
    this->m_nextIndex = d.m_nextIndex;
    this->m_capacity = d.m_capacity;

    // Shallow copy
    //this->data = d.data;

    // Deep copy
    this->m_data = new int [d.m_capacity];
    for (size_t i{}; i < d.m_nextIndex; i++)
    {
        this->m_data[i] = d.m_data[i];
    }

}

void DynamicArray::operator=(const DynamicArray &d)
{
    this->m_nextIndex = d.m_nextIndex;
    this->m_capacity = d.m_capacity;
    this->m_data = new int [d.m_capacity];
    for (size_t i{}; i < d.m_nextIndex; i++)
    {
        this->m_data[i] = d.m_data[i];
    }
}

void DynamicArray::add(int element)
{
    if (m_nextIndex == m_capacity)
    {
        int *newData = new int[m_capacity * 2];
        for (int i {}; i < m_capacity; i++)
        {
            newData[i] = m_data[i];

        }
        delete []m_data;
        m_data = newData;
        m_capacity = m_capacity * 2;
    }
    else
    {
        m_data[m_nextIndex] = element;
        m_nextIndex++;
    }
}

void DynamicArray::insert(int element, int index)
{
    if (index < m_nextIndex)
    {
        m_data[index] = element;
    }
    else if (index == m_nextIndex)
    {
        add(element);
    }
    else {return;}
}

void DynamicArray::print() const
{
    for (int i{}; i < m_nextIndex; i++)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

int DynamicArray::getCapacity() const
{
    return m_capacity;
}

int DynamicArray::getElement(int index) const
{
    if (index >= 0 && index < m_nextIndex) {return m_data[index];}
    else {return -1;}
}
