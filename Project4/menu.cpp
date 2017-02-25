/******************************************************************************
** Program name: menu.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:
Implementation of menu-related functions
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>
#include "inputValidator.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Round.hpp"

/*
/*
menu is a function that is intended to provide a starting point for
the fantasy game. Allows the user to select creature types, and then to start
the game.
*/
void menu()
{
    std::string creature1Name = "Barbarian";
    std::string creature2Name = "Medusa";
    Creature* Creature1 = nullptr;
    Creature* Creature2 = nullptr;

    int selection = -1;
    int subSelection = -1;

    // These lambda functions are used for the input validation function later
    auto inputBetweenTwoValues = [](int input, int value1, int value2) -> bool
                {
                    return (input >= value1) && (input <= value2);
                };
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
            case -1:
                break;
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
                // Creates a new object for Creature 1+2 depending on user
                // input
                if (creature1Name == "Barbarian")
                {
                    Creature1 = new Barbarian;
                }
                else if (creature1Name == "Blue Men")
                {
                    Creature1 = new BlueMen;
                }
                else if (creature1Name == "Harry Potter")
                {
                    Creature1 = new HarryPotter;
                }
                else if (creature1Name == "Medusa")
                {
                    Creature1 = new Medusa;
                }
                else if (creature1Name == "Vampire")
                {
                    Creature1 = new Vampire;
                }

                if (creature2Name == "Barbarian")
                {
                    Creature2 = new Barbarian;
                }
                else if (creature2Name == "Blue Men")
                {
                    Creature2 = new BlueMen;
                }
                else if (creature2Name == "Harry Potter")
                {
                    Creature2 = new HarryPotter;
                }
                else if (creature2Name == "Medusa")
                {
                    Creature2 = new Medusa;
                }
                else if (creature2Name == "Vampire")
                {
                    Creature2 = new Vampire;
                }

                // Randomly selects the first character to attack
                if (randNum(2) == 2)
                {
                    playGame(Creature2, Creature1);
                }
                else
                {
                    playGame(Creature1, Creature2);
                }

                // Deallocate memory for characters when game is over
                delete Creature1;
                delete Creature2;
                Creature1 = nullptr;
                Creature2 = nullptr;

                std::cout << std::endl;

                // Submenu - allows user to exit, or play another game
                while (subSelection != 2 && subSelection != 1)
                {
                    printSubMenu();

                    std::cin >> subSelection;
                    // cin.clear will clear the error flag in cin if an invalid
                    // input is presented
                    std::cin.clear();
                    std::cin.ignore(100, '\n');

                    switch(subSelection)
                    {
                        case 1:
                            selection = -1;
                            break;
                        case 2:
                            selection = 4;
                            break;
                        default:
                            std::cout << "Enter a valid menu item ";
                            std::cout << "(1 or 2)" << std::endl;
                    }
                }
                subSelection = -1;
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
