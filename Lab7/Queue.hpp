/******************************************************************************
** Program name: Queue.hpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:

******************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

struct QueueNode
{
    int data;
    QueueNode* next;
    QueueNode* prev;
};

class Queue
{
public:
    Queue();
    ~Queue();
    void addBack(int newData);
    int getFront();
    int removeFront();
    void printAll();
private:
    QueueNode* front;
    QueueNode* back;
};

#endif
