/******************************************************************************
** Program name: Ant.hpp
** Author: Charles Chen
** Date: 01/11/2017
** Description:

******************************************************************************/

#include <string>

class Ant
{
    public:
    Ant(int nRows, int mCols, int startingRow, int startingCol,
	    std::string startingDir);
    int stepCount;
    int rows;
    int cols;
    int antRow;
    int antCol;
    std::string antDir;
};