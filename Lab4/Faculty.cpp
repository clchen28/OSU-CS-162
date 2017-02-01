/******************************************************************************
** Program name: Faculty.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Person.hpp"
#include "Faculty.hpp"

/*
Faculty::Faculty(std::string name, int age) : People(name, age)
{
    // Set rating to a random number
}
*/

Faculty::Faculty(std::string name, int age, float rating) : Person(name, age)
{
    this->rating = rating;
    if (rating > 5.0)
    {
        this->rating = 5.0;
    }
    if (rating < 0.0)
    {
        this->rating = 0.0;
    }
}

Faculty::~Faculty(){}

void Faculty::do_work(int hoursWorked)
{
    std::cout << "Instructor " << name << " graded papers for " << hoursWorked;
    std::cout << " hours." << std::endl;
    return;
}

void Faculty::printPerson()
{
    std::cout << "Faculty" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Instructor Rating: " << rating << std::endl;
}

Faculty& Faculty::operator=(const Faculty &RHS)
{
    if (this != &RHS)
    {
        name = RHS.name;
        age = RHS.age;
        rating = RHS.rating;
    }
    return *this;
}