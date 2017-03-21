/******************************************************************************
** Program name: Backpack.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:
Implementation of Backpack class
******************************************************************************/

#include <iostream>
#include <set>
#include <string>
#include "Backpack.hpp"

/*
Backpack()
Constructor initializes Backpack with a size of 2.
*/
Backpack::Backpack()
{
    size = 2;
}

/*
~Backpack()
Empty destructor
*/
Backpack::~Backpack(){}

/*
printItems()
Prints items in the backpack. Shows a message if there are no items in the
backpack.
*/
void Backpack::printItems()
{
    if (items.size() == 0)
    {
        std::cout << "No items in backpack" << std::endl;
    }
    else
    {
        std::cout << "Items in backpack:" << std::endl;
        std::set<std::string>::iterator item;
        for (item = items.begin(); item != items.end(); item++)
        {
            std::cout << *item << std::endl;
        }
    }
}

/*
addItem(item)
addItem adds an Item to the backpack if there is room
*/
void Backpack::addItem(std::string item)
{
    if (items.size() >= size)
    {
        std::cout << "Backpack is full" << std::endl;
    }
    else
    {
        items.insert(item);
        std::cout << item << " added to backpack" << std::endl;
    }
}

/*
removeItem(item) removes the specified item from the backpack, if it exists
*/
void Backpack::removeItem(std::string item)
{
    if (hasItem(item))
    {
        items.erase(item);
        std::cout << item << " removed from backpack" << std::endl;
    }
    else
    {
        std::cout << item << " not found in backpack" << std::endl;
    }
}

/*
hasItem(item) returns true if the specified item is the backpack, and false
otherwise
*/
bool Backpack::hasItem(std::string item)
{
    if (items.find(item) != items.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
backpackFull() returns true if the backpack is full, and false otherwise
*/
bool Backpack::backpackFull()
{
    return (items.size() >= size);
}
