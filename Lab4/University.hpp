/******************************************************************************
** Program name: University.hpp
** Author: Charles Chen
** Date: 01/31/2017
** Description:

******************************************************************************/

#include <string>
#include <vector>
#include "Person.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "Building.hpp"

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

class University
{
    public:
        University(std::string universityName);
        ~University();
        void addStudent(std::string name, int age, float gpa);
        void addFaculty(std::string name, int age, float rating);
        void addBuilding(std::string name, int size, std::string address);
        void printPeopleNames();
        void printPeople();
        void printBuildings();
        void personToDoWork(int personInd, int hours);
        int getPeopleCount();
    private:
        std::string universityName;
        std::vector<Building*> buildings;
        std::vector<Person*> people;
};

#endif