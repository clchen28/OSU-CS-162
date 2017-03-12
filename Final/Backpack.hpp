/******************************************************************************
** Program name: Backpack.hpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include <set>
#include <string>

#ifndef BACKPACK_HPP
#define BACKPACK_HPP

class Backpack
{
public:
    Backpack();
    ~Backpack();
    bool hasItem(std::string item);
    void idkfaCheat();
    void addItem(std::string item);
    void removeItem(std::string item);
    void printItems();
protected:
    int size;
    std::set<std::string> items;
};

#endif
