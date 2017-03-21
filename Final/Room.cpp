/******************************************************************************
** Program name: Room.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:
Implementation of the Room class
******************************************************************************/

#include "Room.hpp"

/*
Room()
Default constructor sets surrounding Room pointers to nullptr
*/
Room::Room()
{
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
    setFound(false);
}

/*
Room(Room* up, Room* down, Room* left, Room* right)
Constructor sets surrounding Room pointers to those specified
*/
Room::Room(Room* up, Room* down, Room* left, Room* right)
{
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
    setFound(false);
}

/*
~Room()
Empty destructor
*/
Room::~Room(){}

/*
setFound(bool found)
setFound sets whether or not the current Room has been found
*/
void Room::setFound(bool found)
{
    this->found = found;
}

/*
isFound()
isFound returns true if this room has been found, and false otherwise
*/
bool Room::isFound()
{
    return found;
}

/*
setUp(Room*up)
Sets pointer to Room above this one
*/
void Room::setUp(Room* up)
{
    this->up = up;
}

/*
setDown(Room* down)
Sets pointer to Room below this one
*/
void Room::setDown(Room* down)
{
    this->down = down;
}

/*
setLeft(Room* left)
Sets pointer to Room to the left of this one
*/
void Room::setLeft(Room* left)
{
    this->left = left;
}

/*
setRight(Room* right)
Sets pointer to Room to the right of this one
*/
void Room::setRight(Room* right)
{
    this->right = right;
}

/*
getUp()
Returns pointer to Room above this one
*/
Room* Room::getUp()
{
    return up;
}

/*
getDown()
Returns pointer to Room below this one
*/
Room* Room::getDown()
{
    return down;
}

/*
getLeft()
Returns pointer to Room to the left of this one
*/
Room* Room::getLeft()
{
    return left;
}

/*
getRight()
Returns pointer to Room to the right of this one
*/
Room* Room::getRight()
{
    return right;
}
