/******************************************************************************
** Program name: List.hpp
** Author: Charles Chen
** Date: 01/27/2017
** Description:

******************************************************************************/

#include <string>
#include "Item.hpp"

#ifndef LIST_HPP
#define LIST_HPP

class List
{
    public:
        List();
        ~List();
        void addItem(std::string name, std::string unit, int qtyToBuy,
    float unitPrice);
        void printList();
        void removeItem(std::string name);
    private:
        size_t arraySize;
        int itemCount;
        Item *items;
        int findItem(std::string name); // Eventually want to add this to private
};

#endif