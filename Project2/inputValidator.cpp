/******************************************************************************
** Program name: inputValidator.cpp
** Author: Charles Chen
** Date: 01/28/2017
** Description:
Contains the inputValidator function, which is used to validate given inputs
based on whether or not they match a given criteria. The criteria is provided
as a lambda function. The input is provided as a pass-by-reference to the
parameter that the user is being prompted to enter. Prompt and error messages
strings are also provided. First, the prompt string is provided, and the user
is asked to provide an input. If the input passes the lambda function check,
then this input is stored. If the input fails the check, then the error message
is displayed, and the user is asked for another input.

This function is provided for various input types.
******************************************************************************/

#include <iostream>
#include <string>
#include <functional>

void inputValidator(int &input, std::function<bool (int &input)> func,
    std::string prompt, std::string errorMsg)
{
    // Prompts the user for input
    std::cout << prompt << std::endl;
    std::cin >> input;

    // Flushes keyboard buffer, in case an invalid input is received
    std::cin.clear();
    std::cin.ignore(100, '\n');

    // Uses lambda function to check if the input is valid. If it is not valid,
    // then prompt the user for the input again
    while (!func(input))
    {
        std::cout << errorMsg << std::endl;
        std::cout << prompt << std::endl;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}

void inputValidator(float &input, std::function<bool (float &input)> func,
    std::string prompt, std::string errorMsg)
{
    // Prompts the user for input
    std::cout << prompt << std::endl;
   // std::cin >> input;
    //std::cin.ignore(100, '\n');

    // Flushes keyboard buffer, in case an invalid input is received
    while (!(std::cin >> input) || !func(input))
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        input = -1;
        std::cout << errorMsg << std::endl;
        std::cout << prompt << std::endl;
    }
    std::cin.clear();

}

void inputValidator(int &input, int value1, int value2,
    std::function<bool (int &input, int value1, int value2)> func,
    std::string prompt, std::string errorMsg)
{
    std::cout << prompt << std::endl;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(100, '\n');
    while (!func(input, value1, value2))
    {
        std::cout << errorMsg << std::endl;
        std::cout << prompt << std::endl;
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
    std::getline(std::cin, input);
    while (!func(input))
    {
        std::cout << errorMsg << std::endl;
        std::cout << prompt << std::endl;
        std::getline(std::cin, input);
    }
}
