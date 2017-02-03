/******************************************************************************
** Program name: Building.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Specification of Building class.
******************************************************************************/

#include <string>

#ifndef BUILDING_HPP
#define BUILDING_HPP

class Building
{
    public:
        Building(std::string name, int size, std::string address);
        ~Building();
        void printBuilding();
        std::string getBuildingName();
    
    private:
        std::string name;
        int size;
        std::string address;
};

#endif