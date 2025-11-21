#include "pet.h"

Pet::Pet()
{
    name = "NO NAME";
    type = "NO TYPE";
}

Pet::Pet(std::string name, std::string type)
{
    this->name = name;
    this->type = type;
}

void Pet::info() const
{
    std::cout << name << " (" << type << ")" << std::endl;
}

bool Pet::operator < (Pet b) const
{
    if (type != b.type)
    {
        return type < b.type;
    }
    else
    {
        return name < b.name;
    }
}

std::set<Pet> getPetsOfType(std::list<Pet> listOfPet, std::string type)
{
    std::set<Pet> petSet;

    for (std::list<Pet>::iterator it = listOfPet.begin(); it != listOfPet.end(); it++)
    {
        if (it->type == type)
        {
            petSet.insert(*it);
        }
    }

    return petSet;
}