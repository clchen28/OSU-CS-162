/******************************************************************************
** Program name: Creature.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Implementation of Creature class.
******************************************************************************/

#include <iostream>
#include "Creature.hpp"

/*
Creature()
Creature() constructor creates a new Creature object, and initializes a
common life attribute for all Creature objects.
*/
Creature::Creature()
{
    life = 1;
    Die AttackDie(6);
    Die DefenseDie(6);
}

/*
~Creature()
Empty ~Creature() destructor.
*/
Creature::~Creature(){}

/*
getArmor()
Returns the armor attribute
*/
int Creature::getArmor()
{
    return armor;
}

/*
getStrength()
Returns the strength attribute
*/
int Creature::getStrength()
{
    return strength;
}

/*
getLife()
Returns the life attribute
*/
int Creature::getLife()
{
    return life;
}

/*
takeDamage(int attack, int defense)
takeDamage takes two integers as inputs - attack, representing the attack
value of an attack against this Creature, and defense, representing the
defense points that this Creature is putting up against the attack. Attack,
defense, and armor are taken into account to determine how much strength this
Creature loses. If strength drops to zero, life is decremented.
*/
void Creature::takeDamage(int attack, int defense)
{
    if (attack > (defense + armor))
    {
        strength -= (attack - defense - armor);
    }

    if (strength <= 0)
    {
        strength = 0;
        life--;
    }
    std::cout << "Strength is now " << strength << std::endl;
}

/*
isDead()
isDead returns true if the Creature is dead
*/
bool Creature::isDead()
{
    if (life <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
