/******************************************************************************
** Program name: Tool.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Implementation of Tool class.
******************************************************************************/

#include "Tool.hpp"

/*
Tool()
Default constructor creates a new Tool with strength 1
*/
Tool::Tool()
{
    setStrength(1);
    this->type[0] = 't';
    this->type[1] = '\0';
}

/*
Tool(int strength)
Constructor creates a new Tool with specified strength.
*/
Tool::Tool(int strength)
{
    setStrength(strength);
    this->type[0] = 't';
    this->type[1] = '\0';
}

/*
void setStrength(int Strength)
Setter method which sets a Tool's strength
*/
void Tool::setStrength(int strength)
{
    this->strength = strength;
    return;
}

/*
int getStrength()
Getter method which returns the Tool's strength
*/
int Tool::getStrength()
{
    return strength;
}

/*
char getType()
Getter method which returns the Tool's type attribute.
*/
char Tool::getType()
{
    return type[0];
}
