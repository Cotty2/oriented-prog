#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include <string>

bool letters(const std::string& word) {
    if (word.size() < 2) {
        return false;
    }
    unsigned char b1 = static_cast<unsigned char>(word[0]);
    unsigned char b2 = static_cast<unsigned char>(word[1]);

    if (b1 != 0xD0) {
        return false;
    }
    return (b2 == 0x81) || (b2 >= 0x90 && b2 <= 0xAF);
}


int main() {
    std::ifstream file("test.txt");
    assert(file && "Не удалось открыть файл");

    std::string line;
    std::getline(file, line);
    assert(line == "Список студентов" && "Неправильный заголовок файла");

    int lineno = 1;
    while (std::getline(file, line)) {
        ++lineno;
        std::istringstream iss(line);
        int num;
        char dot;
        iss >> num >> dot;
        assert(dot == '.' && ("Строка " + std::to_string(lineno) + ": отсутствует номер с точкой").c_str());

        std::string surname, name, patronymic, year_str, city;
        iss >> surname >> name >> patronymic >> year_str >> city;
        assert(!city.empty() && iss.eof() && ("Строка " + std::to_string(lineno) + ": не 5 групп символов").c_str());

        assert(letters(surname) && ("Строка " + std::to_string(lineno) + ": фамилия не с большой буквы").c_str());
        assert(letters(name) && ("Строка " + std::to_string(lineno) + ": имя не с большой буквы").c_str());
        assert(letters(patronymic) && ("Строка " + std::to_string(lineno) + ": отчество не с большой буквы").c_str());
        assert(letters(city) && ("Строка " + std::to_string(lineno) + ": город не с большой буквы").c_str());

        int year = std::stoi(year_str);
        assert(year >= 1950 && year <= 2010 && ("Строка " + std::to_string(lineno) + ": неверный год").c_str());
    }

    std::cout << "\nФайл корректен\n\n";
    return 0;
}
