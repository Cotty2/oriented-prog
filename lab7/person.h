#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person
{
public:
    std::string name;
    int birthYear;
    Person();
    Person(std::string name, int birthYear);
    bool operator<(const Person& p) const;
    bool operator>(const Person& p) const;
    friend std::ostream& operator<<(std::ostream&, const Person&);
};

#endif // PERSON_H
