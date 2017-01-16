/******************************************************************************
** Program name: Ant.hpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:
Specification of Ant class. The ant class contains several attributes that
describe the row and column count of its board, step counts, ant coordinates,
and methods that advance the Langton's Ant simulations and display the board.
******************************************************************************/

#include <string>
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
    public:
    Ant(int nRows, int mCols, int nSteps, int startingRow, int startingCol,
	    std::string startingDir);
    ~Ant();
    void printBoard();
    bool advancePosition();

    private:
    int stepCount;
    int rows;
    int cols;
    int steps;
    int antRow;
    int antCol;
    std::string antColor;
    std::string antDir;
    std::string** board;
    std::string** createBoard(int rows, int cols, int antRow, int antCol);
};

#endif