/******************************************************************************
** Program name: Project3.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Project3 is a fantasy fighting simulation game. Various creatures can be
created, and they can fight against each other. A menu is provided to make this
simple.

To compile, type:
make

To run, type:
./Project3

Each character has attack and defense die, and these are rolled in order to
determine the outcome of the fight. To test this random element of the program,
testing utilities have been provided to check that attack die and defense die
produce expected and reasonably random results.

To compile these test utilities, type:
make testRolls

To run these test utilities, type:
./testRolls

******************************************************************************/

#include <iostream>
#include "Die.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "menu.hpp"
#include "Game.hpp"

int main()
{
    menu();
    return 0;
}
