/******************************************************************************
** Program name: Player.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include "Room.hpp"
#include "Player.hpp"
#include "Backpack.hpp"

Player::Player(Room* startingPosition)
{
    health = 100;
    position = startingPosition;
    invuln = false;
}

Player::~Player(){}

Room* Player::getPlayerPosition()
{
    return position;
}

/*
bool movePlayer(Room* roomPosition)
Moves the player to the specified room. If the room that is given as input
is nullptr, then the function will return false. If the room that is given as
input is a valid room, then the position is set to that room, and the function
returns true.
*/
bool Player::movePlayer(Room* roomPosition)
{
    if (roomPosition != nullptr)
    {
        position = roomPosition;
        return true;
    }
    return false;
}

int Player::getHealth()
{
    return health;
}

void Player::removeHealth(int damage)
{
    health -= damage;
}

bool Player::isDead()
{
    if (health <= 0)
    {
        return true;
    }
    return false;
}

bool Player::hasItem(std::string item)
{
    return backpack.hasItem(item);
}

void Player::idkfaCheat()
{
    backpack.idkfaCheat();
}

void Player::addItem(std::string item)
{
    backpack.addItem(item);
}

void Player::removeItem(std::string item)
{
    backpack.removeItem(item);
}

void Player::printItems()
{
    backpack.printItems();
}

bool Player::backpackFull()
{
    return backpack.backpackFull();
}

bool Player::isInvuln()
{
    return invuln;
}

void Player::setInvuln(bool invuln)
{
    this->invuln = invuln;
}
