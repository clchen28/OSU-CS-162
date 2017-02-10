/******************************************************************************
** Program name: Game.cpp
** Author: Charles Chen
** Date: 02/09/2017
** Description:
Implementation of functions related to running the game.
******************************************************************************/

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "Game.hpp"
#include "Creature.hpp"

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
    // Set first attack to Creature1
    int curAttacker = 1;
    while (!Creature1->isDead() && !Creature2->isDead())
    {
        // Attack the other Creature
        if (curAttacker == 1)
        {
            attackCreature(Creature1, Creature2);
        }
        else if (curAttacker == 2)
        {
            attackCreature(Creature2, Creature1);
        }

        // With this move complete, swap attackers
        if (curAttacker == 1)
        {
            curAttacker = 2;
        }
        else if (curAttacker == 2)
        {
            curAttacker = 1;
        }
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    std::this_thread::sleep_for (std::chrono::seconds(1));
    // Determine which Creature is dead, print who won
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

/*
randNum(int n)
randNum takes in a number n of integers, and will return a random integer
between 1 and n, inclusive. Similar functionality as Die object, bundled into
a function instead.
*/
int randNum(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,n);
    return dist(gen);
}
