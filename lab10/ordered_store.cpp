#include "ordered_store.h"
#include <iostream>
#include <stdexcept>

Person::Person() : name(""), age(0) {}
Person::Person(const std::string& n, int a) : name(n), age(a) {}
bool Person::operator<(const Person& other) const { return age < other.age; }
bool Person::operator<=(const Person& other) const { return age <= other.age; }
std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name << "(" << p.age << ")";
    return os;
}

template <typename T>
OrderedStore<T>::OrderedStore() : size(0) {}

template <typename T>
void OrderedStore<T>::add(const T& x)
{
    if (size < MAX)
    {
        data[size] = x;
        size++;
    }
}

template <typename T>
void OrderedStore<T>::del()
{
    if (size > 0)
    {
        size--;
    }
}

template <typename T>
void OrderedStore<T>::info() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void OrderedStore<T>::iterator::skipForward()
{
    if (!cont || index >= cont->size) return;

    if (index == 0) return;

    T lastValid = cont->data[0];
    int current = 1;
    while (current < index && current < cont->size)
    {
        if (!(cont->data[current] < lastValid))
            lastValid = cont->data[current];
        ++current;
    }

    while (index < cont->size)
    {
        if (index == 0)
            break;
        T candidate = cont->data[0];
        bool valid = true;
        for (int i = 1; i < index; ++i)
        {
            if (!(cont->data[i] < candidate))
                candidate = cont->data[i];
        }
        if (!(cont->data[index] < candidate))
            break;
        ++index;
    }
}

template <typename T>
void OrderedStore<T>::iterator::skipBackward()
{
    if (!cont || index <= 0) return;

    while (index > 0)
    {
        --index;
        if (index == 0) return;

        T candidate = cont->data[0];
        for (int i = 1; i < index; ++i)
        {
            if (!(cont->data[i] < candidate))
                candidate = cont->data[i];
        }
        if (!(cont->data[index] < candidate))
            return;
    }
}

template <typename T>
OrderedStore<T>::iterator::iterator() : cont(nullptr), index(0) {}

template <typename T>
OrderedStore<T>::iterator::iterator(const OrderedStore* c, int i) : cont(c), index(i)
{
    if (cont && index < cont->size)
    {
        if (index > 0)
        {
            T candidate = cont->data[0];
            for (int i = 1; i < index; ++i)
            {
                if (!(cont->data[i] < candidate))
                    candidate = cont->data[i];
            }
            if (cont->data[index] < candidate)
            {
                ++index;
                skipForward();
            }
        }
    }
}

template <typename T>
T& OrderedStore<T>::iterator::operator*()
{
    if (!cont) throw std::runtime_error("Invalid iterator");
    return const_cast<T&>(cont->data[index]);
}

template <typename T>
const T& OrderedStore<T>::iterator::operator*() const
{
    if (!cont) throw std::runtime_error("Invalid iterator");
    return cont->data[index];
}

template <typename T>
typename OrderedStore<T>::iterator& OrderedStore<T>::iterator::operator++()
{
    if (!cont) return *this;
    ++index;
    skipForward();
    return *this;
}

template <typename T>
typename OrderedStore<T>::iterator& OrderedStore<T>::iterator::operator--()
{
    if (!cont) return *this;
    skipBackward();
    return *this;
}

template <typename T>
bool OrderedStore<T>::iterator::operator==(const iterator& other) const
{
    return cont == other.cont && index == other.index;
}

template <typename T>
bool OrderedStore<T>::iterator::operator!=(const iterator& other) const
{
    return !(*this == other);
}

template <typename T>
typename OrderedStore<T>::iterator OrderedStore<T>::begin() const
{
    typename OrderedStore<T>::iterator it(this, 0);
    if (size > 0)
    {
        T candidate = data[0];
        for (int i = 1; i < size; ++i)
        {
            if (!(data[i] < candidate))
                candidate = data[i];
            else
                continue;
        }
    }
    return it;
}

template <typename T>
typename OrderedStore<T>::iterator OrderedStore<T>::end() const
{
    return iterator(this, size);
}

template class OrderedStore<int>;
template class OrderedStore<Person>;