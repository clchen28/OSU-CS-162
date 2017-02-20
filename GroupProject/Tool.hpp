/******************************************************************************
** Program name: Tool.hpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Specification of Tool class.
******************************************************************************/

#include <string>

#ifndef TOOL_HPP
#define TOOL_HPP

class Tool
{
public:
    Tool();
    Tool(int strength);
    Tool(const Tool &RHS);
    Tool& operator=(const Tool &RHS);
    virtual ~Tool();
    void setStrength(int strength);
    int getStrength() const;
    char getType();
    virtual std::string fight(Tool* opponentTool) = 0;
protected:
    int strength;
    char type[2];
};

#endif
