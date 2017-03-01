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
#include <string>
#include "inputValidator.hpp"

/*
selectionSort(std::vector<int> &numbers)
selectionSort takes a vector of integers, and sorts it in ascending order
using selection sort
*/
void selectionSort(std::vector<int> &numbers)
{
    // vector is already sorted if it is of size 0 or 1
    if (numbers.size() <= 1)
    {
        return;
    }

    int minInd;
    int minVal;
    int oldMinVal;

    // Outer loop - from first element to second to last element
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        // Set minInd - ultimately, the smallest number from the current index
        // to the end of the vector should be located in this current index
        minInd = i;
        minVal = numbers[minInd];
        oldMinVal = minVal;

        // Inner loop - find the smallest remaining element of the vector,
        // and place it at the current index
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
    // Used for input validation function
    auto notEmpty = [](std::string input) -> bool
            {
                bool allSpaces = true;
                for (int i = 0; i < input.length(); i++)
                {
                    if (!isspace(input[i]))
                    {
                        allSpaces = false;
                    }
                }
                return (input != "" && !allSpaces);
            };

    // File containing an unsorted set of integers
    std::ifstream originalFile("original.txt");

    std::vector<int> numbers;

    int current;
    // Reads in original file contents into unsorted vector
    while (originalFile >> current)
    {
        numbers.push_back(current);
    }

    // Prints the unsorted vector to screen
    std::cout << "Unsorted vector:" << std::endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Prompts the user for filename of output
    std::string outputFilename;
    inputValidator(outputFilename, notEmpty,
        "Input a filename for the output of the sorted data: ",
        "Filename can not be blank or whitespaces only");
    std::ofstream outputFile(outputFilename);

    // Sorts vector, displays it, and outputs to file
    selectionSort(numbers);
    std::cout << "Sorted vector:" << std::endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
        outputFile << numbers[i];
        outputFile << '\n';
    }
    std::cout << std::endl;

    originalFile.close();
    outputFile.close();
}
