/******************************************************************************
** Program name: People.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include "People.hpp"

People::People(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

People::~People(){}

std::string People::getName()
{
    return name;
}