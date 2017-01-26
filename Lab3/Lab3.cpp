/******************************************************************************
** Program name: Lab3.cpp
** Author: Charles Chen
** Date: 01/25/2017
** Description:

******************************************************************************/

#include <iostream>
#include "menu.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

int main()
{
    Game game = menu();
    game.playGame();
    return 0;
}
