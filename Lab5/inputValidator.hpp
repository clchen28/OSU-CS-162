/******************************************************************************
** Program name: inputValidator.hpp
** Author: Charles Chen
** Date: 01/15/2017
** Description:
Function prototypes for inputValidator functions.
******************************************************************************/

#include <functional>
#include <string>

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

void inputValidator(int &input, std::function<bool (int &input)> func,
    std::string prompt, std::string errorMsg);
void inputValidator(int &input, std::string prompt, std::string errorMsg);
void inputValidator(float &input, std::function<bool (float &input)> func,
    std::string prompt, std::string errorMsg);
void inputValidator(int &input, int value1, int value2,
    std::function<bool (int &input, int value1, int value2)> func,
    std::string prompt, std::string errorMsg);
void inputValidator(std::string &input,
    std::function<bool (std::string &input)> func, std::string prompt,
    std::string errorMsg);

#endif