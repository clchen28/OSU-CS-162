/******************************************************************************
** Program name: Paper.hpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Specification of Paper class.
******************************************************************************/

#include <string>
#include "Tool.hpp"

#ifndef PAPER_HPP
#define PAPER_HPP

class Paper : public Tool
{
public:
    Paper();
    Paper(int strength);
    virtual std::string fight(Tool* opponentTool);
};

#endif
