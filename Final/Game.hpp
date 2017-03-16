/******************************************************************************
** Program name: Game.hpp
** Author: Charles Chen
** Date: 03/13/2017
** Description:

******************************************************************************/

#include "Player.hpp"
#include "Room.hpp"
#include "ItemRoom.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
public:
    Game();
    ~Game();
    void printMap();
    void playGame();
private:
    Room* startRoom;
    Player* player;
    Room* roomRow1;
    Room* roomRow2;
    Room* roomRow3;
    Room* roomRow4;
    void printRow(Room* row);
};

#endif
