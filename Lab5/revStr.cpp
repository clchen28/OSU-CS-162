/******************************************************************************
** Program name: revStr.cpp
** Author: Charles Chen
** Date: 02/04/2017
** Description:
revStr is a program that takes in a string and then prints out the reverse of
that string, using recursion.
******************************************************************************/

#include <string>
#include <iostream>

void revStr(std::string str)
{
    // Base case - the reverse of an empty string is itself
    // In this case, print newline when recursion terminates
    if (str.length() == 0)
    {
        std::cout << "\n";
        return;
    }

    // Recursive step - the reverse of a string is the last element of that
    // string, concatenated with the reverse of the rest of the string
    else
    {
        std::cout << str.at(str.length() - 1);  // Last element of string
        revStr(str.substr(0,str.length() - 1)); // Concatenate with reverse of 
                                                // rest of string
        return;
    }
}