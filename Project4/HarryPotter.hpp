/******************************************************************************
** Program name: HarryPotter.hpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Specificaion of HarryPotter class
******************************************************************************/

#include "Creature.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Creature
{
public:
    HarryPotter();
    HarryPotter(std::string newNickname);
    HarryPotter(const HarryPotter &RHS);
    HarryPotter& operator=(const HarryPotter &RHS);
    ~HarryPotter();
    virtual int rollAttack();
    virtual int rollDefense();
    virtual void takeDamage(int attack, int defense);
};

#endif
