/******************************************************************************
** Program name: Lab1.cpp
** Author: Charles Chen
** Date: 01/09/2017
** Description:
This program prompts the user to enter in the number of rows and columns for
a matrix (either 2 or 3), then prompts the user to fill in each element of the
matrix. The program the prints out the matrix, as well as the determinant.
** Usage:
Simply run the executable compiled from make.
./Lab1
******************************************************************************/

#include <iostream>
#include <iomanip>
#include "readMatrix.hpp"
#include "determinant.hpp"

int main()
{
    const int OUTPUT_WIDTH = 10;

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
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }

    readMatrix(matrix, size);
    int det = determinant(matrix, size);

    std::cout << "The matrix is:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << std::setw(OUTPUT_WIDTH) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "The determinant is: " << det << std::endl;

    // Deallocation of memory for matrix
    for (int i = 0; i < size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}
