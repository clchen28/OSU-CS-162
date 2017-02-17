/******************************************************************************
** Program name: Lab6.cpp
** Author: Charles Chen
** Date: 02/12/2017
** Description:
Lab6 is a demonstration of an implementation of a Linked List.

The main function provides an interface, allowing the user to easily create,
manipulate, and display a linked list.

The getNextNode and setNextNode methods do nothing other than to return
the next node, or to set the next node based on a given parameter - that's it.
This fulfills the intent of the Lab - manipulating the list using pointer
operations, while maintaining data encapsulation.

To compile:
make

To run:
./Lab6
******************************************************************************/

#include <iostream>
#include <string>
#include "Node.hpp"
#include "inputValidator.hpp"

/*
printMenu()
Prints the menu options for this program.
*/
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

/*
main()
Contains a menu interface for the program. main also contains an implementation
of a linked list structure, using Node structs. The menu contains options that
will directly manipulate the defined linked list.
*/
int main()
{
    // These pointers are pointers to linked list Nodes.
    Node* head = nullptr;
    Node* cur = nullptr;
    Node* tail = nullptr;

    // These pointers are meant to be used as temporary head and tail Nodes,
    // for when the user is adding more elements to the existing list.
    Node* tempHead = nullptr;
    Node* tempTail = nullptr;

    // intInput is a placeholder for the integer data that is used to
    // initialize a new Node.
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
                // Think of this menu option as a subroutine that creates a new
                // linked list, and then stitches it with the currently
                // existing list, such that the head of the total list points
                // to the head of this temporary list, and the tail of this
                // temporary list points to the old head of the whole list

                // Reset these to null for new inputs
                tempHead = nullptr;
                tempTail = nullptr;

                std::cout << "Note the following assumption about what is ";
                std::cout << "meant by 'adding to the head' of the list.";
                std::cout << std::endl;
                std::cout << "Note - the numbers you enter will become the new";
                std::cout << " head, in the order you specify." << std::endl;
                std::cout << "e.g., say our linked list is currently ";
                std::cout << "1->2->3" << std::endl;
                std::cout << "If you then enter in 4, 5, 6 in that sequence,";
                std::cout << " the new linked list will be" << std::endl;
                std::cout << "4->5->6->1->2->3" << std::endl;

                while (yOrNSelection == "y")
                {
                    // While the user has more integers to input into the list,
                    // prompt for more inputs
                    inputValidator(intInput,
                        "Enter number: ",
                        "Only integer inputs are allowed");

                    if (tempHead == nullptr)
                    {
                        // If this is the first element in the new temporary
                        // list, then the head and tail are equal to the same
                        // value
                        tempHead = new Node(intInput);
                        tempTail = tempHead;
                    }
                    else
                    {
                        // Otherwise, after we create the the new node,
                        // we have to set the second to last element to point
                        // to the new node, and the new node is now the new
                        // tail of the list.
                        tempTail->setNextNode(new Node(intInput));
                        tempTail = tempTail->getNextNode();
                    }

                    inputValidator(yOrNSelection, yOrN,
                        "Do you want another num (y or n): ",
                        "Enter y or n");
                }

                if (head == nullptr)
                {
                    // If a linked list has not been created yet, then the list
                    // we just created is the full list
                    head = tempHead;
                    tail = tempTail;
                }
                else
                {
                    // Otherwise, we have to put the newly constructed temp
                    // list at the head of the already existing list
                    tempTail->setNextNode(head);
                    head = tempHead;
                }

                yOrNSelection = "y";
                tempHead = nullptr;
                tempTail = nullptr;
            break;

            case 2:
            // Think of this menu option as a subroutine that creates a new
            // linked list, and then stitches it with the currently
            // existing list, such that this new temporary list comes after
            // the last element in the total list.
                tempHead = nullptr;
                tempTail = nullptr;
                while (yOrNSelection == "y")
                {
                    // While the user has more integers to input into the list,
                    // prompt for more inputs
                    inputValidator(intInput,
                        "Enter number: ",
                        "Only integer inputs are allowed");

                    if (tempHead == nullptr)
                    {
                        // If this is the first element in the new temporary
                        // list, then the head and tail are equal to the same
                        // value
                        tempHead = new Node(intInput);
                        tempTail = tempHead;
                    }
                    else
                    {
                        // Otherwise, after we create the the new node,
                        // we have to set the second to last element to point
                        // to the new node, and the new node is now the new
                        // tail of the list.
                        tempTail->setNextNode(new Node(intInput));
                        tempTail = tempTail->getNextNode();
                    }

                    inputValidator(yOrNSelection, yOrN,
                        "Do you want another num (y or n): ",
                        "Enter y or n");
                }

                if (head == nullptr)
                {
                    // If a linked list has not been created yet, then the list
                    // we just created is the full list
                    head = tempHead;
                    tail = tempTail;
                }
                else
                {
                    // Otherwise, we have to put the newly constructed temp
                    // list at the tail of the already existing list
                    tail->setNextNode(tempHead);
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
                    if (head->getNextNode() == nullptr)
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
                        head = head->getNextNode();
                        delete cur;
                        cur = nullptr;

                        std::cout << "The new head node is ";
                        std::cout << head->getData() << std::endl;
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
                    if (head->getNextNode() == nullptr)
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
                        while (cur->getNextNode() != tail)
                        {
                            cur = cur->getNextNode();
                        }
                        delete tail;
                        tail = cur;
                        tail->setNextNode(nullptr);
                        cur = nullptr;

                        std::cout << "The new tail node is ";
                        std::cout << tail->getData() << std::endl;
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
                    // Prints list
                    // We know the tail has been reached when the next pointer
                    // is null
                    std::cout << "Printing list..." << std::endl;
                    while (cur != nullptr)
                    {
                        std::cout << cur->getData() << " " << std::endl;
                        cur = cur->getNextNode();
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
                    std::cout << head->getData() << std::endl;
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
                    std::cout << tail->getData() << std::endl;
                }
            break;

            case 8:
                std::cout << "Exiting..." << std::endl;

                // If there are elements in the list, we need to traverse the
                // list and deallocate memory for every Node, so there are no
                // memory leaks
                if (head != nullptr)
                {
                    cur = head;
                    while (cur != nullptr)
                    {
                        head = cur;
                        cur = cur->getNextNode();
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
