/******************************************************************************
** Program name: Die.cpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:

******************************************************************************/

#include <random>
#include "Die.hpp"

Die::Die()
{
    this->sides = 6;
}

Die::Die(int sides)
{
    this->sides = sides;
}

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