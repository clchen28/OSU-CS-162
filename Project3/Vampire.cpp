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
Vampire::Vampire() : Creature(), CharmDie(2)
{
    this->armor = 1;
    this->strength = 18;
    Creature::AttackDie.setSides(12);
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
    int roll = AttackDie.rollDie();
    std::cout << "Vampire rolled " << roll << " attack points!" << std::endl;
    return roll;
}

/*
rollDefense()
Rolls the defense die for the Vampire. Rolls CharmDie first (2-sided), to
determine if Vampire's Charm ability is activated.
*/
int Vampire::rollDefense()
{
    if (CharmDie.rollDie() == 2)
    {
        std::cout << "Vampire uses Charm!" << std::endl;
        return 8888; // Charm
    }
    else
    {
        int roll = DefenseDie.rollDie();
        std::cout << "Vampire rolled " << roll << " defense points!";
        std::cout << std::endl;
        return roll;
    }
}
