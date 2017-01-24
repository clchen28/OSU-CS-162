/******************************************************************************
** Program name: menu.cpp
** Author: Charles Chen
** Date: 01/23/2017
** Description:
Implementation of menu-related functions
******************************************************************************/

#include <iostream>
#include <string>
#include <functional>
#include "inputValidator.hpp"

/*
printMenu takes the number of rounts to play, Player 1 and Player 2's die
type and size, and prints this information in a menu format.
*/
void printMenu(int rounds, std::string die1Type, int die1Sides,
    std::string die2Type, int die2Sides)
{
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Number of rounds: " << rounds << std::endl;
    std::cout << "2. Player 1's Die Type: " << die1Type << std::endl;
    std::cout << "3. Sides for Player 1's die: " << die1Sides << std::endl;
    std::cout << "4. Player 2's Die Type: " << die2Type << std::endl;
    std::cout << "5. Sides for Player 2's die: " << die2Sides << std::endl;
    std::cout << "6. Play!" << std::endl;
    return;
}

/*
menu is a function that is intended to provide a starting point for
the Die rolling game. It provides various default values for the number of
rounds to play, each Player's die type, and the number of sides for each
Player's die, as well as utilities for changing these options.

The return type is a game object. When the user is done, it
initializes the game with the given initial conditions, returning the object
with these properties.
*/
void menu()
{
    // Initializes default initial conditions
    int rounds = 5;
    std::string die1Type = "normal";
    int die1Sides = 6;
    std::string die2Type = "loaded";
    int die2Sides = 8;

    int selection = -1;

    // These lambda functions are used for the input validation function later
    auto inputPositive = [](int input) -> bool {return input >= 1;};
    auto dieType = [](std::string input) -> bool
    {
        return((input == "normal") || (input == "loaded"));
    };


    while (selection != 6)
    {
        printMenu(rounds, die1Type, die1Sides, die2Type, die2Sides);
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');
        
        // Selects submenu item
        switch (selection)
        {
            case 1:
            inputValidator(rounds, inputPositive, "Enter number of rounds",
                "Must enter a positive integer number of rounds");
            break;

            case 2:
            inputValidator(die1Type, dieType,
                "Enter Player 1's die type",
                "Die types must be normal or loaded");
            break;

            case 3:
            inputValidator(die1Sides, inputPositive,
                "Enter number of sides for Player 1's die",
                "Must enter a positive integer number of sides");
            std::cout << "Enter number of steps" << std::endl;
            break;

            case 4:
            inputValidator(die2Type, dieType,
                "Enter Player 2's die type",
                "Die types must be normal or loaded");
            break;

            case 5:
            inputValidator(die2Sides, inputPositive,
                "Enter number of sides for Player 2's die",
                "Must enter a positive integer number of sides");
            std::cout << "Enter number of steps" << std::endl;
            break;

            case 6:
            std::cout << "Playing..." << std::endl;
            break;

            default:
            std::cout << "Enter a valid menu item (1 through 6)" << std::endl;
        }
    }
    
    // Create object with given parameters
    // return Game(rounds, die1Type, die1Sides, die2Type, die2Sides);
}
