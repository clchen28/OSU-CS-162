/******************************************************************************
** Program name: Rock.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Implementation of Rock class.
******************************************************************************/

#include <string>
#include "Tool.hpp"
#include "Rock.hpp"

/*
Rock()
Default constructor sets the Rock type attribute
*/
Rock::Rock() : Tool()
{
    this->type[0] = 'r';
}

/*
Rock(int strength)
Constructor calls Tool's constructor to set strength to the user specified
input, and sets the type attribute
*/
Rock::Rock(int strength) : Tool(strength)
{
    this->type[0] = 'r';
}

/*
std::string Fight(Tool* opponentTool)
Fight method takes a pointer to another Tool, and determines which will win,
based on the relative values of their strength attributes.
Returns a string of "win", "loss", or "tie", based on results
*/
std::string Rock::fight(Tool* opponentTool)
{
    // Set a temporary strength, so that the actual strength attribute is not
    // modified
    int tempStrength = strength;

    // Temporarily double this Tool's strength if the opponent is Scissors
    // Temporarily half this Tool's strength if the opponent is Paper
    if (opponentTool->getType() == 's')
    {
        tempStrength *= 2;
    }
    else if (opponentTool->getType() == 'p')
    {
        tempStrength /= 2;
    }

    // Compare strength, determine winner
    if (tempStrength > opponentTool->getStrength())
    {
        return "win";
    }
    else if (tempStrength < opponentTool->getStrength())
    {
        return "loss";
    }
    else
    {
        return "tie";
    }
}
