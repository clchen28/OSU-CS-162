/******************************************************************************
** Program name: menu.cpp
** Author: Charles Chen
** Date: 01/13/2017
** Description:
Implementation of menu-related functions
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>
#include "inputValidator.hpp"
#include "University.hpp"

/*
printMenu displays the available options
*/
void printMenu()
{
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Print details of buildings" << std::endl;
    std::cout << "2. Print details of people at university" << std::endl;
    std::cout << "3. Print list of names of people at university" << std::endl;
    std::cout << "4. Choose a person to do work" << std::endl;
    std::cout << "5. Add building to university" << std::endl;
    std::cout << "6. Add person to university" << std::endl;
    std::cout << "7. Exit program" << std::endl;
    return;
}

/*
menu is a function that is intended to provide a starting point for
the University

It takes in an initialized University object as reference, and provides an API
for accessing its methods. Specifically, it allows the user to add People and
Buildings to the University, print the details of Buildings and People, and
choose a Person to do work. These tasks are all performed through University
member methods.
*/
void menu(University &university)
{
    int personInd = -1;
    int hours = -1;
    std::string bldgName = "";
    int bldgSize = -1;
    std::string bldgAddress = "";
    std::string personType = "";
    std::string personName = "";
    float studentGPA = -1.0;
    float facultyRating = -1.0;
    int personAge = -1;

    int selection = -1;
    
    // These lambda functions are used for the input validation function later
    auto inputBetweenTwoValues = [](int input, int value1, int value2) -> bool
                {
                    return (input >= value1) && (input <= value2);
                };
    auto intInputPositive = [](int input) -> bool {return input >= 1;};
    auto intAbove18 = [](int input) -> bool {return input >= 18;};
    auto notEmptyString = [](std::string input) -> bool {return input != "";};
    auto validGPA = [](float input) -> bool
                {
                    return (input >= 0.0) && (input <= 4.0);
                };
    auto validRating = [](float input) -> bool
                {
                    return (input >= 0.0) && (input <= 5.0);
                };
    auto allowedPersonTypes = [](std::string input) -> bool
                {
                    return (input == "student")
                        || (input == "faculty");
                };

    while (selection != 7)
    {
        printMenu();
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');
        
        // Selects submenu item
        switch (selection)
        {
            case 1:
                university.printBuildings();
                std::cout << std::endl;
            break;

            case 2:
                university.printPeople();
                std::cout << std::endl;
            break;

            case 3:
                university.printPeopleNames();
                std::cout << std::endl;
            break;

            case 4:
                // Prints everyone's name
                university.printPeopleNames();

                // Will do nothing if there is no one in University
                if (university.getPeopleCount() != 0)
                {
                    std::cout << std::endl;
                    inputValidator(personInd, 0, university.getPeopleCount() - 1,
                        inputBetweenTwoValues,
                        "Enter index number of person",
                        "Enter from above index numbers");
                    inputValidator(hours,
                        intInputPositive,
                        "Enter number of hours to work",
                        "Enter a positive number of hours to work");

                    university.personToDoWork(personInd, hours);

                    personInd = -1;
                    hours = -1;
                    std::cout << std::endl;
                }
            break;

            case 5:
                inputValidator(bldgName, notEmptyString,
                        "Enter name of building",
                        "Do not enter an empty string for building name");
                inputValidator(bldgSize, intInputPositive,
                        "Enter size of building in sq ft",
                        "Size must be a positive number");
                inputValidator(bldgAddress, notEmptyString,
                        "Enter address of building",
                        "Do not enter an empty string for building address");

                university.addBuilding(bldgName, bldgSize, bldgAddress);
                
                bldgName = "";
                bldgSize = -1;
                bldgAddress = "";
            break;

            case 6:
                // Adds a new person
                inputValidator(personType, allowedPersonTypes,
                        "Adding student or faculty? ",
                        "Enter: student or faculty");
                inputValidator(personName, notEmptyString,
                        "Enter name of person",
                        "Do not enter an empty string for person's name");
                inputValidator(personAge, intAbove18,
                        "Enter person's age - must be 18 or older",
                        "Age must be a number 18 or older");

                // Call different method depending on whether new Person is a 
                // Student or Faculty
                if (personType == "student")
                {
                    inputValidator(studentGPA, validGPA,
                            "Enter student's GPA",
                            "GPA must be between 0.0 and 4.0");
                    university.addStudent(personName, personAge, studentGPA);
                }
                if (personType == "faculty")
                {
                    inputValidator(facultyRating, validRating,
                            "Enter faculty's rating",
                            "Rating must be between 0.0 and 5.0");
                    university.addFaculty(personName, personAge, facultyRating);
                }

                bldgAddress = "";
                personType = "";
                personName = "";
                studentGPA = -1.0;
                facultyRating = -1.0;
                personAge = -1;
            break;

            case 7:
                std::cout << "Exiting..." << std::endl;
            break;

            default:
                std::cout << "Enter a valid menu item (1 through 7)" << std::endl;
        }
    }

    return;
}
