/******************************************************************************
** Program name: Scissors.hpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Specification of Scissors class.
******************************************************************************/

#include <string>
#include "Tool.hpp"

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

class Scissors : public Tool
{
public:
    Scissors();
    Scissors(int strength);
    virtual std::string fight(Tool* opponentTool);
};

#endif
