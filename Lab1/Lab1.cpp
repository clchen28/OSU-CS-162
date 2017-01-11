/******************************************************************************
** Program name: Lab1.cpp
** Author: Charles Chen
** Date: 01/09/2017
** Description:

******************************************************************************/

#include <iostream>
#include "readMatrix.hpp"

int main()
{
    int size;
    std::cout << "Enter number of rows/columns in your matrix: 2 or 3: ";
    std::cin >> size;

    // Error catching - prevents matrices of size other than 2 or 3 from
    // being entered
    while ( !((size == 2) || (size == 3)) )
    {
        std::cout << "Must enter a matrix of size 2 or 3." << std::endl;
        std::cout << "Enter number of rows in your matrix: 2 or 3: ";
        std::cin >> size;
    }

    // Allocation of memory for an array of pointers to arrays
    double** matrix = new double*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
    }

    readMatrix(matrix, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << std::endl;
        }
    }

    // Deallocation of memory for matrix
    for (int i = 0; i < size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}
