/******************************************************************************
** Program name: LoadedDie.cpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:

******************************************************************************/

#include <random>
#include <vector>
#include "Die.hpp"
#include "LoadedDie.hpp"

LoadedDie::LoadedDie() : Die()
{
}

LoadedDie::LoadedDie(int sides) : Die(sides)
{
}

int LoadedDie::rollDie()
{
    // Using a discrete distribution. Documentation:
    // https://msdn.microsoft.com/en-us/library/ee462326.aspx
    std::random_device rd;
    std::mt19937 gen(rd());

    // Constructing a vector of weights
    // Higher numbers are 5 times as likely to be generated
    std::vector<double> weights;
    for (int i = 1; i < this->sides/2; i++)
    {
        weights.push_back(1);
    }
    for (int i = this->sides/2; i <= this->sides; i++)
    {
        weights.push_back(5);
    }

    std::discrete_distribution<> distribution(begin(weights),end(weights));

    // Need to add 1 to have results from [1,sides], not [0,sides-1]
    return distribution(gen) + 1;
}
