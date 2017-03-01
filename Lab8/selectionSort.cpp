/******************************************************************************
** Program name: selectionSort.cpp
** Author: Charles Chen
** Date: 02/27/2017
** Description:
Implementation of Selection Sort, from Gaddis p 619.
******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

void selectionSort(std::vector<int> &numbers)
{
    if (numbers.size() <= 1)
    {
        return;
    }

    int minInd;
    int minVal;
    int oldMinVal;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        minInd = i;
        minVal = numbers[minInd];
        oldMinVal = minVal;
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[j] < minVal)
            {
                minInd = j;
                minVal = numbers[j];
            }
        }
        numbers[i] = minVal;
        numbers[minInd] = oldMinVal;
    }
}

int main()
{
    std::vector<int> myNums = {4, 2, 5, 2, 3, 1, 3, 2, 3, 6, 8};
    selectionSort(myNums);
    for (int i = 0; i < myNums.size(); i++)
    {
        std::cout << myNums[i] << std::endl;
    }
}
