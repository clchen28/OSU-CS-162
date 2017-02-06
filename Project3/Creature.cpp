/******************************************************************************
** Program name: Creature.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#include "Creature.hpp"

Creature::Creature()
{
    life = 1;
}

Creature::~Creature(){}

int Creature::getArmor()
{
    return armor;
}

int Creature::getStrength()
{
    return strength;
}

int Creature::getLife()
{
    return life;
}

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

}
