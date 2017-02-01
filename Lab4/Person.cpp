/******************************************************************************
** Program name: People.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include "Person.hpp"

Person::Person(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

Person::~Person(){}

std::string Person::getName()
{
    return name;
}
