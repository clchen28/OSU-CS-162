/******************************************************************************
** Program name: Project1.cpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>

int main()
{
	int rows;
	int cols;
	int steps;
	int startingRow;
	int startingCol;
	string startingDir;
	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	std::cout << "Enter number of cols: ";
	std::cin >> cols;
	std::cout << "Enter number of steps: ";
	std::cin >> steps;
	std::cout << "Enter row of starting location of ant. Enter -1 for a" <<
		" random row";
	std::cin >> startingRow;
	std::cout << "Enter col of starting location of ant. Enter -1 for a" <<
		" random col";
	std::cin > startingCol;
	std::cout << "Enter starting direction of ant: left, right, up, or " <<
		"down";
	std::cin > startingDir;
}
