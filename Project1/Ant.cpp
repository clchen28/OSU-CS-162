/******************************************************************************
** Program name: Ant.cpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:
Implementation of Ant class.
******************************************************************************/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Ant.hpp"

/*
Ant::Ant
This Ant constructor takes in the number of rows/cols of the board, the
ant's starting location, and the ant's starting direction, and creates a board
that represents these inputs, as well as placing the ant at the specified
starting location.
*/
Ant::Ant(int nRows, int mCols, int nSteps, int startingRow, int startingCol,
	std::string startingDir)
{
	stepCount = 0;

	// It is assumed that, at the start, all squares are white
	antColor = " ";

	rows = nRows;
	cols = mCols;
	steps = nSteps;
	antRow = startingRow;
	antCol = startingCol;
	antDir = startingDir;
	board = createBoard(rows, cols, antRow, antCol);

	// Print board after it has initialized to show the starting location of
	// the ant
	printBoard();
}

Ant::~Ant()
{
	// Ant destructor deallocates memory for board array
	for (int i = 0; i < rows; i++)
    {
		delete [] board[i];
    }
    delete [] board;
}

std::string** Ant::createBoard(int rows, int cols, int antRow, int antCol)
{
	// createBoard takes the row/col count and starting location of the ant,
	// and creates a new board with these given initial conditions.

	// Representing the board as a 2D array of strings
	// * represents the ant, a whitespace represents a white square, and
	// a # represents a black square
	std::string** myBoard = new std::string*[rows];
    for (int i = 0; i < rows; i++)
    {
        myBoard[i] = new std::string[cols];
    }

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((i == antRow) && (j == antCol))
			{
				myBoard[i][j] = "*";
			}
			else
				{
					myBoard[i][j] = " ";
				}
		}
	}
	return myBoard;
}

void Ant::printBoard()
{
	// printBoard takes the current representation of the board array and
	// prints a graphical representation of it to the terminal

	// Print underscores to denote the top border of board
	std::cout << "Step " << stepCount << ":" << std::endl;
	for (int i = 0; i < cols; i++)
	{
		std::cout << "_";
	}
	std::cout << std::endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	return;
}

bool Ant::advancePosition()
{
	// advancePosition advances the Langton's Ant algorithm one step forward.
	// The return type of this function is a boolean. The function returns true
	// when the last step of the algorithm has been reached, and returns false
	// otherwise. This allows the user to either advance the algorithm one step
	// at a time, or to use a loop to advance the algorithm all the way to
	// completion.

	// Save last coordinate and color - needed to modify board representation
	int lastRow = antRow;
	int lastCol = antCol;
	std::string lastColor = antColor;

	// Two possibilities - square is white, or square is black
	// First, deal with situation if square is white
	if (antColor == " ")
	{
		// Rotate ant right
		if (antDir == "up")
		{
			antDir = "right";
		}
		else if (antDir == "right")
		{
			antDir = "down";
		}
		else if (antDir == "down")
		{
			antDir = "left";
		}
		else if (antDir == "left")
		{
			antDir = "up";
		}
	}
	// If square is black
	else if (antColor == "#")
	{
		// Rotate ant left
		if (antDir == "up")
		{
			antDir = "left";
		}
		else if (antDir == "left")
		{
			antDir = "down";
		}
		else if (antDir == "down")
		{
			antDir = "right";
		}
		else if (antDir == "right")
		{
			antDir = "up";
		}
	}

	// Advance ant in direction it is facing
	if (antDir == "up")
	{
		antRow -= 1;
	}
	else if (antDir == "left")
	{
		antCol -= 1;
	}
	else if (antDir == "down")
	{
		antRow += 1;
	}
	else if (antDir == "right")
	{
		antCol += 1;
	}

	// Implement edge case logic - if ant has reached the border of the board,
	// then mirror its location to the other side of the board
	if (antRow == rows)
	{
		antRow = 0;
	}
	if (antRow == -1)
	{
		antRow = rows - 1;
	}
	if (antCol == cols)
	{
		antCol = 0;
	}
	if (antCol == -1)
	{
		antCol = cols - 1;
	}

	// Save color of ant's current square
	antColor = board[antRow][antCol];

	// Change color of last square
	if (lastColor == " ")
	{
		board[lastRow][lastCol] = "#";
	}
	else if (lastColor == "#")
	{
		board[lastRow][lastCol] = " ";
	}

	// Change board's representation of ant square
	board[antRow][antCol] = "*";

	stepCount++;

	std::this_thread::sleep_for (std::chrono::seconds(1));
	printBoard();

	if (stepCount < steps)
	{
		return true;
	}
	else
	{
		return false;
	}
}