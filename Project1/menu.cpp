/******************************************************************************
** Program name: menu.cpp
** Author: Charles Chen
** Date: 01/13/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Ant.hpp"

/*
void inputValidator(int *input, bool validator, std::string errorMsg)
{
    // for validator - could this be a pointer to a parameter?
    while (!validator)
    {
        std::cout << errorMsg << std::endl;
        std::cin >> *input;
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
    std::cout << "6. Starting direction of ant: " << startingDir << std::endl;
    std::cout << "7. Start simulation" << std::endl;
    return;
}

Ant menu()
{
    int rows = 10;
    int *rowsPtr = &rows;

    int cols = 10;
    int *colsPtr = &cols;

    int steps = 10;
    int *stepsPtr = &steps;

    int startingRow = 1;
    int *startingRowPtr = &startingRow;

    int startingCol = 1;
    int *startingColPtr = &startingCol;

    std::string startingDir = "up";
    std::string *startingDirPtr = &startingDir;

    int selection = -1;
    while (selection != 7)
    {
        printMenu(rows, cols, steps, startingRow, startingCol, startingDir);
        std::cin >> selection;
        switch (selection)
        {
            case 1:
            std::cout << "Enter number of board rows" << std::endl;
            std::cin >> rows;
            while (rows < 1)
            {
                std::cout << "Must enter a positive integer number of rows"
                    << std::endl;
                std::cout << "Enter number of board rows" << std::endl;
                std::cin >> rows;
            }
            break;

            case 2:
            std::cout << "Enter number of board cols" << std::endl;
            std::cin >> cols;
            while (cols < 1)
            {
                std::cout << "Must enter a positive integer number of cols"
                    << std::endl;
                std::cout << "Enter number of board cols" << std::endl;
                std::cin >> cols;
            }
            break;

            case 3:
            std::cout << "Enter number of steps" << std::endl;
            std::cin >> steps;
            while (steps < 1)
            {
                std::cout << "Must enter a positive integer number of steps"
                    << std::endl;
                std::cout << "Enter number of steps" << std::endl;
                std::cin >> steps;
            }
            break;

            case 4:
            std::cout << "Enter starting row of ant" << std::endl;
            std::cin >> startingRow;
            while (!((startingRow >= 1) && (startingRow <= rows)))
            {
                std::cout << "Starting row of ant must be on the board"
                    << std::endl;
                std::cout << "Starting row can be a number from 1 to "
                    << "the number of rows, inclusive" << std::endl;
                std::cout << "Enter starting row of ant" << std::endl;
                std::cin >> startingRow;
            }
            break;

            case 5:
            std::cout << "Enter starting col of ant" << std::endl;
            std::cin >> startingCol;
            while (!((startingCol >= 1) && (startingCol <= cols)))
            {
                std::cout << "Starting col of ant must be on the board"
                    << std::endl;
                std::cout << "Starting col can be a number from 1 to "
                    << "the number of cols, inclusive" << std::endl;
                std::cout << "Enter starting col of ant" << std::endl;
                std::cin >> startingCol;
            }
            break;

            case 6: 
            std::cout << "Enter starting direction of ant" << std::endl;
            // Use different method to read in string
            std::cin >> startingDir;
            while (!(startingDir == "up" || startingDir == "down"
                || startingDir == "left" || startingDir == "right"))
            {
                std::cout << "Starting direction of ant must be up, down, "
                    << "left, or right" << std::endl;
                std::cout << "Enter starting direction of ant" << std::endl;
                std::cin >> startingDir;
            }
            break;

            case 7:
            std::cout << "Executing simulation..." << std::endl;
            break;

            default:
            std::cout << "Enter a valid menu item (1 through 7)" << std::endl;
        }
    }
    
    // Decrementing row and column by 1 to go from row/col coordinate to
    // matrix index
    startingRow -= 1;
    startingCol -= 1;

    // Create object with given parameters
    return Ant(rows, cols, steps, startingRow, startingCol, startingDir);
}
