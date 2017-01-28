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
    items = new Item*[arraySize];
}

List::~List()
{
    delete [] items;
}

int List::findItem(std::string searchTerm)
{
    int index = -1;
    std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(),
        tolower);
    for (int i = 0; i < arraySize; i++)
    {
        if ( *(items[i]) == searchTerm )
        {
            index = i;
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
        std::cout << "The item already exists, ignoring" << std::endl;
        return;
    }
    else
    {  
        itemCount++;
        Item newItem(name, unit, qtyToBuy, unitPrice);
        if (itemCount <= arraySize)
        {
            items[itemCount - 1] = &newItem;
        }
        else if (itemCount > arraySize)
        {
            Item **newItems = new Item*[arraySize + 5];
            std::copy(std::begin(items), std::end(items), newItems);
            delete [] items;
            items = newItems;
        }
    }
}

int main()
{return 0;}