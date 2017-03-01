/******************************************************************************
** Program name: linearSearch.cpp
** Author: Charles Chen
** Date: 02/27/2017
** Description:
Implementation of linear search (Gaddis p. 604), with some modifications.
******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

int linearSearch(std::vector<int> numbers, int searchValue)
{
    int index = 0;
    bool searchFound = false;
    while (index < numbers.size())
    {
        if (numbers[index] == searchValue)
        {
            return index;
        }
        index++;
    }
    return -1;
}

int main()
{
    std::ifstream earlyFile("early.txt");
    std::ifstream middleFile("middle.txt");
    std::ifstream lateFile("late.txt");

    std::vector<int> early;
    std::vector<int> middle;
    std::vector<int> late;

    int current;
    while (earlyFile >> current)
    {
        early.push_back(current);
    }
    while (middleFile >> current)
    {
        middle.push_back(current);
    }
    while (lateFile >> current)
    {
        late.push_back(current);
    }

    std::cout << "'Early' vector:" << std::endl;
    for (int i = 0; i < early.size(); i++)
    {
        std::cout << early[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Index of 0 in 'Early' vector: ";
    std::cout << linearSearch(early, 0) << std::endl;

    std::cout << "'Middle' vector:" << std::endl;
    for (int i = 0; i < middle.size(); i++)
    {
        std::cout << middle[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Index of 0 in 'middle' vector: ";
    std::cout << linearSearch(middle, 0) << std::endl;

    std::cout << "'Late' vector:" << std::endl;
    for (int i = 0; i < late.size(); i++)
    {
        std::cout << late[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Index of 0 in 'late' vector: ";
    std::cout << linearSearch(late, 0) << std::endl;

    earlyFile.close();
    middleFile.close();
    lateFile.close();
    return 0;
}
