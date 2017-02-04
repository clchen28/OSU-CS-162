/******************************************************************************
** Program name: Building.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Implementation of Building class.
******************************************************************************/

#include <iostream>
#include <string>
#include "Building.hpp"

/*
Building(std::string name, int size, std::string address)
Creates a new Building object with the specified name, size, and address.
*/
Building::Building(std::string name, int size, std::string address)
{
    this->name = name;
    this->size = size;
    this->address = address;
}

/*
~Building()
Empty destructor.
*/
Building::~Building(){}

/*
printBuilding()
Prints the details of the specified building.
*/
void Building::printBuilding()
{
    std::cout << "Name of building: " << name << std::endl;
    std::cout << "Size of building: " << size << " sqft" << std::endl;
    std::cout << "Address of building: " << address << std::endl;
    return;
}

/*
returnBuilding()
Returns the details of Building in string
*/
std::string Building::returnBuilding()
{
    return "Building\n" + name + "\n" + std::to_string(size) + "\n" + address
        + "\n";
}

/*
getBuildingName()
Returns the name of the building.
*/
std::string Building::getBuildingName()
{
    return name;
}