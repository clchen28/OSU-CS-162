/******************************************************************************
** Program name: Building.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Building.hpp"

Building::Building(std::string name, int size, std::string address)
{
    this->name = name;
    this->size = size;
    this->address = address;
}

void Building::printBuilding()
{
    std::cout << "Name of building: " << name << std::endl;
    std::cout << "Size of building: " << size << " sqft" << std::endl;
    std::cout << "Address of building: " << address << std::endl;
    return;
}
