/******************************************************************************
** Program name: Item.cpp
** Author: Charles Chen
** Date: 01/26/2017
** Description:
Contains the implementation of the Item class.
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Item.hpp"

/*
Item()
Default constructor, which sets empty strings for the name and unit, and
sets qtyToBuy and unitPrice to 0.
*/
Item::Item()
{
    this->name = "";
    this->unit = "";
    qtyToBuy = 0;
    unitPrice = 0;
}

/*
Item(std::string name, std::string unit, int qtyToBuy,
            float unitPrice)
Overloaded constructor, which allows name, unit, qtyToBuy, and unitPrice to be
set at initialization time.
*/
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

/*
~Item()
Empty destructor
*/
Item::~Item(){}


/*
getExtPrice()
Calculates and returns the extended price of this Item object
*/
float Item::getExtPrice() const
{
    return qtyToBuy * unitPrice;
}

/*
printItem()
Prints relevant attributes of this Item object, as well as the extended price.
*/
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

/*
operator==(const std::string &RHS)
Overloaded == operator allows user to compare an Item object on the left hand
side with a string on the right hand side. If the name attribute of the Item
object matches the string on the right hand side, returns True.
*/
const bool Item::operator==(const std::string &RHS)
{
    std::string LHSName = name;
    std::string RHSName = RHS;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName == RHSName;
}

/*
operator==(const Item &RHS)
Overloaded == operator allows user to compare an Item object on the left hand
side with aanother Item on the right hand side. If the name attribute of the Item
object matches the right hand side's name attribute, returns True.
*/
const bool Item::operator==(const Item &RHS)
{
    std::string LHSName = this->name;
    std::string RHSName = RHS.name;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName == RHSName;
}

/*
operator!=(const std::string &RHS)
Overloaded != operator allows user to compare an Item object on the left hand
side with a string on the right hand side. If the name attribute of the Item
object doesn't match the string on the right hand side, returns True.
*/
const bool Item::operator!=(const std::string &RHS)
{
    std::string LHSName = name;
    std::string RHSName = RHS;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName != RHSName;
}

/*
operator!=(const std::string &RHS)
Overloaded == operator allows user to compare an Item object on the left hand
side with aanother Item on the right hand side. If the name attribute of the Item
object doesn't match the right hand side's name attribute, returns True.
*/
const bool Item::operator!=(const Item &RHS)
{
    std::string LHSName = this->name;
    std::string RHSName = RHS.name;
    std::transform(LHSName.begin(), LHSName.end(), LHSName.begin(), tolower);
    std::transform(RHSName.begin(), RHSName.end(), RHSName.begin(), tolower);
    return LHSName != RHSName;
}

/*
operator=(const Item &RHS)
Overloaded = operator. Allows contents of right hand side Item object to be
copied to the contents of an initialize left hand side Item object.
*/
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

/*
Item(const Item &RHS)
Copy constructor. Allows contents of right hand side object to be copied to
left hand side object on initialization.
*/
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