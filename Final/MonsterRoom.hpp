/******************************************************************************
** Program name: MonsterRoom.hpp
** Author: Charles Chen
** Date: 03/14/2017
** Description:

******************************************************************************/

#include "Room.hpp"
#include "Player.hpp"
#include <string>

#ifndef MONSTERROOM_HPP
#define MONSTERROOM_HPP

class MonsterRoom : public Room
{
public:
    MonsterRoom();
    MonsterRoom(Room* up, Room* down, Room* left, Room* right);
    virtual ~MonsterRoom();
    virtual void doSpecial(Player* player);
    virtual std::string getType();
private:
    void printMenu(Player* player);
    int randNum(int n);
    bool monsterDead;
};

#endif
