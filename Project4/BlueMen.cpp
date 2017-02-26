/******************************************************************************
** Program name: BlueMen.cpp
** Author: Charles Chen
** Date: 02/07/2017
** Description:
Implementation of BlueMen class
******************************************************************************/

#include <iostream>
#include <string>
#include "Creature.hpp"
#include "BlueMen.hpp"

/*
BlueMen()
Creates a new BlueMen object. Sets armor and strength attributes. BlueMen
defense attribute scales with strength, so numDefenseDie is initialized here
as well.
*/
BlueMen::BlueMen() : Creature()
{
    this->armor = 3;
    this->strength = 12;
    this->startingStrength = 12;
    this->numDefenseDie = 3;
    Creature::AttackDie.setSides(10);
    this->name = "Blue Men";
}

/*
BlueMen()
Creates a new BlueMen object. Sets armor and strength attributes. BlueMen
defense attribute scales with strength, so numDefenseDie is initialized here
as well.
*/
BlueMen::BlueMen(std::string newNickname) : Creature(newNickname)
{
    this->armor = 3;
    this->strength = 12;
    this->startingStrength = 12;
    this->numDefenseDie = 3;
    Creature::AttackDie.setSides(10);
    this->name = "Blue Men";
}

/*
BlueMen(const BlueMen &RHS)
Copy constructor copies BlueMen speciifc attributes, and also sets the
number of sides on the AttackDie appropriately.
*/
BlueMen::BlueMen(const BlueMen &RHS) : Creature(RHS)
{
    this->armor = RHS.armor;
    this->strength = RHS.strength;
    this->startingStrength = RHS.startingStrength;
    this->numDefenseDie = RHS.numDefenseDie;
    Creature::AttackDie.setSides(RHS.AttackDie.getSides());
    this->name = RHS.name;
}

/*
operator=(const BlueMen &RHS)
Assignment overload sets BlueMen specific attributes, and also sets the number
of sides on the AttackDie appropriately.
*/
BlueMen& BlueMen::operator=(const BlueMen &RHS)
{
    if (this != &RHS)
    {
        Creature::operator=(RHS);
        this->armor = RHS.armor;
        this->strength = RHS.strength;
        this->startingStrength = RHS.startingStrength;
        this->numDefenseDie = RHS.numDefenseDie;
        Creature::AttackDie.setSides(RHS.AttackDie.getSides());
        this->name = RHS.name;
    }
    return *this;
}

/*
~BlueMen()
Empty destructor
*/
BlueMen::~BlueMen(){}

/*
rollDefense()
Returns an integer representing the roll of the Defense dice
*/
int BlueMen::rollDefense()
{
    int roll = 0;

    // Need to roll Defense Die for the number of Defense Die still left
    for (int i = 1; i <= numDefenseDie; i++)
    {
        roll += DefenseDie.rollDie();
    }
    std::cout << "Blue Men rolled " << roll << " defense points!";
    std::cout << std::endl;
    return roll;
}

/*
rollAttack()
Returns an integer representing the roll of the Attack dice
*/
int BlueMen::rollAttack()
{
    int roll = AttackDie.rollDie() + AttackDie.rollDie();
    std::cout << "Blue Men rolled " << roll << " attack points!";
    std::cout << std::endl;
    return roll;
}

/*
takeDamage(int attack, int defense)
takeDamage takes two integers as inputs - attack, representing the attack
value of an attack against this Creature, and defense, representing the
defense points that this Creature is putting up against the attack. Attack,
defense, and armor are taken into account to determine how much strength this
Creature loses. If strength drops to zero, life is decremented.

For the BlueMen takeDamage method, the number of defense die is also
decremented for every time that strength drops by 4 from the original value of
12.
*/
void BlueMen::takeDamage(int attack, int defense)
{
    int origStrength = strength;
    if (attack > (defense + armor))
    {
        strength -= (attack - defense - armor);
    }
    std::cout << name << " strength was " << origStrength;
    std::cout << ", strength is now " << strength << std::endl;

    // Check strength to determine if number of DefenseDie needs to be reduced
    // This if branch is set up so that the method will only change the
    // number of Defense Die if necessary.
    if (numDefenseDie == 3 && strength <= 8)
    {
        numDefenseDie = 2;
        std::cout << "Blue Men strength dropped below 8 - two Defense Die ";
        std::cout << "left!" << std::endl;
        if (strength <= 4)
        {
            numDefenseDie = 1;
            std::cout << "Blue Men strength dropped below 4 - one Defense ";
            std::cout << "Die left!" << std::endl;
        }
    }
    else if (numDefenseDie == 2 && strength <= 4)
    {
        numDefenseDie = 1;
        std::cout << "Blue Men strength dropped below 4 - one Defense ";
        std::cout << "Die left!" << std::endl;
    }
    std::cout << std::endl;

    // Decrement life if strength drops to 0
    if (strength <= 0)
    {
        strength = 0;
        life--;
    }

}
