/******************************************************************************
** Program name: Student.hpp
** Author: Charles Chen
** Date: 01/30/2017
** Description:
Specification of the Student class. Students are derived from the Person class.
Students have GPA's, and specialized printPerson and do_work methods.
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