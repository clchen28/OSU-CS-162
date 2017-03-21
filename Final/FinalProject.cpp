/******************************************************************************
** Program name: FinalProject.cpp
** Author: Charles Chen
** Date: 03/20/2017
** Description:
Final project is a Doom-like game with a series of rooms, which may contain
items, monsters, or the exit. The goal is to reach the exit without dying.

To compile:
make

To run:
./FinalProject
******************************************************************************/
#include <iostream>
#include <string>
#include "Game.hpp"

int main()
{
    Game game;
    game.playGame();
    return 0;
}
