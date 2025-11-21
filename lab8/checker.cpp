#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include <string>

bool letters(const std::string& word) {
    if ((unsigned char)word[0] == 0xD0 && word.size() >= 2) {
        unsigned char c = word[1];
        return (c >= 0x90 && c <= 0xAF); 
    }
    if ((unsigned char)word[0] == 0xD1 && word.size() >= 2) {
        unsigned char c = word[1];
        return c == 0x81; 
    }
    return false;
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
