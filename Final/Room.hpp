/******************************************************************************
** Program name: Room.hpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:
Specification of the Room class
******************************************************************************/

#include <string>

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
    void setUp(Room* up);
    void setDown(Room* down);
    void setLeft(Room* left);
    void setRight(Room* right);
    Room* getUp();
    Room* getDown();
    Room* getLeft();
    Room* getRight();
    virtual std::string getType() = 0;
protected:
    Room* up;
    Room* down;
    Room* left;
    Room* right;
    bool found;
};

#include "Player.hpp"

#endif
