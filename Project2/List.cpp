/******************************************************************************
** Program name: List.cpp
** Author: Charles Chen
** Date: 01/27/2017
** Description:

******************************************************************************/

#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "Item.hpp"
#include "List.hpp"

List::List()
{
    arraySize = 4;
    itemCount = 0;
    items = new Item[arraySize];
}

List::~List()
{
    delete [] items;
}

int List::findItem(std::string searchTerm)
{
    int index = -1;
    if (searchTerm != "")
    {
        std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(),
            tolower);
        for (int i = 0; i < arraySize; i++)
        {
            if ( items[i] == searchTerm )
            {
                index = i;
            }
        }
    }
    return index;
}

void List::addItem(std::string name, std::string unit, int qtyToBuy,
    float unitPrice)
{
    if (name == "")
    {
        std::cout << "Empty strings are not allowed" << std::endl;
        return;
    }
    
    if (findItem(name) != -1)
    {
        std::cout << "Item ''" << name << "' already exists, ignoring";
        std::cout << std::endl;
        return;
    }
    
    else
    {  
        itemCount++;
        if (itemCount <= arraySize)
        {
            items[itemCount - 1] = Item(name, unit, qtyToBuy, unitPrice);
        }
        else if (itemCount > arraySize)
        {
            Item *newItems = new Item[arraySize + 5];
            // std::copy(std::begin(*items), std::end(*items), newItems);
            for (int i = 0; i < itemCount - 1; i++)
            {
                newItems[i] = items[i];
            }
            newItems[itemCount - 1] = Item(name, unit, qtyToBuy, unitPrice);

            // Deallocate memory that was originally allocated for items
            delete [] items;

            // Set items to the pointer to newly allocated arrray
            items = newItems;
            arraySize += 5;
        }
    }
}