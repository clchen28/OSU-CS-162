/******************************************************************************
** Program name: Player.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:
Implementation of Player class
******************************************************************************/

#include <iostream>
#include "Room.hpp"
#include "Player.hpp"
#include "Backpack.hpp"

/*
Player(Room* startingPosition)
Create a new Player at the specified starting Room
*/
Player::Player(Room* startingPosition)
{
    health = 100;
    position = startingPosition;
    reachedExit = false;
}

/*
~Player()
Default destructor
*/
Player::~Player(){}

/*
getPlayerPosition() returns a pointer to the Room that the Player is currently
in
*/
Room* Player::getPlayerPosition()
{
    return position;
}

/*
void movePlayer(Room* roomPosition)
Moves the player to the specified room.
*/
void Player::movePlayer(Room* roomPosition)
{
    if (roomPosition != nullptr)
    {
        position = roomPosition;
    }
    else
    {
        std::cout << "There's a wall there..." << std::endl;
    }
}

/*
getHealth()
Returns the player's health
*/
int Player::getHealth()
{
    return health;
}

/*
removeHealth(int damage)
Removes the specified amount of health from the Player
*/
void Player::removeHealth(int damage)
{
    health -= damage;
}

/*
isDead()
Returns true if the player is dead
*/
bool Player::isDead()
{
    if (health <= 0)
    {
        return true;
    }
    return false;
}

/*
hasItem(item)
hasItem returns true if the player has the specified item in the backpack
*/
bool Player::hasItem(std::string item)
{
    return backpack.hasItem(item);
}

/*
addItem(item)
addItem adds the specified item to the player's backpack
*/
void Player::addItem(std::string item)
{
    backpack.addItem(item);
}

/*
removeItem(item)
removeItem removes the specified item from the player's backpack
*/
void Player::removeItem(std::string item)
{
    backpack.removeItem(item);
}

/*
printItems()
printItems prints the items in the player's backpack
*/
void Player::printItems()
{
    backpack.printItems();
}

/*
backpackFull()
backpackFull returns true if there is no more room in the player's backpack
*/
bool Player::backpackFull()
{
    return backpack.backpackFull();
}

/*
setReachedExit(bool reachedExit)
setReachedExit is used to set whether or not the player has reached the exit
*/
void Player::setReachedExit(bool reachedExit)
{
    this->reachedExit = reachedExit;
}

/*
getReachedExit()
getReachedExit returns true if the player has reached the exit
*/
bool Player::getReachedExit()
{
    return reachedExit;
}
