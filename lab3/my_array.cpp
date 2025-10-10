#include "my_array.h"
#include <iostream>

MyArray::MyArray()
{
    size = 0;
}

void MyArray::add(float x)
{
    data[size] = x;
    size++;
}

void MyArray::del()
{
    size--;
}

void MyArray::info()
{
    for(int i=0; i<size; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << "\n";
}

MyArray MyArray::operator+(MyArray arr2)
{
    MyArray result;
    for(int i =0; i <size; i++)
    {
        result.add(data[i]);

    }
    for( int i =0; i < arr2.size; i++)
    {
        result.add(arr2.data[i]);
    }
    return result;
}

bool MyArray::operator%( float x)
{
    MyArray result;
    for(int i = 0; i < size; i++)
    {
        if (data[i] == x) {
            return true; 
        }
    }
    return false; 
}
void MyArray::operator++()
{
    for(int i = 0; i < size; i++)
    {
        data[i]++;
    }
}

void MyArray::operator++(int)
{
    for(int i = 0; i < size; i++)
    {
        data[i]++;
    }
}

void MyArray::operator--()
{
    for(int i = 0; i < size; i++)
    {
        data[i]--;
    }
}

void MyArray::operator--(int)
{
    for(int i = 0; i < size; i++)
    {
        data[i]--;
    }
}