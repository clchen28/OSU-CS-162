/******************************************************************************
** Program name: triNum.cpp
** Author: Charles Chen
** Date: 02/04/2017
** Description:
triNum takes an integer, n, and calculates the triangular number about this n.
The triangular number is returned as an integer.
******************************************************************************/

#include "triNum.hpp"

int triNum(int n)
{
    // Base case - triangular number about 0 is 0
    if (n <= 0)
    {
        return 0;
    }
    // Recursive case - triangular number about n is n added to the triangular
    // number about the integer 1 less than n.
    else
    {
        return n + triNum(n-1);
    }
}
