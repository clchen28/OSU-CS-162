/******************************************************************************
** Program name: ExitRoom.cpp
** Author: Charles Chen
** Date: 03/14/2017
** Description:
Implementation of ExitRoom class.
******************************************************************************/

#include "Room.hpp"
#include "Player.hpp"
#include "ExitRoom.hpp"
#include <string>
#include <iostream>

/*
ExitRoom()
Constructor derives from Room constructor
*/
ExitRoom::ExitRoom() : Room(){}

/*
ExitRoom(Room* up, Room* down, Room* left, Room* right)
Non-default constructor inherits from non-default Room constructor, setting
adjacent Room pointers.
*/
ExitRoom::ExitRoom(Room* up, Room* down, Room* left, Room* right) : Room(up,
    down, left, right){}

/*
~ExitRoom()
Empty destructor
*/
ExitRoom::~ExitRoom(){}

/*
doSpecial(Player* player)
doSpecial performs the special function of this room. In this case, if the
player has a key, then this method will set the player's reachedExit bool
to true. Otherwise, this method informs the player that a key is needed to
exit.
*/
void ExitRoom::doSpecial(Player* player)
{
    found = true;
    if (!(player->hasItem("Key")))
    {
        std::cout << "You need a key to exit" << std::endl;
    }
    else
    {
        player->setReachedExit(true);
    }
}

/*
getType()
Returns "Exit"
*/
std::string ExitRoom::getType()
{
    return "Exit";
}
