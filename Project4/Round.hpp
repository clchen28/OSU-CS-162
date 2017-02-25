/******************************************************************************
** Program name: Round.hpp
** Author: Charles Chen
** Date: 02/09/2017
** Description:
Specification of functions related to running the game.
******************************************************************************/

#include "Creature.hpp"

#ifndef ROUND_HPP
#define ROUND_HPP

void attackCreature(Creature* Attacker, Creature* Defender);
void playRound(Creature* Creature1, Creature* Creature2, int roundN);
int randNum(int n);

#endif
