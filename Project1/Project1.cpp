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
	while (myAnt.advancePosition())
	{
		;
	}
	return 0;
}
