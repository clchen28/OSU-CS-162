/******************************************************************************
** Program name: Room.hpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

class Player;

class Room
{
public:
    Room();
    Room(Room* up, Room* down, Room* left, Room* right);
    virtual ~Room();
    bool isFound();
    void setFound(bool found);
    virtual void doSpecial(Player* player) = 0;
protected:
    Room* up;
    Room* down;
    Room* left;
    Room* right;
    bool found;
};

#include "Player.hpp"

#endif
