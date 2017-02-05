/******************************************************************************
** Program name: revStr.cpp
** Author: Charles Chen
** Date: 02/04/2017
** Description:

******************************************************************************/

#include <string>
#include <iostream>

void revStr(std::string str)
{
    if (str.length() == 0)
    {
        std::cout << "\n";
        return;
    }
    else
    {
        std::cout << str.at(str.length() - 1);
        revStr(str.substr(0,str.length() - 1));
        return;
    }
}