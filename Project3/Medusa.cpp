/******************************************************************************
** Program name: Medusa.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Creature.hpp"
#include "Medusa.hpp"

Medusa::Medusa() : Creature()
{
    this->armor = 3;
    this->strength = 8;
    Die AttackDie(6);
    Die DefenseDie(6);
}

Medusa::~Medusa(){}

int Medusa::rollAttack()
{
    int attack = AttackDie.rollDie() + AttackDie.rollDie();
    if (attack == 12)
    {
        attack = 9999; // Glare
        std::cout << "Medusa used Glare!" << std::endl;
    }
    return attack;
}

int Medusa::rollDefense()
{
    return DefenseDie.rollDie();
}
