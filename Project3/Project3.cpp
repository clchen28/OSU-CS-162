/******************************************************************************
** Program name: Project3.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Die.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "menu.hpp"

/*
attackCreature(Creature* Attacker, Creature* Defender)
attackCreature takes the pointers to an attacker Creature and Defender
Creature. It rolls the attack die for the Attacker, the Defense Die for the
defender, and calls the Defender's takeDamage method.
*/
void attackCreature(Creature* Attacker, Creature* Defender)
{
    Defender->takeDamage(Attacker->rollAttack(), Defender->rollDefense());
    return;
}

/*
playGame(Creature* Creature1, Creature* Creature2)
playGame takes pointers to two Creature objects, and sets the first one to
attack first, and has them attack each other until one of them dies.
*/
void playGame(Creature* Creature1, Creature* Creature2)
{
    int curAttacker = 1;
    while (!Creature1->isDead() && !Creature2->isDead())
    {
        if (curAttacker == 1)
        {
            attackCreature(Creature1, Creature2);
        }
        else if (curAttacker == 2)
        {
            attackCreature(Creature2, Creature1);
        }

        if (curAttacker == 1)
        {
            curAttacker = 2;
        }
        else if (curAttacker == 2)
        {
            curAttacker = 1;
        }
    }

    if (Creature1->isDead() && !Creature2->isDead())
    {
        std::cout << "Creature 1, " << Creature1->getName() << ", is dead!";
        std::cout << std::endl;

        std::cout << "Creature 2, " << Creature2->getName() << ", is the ";
        std::cout << "winner!" << std::endl;
    }
    else if (Creature2->isDead() && !Creature1->isDead())
    {
        std::cout << "Creature 2, " << Creature2->getName() << ", is dead!";
        std::cout << std::endl;

        std::cout << "Creature 1, " << Creature1->getName() << ", is the ";
        std::cout << "winner!" << std::endl;
    }
    return;
}

int main()
{
    //menu();
    Creature *creature;
    creature = new Barbarian;
    std::cout << creature->getName() << std::endl;
    return 0;
}
