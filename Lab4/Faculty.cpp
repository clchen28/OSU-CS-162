/******************************************************************************
** Program name: Faculty.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Implementation of the Faculty class.
******************************************************************************/

#include <iostream>
#include "Person.hpp"
#include "Faculty.hpp"

/*
Faculty(std::string name, int age, float rating) : Person(name, age)
Creates a new Faculty with the given name, age, and faculty rating.
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

/*
~Faculty()
Empty destructor.
*/
Faculty::~Faculty(){}

/*
do_work(int hoursWorked)
Prints out the number of hours that the Faculty has worked
*/
void Faculty::do_work(int hoursWorked)
{
    std::cout << "Instructor " << name << " graded papers for " << hoursWorked;
    std::cout << " hours." << std::endl;
    return;
}

/*
printPerson()
Prints the details of the specified Instructor.
*/
void Faculty::printPerson()
{
    std::cout << "Faculty" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Instructor Rating: " << rating << std::endl;
}


/*
returnPerson()
returnPerson returns the details of this Student in a string
*/
std::string Faculty::returnPerson()
{
    return "Faculty\n" + name + "\n" + std::to_string(age) +
        "\n" + std::to_string(rating) + "\n";
}