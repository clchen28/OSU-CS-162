/******************************************************************************
** Program name: Lab7.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Implementation of a queue ADT. Creates a Queue object. Gives options to user
to add values to the queue, get a value from the queue, remove a value from
the queue, or to display the contents of the queue in order.

To compile:
make

To run:
./Lab7
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

/*
main()
main contains a menu which prompts the user to interact with the queue.
*/
int main()
{
    Queue queue;

    // Initializes menu options
    int newVal = -1;
    char selection = 'z';

    // These lambda functions are used for the input validation function later
    auto intInputNonNeg = [](int input) -> bool {return input > 0;};

    while (selection != 'x')
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
            // Adds an item to the queue
            case 'a':
                inputValidator(newVal, intInputNonNeg,
                    "Enter a positive integer to add to the queue: ",
                    "Invalid, must enter a positive integer");
                queue.addBack(newVal);
            break;

            case 'b':
            // Checks to see if there are items in the queue first
                if (queue.getFront() == -1)
                {
                    std::cout << "There are no elements in the queue";
                    std::cout << std::endl;
                }
            // If there are items in the queue prints the front value
                else
                {
                    std::cout << "Front is " << queue.getFront() << std::endl;
                }
            break;

            case 'c':
            // Checks to see if there are items in the queue first
                if (queue.getFront() == -1)
                {
                    std::cout << "There are no elements in the queue";
                    std::cout << std::endl;
                }
            // If there are items, removes the front of the queue
                else
                {
                    std::cout << "Removed front: " << queue.removeFront();
                    std::cout << std::endl;
                }
            break;

            case 'd':
            // Prints all items in the queue in order
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
