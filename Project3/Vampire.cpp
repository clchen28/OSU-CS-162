/******************************************************************************
** Program name: Vampire.cpp
** Author: Charles Chen
** Date: 02/06/2017
** Description:
Implementation for Vampire class
******************************************************************************/

#include <iostream>
#include <string>
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
    this->name = "Vampire";
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
    // 50% chance of Vampire activating Charm
    // If Vampire activates Charm, return 8888 defense points - will protect
    // against anything except for Medusa's Glare
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
