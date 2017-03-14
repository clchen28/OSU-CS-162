/******************************************************************************
** Program name: Room.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include "Room.hpp"

Room::Room()
{
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
    setFound(false);
}

Room::Room(Room* up, Room* down, Room* left, Room* right)
{
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
    setFound(false);
}

Room::~Room(){}

void Room::setFound(bool found)
{
    this->found = found;
}

bool Room::isFound()
{
    return found;
}

void Room::setUp(Room* up)
{
    this->up = up;
}

void Room::setDown(Room* down)
{
    this->down = down;
}

void Room::setLeft(Room* left)
{
    this->left = left;
}

void Room::setRight(Room* right)
{
    this->right = right;
}

Room* Room::getUp()
{
    return up;
}

Room* Room::getDown()
{
    return down;
}

Room* Room::getLeft()
{
    return left;
}

Room* Room::getRight()
{
    return right;
}
