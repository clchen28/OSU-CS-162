/******************************************************************************
** Program name: Ant.cpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:

******************************************************************************/

Ant::Ant(int nRows, int mCols, int startingRow, int startingCol)
{
	stepCount = 0;
	rows = nRows;
	cols = mCols;
	antRow = startingRow;
	antCol = startingCol;
	createBoard(rows, cols, antRow, antCol);
}
