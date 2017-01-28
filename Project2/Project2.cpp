#include <iostream>
#include <string>
#include "Item.hpp"
#include "List.hpp"

int main()
{
    
    List myList;
    myList.removeItem("item");
    myList.addItem("item1", "unit1", 1, 1.00);
    myList.addItem("item2", "unit2", 2, 2.00);
    myList.addItem("item3", "unit3", 3, 3.00);
    myList.addItem("item4", "unit4", 4, 4.00);
    myList.addItem("item5", "unit5", 5, 5.00);
/*
    std::cout << myList.items[0].name << std::endl;
    std::cout << myList.items[1].name << std::endl;
    std::cout << myList.items[2].name << std::endl;
    std::cout << myList.items[3].name << std::endl;
    std::cout << myList.items[4].name << std::endl;
    std::cout << myList.items[5].name << std::endl;
    */
    myList.printList();

    myList.removeItem("item3");
    myList.removeItem("item2");
    myList.removeItem("item1");
    myList.removeItem("item");

    myList.printList();

    
    return 0;
}