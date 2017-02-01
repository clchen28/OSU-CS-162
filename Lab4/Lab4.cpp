/******************************************************************************
** Program name: Lab4.cpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "People.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "Building.hpp"

int main()
{
    Building *myBuilding;
    myBuilding = new Building("Azalea House",10457,"1050 SW MADISON AVE, CORVALLIS, OR 97331");
    //Student *myStudent = Student("Charles Chen", 24, 3.5);
    //Faculty *myFaculty = Faculty("Prof Wee", 35, 3.2);

    myBuilding->printBuilding();
    
    /*
    myBuilding.printBuilding();
    myStudent.printPerson();
    myFaculty.printPerson();
    */


    return 0;
}