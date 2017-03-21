/******************************************************************************
** Program name: Backpack.hpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:
Specification of Backpack class.
******************************************************************************/

#ifndef BACKPACK_HPP
#define BACKPACK_HPP
#include <set>
#include <string>

class Backpack
{
public:
    Backpack();
    ~Backpack();
    bool hasItem(std::string item);
    void addItem(std::string item);
    void removeItem(std::string item);
    void printItems();
    bool backpackFull();
protected:
    int size;
    std::set<std::string> items;
};

#endif
