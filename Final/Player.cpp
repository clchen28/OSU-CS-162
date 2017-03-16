/******************************************************************************
** Program name: Player.cpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Room.hpp"
#include "Player.hpp"
#include "Backpack.hpp"

Player::Player(Room* startingPosition)
{
    health = 100;
    position = startingPosition;
    invuln = false;
    reachedExit = false;
}

Player::~Player(){}

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

void Player::setReachedExit(bool reachedExit)
{
    this->reachedExit = reachedExit;
}

bool Player::getReachedExit()
{
    return reachedExit;
}
