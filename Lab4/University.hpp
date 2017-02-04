/******************************************************************************
** Program name: University.hpp
** Author: Charles Chen
** Date: 01/31/2017
** Description:
Contains the specification for the University class.
This class has People (Student, Faculty) and Building objects, stored in
vectors of pointers. It also provides utilities for adding People and
Buildings, as well as printing the contents of People and Buildings.
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
        void deleteAll();
        void saveAll();
        void loadAll();
    private:
        std::string universityName;
        std::vector<Building*> buildings;
        std::vector<Person*> people;
};

#endif