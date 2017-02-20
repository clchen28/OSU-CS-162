/******************************************************************************
** Program name: Scissors.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Implementation of Scissors class.
******************************************************************************/

#include <string>
#include "Tool.hpp"
#include "Scissors.hpp"

/*
Scissors()
Default constructor sets the Scissors type attribute
*/
Scissors::Scissors() : Tool()
{
    this->type[0] = 's';
}

/*
Scissors(int strength)
Constructor calls Tool's constructor to set strength to the user specified
input, and sets the type attribute
*/
Scissors::Scissors(int strength) : Tool(strength)
{
    this->type[0] = 's';
}

/*
Scissors(const Scissors &RHS)
Copy constructor creates a new Scissors with the same strength as another
*/
Scissors::Scissors(const Scissors &RHS) : Tool(RHS)
{
    this->type[0] = 's';
}

/*
operator=(const Scissors &RHS)
Assignment overload changes the attributes of one Paper to match that of
the other
*/
Scissors& Scissors::operator=(const Scissors &RHS)
{
    if (this != &RHS)
    {
        Tool::operator=(RHS);
        this->type[0] = 's';
    }
    return *this;
}

/*
~Scissors()
Empty destructor
*/
Scissors::~Scissors(){}

/*
std::string Fight(Tool* opponentTool)
Fight method takes a pointer to another Tool, and determines which will win,
based on the relative values of their strength attributes.
Returns a string of "win", "loss", or "tie", based on results
*/
std::string Scissors::fight(Tool* opponentTool)
{
    // Set a temporary strength, so that the actual strength attribute is not
    // modified
    int tempStrength = strength;

    // Temporarily half this Tool's strength if the opponent is Rock
    // Temporarily double this Tool's strength if the opponent is Paper
    if (opponentTool->getType() == 'r')
    {
        tempStrength /= 2;
    }
    else if (opponentTool->getType() == 'p')
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
