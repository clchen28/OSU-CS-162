/******************************************************************************
** Program name: Item.cpp
** Author: Charles Chen
** Date: 01/26/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Item.hpp"

Item::Item()
{
    this->name = "";
    this->unit = "";
    qtyToBuy = 0;
    unitPrice = 0;
}

Item::Item(std::string name, std::string unit, int qtyToBuy,
            float unitPrice)
{
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    this->name = name;
    this->unit = unit;
    this->qtyToBuy = qtyToBuy;
    this->unitPrice = unitPrice;
    return;
}

Item::~Item(){}

float Item::getExtPrice() const
{
    return qtyToBuy * unitPrice;
}

void Item::printItem() const
{
    std::cout << "Item: " << name << std::endl;
    std::cout << "Unit: " << unit << std::endl;
    std::cout << "Quantity: " << qtyToBuy << std::endl;
    std::cout << "Unit Price: " << unitPrice << std::endl;
    std::cout << "Extended Price: " << getExtPrice() << std::endl << std::endl;
    return;
}

const bool Item::operator==(const std::string &RHS)
{
    return (this->name) == RHS;
}

const bool Item::operator!=(const std::string &RHS)
{
    return (this->name) != RHS;
}

Item& Item::operator=(const Item &RHS)
{
    name = RHS.name;
    unit = RHS.unit;
    qtyToBuy = RHS.qtyToBuy;
    unitPrice = RHS.unitPrice;

    return *this;
}