/******************************************************************************
** Program name: listTest.cpp
** Author: Charles Chen
** Date: 01/28/2017
** Description:
listTest is a test program designed to test the correct functionality of
the List class's copy constructor and assignment overloads

To compile:
make listTest

To run:
./listTest
******************************************************************************/

#include <iostream>
#include "Item.hpp"
#include "List.hpp"

int main()
{
    List list1;
    list1.addItem("item1","unit1",1,1);
    list1.addItem("item2","unit2",2,2);
    list1.addItem("item3","unit3",3,3);
    list1.addItem("item4","unit4",4,4);
    list1.addItem("item5","unit5",5,5);
    std::cout << "Created list1, with 5 items" << std::endl;

    List list2 = list1;
    std::cout << "Created list2 from list1 with copy constructor" << std::endl;

    List list3;
    list3 = list1;
    std::cout << "Created list3 from list1 with assignment" << std::endl;

    list1.removeItem("item5");
    std::cout << "Removing item5 from list1" << std::endl;

    list1.addItem("item6","unit6",6,6);
    std::cout << "Adding item6 to list1" << std::endl;

    std::cout << "Printing list1, list2, and list3" << std::endl;
    std::cout << "Output of list1 should be missing item5" << std::endl;
    std::cout << "Output of list1 should have item6" << std::endl;
    std::cout << "Output of list2 and list3 should be the same" << std::endl;
    std::cout << "Output of list2 and 3 should not have item6" << std::endl;

    std::cout << "List 1:" << std::endl;
    list1.printList();

    std::cout << "List 2:" << std::endl;
    list2.printList();

    std::cout << "List 3:" << std::endl;
    list3.printList();
}