/******************************************************************************
** Program name: People.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include <string>

#ifndef PEOPLE_HPP
#define PEOPLE_HPP

class People
{
    public:
        People(std::string name, int age);
        virtual ~People();
        virtual void do_work(int hoursWorked) = 0;
        std::string getName();

    protected:
        std::string name;
        int age;
};

#endif