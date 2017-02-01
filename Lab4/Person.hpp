/******************************************************************************
** Program name: People.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

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