/******************************************************************************
** Program name: Game.hpp
** Author: Charles Chen
** Date: 02/09/2017
** Description:
Specification of functions related to running the game.
******************************************************************************/

#include "Creature.hpp"

#ifndef GAME_HPP
#define GAME_HPP

void attackCreature(Creature* Attacker, Creature* Defender);
void playGame(Creature* Creature1, Creature* Creature2);
int randNum(int n);

#endif
