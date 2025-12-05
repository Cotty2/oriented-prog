#ifndef ORDERED_STORE_H
#define ORDERED_STORE_H

#include <iostream>
#include <string>

const int MAX = 100;

class Person
{
public:
    std::string name;
    int age;
    Person();
    Person(const std::string& n, int a);
    bool operator<(const Person& other) const;
    bool operator<=(const Person& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

template <typename T>
class OrderedStore
{
private:
    T data[MAX];
    int size;

public:
    OrderedStore();
    void add(const T& x);
    void del();
    void info() const;

    class iterator
    {
    private:
        const OrderedStore* cont;
        int index;

        void skipForward();
        void skipBackward();

    public:
        iterator();
        iterator(const OrderedStore* c, int i);
        T& operator*();
        const T& operator*() const;
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    };

    iterator begin() const;
    iterator end() const;
};

#endif