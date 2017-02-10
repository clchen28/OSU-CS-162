/******************************************************************************
** Program name: BlueMen.hpp
** Author: Charles Chen
** Date: 02/07/2017
** Description:
Specification of BlueMen class
******************************************************************************/

#include "Creature.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Creature
{
private:
    int numDefenseDie;
public:
    BlueMen();
    ~BlueMen();
    virtual int rollDefense();
    virtual int rollAttack();
    virtual void takeDamage(int attack, int defense);
};

#endif
