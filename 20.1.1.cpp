#include <iostream>
#include <fstream>
#include <sstream>

int input_check(std::string a)
{
    int b = 0;

    try
    {
        b = stoi(a);
    }
    catch (const std::exception&)
    {
        b = -1;
    }
    return b;
}


int main()
{
    std::stringstream line;
    std::string name, surname, day, month, year, money;
    std::cout << "input name, surname, date of payment and amount of money\n";
    std::cout << "name: ";
    std::cin >> name;
    std::cout << "surname: ";
    std::cin >> surname;
    std::cout << "money: ";
    std::cin >> money;
    std::cout << "date (day, month, year)";
    std::cout << "day";
    std::cin >> day;
    std::cout << "month";
    std::cin >> month;
    std::cout << "year";
    std::cin >> year;
    if (input_check(money) < 0 || input_check(day) < 1 || input_check(day) > 31 || input_check(month) < 1 ||
        input_check(month) > 12 || input_check(year) < 1900 || input_check(year) > 2022)
    {
        std::cout << "invalid input";
    }
    else
    {
        std::ofstream file("statement.txt", std::ios::app);
        if (!file.is_open())
        {
            std::cout << "wrong file path";
        }
        else
        {
            file << name << ' ' << surname << ' ' << money << ' ' << day << '.' << month << '.' << year;
        }
    }
}
