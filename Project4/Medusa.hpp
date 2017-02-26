/******************************************************************************
** Program name: Medusa.hpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Specification of Medusa class
******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Creature
{
public:
    Medusa();
    Medusa(std::string newNickname);
    Medusa(const Medusa &RHS);
    Medusa& operator=(const Medusa &RHS);
    ~Medusa();
    virtual int rollAttack();
    virtual int rollDefense();
};

#endif
