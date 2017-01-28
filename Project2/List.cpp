/******************************************************************************
** Program name: List.cpp
** Author: Charles Chen
** Date: 01/27/2017
** Description:
Contains the implementation of the List class.
******************************************************************************/

#include <string>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "Item.hpp"
#include "List.hpp"

/*
List()
Default constructor sets initial conditions and allocates memories for
future added items.
*/
List::List()
{
    arraySize = 4;
    itemCount = 0;
    items = new Item[arraySize];
}

/*
~List()
Destructor deallocates memory that was allocated for items
*/
List::~List()
{
    delete [] items;
}

/*
findItem(std::string searchTerm)
findItem takes a string as a search input and returns the index in which
the specified Item exists in the items array member attribute. If it does
not exist, it returns -1.

findItem is meant to be used as a helper method for other members of List.
addItem and removeItem provide the public API for the user to interact with the
List - findItem is a helper function for those two functions.
*/
int List::findItem(std::string searchTerm)
{
    int index = -1;
    if (searchTerm != "")
    {
        // Allows the search to be case insensitive
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

/*
addItem(std::string name, std::string unit, int qtyToBuy,
    float unitPrice)
addItem creates and adds the specified Item to the List's list attribute.
If user tries to add an Item with an empty name, this is rejected.
If the user tries to add an Item that is already on the list, this is rejected.
If the array size allocated for items is exceeded, this function will increase
the size of lists by 5, and reallocate memory.
*/
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
        std::cout << "Item '" << name << "' already exists, ignoring";
        std::cout << std::endl;
        return;
    }
    
    else
    {  
        itemCount++;
        // If there is enough room in items, then just add the new item
        if (itemCount <= arraySize)
        {
            items[itemCount - 1] = Item(name, unit, qtyToBuy, unitPrice);
        }

        // If adding this Item will overflow the items array, increase size of
        // array
        else if (itemCount > arraySize)
        {
            // Allocate new memory in heap for an array that is 5 indices
            // larger
            Item *newItems = new Item[arraySize + 5];

            // Copy contents of old array to new array
            for (int i = 0; i < itemCount - 1; i++)
            {
                newItems[i] = items[i];
            }

            // Add new Item
            newItems[itemCount - 1] = Item(name, unit, qtyToBuy, unitPrice);

            // Deallocate memory that was originally allocated for items
            delete [] items;

            // Set items to the pointer to newly allocated arrray
            items = newItems;
            arraySize += 5;
        }
    }
}

/*
removeItem(std::string name)
removeItem removes the specified item from the List. If the specified Item does
not exist, an error is output. If there are no items in the List, an error is
output.
*/
void List::removeItem(std::string name)
{
    if (name == "")
    {
        std::cout << "Item not found, ignoring" << std::endl;
        return;
    }
    if (itemCount == 0)
    {
        std::cout << "No items to remove" << std::endl;
        return;
    }

    int index = findItem(name);
    if (index == -1)
    {
        std::cout << "Item '" << name << "' not found, ignoring";
        std::cout << std::endl;
        return;
    }
    else
    {
        // Removes the Item by setting it to an empty Item using default Item
        // constructor
        items[index] = Item();

        // If array is larger than size 1 and the Item is in the middle of the
        // array, remove it and shift elements to the right of this index over
        if ( !((index == arraySize - 1) && (arraySize != 1)) )
        {
            for (int i = index; i < arraySize - 1; i++)
            {
                items[i] = items[i + 1];
            }
        }

        // Edge cases:
        // 1. Removing item that is last element of array
        // 2. Array is size 1, and we remove it
        // Solutions:
        // 1. By reducing arraySize by 1, we do not have access to the removed
        // item anymore. We skip the step above, as there are no Items to the
        // right of the removed Item that need to be shifted.
        // 2. By setting itemCount to 0, other functions in List know that
        // there are no more Items in List. An empty Item object is placed
        // in the first element of the array as a placeholder.
        itemCount--;
        arraySize--;
    }
    return;
}

/*
printList()
Prints the contents of the List, then prints the total price of all Items
inside the List.
*/
void List::printList()
{
    float totalExtPrice = 0;
    if (itemCount == 0)
    {
        std::cout << "No items" << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < itemCount; i++)
        {
            items[i].printItem();
            totalExtPrice += items[i].getExtPrice();
        }
        std::cout << "Total Price: ";
        std::cout << std::setprecision(2) << std::fixed << totalExtPrice << std::endl;
        std::cout << std::endl;
    }
}