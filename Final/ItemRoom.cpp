/******************************************************************************
** Program name: ItemRoom.cpp
** Author: Charles Chen
** Date: 03/12/2017
** Description:

******************************************************************************/

#include "Room.hpp"
#include "Player.hpp"
#include "ItemRoom.hpp"
#include "inputValidator.hpp"
#include <string>
#include <set>
#include <iostream>

ItemRoom::ItemRoom() : Room(){}

ItemRoom::ItemRoom(Room* up, Room* down, Room* left,
        Room* right) : Room(up, down, left, right){}

ItemRoom::ItemRoom(std::set<std::string> roomItems) : Room()
{
    this->roomItems = roomItems;
}

ItemRoom::ItemRoom(std::set<std::string> roomItems, Room* up, Room* down,
        Room* left, Room* right) : Room(up, down, left, right)
{
    this->roomItems = roomItems;
}

ItemRoom::~ItemRoom(){}

void ItemRoom::printItems()
{
    if (roomItems.size() == 0)
    {
        std::cout << "No items in room" << std::endl;
    }
    else
    {
        std::cout << "Items in room:" << std::endl;
        std::set<std::string>::iterator item;
        for (item = roomItems.begin(); item != roomItems.end(); item++)
        {
            std::cout << *item << std::endl;
        }
    }
}

void ItemRoom::doSpecial(Player* player)
{
    auto yOrN = [](std::string input) -> bool
        {
            return ((input == "y")
                || (input == "Y")
                || (input == "n")
                || (input == "N"));
        };
    printItems();
    if (roomItems.size() == 0)
    {
        return;
    }
    std::string userInput = "";
    if (player->backpackFull())
    {
        inputValidator(userInput, yOrN,
            "Your backpack is full, would you like to drop some items? [y/n]: ",
            "Please input y or n");
    }
}
