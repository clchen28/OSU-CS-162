/******************************************************************************
** Program name: ExitRoom.hpp
** Author: Charles Chen
** Date: 03/14/2017
** Description:

******************************************************************************/

#include "Room.hpp"
#include "Player.hpp"
#include <string>

#ifndef EXITROOM_HPP
#define EXITROOM_HPP

class ExitRoom : public Room
{
public:
    ExitRoom();
    ExitRoom(Room* up, Room* down, Room* left, Room* right);
    virtual ~ExitRoom();
    virtual void doSpecial(Player* player);
    virtual std::string getType();
};

#endif
