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

int main()
{
    Creature* creature;
    creature = new HarryPotter;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    creature->takeDamage(5, 2);
    std::cout << creature->getStrength() << std::endl;
    std::cout << creature->getLife() << std::endl;
    delete creature;
    return 0;
}
