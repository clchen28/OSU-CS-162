/******************************************************************************
** Program name: Person.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Specification of Person class.

Person class is an abstract class. Student and Faculty classes are derived from
it. Every Person has a name and age. do_work and printPerson are abstract
methods which are overridden by derived classes.
******************************************************************************/

#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

class Person
{
    public:
        Person(std::string name, int age);
        virtual ~Person();
        virtual void do_work(int hoursWorked) = 0;
        virtual void printPerson() = 0;
        std::string getName();

    protected:
        std::string name;
        int age;
};

#endif