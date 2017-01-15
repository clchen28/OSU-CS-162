/******************************************************************************
** Program name: inputValidator.cpp
** Author: Charles Chen
** Date: 01/15/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include <functional>

void inputValidator(int &input, std::function<bool (int &input)> func, std::string prompt, std::string errorMsg)
{
    std::cout << prompt << std::endl;
    std::cin >> input;
    // for validator - could this be a pointer to a parameter?
    while (!func(input))
    {
        std::cout << errorMsg << std::endl;
        std::cin >> input;
    }
}


void inputValidator(std::string *input, bool validator, std::string errorMsg)
{
    // for validator - could this be a pointer to a parameter?
    while (!validator)
    {
        std::cout << errorMsg << std::endl;
        std::cin >> *input;
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