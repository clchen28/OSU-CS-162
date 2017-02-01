/******************************************************************************
** Program name: University.cpp
** Author: Charles Chen
** Date: 01/31/2017
** Description:
Contains the implementation of the University class.
******************************************************************************/

#include <string>
#include <iostream>
#include "Person.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "University.hpp"
#include "inputValidator.hpp"

/*
University(std::string universityName)
The constructor creates a new University object with the given university name.
*/
University::University(std::string universityName)
{
    this->universityName = universityName;
}

/*
~University()
The destructor deallocates memory that was dynamically allocated for the
vectors which contain pointers to Person and Building objects.
*/
University::~University()
{
    for (int i = 0; i < people.size(); i++)
    {
        delete people[i];
    }
    for (int i = 0; i < buildings.size(); i++)
    {
        delete buildings[i];
    }
}

/*
addStudent(std::string name, int age, float gpa)
addStudent takes a student name, student age, and student GPA, creates a new
Student object with these inputs, and stores it in the people attribute. In 
particular, memory is dynamically allocated for this new Student, and a 
pointer to this new Student is stored in people.
*/
void University::addStudent(std::string name, int age, float gpa)
{
    for (int i = 0; i < people.size(); i++)
    {
        if (people[i]->getName() == name)
        {
            std::cout << "Student already exists - ignoring" << std::endl;
            return;
        }
    }
    people.push_back(new Student(name, age, gpa));
    return;
}

/*
addFaculty(std::string name, int age, float rating)
addFaculty takes a faculty name, faculty age, and faculty rating, creates a new
Faculty object with these inputs, and stores it in the people attribute. In 
particular, memory is dynamically allocated for this new Faculty, and a 
pointer to this new Faculty is stored in people.
*/
void University::addFaculty(std::string name, int age, float rating)
{
    for (int i = 0; i < people.size(); i++)
    {
        if (people[i]->getName() == name)
        {
            std::cout << "Faculty already exists - ignoring" << std::endl;
            return;
        }
    }
    people.push_back(new Faculty(name, age, rating));
    return;
}

/*
addBuilding(std::string name, int size, std::string address)
addBuilding takes a building name, size in sq ft, and address, and creates a 
new Building with these given parameters. Memory is dynamically allocated for 
this new Building, and the pointer to this object is stored in the buildings
attribute.
*/
void University::addBuilding(std::string name, int size, std::string address)
{
    for (int i = 0; i < buildings.size(); i++)
    {
        if (buildings[i]->getBuildingName() == name)
        {
            std::cout << "Building already exists - ignoring" << std::endl;
            return;
        }
    }
    buildings.push_back(new Building(name, size, address));
    return;
}

/*
printPeople()
printPeople prints the details of every person in the university - name and 
age. For students, the GPA is printed - for faculty, faculty rating is 
printed.
*/
void University::printPeople()
{
    if (people.size() == 0)
    {
        std::cout << "No people at university" << std::endl;
    }
    else
    {
        std::cout << "People:" << std::endl;
        for (int i = 0; i < people.size(); i++)
        {
            people[i]->printPerson();
            std::cout << std::endl;
        }
    }
    return;
}

/*
printPeopleNames()
printPeopleNames prints just the names of everyone in the University, as well 
as an index next to each name.
*/
void University::printPeopleNames()
{
    if (people.size() == 0)
    {
        std::cout << "No people at university" << std::endl;
    }
    else
    {
        std::cout << "People names:" << std::endl;
        for (int i = 0; i < people.size(); i++)
        {
            std::cout << i << ": ";
            std::cout << people[i]->getName() << std::endl;
        }
    }
    return;
}

/*
printBuildings()
printBuildings prints the details of every Building in the University. Namely, 
it will print the building name, size in square feet, and address of each
building.
*/
void University::printBuildings()
{
    if (buildings.size() == 0)
    {
        std::cout << "No buildings at university" << std::endl;
    }
    else
    {
        std::cout << "Buildings:" << std::endl;
        for (int i = 0; i < buildings.size(); i++)
        {
            buildings[i]->printBuilding();
            std::cout << std::endl;
        }
    }
    return;
}

/*
personToDoWork(int personInd, int hours)
personToDoWork takes an integer which represents the index of a certain Person,
and an integer number of hours. It then calls that Person's do_work method,
which prints prints out that Person's name and how many hours they've worked.
*/
void University::personToDoWork(int personInd, int hours)
{
    if (people.size() == 0)
    {
        return;
    }

    people[personInd]->do_work(hours);
    return;
}

/*
getPeopleCount()
getPeopleCount returns the number of People in the University.
*/
int University::getPeopleCount()
{
    return people.size();
}