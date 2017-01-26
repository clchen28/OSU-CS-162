/******************************************************************************
** Program name: LoadedDie.cpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:
LoadedDie.cpp contains the implementation of the LoadedDie class.
******************************************************************************/

#include <string>
#include <random>
#include <vector>
#include "Die.hpp"
#include "LoadedDie.hpp"

/*
LoadedDie()
The default constructor of the LoadedDie class inherits the Die constructor
to set the number of sides. The dieType is set to "loaded".
*/
LoadedDie::LoadedDie() : Die()
{
    this->dieType = "loaded";
}

/*
LoadedDie()
This constructor of the LoadedDie class inherits the Die constructor to take an
input, which is used to set the number of sides. The dieType is set to "loaded"
*/
LoadedDie::LoadedDie(int sides) : Die(sides)
{
    this->dieType = "loaded";
}

/*
~LoadedDie() is destructor for the LoadedDie class. There are no dynamically
allocated members of the LoadedDie class.
*/
LoadedDie::~LoadedDie()
{}

/*
rollDie() returns an integer, representing the result of randomly rolling
the die. It uses a random number generator to do so. The rollDie method
contained in the LoadedDie class uses a piecewise constant distribution,
with weights set such that higher numbers are 4 times as likely to roll as
compared to lower numbers.
*/
int LoadedDie::rollDie()
{
    // Using a piecewise constant distribution:
    // http://stackoverflow.com/questions/1761626/weighted-random-numbers
    // More resources:
    // https://msdn.microsoft.com/en-us/library/ee462281.aspx
    std::random_device rd;
    std::mt19937 gen(rd());

    // Intervals represents the possible die roll results
    std::vector<int> intervals;
    for (int i = 1; i <= sides + 1; i++)
    {
        intervals.push_back(i);
    }

    // Constructing a vector of weights
    // Higher numbers are 4 times as likely to be generated
    std::vector<double> weights;
    for (int i = 1; i <= sides; i++)
    {
        if (i <= sides/2)
        {
            weights.push_back(1);
        }
        else
        {
            weights.push_back(4);
        }
    }

    std::piecewise_constant_distribution<> distribution(begin(intervals),
        end(intervals),begin(weights));
    return distribution(gen);
}

/*
getType() returns the type of the die. The dieType for the base Die class
is "loaded".
*/
std::string LoadedDie::getType()
{
    return dieType;
}

/*
getSides() returns the number of sides of the specified LoadedDie object.
*/
int LoadedDie::getSides()
{
    return sides;
}