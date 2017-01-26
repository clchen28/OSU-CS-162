/******************************************************************************
** Program name: menu.hpp
** Author: Charles Chen
** Date: 01/23/2017
** Description:
Specification of the menu functions
******************************************************************************/

#include <string>
#include "Game.hpp"

#ifndef MENU_HPP
#define MENU_HPP

void printMenu(int rows, int cols, int steps, int startingRow, int startingCol,
    std::string startingDir);
Game menu();

#endif
