#ifndef MYTEMPLATES
#define MYTEMPLATES

#include <iostream>
#include <type_traits>
#include "person.h"

const int MAXSIZE = 100;

template <class T>
class Container
{
private:
    T data[MAXSIZE];
    int size;
public:
    Container();
    void add(T x);
    void del();
    void info();
    void sort();
};

template <class T>
Container<T>::Container()
{
    size = 0;
}

template <class T>
void Container<T>::add(T x)
{
    if (size >= MAXSIZE)
    {
        std::cout << "массив переполнен.\n";
        return;
    }
    if (size == 0)
    {
        data[size++] = x;
        return;
    }
    T maxElem = data[0];
    for (int i = 1; i < size; ++i)
        if (data[i] > maxElem)
            maxElem = data[i];
    if (x > maxElem * 2)
    {
        std::cout << "элемент слишком большой.\n";
        return;
    }
    data[size++] = x;
}
template <>
void Container<Person>::add(Person x)
{
    if (size >= MAXSIZE)
    {
        std::cout << "массив переполнен\n";
        return;
    }
    if (size == 0)
    {
        data[size++] = x;
        return;
    }
    Person maxElem = data[0];
    for (int i = 1; i < size; ++i)
        if (data[i].birthYear > maxElem.birthYear)
            maxElem = data[i];
    if (x.birthYear > maxElem.birthYear * 2)
    {
        std::cout << "неправильная дата\n";
        return;
    }
    data[size++] = x;
}

template <class T>
void Container<T>::del()
{
    if (size <= 0)
    {
        std::cout << "массив пуст.\n";
        return;
    }
    size--;
}

template <class T>
void Container<T>::info()
{
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << data[i] << ", ";
    }
    if (size > 0)
    {
        std::cout << data[size - 1];
    }
    std::cout << "\n";
}

template <>
void Container<Person>::info()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i].name << " " << data[i].birthYear;
        if (i != size - 1) std::cout << ", ";
    }
    std::cout << "\n";
}

template <class T>
void Container<T>::sort()
{
    T element;
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if (data[j+1] < data[j])
            {
                element = data[j];
                data[j] = data[j+1];
                data[j+1] = element;
            }
        }
    }
}

template <>
void Container<Person>::sort()
{
    Person element;
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if (data[j+1].birthYear < data[j].birthYear)
            {
                element = data[j];
                data[j] = data[j+1];
                data[j+1] = element;
            }
        }
    }
}

#endif // MYTEMPLATES
