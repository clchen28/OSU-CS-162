/******************************************************************************
** Program name: Item.cpp
** Author: Charles Chen
** Date: 01/26/2017
** Description:

******************************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
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
    this->name = name;
    this->unit = unit;
    this->qtyToBuy = qtyToBuy;
    this->unitPrice = unitPrice;
    if (unitPrice < 0)
    {
        this->unitPrice = 0;
    }
    if (qtyToBuy < 0)
    {
        this->qtyToBuy = 0;
    }
    return;
}

Item::~Item(){}

float Item::getExtPrice() const
{
    return qtyToBuy * unitPrice;
}

void Item::printItem() const
{
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Item: " << name << std::endl;
    std::cout << "Unit: " << unit << std::endl;
    std::cout << "Quantity: " << qtyToBuy << std::endl;
    std::cout << "Unit Price: ";
    std::cout << std::setprecision(2) << std::fixed << unitPrice << std::endl;
    std::cout << "Extended Price: ";
    std::cout << std::setprecision(2) << std::fixed << getExtPrice();
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    return;
}

const bool Item::operator==(const std::string &RHS)
{
    std::string LHSName = name;
    std::string RHSName = RHS;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName == RHSName;
}

const bool Item::operator==(const Item &RHS)
{
    std::string LHSName = this->name;
    std::string RHSName = RHS.name;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName == RHSName;
}

const bool Item::operator!=(const std::string &RHS)
{
    std::string LHSName = name;
    std::string RHSName = RHS;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName != RHSName;
}

const bool Item::operator!=(const Item &RHS)
{
    std::string LHSName = this->name;
    std::string RHSName = RHS.name;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName != RHSName;
}

Item& Item::operator=(const Item &RHS)
{
    if (this != &RHS)
    {
        name = RHS.name;
        unit = RHS.unit;
        qtyToBuy = RHS.qtyToBuy;
        unitPrice = RHS.unitPrice;
    }

    return *this;
}

Item::Item(const Item &RHS)
{
    this->name = RHS.name;
    this->unit = RHS.unit;
    this->qtyToBuy = RHS.qtyToBuy;
    this->unitPrice = RHS.unitPrice;
    if (RHS.unitPrice < 0)
    {
        this->unitPrice = 0;
    }
    if (RHS.qtyToBuy < 0)
    {
        this->qtyToBuy = 0;
    }
}