/******************************************************************************
** Program name: Faculty.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Specification of the Faculty class. The Faculty class is derived from the
Person class, and has specialized do_work and printPerson methods. Faculty
also have a rating.
******************************************************************************/

#include <string>
#include "Person.hpp"

#ifndef FACULTY_HPP
#define FACULTY_HPP

class Faculty : public Person
{
    public:
        Faculty(std::string name, int age, float rating);
        virtual ~Faculty();
        virtual void do_work(int hoursWorked);
        virtual void printPerson();
        virtual std::string returnPerson();
    
    private:
        float rating;
};

#endif