/******************************************************************************
** Program name: HarryPotter.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Creature.hpp"
#include "HarryPotter.hpp"

HarryPotter::HarryPotter() : Creature()
{
    this->life = 2;
    this->armor = 0;
    this->strength = 10;
    Die AttackDie(6);
    Die DefenseDie(6);
}

HarryPotter::~HarryPotter(){}

int HarryPotter::rollAttack()
{
    return AttackDie.rollDie() + AttackDie.rollDie();
}

int HarryPotter::rollDefense()
{
    return DefenseDie.rollDie() + DefenseDie.rollDie();
}

void HarryPotter::takeDamage(int attack, int defense)
{
    if (attack > (defense + armor))
    {
        strength -= (attack - defense - armor);
    }

    if (strength <= 0)
    {
        strength = 0;
        life--;

        if (life == 1)
        {
            std::cout << "Harry Potter uses Hogwarts ability" << std::endl;
            strength = 20;
        }
    }
}
