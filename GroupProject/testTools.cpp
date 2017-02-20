/******************************************************************************
** Program name: testTools.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Tool.hpp"
#include "Paper.hpp"
#include "Rock.hpp"
#include "Scissors.hpp"

int main()
{
    Tool* tool1;
    Tool* tool2;
    tool1 = new Rock;
    tool2 = new Paper;

    std::cout << tool1->fight(tool2) << std::endl;

    return 0;
}
