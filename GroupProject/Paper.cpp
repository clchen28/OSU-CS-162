/******************************************************************************
** Program name: Paper.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Implementation of Paper class.
******************************************************************************/

#include <string>
#include "Tool.hpp"
#include "Paper.hpp"

/*
Paper()
Default constructor sets the Rock type attribute
*/
Paper::Paper() : Tool()
{
    this->type[0] = 'p';
}

/*
Paper(int strength)
Constructor calls Tool's constructor to set strength to the user specified
input, and sets the type attribute
*/
Paper::Paper(int strength) : Tool(strength)
{
    this->type[0] = 'p';
}

/*
Paper(const Paper &RHS)
Copy constructor creates a new Paper with the same strength as another
*/
Paper::Paper(const Paper &RHS) : Tool(RHS)
{
    this->type[0] = 'p';
}

/*
operator=(const Paper &RHS)
Assignment overload changes the attributes of one Paper to match that of
the other
*/
Paper& Paper::operator=(const Paper &RHS)
{
    if (this != &RHS)
    {
        Tool::operator=(RHS);
        this->type[0] = 'p';
    }
    return *this;
}

/*
~Paper()
Empty destructor.
*/
Paper::~Paper(){}

/*
std::string fight(Tool* opponentTool)
Fight method takes a pointer to another Tool, and determines which will win,
based on the relative values of their strength attributes.
Returns a string of "win", "loss", or "tie", based on results
*/
std::string Paper::fight(Tool* opponentTool)
{
    // Set a temporary strength, so that the actual strength attribute is not
    // modified
    int tempStrength = strength;

    // Temporarily half this Tool's strength if the opponent is Scissors
    // Temporarily double this Tool's strength if the opponent is Rock
    if (opponentTool->getType() == 's')
    {
        tempStrength /= 2;
    }
    else if (opponentTool->getType() == 'r')
    {
        tempStrength *= 2;
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
