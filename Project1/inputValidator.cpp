/******************************************************************************
** Program name: inputValidator.cpp
** Author: Charles Chen
** Date: 01/15/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include <functional>

void inputValidator(int &input, std::function<bool (int &input)> func,
    std::string prompt, std::string errorMsg)
{
    std::cout << prompt << std::endl;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(100, '\n');
    while (!func(input))
    {
        std::cout << errorMsg << std::endl;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}


void inputValidator(std::string &input,
    std::function<bool (std::string &input)> func, std::string prompt,
    std::string errorMsg)
{
    std::cout << prompt << std::endl;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(100, '\n');
    while (!func(input))
    {
        std::cout << errorMsg << std::endl;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}


int main()
{
    std::cout << "Starting code" << std::endl;
    int i;
    auto func1 = [](int input) -> bool {return input > 0;};
    inputValidator(i, func1, "Enter i", "Try again");
    std::cout << "i is " << i << std::endl;
    return 0;
    
}