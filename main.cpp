#include <QCoreApplication>
#include <iostream>

#include "dynamicarray.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // TEST CREATE ARRAY
    std::cout << "===== TEST CREATE ARRAY =====" << std::endl;
    DynamicArray array;
    for (size_t i {}; i < 10; ++i)
    {
        array.add(i);
    }
    std::cout << "Array is - ";
    array.print();
    std::cout << "Capacity - " << array.getCapacity() << std::endl;

    // TEST ADD() METHOD
    std::cout << "\n===== TEST ADD() METHOD =====" << std::endl;
    array.add(30);
    array.add(40);
    array.add(50);
    array.print();


    // TEST INSERT() METHOD AND GET_ELEMENT() METHOD
    std::cout << "\n===== TEST INSERT() METHOD AND GET_ELEMENT() METHOD =====" << std::endl;
    array.insert(50, 3);
    array.insert(10, 8);
    array.print();
    std::cout << "Element[3] - " << array.getElement(3) << std::endl;

    // TEST COPY CONSTRUCTOR
    std::cout << "\n===== TEST COPY CONSTRUCTOR =====" << std::endl;
    DynamicArray array2;
    for (size_t i{}; i < 8; ++i)
    {
        array2.add(i * 2);
    }
    std::cout << "Array2 is - ";
    array2.print();
    std::cout << "Capacity - " << array2.getCapacity() << std::endl;
    DynamicArray array3(array2);
    array3.print();

    // TEST OPERATOR= OVERLOAD
    std::cout << "\n===== TEST OPERATOR= OVERLOAD =====" << std::endl;
    array2 = array3;
    array2.print();

    // TEST PARAMETRIC CONSTRUCTOR
    std::cout << "\n===== TEST PARAMETRIC CONSTRUCTOR =====" << std::endl;
    DynamicArray array4(10);
    std::cout << "Capacity of array 4 is - " << array4.getCapacity() << std::endl;

    return a.exec();
}
