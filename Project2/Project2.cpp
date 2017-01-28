/******************************************************************************
** Program name: Project2.cpp
** Author: Charles Chen
** Date: 01/28/2017
** Description:
This code provides an interface for the List class. It generates a new List,
and prompts the user to add items, remove items, or print the contents of
the list.

To compile:
make

To run:
./Project2
******************************************************************************/

#include <iostream>
#include <string>
#include "Item.hpp"
#include "List.hpp"
#include "menu.hpp"

int main()
{
    
    List myList;
    menu(myList);

    return 0;
}