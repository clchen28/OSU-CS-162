/******************************************************************************
** Program name: Lab4.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

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
    
    menu(osu);
    
    /*
    myBuilding.printBuilding();
    myStudent.printPerson();
    myFaculty.printPerson();
    */


    return 0;
}