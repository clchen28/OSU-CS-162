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
Tool(const Tool &RHS)
Copy constructor creates a new Tool with the same strength as another
*/
Tool::Tool(const Tool &RHS)
{
    this->setStrength(RHS.getStrength());
    this->type[0] = 't';
    this->type[1] = '\0';
}

/*
operator=(const Tool &RHS)
Assignment overload changes the attributes of one Tool to match that of
the other
*/
Tool& Tool::operator=(const Tool &RHS)
{
    if (this != &RHS)
    {
        this->setStrength(RHS.getStrength());
        this->type[0] = 't';
        this->type[1] = '\0';
    }
    return *this;
}

/*
~Tool()
Empty destructor.
*/
Tool::~Tool(){}

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
int Tool::getStrength() const
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
