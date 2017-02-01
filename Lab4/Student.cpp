/******************************************************************************
** Program name: Student.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Person.hpp"
#include "Student.hpp"

/*
Student::Student(std::string name, int age) : People(name, age)
{
    // Set gpa to a random number
}
*/

Student::Student(std::string name, int age, float gpa) : Person(name, age)
{
    this->gpa = gpa;
    if (gpa > 4.0)
    {
        this->gpa = 4.0;
    }
    if (gpa < 0.0)
    {
        this->gpa = 0.0;
    }
}

Student::~Student(){}

void Student::do_work(int hoursWorked)
{
    std::cout << name << " did " << hoursWorked << " hours of homework.";
    std::cout << std::endl;
    return;
}

void Student::printPerson()
{
    std::cout << "Student" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
}
