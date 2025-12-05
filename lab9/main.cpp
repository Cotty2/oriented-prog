/*
 * Определить класс «Книга», данные которого включают название книги, автора и число
 * страниц. Написать функцию, формирующую по заданному списку (шаблонный класс list)
 * объектов класса «Книга» множество (шаблонный класс set) из элементов списка.
 * В множество включаются книги определенного автора
 */


#include <iostream>
#include "pet.h"

using namespace std;

int main()
{
    Pet p1;
    Pet p2("Барбос", "Собака");
    Pet p3("Барбос", "Собака");
    Pet p4("Пушок", "Кошка");
    Pet p5("Чики", "Хомяк");

    std::list<Pet> petList;
    std::set<Pet> petSet;

    petList.push_back(p1);
    petList.push_back(p2);
    petList.push_back(p3);
    petList.push_back(p4);
    petList.push_back(p5);

    for (std::list<Pet>::iterator it = petList.begin(); it != petList.end(); it++)
    {
        it->info();
    }

    std::cout << "----------------" << "\n";

    petSet = getPetsOfType(petList, "Собака");

    for (std::set<Pet>::iterator it = petSet.begin(); it != petSet.end(); it++)
    {
        it->info();
    }

    return 0;
}