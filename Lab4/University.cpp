/******************************************************************************
** Program name: University.cpp
** Author: Charles Chen
** Date: 01/31/2017
** Description:
Contains the implementation of the University class.
******************************************************************************/

#include <string>
#include <fstream>
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

/*
deleteAll()
deleteAll will deallocate memory that was dynamically allocated for every
object in the University, and then set the people and buildings member
attributes to be empty vectors.
*/
void University::deleteAll()
{
    // Deallocates memory allocated for every Person in people
    for (int i = 0; i < people.size(); i++)
    {
        delete people[i];
    }
    people.clear();

    // Deallocates memory allocated for every Building in buildings
    for (int i = 0; i < buildings.size(); i++)
    {
        delete buildings[i];
    }
    buildings.clear();

}

/*
saveAll
saveAll takes all Person and Building members in the University and outputs
the details to an output.txt file on disk.
*/
void University::saveAll()
{
    std::ofstream outputFile;
    outputFile.open("output.txt");
    // Uses returnPerson method of each member attribute, and saves to
    // output.txt
    if (outputFile)
    {
        for (int i = 0; i < people.size(); i++)
        {
            outputFile << people[i]->returnPerson();
        }
        for (int i = 0; i < buildings.size(); i++)
        {
            outputFile << buildings[i]->returnBuilding();
        }
        outputFile.close();
    }
}

/*
loadAll
loadAll reads in output.txt and reads in attribute information, and adds these
members to the current university
*/
void University::loadAll()
{
    // First, delete all attributes of current University
    // This allows loadAll to overwrite the contents of the current University
    this->deleteAll();

    std::string inputType;
    std::string input1;
    std::string input2;
    std::string input3;

    std::ifstream inputFile;
    inputFile.open("output.txt");
    if (inputFile)
    {
        // output.txt is formatted with 4 lines for each Building or Person
        // The first line is either Building, Student, or Faculty
        // input1, input2, and input3 (the next 3 lines) correspond to strings
        // that can be used with each class's constructor
        while (std::getline(inputFile, inputType))
        {
            std::getline(inputFile, input1);
            std::getline(inputFile, input2);
            std::getline(inputFile, input3);

            std::cout << "input1 is " << input1 << std::endl;
            std::cout << "input2 is " << input2 << std::endl;
            std::cout << "input3 is " << input3 << std::endl;

            // input1, inptu2, and input3 are, in order, the parameters
            // needed for each class's constructor
            // This selects the appropriate constructor, based on the input
            // type
            if (inputType == "Student")
            {
                this->addStudent(input1, std::stoi(input2), std::stof(input3));
            }
            else if (inputType == "Faculty")
            {
                this->addFaculty(input1, std::stoi(input2), std::stof(input3));
            }
            else if (inputType == "Building")
            {
                this->addBuilding(input1, std::stoi(input2), input3);
            }
        }
        
        inputFile.close();
    }
}