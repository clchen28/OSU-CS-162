/******************************************************************************
** Program name: Vampire.hpp
** Author: Charles Chen
** Date: 02/06/2017
** Description:
Specification for Vampire class.
******************************************************************************/

#include "Die.hpp"
#include "Creature.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Creature
{
private:
    Die CharmDie;
    Die AttackDie;
public:
    Vampire();
    ~Vampire();
    virtual int rollAttack();
    virtual int rollDefense();
};

#endif
