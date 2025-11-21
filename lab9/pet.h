#ifndef PET_H
#define PET_H

#include <iostream>
#include <set>
#include <list>
#include <string>

class Pet
{
public:
    std::string name;
    std::string type; 

    Pet();
    Pet(std::string name, std::string type);
    void info() const;
    bool operator < (Pet b) const; 
};

std::set<Pet> getPetsOfType(std::list<Pet> listOfPet, std::string type);

#endif // PET_H