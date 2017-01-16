/******************************************************************************
** Program name: Project1.cpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:
Project1 simply creates a new Ant object via the menu, and then runs the
simulation to completion.
To compile, simple use make.
To run, simply run the executable generated from make, e.g. ./Project1
******************************************************************************/

#include <iostream>
#include <string>
#include "Ant.hpp"
#include "menu.hpp"

int main()
{
	// main initializes the menu, creating a new ant object, and runs the
	// simulation
	Ant myAnt = menu();
	while (myAnt.advancePosition())
	{
		;
	}
	return 0;
}
