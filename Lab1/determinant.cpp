/******************************************************************************
** Program name: determinant.cpp
** Author: Charles Chen
** Date: 01/10/2017
** Description:

Inputs:
matrix - 2D Array of ints (technically, pointer to an array of pointers), for
which the determinant is to be calculated
size - integer, number of rows/columns of matrix

Prerequisities:
size must be either 2 or 3

Outputs:
det - an int, which represents the determinant of matrix

determinant is a function which, given a matrix and the size of the matrix,
will calculate and return the determinant of the given matrix.
******************************************************************************/

#include <iostream>

int determinant(int** matrix, int size)
{
    double det;

    if (size == 2)
    {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else if (size == 3)
    {
        det = matrix[0][0] * matrix[1][1] * matrix[2][2]
            + matrix[0][1] * matrix[1][2] * matrix[2][0]
            + matrix[0][2] * matrix[1][0] * matrix[2][1]
            - matrix[0][2] * matrix[1][1] * matrix[2][0]
            - matrix[0][0] * matrix[1][2] * matrix[2][1]
            - matrix[0][1] * matrix[1][0] * matrix[2][2];
    }
    return det;
}
