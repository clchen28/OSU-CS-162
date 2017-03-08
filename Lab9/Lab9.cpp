/******************************************************************************
** Program name: Lab9.cpp
** Author: Charles Chen
** Date: 03/07/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>
#include <queue>
#include "menu.hpp"
#include "Queue.hpp"
#include "inputValidator.hpp"

/*
printMenu displays the available options
*/
void printMenu()
{
    std::cout << "Select a menu option: " << std::endl;
    std::cout << "1. Test the buffer" << std::endl;
    std::cout << "2. Create a palindrome" << std::endl;
    std::cout << "3. Exit program" << std::endl;
}

/*
menu is a function that is intended to provide a starting point for
the fantasy game. Allows the user to select creature types, and then to start
the game.
*/
int main()
{
    int rounds = -1;
    int insertProb = -1;
    int removeProb = -1;
    std::queue<int> buffer;

    int selection = -1;

    // These lambda functions are used for the input validation function later
    auto validPercent = [](int input) -> bool
                {
                    return (input >= 0) && (input <= 100);
                };
    auto intPositive = [](int input) -> bool
                {
                    return (input >= 1);
                };

    while (selection != 3)
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
                inputValidator(rounds, intPositive,
                    "Enter number of rounds to run",
                    "Must be a positive integer");
                inputValidator(insertProb, validPercent,
                    "Enter percentage from 0 to 100 that number will be inserted into queue",
                    "Must be between 0 and 100 inclusive");
                inputValidator(removeProb, validPercent,
                    "Enter percentage from 0 to 100 that number will be removed from queue",
                    "Must be between 0 and 100 inclusive");

                buffer = {};
                for (int i = 0; i < 10; i++)
                {
                    buffer.push(randNum(100));
                }

                runSimulation(buffer, rounds, insertProb, removeProb);

                rounds = -1;
                insertProb = -1;
                removeProb = -1;

                std::cout << std::endl;
            break;

            case 2:
            break;

            case 3:
                std::cout << "Exiting..." << std::endl;
            break;

            default:
                std::cout << "Enter a valid menu item (1 through 3)" << std::endl;
        }
    }

    return 0;
}
