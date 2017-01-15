/******************************************************************************
** Program name: Ant.cpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Ant.hpp"

/* Ant::Ant
This Ant constructor takes in the number of rows/cols of the board, the
ant's starting location, and the ant's starting direction, and creates a board
that represents these inputs, as well as placing the ant at the specified
starting location.
*/
Ant::Ant(int nRows, int mCols, int startingRow, int startingCol,
	std::string startingDir)
{
	stepCount = 0;
	rows = nRows;
	cols = mCols;
	antRow = startingRow;
	antCol = startingCol;
	antDir = startingDir;
	antBoard = createBoard(rows, cols, antRow, antCol);
}

std::string** Ant::createBoard(int rows, int cols, int antRow, int antCol)
{
	// Representing the board as a 2D array of strings
	// * represents the ant, a whitespace represents a white square, and
	// a # represents a black square
	std::string** board = new std::string*[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new std::string[cols];
    }

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((i == antRow) && (j == antCol))
			{
				board[i][j] = "*";
			}
			else
				{
					board[i][j] = " ";
				}
		}
	}
	return board;
}

void Ant::printBoard()
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << "_";
	}
	std::cout << std::endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << antBoard[i][j];
		}
		std::cout << std::endl;
	}
	return;
}