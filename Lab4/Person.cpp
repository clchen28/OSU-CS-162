/******************************************************************************
** Program name: Person.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Implementation of Person class.
******************************************************************************/

#include "Person.hpp"

/*
Person(std::string name, int age)
Constructor which initializes a new Person given a name and an age.
*/
Person::Person(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

/*
~Person()
Empty destructor.
*/
Person::~Person(){}

/*
getName()
Returns the name of the specified Person.
*/
std::string Person::getName()
{
    return name;
}
