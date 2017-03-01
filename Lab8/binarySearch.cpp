/******************************************************************************
** Program name: binarySearch.cpp
** Author: Charles Chen
** Date: 02/28/2017
** Description:
Implementation of binary search algorithm, based on Gaddis Ch 9.1.
******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

int binarySearch(std::vector<int> numbers, int searchValue)
{
    if (numbers.size() == 0)
    {
        return -1;
    }

    int index = -1;
    int first = 0;
    int last = numbers.size() - 1;

    while ((numbers[index] != searchValue) && (first <= last))
    {
        index = (last + first) / 2;

        if (numbers[index] == searchValue)
        {
            return index;
        }
        else if (numbers[index] > searchValue)
        {
            last = index - 1;
        }
        else
        {
            first = index + 1;
        }
    }
    return -1;
}
