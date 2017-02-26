/******************************************************************************
** Program name: Creature.hpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Specification for abstract Creature class.
******************************************************************************/

#include <string>
#include "Die.hpp"

#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature
{
protected:
    int armor;
    int strength;
    int life;
    int startingStrength;
    std::string name;
    std::string nickname;
    Die AttackDie;
    Die DefenseDie;
public:
    Creature();
    Creature(std::string newNickname);
    Creature(const Creature &RHS);
    Creature& operator=(const Creature &RHS);
    virtual ~Creature();
    virtual int rollAttack() = 0;
    virtual int rollDefense() = 0;
    int getArmor();
    int getStrength();
    int getLife();
    virtual void takeDamage(int attack, int defense);
    bool isDead();
    std::string getName();
    void setNickname(std::string newNickname);
    std::string getNickname();
    void restoreStrength();
};

#endif
