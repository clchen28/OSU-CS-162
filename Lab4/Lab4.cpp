/******************************************************************************
** Program name: Lab4.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Lab4 is a University information system simulator, containing information
about the university. It contains Building and Person objects. The main program
manually initializes the University, adds a Student, a Faculty, and two
Buildings, then displays a menu which gives the user the ability to add
more objects, display results, or to have a Person do work.

To compile:
make

To run:
./Lab4
******************************************************************************/

#include <iostream>
#include <string>
#include "Person.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "Building.hpp"
#include "University.hpp"
#include "menu.hpp"

int main()
{
    University osu("Oregon State University");
    osu.addStudent("Charles Chen", 24, 3.9);
    osu.addFaculty("Tim Alcon", 35, 4.9);
    osu.addBuilding("Bell Tower", 518, "CORVALLIS, OR 97331");
    osu.addBuilding("Dryden Hall", 19418,
        "450 SW 30TH STREET, CORVALLIS, OR 97331");
    
    menu(osu);

    return 0;
}