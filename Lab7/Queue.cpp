/******************************************************************************
** Program name: Queue.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Implementation of Queue class.
******************************************************************************/
#include <iostream>
#include "Queue.hpp"

/*
Queue()
Constructor creates a new empty Queue by creating 1 node, and setting its next
and previous pointers to itself. Data is initialized to -1 to denote that it
does not yet hold any data.
*/
Queue::Queue()
{
    front = new QueueNode;
    back = front;
    front->next = back;
    front->prev = back;
    front->data = -1;
}

/*
~Queue()
Destructor goes through every node and deallocates the memory allocated for
every node in the Queue.
*/
Queue::~Queue()
{
    // Checks for situation where there is only one node
    if (front->next == front)
    {
        // Only one node - delete it
        delete front;
        return;
    }
    // Otherwise, at least two nodes
    else
    {
        // Sets back to be the node at the end, i.e., right before the front
        // This is necessary in case any nodes in the Queue have been "deleted",
        // i.e., their data value is set to -1
        back = front->prev;

        // Traverse the queue deleting all nodes
        while (front != back)
        {
            front = front->next;
            delete front->prev;
        }
        delete front;
        return;
    }
}

/*
int getFront()
getter function returns the first value of the Queue
*/
int Queue::getFront()
{
    return front->data;
}

/*
void addBack(int newData)
addBack takes a user input, and adds the value to the back of the Queue
*/
void Queue::addBack(int newData)
{
    // In the situation where the head points to a node with no data, add the
    // new data to that node
    if (getFront() == -1)
    {
        front->data = newData;
    }

    // In the situation where some nodes have been deleted, the next node has
    // a value of -1 (empty). If this is the case, set this node to accept
    // the new data, and move the back of the Queue to point to this node
    else if (back->next->data == -1)
    {
        back = back->next;
        back->data = newData;
    }

    // In the situation where there is more than 1 node, and a new node has to
    // be created to fit the new data, do so by creating a new node, setting
    // the current back to point to the new data, and readjust the new back
    // node to point to the front as the next value. Also need the front's prev
    // pointer to point to the new node.
    else
    {
        back->next = new QueueNode;
        back->next->prev = back;
        back->next->next = front;
        back->next->data = newData;
        back = back->next;
        front->prev = back;
    }
}

/*
int removeFront()
Removes the front value from the Queue. Also returns its value to the caller.
Removes the value by setting the front node to -1, and readjusting the front
pointer.
*/
int Queue::removeFront()
{
    // Needed so that we can return the value of the front to the caller
    int removedVal = getFront();

    // Removes the value
    front->data = -1;

    // If there is more than one node, then move front forward one node, since
    // we just deleted the data that is stored in the node that front is
    // currently pointing to
    if (back != front)
    {
        front = front->next;
    }

    return removedVal;
}

/*
void printAll()
Traverses the list, printing all values.
*/
void Queue::printAll()
{
    // Check first to see if there are values in the Queue
    if (getFront() == -1)
    {
        std::cout << "No elements in queue" << std::endl;
    }
    else
    {
        // Traverses the Queue
        QueueNode* temp = front;
        do
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        } while (temp->data != -1 && temp != front);
    }
    return;
}
