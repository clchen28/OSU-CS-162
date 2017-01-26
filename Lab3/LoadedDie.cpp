/******************************************************************************
** Program name: LoadedDie.cpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:

******************************************************************************/

#include <string>
#include <random>
#include <vector>
#include "Die.hpp"
#include "LoadedDie.hpp"

LoadedDie::LoadedDie() : Die()
{
    this->dieType = "loaded";
}

LoadedDie::LoadedDie(int sides) : Die(sides)
{
    this->dieType = "loaded";
}

int LoadedDie::rollDie()
{

    // Using a piecewise constant distribution:
    // http://stackoverflow.com/questions/1761626/weighted-random-numbers
    // More resources:
    // https://msdn.microsoft.com/en-us/library/ee462281.aspx
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<int> intervals;
    for (int i = 1; i <= sides + 1; i++)
    {
        intervals.push_back(i);
    }

    // Constructing a vector of weights
    // Higher numbers are 3 times as likely to be generated
    std::vector<double> weights;
    for (int i = 1; i <= sides; i++)
    {
        if (i <= sides/2)
        {
            weights.push_back(1);
        }
        else
        {
            weights.push_back(3);
        }
    }

    std::piecewise_constant_distribution<> distribution(begin(intervals),
        end(intervals),begin(weights));
    return distribution(gen);
}

std::string LoadedDie::getType()
{
    return dieType;
}

int LoadedDie::getSides()
{
    return sides;
}