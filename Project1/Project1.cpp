/******************************************************************************
** Program name: Project1.cpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Ant.hpp"
#include "menu.hpp"

int main()
{
	Ant myAnt = menu();
	std::cout << myAnt.stepCount << std::endl;
    std::cout << myAnt.rows << std::endl;
    std::cout << myAnt.cols << std::endl;
    std::cout << myAnt.antRow << std::endl;
    std::cout << myAnt.antCol << std::endl;
    std::cout << myAnt.antDir << std::endl;
	return 0;
}
