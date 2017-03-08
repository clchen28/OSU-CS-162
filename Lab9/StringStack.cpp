/******************************************************************************
** Program name: StringStack.cpp
** Author: Charles Chen
** Date: 03/07/2017
** Description:
Provides a function to return a string and its palindrome
******************************************************************************/

#include "StringStack.hpp"
#include <iostream>
#include <stack>
#include <string>

/*
palindrome(std::string inStr)
palindrome takes a string as input, and returns a string containing the input
string concatenated with its palindrome
*/
std::string palindrome(std::string inStr)
{
    std::stack<char> temp;

    // Pushes characters in input string to stack
    for (int i = 0; i < inStr.length(); i++)
    {
        temp.push(inStr[i]);
    }

    std::string outStr = inStr;

    while (!temp.empty())
    {
        // Stack is FILO, so palindrome can be obtained by popping off top of
        // stack until it is empty
        outStr = outStr + temp.top();
        temp.pop();
    }
    return outStr;
}
