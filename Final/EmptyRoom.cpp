/******************************************************************************
** Program name: EmptyRoom.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Room.hpp"
#include "EmptyRoom.hpp"

EmptyRoom::EmptyRoom() : Room(){}

EmptyRoom::EmptyRoom(Room* up, Room* down, Room* left, Room* right) : Room(up,
    down, left, right){}

EmptyRoom::~EmptyRoom(){}

void EmptyRoom::doSpecial()
{
    std::cout << "This is just an empty room." << std::endl;
}
