/******************************************************************************
** Program name: HarryPotter.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Implementation of HarryPotter class
******************************************************************************/

#include <iostream>
#include <string>
#include "Creature.hpp"
#include "HarryPotter.hpp"

/*
HarryPotter()
Constructor sets life, armor, strength, and name
*/
HarryPotter::HarryPotter() : Creature()
{
    this->life = 2;
    this->armor = 0;
    this->strength = 10;
    this->startingStrength = 10;
    this->name = "Harry Potter";
}

/*
HarryPotter()
Constructor sets life, armor, strength, and name
*/
HarryPotter::HarryPotter(std::string newNickname) : Creature(newNickname)
{
    this->life = 2;
    this->armor = 0;
    this->strength = 10;
    this->startingStrength = 10;
    this->name = "Harry Potter";
}

/*
HarryPotter(const HarryPotter &RHS)
Copy constructor copies HarryPotter specific attributes
*/
HarryPotter::HarryPotter(const HarryPotter &RHS) : Creature(RHS)
{
    this->life = RHS.life;
    this->armor = RHS.armor;
    this->strength = RHS.strength;
    this->startingStrength = RHS.startingStrength;
    this->name = RHS.name;
}

/*
operator=(const HarryPotter &RHS)
Assignment overload copies HarryPotter specific attributes
*/
HarryPotter& HarryPotter::operator=(const HarryPotter &RHS)
{
    if (this != &RHS)
    {
        Creature::operator=(RHS);
        this->life = RHS.life;
        this->armor = RHS.armor;
        this->strength = RHS.strength;
        this->startingStrength = RHS.startingStrength;
        this->name = RHS.name;
    }
    return *this;
}

/*
~HarryPotter()
Empty destructor
*/
HarryPotter::~HarryPotter(){}

/*
rollAttack()
rollAttack rolls Harry Potter's attack die
*/
int HarryPotter::rollAttack()
{
    int roll;
    roll = AttackDie.rollDie() + AttackDie.rollDie();
    std::cout << getNameAndNickname();
    std::cout << " rolled " << roll << " attack points!";
    std::cout << std::endl;
    return roll;
}

/*
rollDefense()
rollDefense rolls Harry Potter's defense die
*/
int HarryPotter::rollDefense()
{
    int roll;
    roll = DefenseDie.rollDie() + DefenseDie.rollDie();
    std::cout << getNameAndNickname();
    std::cout << " rolled " << roll << " defense points!";
    std::cout << std::endl;
    return roll;
}

/*
takeDamage(int attack, int defense)
takeDamage takes two integers as inputs - attack, representing the attack
value of an attack against this object, and defense, representing the
defense points that this object is putting up against the attack. Attack,
defense, and armor are taken into account to determine how much strength this
object loses. If strength drops to zero, life is decremented.
*/
void HarryPotter::takeDamage(int attack, int defense)
{
    int origStrength = strength;
    if (attack > (defense + armor))
    {
        strength -= (attack - defense - armor);
    }
    std::cout << getNameAndNickname() << " strength was " << origStrength;
    std::cout << ", strength is now " << strength << std::endl << std::endl;

    // If strength drops to 0, decrement one life
    if (strength <= 0)
    {
        strength = 0;
        life--;

        // If Harry has just lost his first life, reincarnate with 20 strength
        if (life == 1)
        {
            std::cout << getNameAndNickname();
            std::cout << " uses Hogwarts ability!" << std::endl;
            strength = 20;
            startingStrength = 20;
            std::cout << getNameAndNickname();
            std::cout << " strength is now " << strength << std::endl;
            std::cout << std::endl;
        }
    }
}
