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
}

Medusa::~Medusa(){}

int Medusa::rollAttack()
{
    int roll = AttackDie.rollDie() + AttackDie.rollDie();
    if (roll == 12)
    {
        roll = 9999; // Glare
        std::cout << "Medusa used Glare!" << std::endl;
    }
    else
    {
        std::cout << "Medusa rolled " << roll << " attack points!";
        std::cout << std::endl;
    }
    return roll;
}

int Medusa::rollDefense()
{
    int roll = DefenseDie.rollDie();
    std::cout << "Medusa rolled " << roll << " defense points!" << std::endl;
    return roll;
}
