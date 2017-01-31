/******************************************************************************
** Program name: Faculty.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include <iostream>
#include "People.hpp"
#include "Faculty.hpp"

/*
Faculty::Faculty(std::string name, int age) : People(name, age)
{
    // Set rating to a random number
}
*/

Faculty::Faculty(std::string name, int age, float rating) : People(name, age)
{
    this->rating = rating;
}

Faculty::~Faculty(){}

void Faculty::do_work(int hoursWorked)
{
    std::cout << "Instructor " << name << " graded papers for " << hoursWorked;
    std::cout << " hours." << std::endl;
    return;
}