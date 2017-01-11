/******************************************************************************
** Program name: readMatrix.cpp
** Author: Charles Chen
** Date: 01/09/2017
** Description:
Inputs:
matrix - 2D Array of ints (technically, pointer to an array of pointers), for
which the determinant is to be calculated
size - integer, number of rows/columns of matrix

Prerequisities:
size must be either 2 or 3

readMatrix is a function which takes in a matrix, the size of this matrix,
and prompts the user for values for each element of this matrix.
******************************************************************************/

#include <iostream>

void readMatrix(int** matrix, int size)
{
    if (size == 2)
    {
        std::cout << "Enter in the number for Row 1/Col 1:" << std::endl;
        std::cin >> matrix[0][0];
        std::cout << "Enter in the number for Row 1/Col 2:" << std::endl;
        std::cin >> matrix[0][1];
        std::cout << "Enter in the number for Row 2/Col 1:" << std::endl;
        std::cin >> matrix[1][0];
        std::cout << "Enter in the number for Row 2/Col 2:" << std::endl;
        std::cin >> matrix[1][1];
        return;
    }

    if (size == 3)
    {
        std::cout << "Enter in the number for Row 1/Col 1:" << std::endl;
        std::cin >> matrix[0][0];
        std::cout << "Enter in the number for Row 1/Col 2:" << std::endl;
        std::cin >> matrix[0][1];
        std::cout << "Enter in the number for Row 1/Col 3:" << std::endl;
        std::cin >> matrix[0][2];
        std::cout << "Enter in the number for Row 2/Col 1:" << std::endl;
        std::cin >> matrix[1][0];
        std::cout << "Enter in the number for Row 2/Col 2:" << std::endl;
        std::cin >> matrix[1][1];
        std::cout << "Enter in the number for Row 2/Col 3:" << std::endl;
        std::cin >> matrix[1][2];
        std::cout << "Enter in the number for Row 3/Col 1:" << std::endl;
        std::cin >> matrix[2][0];
        std::cout << "Enter in the number for Row 3/Col 2:" << std::endl;
        std::cin >> matrix[2][1];
        std::cout << "Enter in the number for Row 3/Col 3:" << std::endl;
        std::cin >> matrix[2][2];
        return;
    }
}
