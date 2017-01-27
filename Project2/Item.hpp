/******************************************************************************
** Program name: Item.hpp
** Author: Charles Chen
** Date: 01/26/2017
** Description:

******************************************************************************/

#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
    public:
        Item(std::string name, std::string unit, int qtyToBuy,
           float unitPrice);
        float getExtPrice();
        void printItem();
        const bool operator==(const std::string &RHS);
        const bool operator!=(const std::string &RHS);
    private:
        std::string name;
        std::string unit;
        int qtyToBuy;
        float unitPrice;
};

#endif
