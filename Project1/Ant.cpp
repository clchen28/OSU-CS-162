/******************************************************************************
** Program name: Ant.cpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Ant.hpp"

Ant::Ant(int nRows, int mCols, int startingRow, int startingCol,
	std::string startingDir)
{
	stepCount = 0;
	rows = nRows;
	cols = mCols;
	antRow = startingRow;
	antCol = startingCol;
	antDir = startingDir;
	//createBoard(rows, cols, antRow, antCol, startingDir);
}
