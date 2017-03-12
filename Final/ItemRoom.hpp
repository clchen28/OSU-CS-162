/******************************************************************************
** Program name: ItemRoom.hpp
** Author: Charles Chen
** Date: 03/12/2017
** Description:

******************************************************************************/

#include <set>
#include <string>

#ifndef ITEMROOM_HPP
#define ITEMROOM_HPP

class Room;
class Player;

class ItemRoom : public Room
{
public:
    ItemRoom();
    ItemRoom(Room* up, Room* down, Room* left, Room* right);
    ItemRoom(std::set<std::string> roomItems);
    ItemRoom(std::set<std::string> roomItems, Room* up, Room* down,
        Room* left, Room* right);
    virtual ~ItemRoom();
    virtual void doSpecial(Player* player);
private:
    std::set<std::string> roomItems;
    void printItems();
    void printMenu();
    void pickUpItem(std::string item, Player* player);
    void dropItem(std::string item, Player* player);
};

#include "Room.hpp"
#include "ItemRoom.hpp"

#endif
