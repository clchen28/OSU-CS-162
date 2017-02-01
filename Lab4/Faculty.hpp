/******************************************************************************
** Program name: Faculty.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include "People.hpp"

#ifndef FACULTY_HPP
#define FACULTY_HPP

class Faculty : public People
{
    public:
        Faculty(std::string name, int age, float rating);
        virtual ~Faculty();
        virtual void do_work(int hoursWorked);
        virtual void printPerson();
        Faculty& operator=(const Faculty &RHS);
    
    private:
        float rating;
};

#endif