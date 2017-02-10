/******************************************************************************
** Program name: Barbarian.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Implementation for Barbarian class.
******************************************************************************/

#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Die.hpp"

/*
Barbarian()
Barbarian constructor sets armor and strength
*/
Barbarian::Barbarian() : Creature()
{
    this->armor = 0;
    this->strength = 12;
    this->name = "Barbarian";
}

/*
~Barbarian()
Empty destructor
*/
Barbarian::~Barbarian(){}

/*
rollAttack()
rollAttack rolls the Barbarian's attack die
*/
int Barbarian::rollAttack()
{
    int roll = AttackDie.rollDie() + AttackDie.rollDie();
    std::cout << "Barbarian rolled " << roll << " attack points!" << std::endl;
    return roll;
}
/*
rollDefense()
rollDefense rolls the Barbarian's defense die
*/
int Barbarian::rollDefense()
{
    int roll = DefenseDie.rollDie() + DefenseDie.rollDie();
    std::cout << "Barbarian rolled " << roll << " defense points!";
    std::cout << std::endl;
    return roll;
}
