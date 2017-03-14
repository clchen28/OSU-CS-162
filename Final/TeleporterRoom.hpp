/******************************************************************************
** Program name: TeleporterRoom.hpp
** Author: Charles Chen
** Date: 03/13/2017
** Description:

******************************************************************************/

#include <string>
#include "Player.hpp"
#include "Room.hpp"

#ifndef TELEPORTERROOM_HPP
#define TELEPORTERROOM_HPP

class TeleporterRoom : public Room
{
public:
    TeleporterRoom();
    TeleporterRoom(Room* destination);
    TeleporterRoom(Room* up, Room* down, Room* left, Room* right);
    TeleporterRoom(Room* destination, Room* up, Room* down,
        Room* left, Room* right);
    virtual ~TeleporterRoom();
    virtual void doSpecial(Player* player);
    virtual std::string getType();
private:
    Room* destination;
    void printMenu();
};

#endif
