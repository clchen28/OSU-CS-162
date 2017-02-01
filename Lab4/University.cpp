/******************************************************************************
** Program name: University.cpp
** Author: Charles Chen
** Date: 01/31/2017
** Description:

******************************************************************************/

#include <string>
#include <iostream>
#include "Person.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "University.hpp"
#include "inputValidator.hpp"

University::University(std::string universityName)
{
    this->universityName = universityName;
}

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

void University::addStudent(std::string name, int age, float gpa)
{
    people.push_back(new Student(name, age, gpa));
    return;
}

void University::addFaculty(std::string name, int age, float rating)
{
    people.push_back(new Faculty(name, age, rating));
    return;
}

void University::addBuilding(std::string name, int size, std::string address)
{
    buildings.push_back(new Building(name, size, address));
    return;
}

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

void University::personToDoWork(int personInd, int hours)
{
    if (people.size() == 0)
    {
        return;
    }

    people[personInd]->do_work(hours);
    return;
}

int University::getPeopleCount()
{
    return people.size();
}