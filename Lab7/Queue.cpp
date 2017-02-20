/******************************************************************************
** Program name: Queue.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:

******************************************************************************/
#include <iostream>
#include "Queue.hpp"

Queue::Queue()
{
    front = new QueueNode;
    back = front;
    front->next = back;
    front->prev = back;
    front->data = -1;
}

Queue::~Queue()
{
    if (front->next == front)
    {
        delete front;
        return;
    }
    else
    {
        back = front->prev;
        while (front != back)
        {
            front = front->next;
            delete front->prev;
        }
        delete front;
        return;
    }
}

int Queue::getFront()
{
    return front->data;
}

void Queue::addBack(int newData)
{
    if (getFront() == -1)
    {
        front->data = newData;
    }

    else if (back->next->data == -1)
    {
        back = back->next;
        back->data = newData;
    }

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

int Queue::removeFront()
{
    int removedVal = getFront();

    front->data = -1;
    if (back != front)
    {
        front = front->next;
    }

    return removedVal;
}

void Queue::printAll()
{
    if (getFront() == -1)
    {
        std::cout << "No elements in queue" << std::endl;
    }
    else
    {
        QueueNode* temp = front;
        do
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        } while (temp->data != -1 && temp != front);
    }
    return;
}
