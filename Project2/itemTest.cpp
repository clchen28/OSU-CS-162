/******************************************************************************
** Program name: itemTest.cpp
** Author: Charles Chen
** Date: 01/28/2017
** Description:
itemTest contains a test program which demonstrates multiple test cases
of the Item object, shown in isolation.

To compile:
make itemTest

To run:
./itemTest
******************************************************************************/

#include <iostream>
#include "Item.hpp"


int main()
{
    Item item1("item1","unit1",3,4.30);
    std::cout << "Checking for proper function of getExtPrice for nominal";
    std::cout << " inputs - should be 7.65" << std::endl;
    item1.printItem();

    std::cout << "Tests the proper functioning of copy constructor" << std::endl;
    std::cout << "Output should be the same as above" << std::endl;
    Item item2 = item1;
    item2.printItem();

    std::cout << "Tests the proper functioning of overloaded assignment";
    std::cout << std::endl;
    std::cout << "Output should be the same as above" << std::endl;
    Item item3;
    item3 = item1;
    item3.printItem();

    std::cout << "Tests proper overloading of == operator" << std::endl;
    std::cout << "item3 == item1 should evaluate to true: " << std::endl;
    if (item3 == item1)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    std::cout << "item1 == \"item1\" should evaluate to true: " << std::endl;
    if (item1 == "item1")
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    Item item4("item4","unit4", 2, 3.99);
    std::cout << "Created item4 with name of item4" << std::endl;
    std::cout << "Tests proper overloading of != operator" << std::endl;
    std::cout << "item4 != item1 should evaluate to true: " << std::endl;
    if (item4 != item1)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    std::cout << "item4 != \"item3\" should evaluate to false: " << std::endl;
    if (item4 != "item3")
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    Item item5("item5","unit5", -5, -5);
    std::cout << "Created item5 with negative quantity and price" << std::endl;
    std::cout << "Output should show these set to 0: " << std::endl;
    item5.printItem();

    Item item6("item 6","unit 6", 6, 6.66);
    std::cout << "Created item6 with whitespace in item and unit name";
    std::cout << std::endl;
    std::cout << "Name should show up as item 6" << std::endl;
    std::cout << "Unit should show up as unit 6" << std::endl;
    item6.printItem();

    Item Item6("Item 6","Unit 6", 6, 6.66);
    std::cout << "Created Item6 with name \"Item 6\"" << std::endl;
    std::cout << std::endl;
    std::cout << "Comparing item6 == Item6" << std::endl;
    std::cout << "Names should be case insensitive, so this should evaluate ";
    std::cout << "to true:" << std::endl;
    if (item6 == Item6)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    Item item7("item7","unit7",5,3.42341243214124312);
    std::cout << "Created item7 with many digits after decimal for unitPrice";
    std::cout << std::endl;
    std::cout << "Below output should truncate to two decimal places";
    std::cout << std::endl;
    item7.printItem();
    return 0;
}