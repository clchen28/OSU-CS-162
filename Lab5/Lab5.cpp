/******************************************************************************
** Program name: Lab5.cpp
** Author: Charles Chen
** Date: 02/04/2017
** Description:
Lab5 contains three functions that demonstrate the use of recursion.
This program provides a menu interface, which can be used to call the three
functions: revStr (reverse a string), sumArr (sum elements of an array),
and triNum (find triangular number). The menu guides the user on appropriate
inputs needed to call these functions.

To compile:
make

To run:
./Lab5
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>
#include <algorithm>
#include "revStr.hpp"
#include "sumArr.hpp"
#include "triNum.hpp"
#include "inputValidator.hpp"

/*
printMenu
printMenu displays the available options of the menu
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
main
In previous programs, menu functionality was implemented in a separate
subroutine. This was not done for this program, as there is no separate
functionality required in main that is not encapsulated in the menu.
*/
int main()
{
    std::string str;
    int *arr = nullptr;
    int arrSize = 5;
    int arrNumOfInputs = 0;
    std::string arrInput = "-1";
    int triNumN;

    int selection = -1;

    // These lambda functions are used for the input validation function later
    auto intInputNonNeg = [](int input) -> bool {return input >= 0;};
    auto exitInput = [](std::string input) -> bool {return input == "e";};

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
                // Gets a string from the user, and reverses it
                std::cout << "Enter a string: ";
                std::getline(std::cin, str);
                std::cout << "Reversing string..." << std::endl;
                revStr(str);
            break;

            case 2:
                // Gets an array size from user, then asks user to populate the
                // array
                arr = new int[arrSize];

                do {
                    std::cout << "Enter an integer, or enter e to stop"; std::cout << std::endl;
                    inputValidator(arrInput, exitInput,
                    "Enter number " + std::to_string(arrNumOfInputs+1) + ": ",
                    "Only integer inputs are allowed");

                    if (arrNumOfInputs + 1 > arrSize)
                    {
                        arrSize *= 2;
                        int *tempArr = new int[arrSize];
                        for (int i = 0; i < arrNumOfInputs; i++)
                        {
                            tempArr[i] = arr[i];
                        }
                        delete [] arr;
                        arr = tempArr;
                    }

                    if (isAllDigit(arrInput))
                    {
                        arr[arrNumOfInputs] = std::stoi(arrInput);
                        arrNumOfInputs++;
                    }
                } while (arrInput != "e");

                std::cout << "Calculating sum of array... " << std::endl;
                std::cout << "Sum is " << sumArr(arr, arrNumOfInputs);
                std::cout << std::endl;

                delete [] arr;
                arr = nullptr;
                arrNumOfInputs = 0;
                arrSize = 5;
            break;

            case 3:
                // Asks user for an integer about which to calculate the
                // triangular number
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

    return 0;
}
