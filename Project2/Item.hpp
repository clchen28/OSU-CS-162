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
        Item();
        Item(std::string name, std::string unit, int qtyToBuy,
           float unitPrice);
        ~Item();
        float getExtPrice();
        void printItem();
        const bool operator==(const std::string &RHS);
        const bool operator!=(const std::string &RHS);

        std::string name;
        std::string unit;
        int qtyToBuy;
        float unitPrice;
    private:
    /*
        std::string name;
        std::string unit;
        int qtyToBuy;
        float unitPrice;
        */
};

#endif
