/******************************************************************************
** Program name: Backpack.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include <iostream>
#include <set>
#include <string>
#include "Backpack.hpp"

Backpack::Backpack()
{
    size = 2;
}

Backpack::~Backpack(){}

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

void Backpack::addItem(std::string item)
{
    if (items.size() >= size)
    {
        std::cout << "Backpack is full" << std::endl;
    }
    else
    {
        items.insert(item);
    }
}

void Backpack::removeItem(std::string item)
{
    if (hasItem(item))
    {
        items.erase(item);
    }
    else
    {
        std::cout << item << " not found in backpack" << std::endl;
    }
}

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

void Backpack::idkfaCheat()
{
    items.clear();
    size = 3;
    addItem("Shotgun");
    addItem("Key");
    addItem("BFG 9000");
}

bool Backpack::backpackFull()
{
    return (items.size() >= size);
}