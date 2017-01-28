/******************************************************************************
** Program name: Item.hpp
** Author: Charles Chen
** Date: 01/26/2017
** Description:
Contains the specification of the Item class.

Item contains name, unit, qtyToBuy, and unitPrice member attributes.
Default constructor and overloaded constructors are provided.
Copy constructors and assignment overloads are provided.
== and != operators are overloaded to allow users to compare Item objects
to other Item objects, or by name.
******************************************************************************/

#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
    public:
        Item();
        Item(std::string name, std::string unit, int qtyToBuy,
           float unitPrice);
        Item(const Item &RHS);
        ~Item();        

        void printItem() const;
        const bool operator==(const std::string &RHS);
        const bool operator==(const Item &RHS);
        const bool operator!=(const std::string &RHS);
        const bool operator!=(const Item &RHS);
        Item& operator=(const Item &RHS);
        float getExtPrice() const;

    private:
        std::string name;
        std::string unit;
        int qtyToBuy;
        float unitPrice;
};

#endif
