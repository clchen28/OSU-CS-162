/******************************************************************************
** Program name: Barbarian.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Die.hpp"

Barbarian::Barbarian() : Creature()
{
    this->armor = 0;
    this->strength = 12;
    Die AttackDie(6);
    Die DefenseDie(6);
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
