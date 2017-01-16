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
#include "Ant.hpp"
#include "inputValidator.hpp"

/*
printMenu takes in row/col/step count, starting row and column indices,
starting direction, and displays this information in a menu format
*/
void printMenu(int rows, int cols, int steps, int startingRow, int startingCol,
    std::string startingDir)
{
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Number of board rows: " << rows << std::endl;
    std::cout << "2. Number of board columns: " << cols << std::endl;
    std::cout << "3. Number of steps: " << steps << std::endl;
    std::cout << "4. Starting row of ant: " << startingRow << std::endl;
    std::cout << "5. Starting col of ant: " << startingCol << std::endl;
    std::cout << "6. Randomize the starting position of ant" << std::endl;
    std::cout << "7. Starting direction of ant: " << startingDir << std::endl;
    std::cout << "8. Start simulation" << std::endl;
    return;
}

/*
menu is a function that is intended to provide a starting point for
the Langton's Ant simulation. It provides various default values for
row/col/step count, ant starting location, and ant starting direction.
It prints a menu with the current starting settings, and allows the user
to change any of these initial conditions.

The return type is an Ant object. When the user is done, it
initializes the simulation with the given initial conditions and
executes the simulation for the specified number of step counts, returning the
object with these properties.
*/
Ant menu()
{
    // Initializes default initial conditions
    int rows = 10;
    int cols = 10;
    int steps = 10;
    int startingRow = 1;
    int startingCol = 1;
    std::string startingDir = "up";

    int selection = -1;

    // These lambda functions are used for the input validation function later
    auto inputPositive = [](int input) -> bool {return input >= 1;};
    auto inputBetweenTwoValues = [](int input, int value1, int value2) -> bool
                    {
                        return (input >= value1) && (input <= value2);
                    };

    while (selection != 8)
    {
        printMenu(rows, cols, steps, startingRow, startingCol, startingDir);
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');
        
        // Selects submenu item
        switch (selection)
        {
            case 1:
            inputValidator(rows, inputPositive, "Enter number of board rows",
                "Must enter a positive integer number of rows");
            break;

            case 2:
            inputValidator(cols, inputPositive, "Enter number of board cols",
                "Must enter a positive integer number of cols");
            break;

            case 3:
            inputValidator(steps, inputPositive, "Enter number of steps",
                "Must enter a positive integer number of steps");
            std::cout << "Enter number of steps" << std::endl;
            break;

            case 4:
            inputValidator(startingRow, 1, rows, inputBetweenTwoValues,
                "Enter starting row of ant",
                "Starting row of ant must be on the board\nStarting row can be a number from 1 to the number of rows, inclusive");
            break;

            case 5:
            inputValidator(startingCol, 1, cols, inputBetweenTwoValues,
                "Enter starting col of ant",
                "Starting col of ant must be on the board\nStarting col can be a number from 1 to the number of cols, inclusive");
            break;

            case 6:
            std::cout << "Randomizing location of ant..." << std::endl;
            startingRow = rand() % rows + 1;
            startingCol = rand() % cols + 1;
            break;

            case 7: 
            inputValidator(startingDir,
                [](std::string input) -> bool
                    {
                        return (input == "up") || (input == "down")
                            || (input == "left")
                            || (input == "right");
                    },
                "Enter starting direction of ant",
                "Starting direction of ant must be up, down, left, or right");
            std::cout << "Enter starting direction of ant" << std::endl;
            std::cout << "Starting direction of ant must be up, down, "
                    << "left, or right" << std::endl;
            break;

            case 8:
            std::cout << "Executing simulation..." << std::endl;
            break;

            default:
            std::cout << "Enter a valid menu item (1 through 8)" << std::endl;
        }
    }
    
    // Decrementing row and column by 1 to go from row/col coordinate to
    // matrix index
    startingRow -= 1;
    startingCol -= 1;

    // Create object with given parameters
    return Ant(rows, cols, steps, startingRow, startingCol, startingDir);
}
