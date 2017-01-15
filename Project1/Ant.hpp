/******************************************************************************
** Program name: Ant.hpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:

******************************************************************************/

#include <string>
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
    public:
    Ant(int nRows, int mCols, int startingRow, int startingCol,
	    std::string startingDir);
    void printBoard();

    private:
    int stepCount;
    int rows;
    int cols;
    int antRow;
    int antCol;
    std::string antDir;
    std::string** antBoard;
    std::string** createBoard(int rows, int cols, int antRow, int antCol);
};

#endif