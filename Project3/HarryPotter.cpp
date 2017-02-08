/******************************************************************************
** Program name: HarryPotter.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Creature.hpp"
#include "HarryPotter.hpp"

HarryPotter::HarryPotter() : Creature()
{
    this->life = 2;
    this->armor = 0;
    this->strength = 10;
    this->name = "Harry Potter";
}

HarryPotter::~HarryPotter(){}

int HarryPotter::rollAttack()
{
    int roll;
    roll = AttackDie.rollDie() + AttackDie.rollDie();
    std::cout << "Harry Potter rolled " << roll << " attack points!";
    std::cout << std::endl;
    return roll;
}

int HarryPotter::rollDefense()
{
    int roll;
    roll = DefenseDie.rollDie() + DefenseDie.rollDie();
    std::cout << "Harry Potter rolled " << roll << " defense points!";
    std::cout << std::endl;
    return roll;
}

void HarryPotter::takeDamage(int attack, int defense)
{
    if (attack > (defense + armor))
    {
        strength -= (attack - defense - armor);
    }
    std::cout << "Strength is now " << strength << std::endl;

    if (strength <= 0)
    {
        strength = 0;
        life--;

        if (life == 1)
        {
            std::cout << "Harry Potter uses Hogwarts ability!" << std::endl;
            strength = 20;
            std::cout << "Strength is now " << strength << std::endl;
        }
    }
}
