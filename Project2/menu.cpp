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
#include "List.hpp"

/*
printMenu displays the available options
*/
void printMenu()
{
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Add an item" << std::endl;
    std::cout << "2. Remove an item" << std::endl;
    std::cout << "3. Display the shopping list" << std::endl;
    std::cout << "4. Exit the program" << std::endl;
    return;
}

/*
menu is a function that is intended to provide a starting point for
the Shopping List simulator.

It takes in an initialized list object as reference, and provides an API for
accessing the list object's methods. Specifically, it allows the user to
add an item to the list, remove an item, and display the shopping list, which
are all done through the List class's member methods.
*/
void menu(List &list)
{
    std::string itemName = "";
    std::string unit = "";
    int qtyToBuy = -1;
    float unitPrice = -1;

    int selection = -1;

    // These lambda functions are used for the input validation function later
    auto intInputPositive = [](int input) -> bool {return input >= 1;};
    auto floatInputPositive = [](float input) -> bool {return input >= 0;};
    auto notEmptyString = [](std::string input) -> bool {return input != "";};

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
                itemName = "";
                unit = "";
                qtyToBuy = -1;
                unitPrice = -1;
                inputValidator(itemName, notEmptyString, "Enter item name",
                    "Item name must not be an empty string");
                inputValidator(unit, notEmptyString, "Enter unit name",
                    "Unit name must not be an empty string");
                inputValidator(qtyToBuy, intInputPositive, "Enter quantity to buy",
                    "Must be greater than 0");
                inputValidator(unitPrice, floatInputPositive,
                    "Enter unit price",
                    "Price must not be lower than 0");
                list.addItem(itemName, unit, qtyToBuy, unitPrice);
            break;

            case 2:
                itemName = "";
                inputValidator(itemName, notEmptyString,
                    "Enter the name of the item you'd like to remove: ",
                    "Item name must not be an empty string");
                list.removeItem(itemName);
            break;

            case 3:
                list.printList();
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
