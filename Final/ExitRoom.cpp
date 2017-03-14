/******************************************************************************
** Program name: ExitRoom.cpp
** Author: Charles Chen
** Date: 03/14/2017
** Description:

******************************************************************************/

#include "Room.hpp"
#include "Player.hpp"
#include "ExitRoom.hpp"
#include <string>
#include <iostream>

ExitRoom::ExitRoom() : Room(){}

ExitRoom::ExitRoom(Room* up, Room* down, Room* left, Room* right) : Room(up,
    down, left, right){}

ExitRoom::~ExitRoom(){}

void ExitRoom::doSpecial(Player* player)
{
    if (!(player->hasItem("Key")))
    {
        std::cout << "You need a key to exit" << std::endl;
    }
    else
    {
        player->setReachedExit(true);
    }
}

std::string ExitRoom::getType()
{
    return "Exit";
}
