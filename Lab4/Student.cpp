/******************************************************************************
** Program name: Student.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Implementation of the Student class.
******************************************************************************/

#include <iostream>
#include "Person.hpp"
#include "Student.hpp"

/*
Student(std::string name, int age, float gpa) : Person(name, age)
Creates a new Student object with the specified name, age, and GPA.
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

/*
~Student()
Empty destructor.
*/
Student::~Student(){}

/*
do_work(int hoursWorked)
do_work takes the input hours worked, and prints out what the student worked on
*/
void Student::do_work(int hoursWorked)
{
    std::cout << name << " did " << hoursWorked << " hours of homework.";
    std::cout << std::endl;
    return;
}

/*
printPerson()
printPerson prints out the details of this specific Student.
*/
void Student::printPerson()
{
    std::cout << "Student" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
}

/*
returnPerson()
returnPerson returns the details of this Student in a string
*/
std::string Student::returnPerson()
{
    return "Student\n" + name + "\n" + std::to_string(age) +    
        "\n" + std::to_string(gpa) + "\n";
}