/******************************************************************************
** Program name: menu.cpp
** Author: Charles Chen
** Date: 02/07/2017
** Description:
Implementation of menu-related functions
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>
#include "inputValidator.hpp"
#include "Creature.hpp"

/*
printMenu displays the available options
*/
void printMenu(std::string creature1Name, std::string creature2Name)
{
    std::cout << "Select a menu option: " << std::endl;
    std::cout << "First creature: " << creature1Name << std::endl;
    std::cout << "Second creature: " << creature2Name << std::endl;
    std::cout << "1. Change first creature" << std::endl;
    std::cout << "2. Change second creature" << std::endl;
    std::cout << "3. Start the fight!" << std::endl;
    std::cout << "4. Exit program" << std::endl;
}

/*
menu is a function that is intended to provide a starting point for
the fantasy game
*/
void menu()
{
    std::string creature1Name = "Barbarian";
    std::string creature2Name = "Medusa";

    int selection = -1;

    // These lambda functions are used for the input validation function later
    auto inputBetweenTwoValues = [](int input, int value1, int value2) -> bool
                {
                    return (input >= value1) && (input <= value2);
                };
    auto intInputPositive = [](int input) -> bool {return input >= 1;};
    auto intAbove18 = [](int input) -> bool {return input >= 18;};
    auto notEmptyString = [](std::string input) -> bool {return input != "";};
    auto allowedCreatureTypes = [](std::string input) -> bool
                {
                    return (input == "Barbarian")
                        || (input == "Blue Men")
                        || (input == "Harry Potter")
                        || (input == "Medusa")
                        || (input == "Vampire");
                };

    while (selection != 4)
    {
        printMenu(creature1Name, creature2Name);
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');

        // Selects submenu item
        switch (selection)
        {
            case 1:
                inputValidator(creature1Name, allowedCreatureTypes,
                    "Enter Creature 1 type. May be Barbarian, Blue Men, Harry Potter, Medusa, or Vampire",
                    "Invalid creature type");
                std::cout << std::endl;
            break;

            case 2:
            inputValidator(creature2Name, allowedCreatureTypes,
                "Enter Creature 2 type. May be Barbarian, Blue Men, Harry Potter, Medusa, or Vampire",
                "Invalid creature type");
                std::cout << std::endl;
            break;

            case 3:
                //
                std::cout << std::endl;
            break;

            case 4:
                std::cout << "Exiting..." << std::endl;
            break;

            default:
                std::cout << "Enter a valid menu item (1 through 3)" << std::endl;
        }
    }

    return;
}
