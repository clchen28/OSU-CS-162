/******************************************************************************
** Program name: readMatrix.cpp
** Author: Charles Chen
** Date: 01/09/2017
** Description:

******************************************************************************/

#include <iostream>

void readMatrix(double** matrix, int matrixSize)
{
    if (matrixSize == 2)
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

    if (matrixSize == 3)
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
