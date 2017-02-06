/******************************************************************************
** Program name: Medusa.hpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Creature
{
public:
    Medusa();
    ~Medusa();
    virtual int rollAttack();
    virtual int rollDefense();
};

#endif
