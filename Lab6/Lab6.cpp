/******************************************************************************
** Program name: Lab6.cpp
** Author: Charles Chen
** Date: 02/12/2017
** Description:
Lab6 is a demonstration of an implementation of a Linked List.
For the purposes of this lab, I have left the parameters of the Node struct
public. I assume that in general, this is poor practice - we could make the
attributes private, and use getter/setter functions to access them. However,
because of the requirement that methods not be used to access and set the
Nodes, I have chosen to make all attributes public, and to access them
directly.
******************************************************************************/

#include <iostream>
#include <string>
#include "inputValidator.hpp"

void printMenu()
{
    std::cout << "Select a menu option: " << std::endl;
    std::cout << "1. Add from head" << std::endl;
    std::cout << "2. Add from tail " << std::endl;
    std::cout << "3. Delete from head" << std::endl;
    std::cout << "4. Delete from tail" << std::endl;
    std::cout << "5. Print in sequence" << std::endl;
    std::cout << "6. Get head value" << std::endl;
    std::cout << "7. Get tail value" << std::endl;
    std::cout << "8. Exit program" << std::endl;
}

struct Node
{
public:
    int data;
    Node* nextNode;

    Node(int value)
    {
        data = value;
        this->nextNode = nullptr;
    }
};

int main()
{
    Node* head = nullptr;
    Node* cur = nullptr;
    Node* tail = nullptr;

    Node* tempHead = nullptr;
    Node* tempTail = nullptr;
    int intInput;

    int selection = -1;
    std::string yOrNSelection = "y";

    auto yOrN = [](std::string input) -> bool
                {
                    return (input == "y")
                        || (input == "n");
                };

    while (selection != 8)
    {
        printMenu();
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');

        // Selects submenu item
        switch (selection)
        {
            case 1:
                tempHead = nullptr;
                tempTail = nullptr;
                while (yOrNSelection == "y")
                {
                    inputValidator(intInput,
                        "Enter number: ",
                        "Only integer inputs are allowed");
                    if (tempHead == nullptr)
                    {
                        tempHead = new Node(intInput);
                        tempTail = tempHead;
                    }
                    else
                    {
                        tempTail->nextNode = new Node(intInput);
                        tempTail = tempTail->nextNode;
                    }

                    inputValidator(yOrNSelection, yOrN,
                        "Do you want another num (y or n): ",
                        "Enter y or n");
                }

                if (head == nullptr)
                {
                    head = tempHead;
                    tail = tempTail;
                }
                else
                {
                    tempTail->nextNode = head;
                    head = tempHead;
                }

                yOrNSelection = "y";
                tempHead = nullptr;
                tempTail = nullptr;
            break;

            case 2:
                tempHead = nullptr;
                tempTail = nullptr;
                while (yOrNSelection == "y")
                {
                    inputValidator(intInput,
                        "Enter number: ",
                        "Only integer inputs are allowed");
                    if (tempHead == nullptr)
                    {
                        tempHead = new Node(intInput);
                        tempTail = tempHead;
                    }
                    else
                    {
                        tempTail->nextNode = new Node(intInput);
                        tempTail = tempTail->nextNode;
                    }

                    inputValidator(yOrNSelection, yOrN,
                        "Do you want another num (y or n): ",
                        "Enter y or n");
                }

                if (head == nullptr)
                {
                    head = tempHead;
                    tail = tempTail;
                }
                else
                {
                    tail->nextNode = tempHead;
                    tail = tempTail;
                }

                yOrNSelection = "y";
                tempHead = nullptr;
                tempTail = nullptr;
            break;

            case 3:
                if (head == nullptr)
                {
                    std::cout << "Deleting failed, list is empty!!";
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Deleting head..." << std::endl;
                    // Deal with situation where there is only one element in
                    // linked list
                    // In this case, linked list should be empty after
                    // deleting
                    if (head->nextNode == nullptr)
                    {
                        delete head;
                        head = nullptr;
                        tail = nullptr;
                        std::cout << "The list is now empty." << std::endl;
                    }
                    // Otherwise, set new head to second element, and deallocate
                    // memory for the old head
                    else
                    {
                        cur = head;
                        head = head->nextNode;
                        delete cur;
                        cur = nullptr;

                        std::cout << "The new head node is ";
                        std::cout << head->data << std::endl;
                    }
                }
            break;

            case 4:
                if (head == nullptr)
                {
                    std::cout << "Deleting failed, list is empty!!";
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Deleting tail..." << std::endl;
                    // Deal with situation where there is only one element in
                    // linked list
                    // In this case, linked list should be empty after
                    // deleting
                    if (head->nextNode == nullptr)
                    {
                        delete tail;
                        head = nullptr;
                        tail = nullptr;
                        std::cout << "The list is now empty" << std::endl;
                    }
                    // Otherwise, set new tail to second to last element, and
                    // deallocate memory for the old tail
                    else
                    {
                        cur = head;
                        while (cur->nextNode != tail)
                        {
                            cur = cur->nextNode;
                        }
                        delete tail;
                        tail = cur;
                        tail->nextNode = nullptr;
                        cur = nullptr;

                        std::cout << "The new tail node is ";
                        std::cout << tail->data << std::endl;
                    }
                }
            break;

            case 5:
                cur = head;
                if (cur == nullptr)
                {
                    std::cout << "List is empty!!" << std::endl;
                }
                else
                {
                    std::cout << "Printing list..." << std::endl;
                    while (cur != nullptr)
                    {
                        std::cout << cur->data << " " << std::endl;
                        cur = cur->nextNode;
                    }
                }
                cur = nullptr;
            break;

            case 6:
                if (head == nullptr)
                {
                    std::cout << "List is empty!!" << std::endl;
                }
                else
                {
                    std::cout << "Head node is ";
                    std::cout << head->data << std::endl;
                }
            break;

            case 7:
                if (head == nullptr)
                {
                    std::cout << "List is empty!!" << std::endl;
                }
                else
                {
                    std::cout << "Tail node is ";
                    std::cout << tail->data << std::endl;
                }
            break;
            case 8:
                std::cout << "Exiting..." << std::endl;
                if (head != nullptr)
                {
                    cur = head;
                    while (cur != nullptr)
                    {
                        head = cur;
                        cur = cur->nextNode;
                        delete head;
                    }
                }
                head = nullptr;
                tail = nullptr;
                cur = nullptr;
            break;

            default:
                std::cout << "Enter a valid menu item (1 through 8)" << std::endl;
        }
    }

    return 0;
}
