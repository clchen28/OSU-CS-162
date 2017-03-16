/******************************************************************************
** Program name: Player.hpp
** Author: Charles Chen
** Date: 03/11/2017
** Description:

******************************************************************************/

#include "Backpack.hpp"
#include <string>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Room;

class Player
{
public:
    Player(Room* startingPosition);
    ~Player();
    Room* getPlayerPosition();
    void movePlayer(Room* roomPosition);
    int getHealth();
    void removeHealth(int damage);
    bool hasItem(std::string item);
    void idkfaCheat();
    void addItem(std::string item);
    void removeItem(std::string item);
    void printItems();
    bool backpackFull();
    bool isInvuln();
    void setInvuln(bool invuln);
    bool isDead();
    void setReachedExit(bool reachedExit);
    bool getReachedExit();
private:
    Room* position;
    int health;
    Backpack backpack;
    bool invuln;
    bool reachedExit;
};

#include "Room.hpp"

#endif
