/******************************************************************************
** Program name: EmptyRoom.hpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include "Room.hpp"

#ifndef EMPTYROOM_HPP
#define EMPTYROOM_HPP

class EmptyRoom : public Room
{
public:
    EmptyRoom();
    EmptyRoom(Room* up, Room* down, Room* left, Room* right);
    virtual ~EmptyRoom();
    virtual void doSpecial();
};

#endif
