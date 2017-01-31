/******************************************************************************
** Program name: Student.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include <iostream>
#include "People.hpp"
#include "Student.hpp"

/*
Student::Student(std::string name, int age) : People(name, age)
{
    // Set gpa to a random number
}
*/

Student::Student(std::string name, int age, float gpa) : People(name, age)
{
    this->gpa = gpa;
}

Student::~Student(){}

void Student::do_work(int hoursWorked)
{
    std::cout << name << " did " << hoursWorked << " hours of homework.";
    std::cout << std::endl;
    return;
}