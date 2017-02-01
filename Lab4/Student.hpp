/******************************************************************************
** Program name: Student.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:

******************************************************************************/

#include "Person.hpp"

#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student : public Person
{
    public:
        Student(std::string name, int age, float gpa);
        virtual ~Student();
        virtual void do_work(int hoursWorked);
        virtual void printPerson();

    private:
        float gpa;

};

#endif