/******************************************************************************
** Program name: Lab7.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Queue.hpp"
#include "inputValidator.hpp"

/*
printMenu displays the available options
*/
void printMenu()
{
    std::cout << "Select a menu option: " << std::endl;
    std::cout << "a. Enter a value to be added to the queue" << std::endl;
    std::cout << "b. Display first node (front) value" << std::endl;
    std::cout << "c. Remove first node (front) value" << std::endl;
    std::cout << "d. Display the queue contents" << std::endl;
    std::cout << "x. Exit" << std::endl;
}

int main()
{
    Queue queue;
    int newVal = -1;
    char selection = 'z';

    // These lambda functions are used for the input validation function later
    auto intInputNonNeg = [](int input) -> bool {return input > 0;};

    while (selection != 'x')
    {
        printMenu();
        std::cin.get(selection);
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');

        // Selects submenu item
        switch (selection)
        {
            case 'a':
                inputValidator(newVal, intInputNonNeg,
                    "Enter a positive integer to add to the queue: ",
                    "Invalid, must enter a positive integer");
                queue.addBack(newVal);
            break;

            case 'b':
                if (queue.getFront() == -1)
                {
                    std::cout << "There are no elements in the queue";
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Front is " << queue.getFront() << std::endl;
                }
            break;

            case 'c':
                if (queue.getFront() == -1)
                {
                    std::cout << "There are no elements in the queue";
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Removed front: " << queue.removeFront();
                    std::cout << std::endl;
                }
            break;

            case 'd':
                queue.printAll();
            break;

            case 'x':
                std::cout << "Exiting..." << std::endl;
            break;

            default:
                std::cout << "Enter a valid menu item" << std::endl;
        }
    }
    return 0;
}
