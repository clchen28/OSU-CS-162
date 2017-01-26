/******************************************************************************
** Program name: Lab3.cpp
** Author: Charles Chen
** Date: 01/25/2017
** Description:
To compile the main program, type:
make
To run the main program, type:
./Lab3

To compile the testing program for testing die functionality, type:
make dietest

To run the testing program, type:
./dieTest

This program uses a menu to ask the user to define certain initial conditions
for the die rolling game (rounds, Player 1 and 2 die type/sides), then executes
the game.
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
