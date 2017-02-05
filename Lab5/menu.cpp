/******************************************************************************
** Program name: menu.cpp
** Author: Charles Chen
** Date: 01/13/2017
** Description:
Implementation of menu-related functions
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>
#include "inputValidator.hpp"
#include "revStr.hpp"
#include "sumArr.hpp"
#include "triNum.hpp"

/*
printMenu displays the available options
*/
void printMenu()
{
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Run revStr - reverse a string function" << std::endl;
    std::cout << "2. Run sumArr - sum of array function" << std::endl;
    std::cout << "3. Run triNum - triangular number function" << std::endl;
    std::cout << "4. Exit program" << std::endl;
    return;
}

/*
menu is a function that is intended to provide a starting point for
the University

It takes in an initialized University object as reference, and provides an API
for accessing its methods. Specifically, it allows the user to add People and
Buildings to the University, print the details of Buildings and People, and
choose a Person to do work. These tasks are all performed through University
member methods.
*/
void menu()
{
    std::string str;
    int *arr = nullptr;
    int arrSize = -1;
    int arrInput = -1;
    int triNumN;

    int selection = -1;
    
    // These lambda functions are used for the input validation function later
    auto intInputPositive = [](int input) -> bool {return input >= 1;};
    auto intInputNonNeg = [](int input) -> bool {return input >= 0;};

    while (selection != 4)
    {
        printMenu();
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');
        
        // Selects submenu item
        switch (selection)
        {
            case 1:
                std::cout << "Enter a string: ";
                std::getline(std::cin, str);
                std::cout << "Reversing string..." << std::endl;
                revStr(str);
            break;

            case 2:
                inputValidator(arrSize, intInputPositive,
                    "Enter the size of the array",
                    "Size of array must be a positive integer");
                arr = new int[arrSize];
                for (int i = 0; i < arrSize; i++)
                {
                    inputValidator(arrInput,
                        "Enter number " + std::to_string(i+1) + ": ",
                        "Only integer inputs are allowed");
                    arr[i] = arrInput;
                }

                std::cout << "Calculating sum of array... " << std::endl;
                std::cout << "Sum is " << sumArr(arr, arrSize) << std::endl;

                delete [] arr;
                arr = nullptr;
            break;

            case 3:
                std::cout << "triNum will calculate the triangle number for ";
                std::cout << "integer N" << std::endl;
                inputValidator(triNumN, intInputNonNeg,
                    "Enter a non-negative integer for N",
                    "N must be zero or positive");
                std::cout << "Calculating triangular number for N..." << std::endl;
                std::cout << "Triangular number is ";
                std::cout << triNum(triNumN) << std::endl;
                
            break;

            case 4:
                std::cout << "Exiting..." << std::endl;
            break;

            default:
                std::cout << "Enter a valid menu item (1 through 4)" << std::endl;
        }
    }

    return;
}
