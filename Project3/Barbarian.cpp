/******************************************************************************
** Program name: Barbarian.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Implementation for Barbarian class.
******************************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Die.hpp"

Barbarian::Barbarian() : Creature()
{
    this->armor = 0;
    this->strength = 12;
}

Barbarian::~Barbarian(){}

int Barbarian::rollAttack()
{
    return AttackDie.rollDie() + AttackDie.rollDie();
}

int Barbarian::rollDefense()
{
    return DefenseDie.rollDie() + DefenseDie.rollDie();
}
