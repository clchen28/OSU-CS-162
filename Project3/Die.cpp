/******************************************************************************
** Program name: Die.cpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:
Die.cpp contains the implementation of the Die class.
******************************************************************************/

#include <string>
#include <random>
#include "Die.hpp"

/*
Die()
The default constructor for the die class will create a die object of 6 sides.
*/
Die::Die()
{
    this->sides = 6;
    this->dieType = "normal";
}

/*
Die(int sides) is a constructor that will create a Die object with the given
number of sides.
*/
Die::Die(int sides)
{
    this->sides = sides;
    this->dieType = "normal";
}

/*
~Die is a destructor for the Die class. There are no dynamically allocated
members of the Die class.
*/
Die::~Die()
{}

/*
rollDie() returns an integer, representing the result of randomly rolling
the die. It uses a random number generator to do so.
*/
int Die::rollDie()
{
    // Using <random> library with a uniform random distribution
    // Source: https://msdn.microsoft.com/en-us/library/bb982398.aspx
    // Chose to use this library, as it results in a more uniform random
    // distribution than the pseudo-random rand() function from <cstdlib>
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,this->sides);
    return dist(gen);
}

/*
getType() returns the type of the die. The dieType for the base Die class
is "normal".
*/
std::string Die::getType()
{
    return dieType;
}

/*
getSides() returns the number of sides of the specified Die object.
*/
int Die::getSides()
{
    return sides;
}

/*
setSides(int sides)
setSides takes and integer number of sides as input, and sets the number of
sides of this Die object.
*/
void Die::setSides(int sides)
{
    if (sides >= 2)
    {
        this->sides = sides;
    }
}
