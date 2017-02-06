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

int main()
{
    Creature* creature;
    creature = new Medusa;
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
