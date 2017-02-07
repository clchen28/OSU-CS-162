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

int main()
{
    Creature* creature;
    creature = new Vampire;

    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;
    creature->takeDamage(3,creature->rollDefense());
    std::cout << creature->getStrength() << std::endl;

    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;
    std::cout << creature->rollAttack() << std::endl;

    delete creature;

    return 0;
}
