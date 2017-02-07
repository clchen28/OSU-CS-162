/******************************************************************************
** Program name: Vampire.cpp
** Author: Charles Chen
** Date: 02/06/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Die.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"

/*
Vampire()
Vampire constructor. Creates a new vampire with appropriate armor and
strength. Vampire also has a Charm ability, which has a 50% chance of
activating. This is controlled by a CharmDie, which is initialized here.
*/
Vampire::Vampire() : Creature(), CharmDie(2), AttackDie(12)
{
    this->armor = 1;
    this->strength = 18;
}

/*
~Vampire()
Empty destructor.
*/
Vampire::~Vampire(){}

/*
rollAttack()
Rolls the attack die for the Vampire
*/
int Vampire::rollAttack()
{
    return AttackDie.rollDie();
}

/*
rollDefense()
*/
int Vampire::rollDefense()
{
    if (CharmDie.rollDie() == 2)
    {
        std::cout << "Vampire uses Charm! Attack is negated" << std::endl;
        return 9999; // Charm
    }
    else
    {
        return DefenseDie.rollDie();
    }

}
