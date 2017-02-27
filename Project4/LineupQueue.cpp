/******************************************************************************
** Program name: LineupQueue.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:
Implementation of LineupQueue class.
******************************************************************************/

#include "LineupQueue.hpp"
#include "ListNode.hpp"
#include "Creature.hpp"

/*
LineupQueue()
Constructor sets the size of this Queue to 0, and points the front and back
of this Queue to null
*/
LineupQueue::LineupQueue()
{
    queueSize = 0;
    front = nullptr;
    back = nullptr;
}

/*
~LineupQueue()
Destructor will deallocate memory for each node in the Queue.
*/
LineupQueue::~LineupQueue()
{
    if (queueSize == 0)
    {
        return;
    }
    else
    {
        back->setNext(nullptr);
        ListNode* cur = front;
        while (cur->getNext() != nullptr)
        {
            cur = cur->getNext();
            delete cur->getPrev();
        }
        delete cur;
    }
}

/*
addCreature(Creature* newCreature)
addCreature will take a pointer to a Creature object and add it to the Queue.
This is done by allocating memory for a new Node, and changing front and back
pointers appropriately
*/
void LineupQueue::addCreature(Creature* newCreature)
{
    ListNode* newNode = new ListNode(newCreature);
    // If this is the first Node, then point the next and previous pointers
    // of the new Node to itself.
    if (queueSize == 0)
    {
        front = newNode;
        back = newNode;
        front->setNext(front);
        front->setPrev(front);
    }
    else
    {
        // Need to create a new Node. The new node needs to be the new back
        // of the Queue, as this ADT is Last In - Last Out.
        newNode->setPrev(back);
        newNode->setNext(front);
        back->setNext(newNode);
        front->setPrev(newNode);
        back = newNode;
    }
    queueSize++;
}

/*
popCreature()
popCreature will pop off the top of the Queue. It returns a pointer to the
Creature currently at the top of the Queue, and removes it from the Queue.
*/
Creature* LineupQueue::popCreature()
{
    // If there is nothing at the top of the Queue, then return null
    if (queueSize == 0)
    {
        return nullptr;
    }
    else
    {
        // First, adjust the Queue so that the front of the Queue is the
        // second Node in the Queue. Then, remove the first Node,
        // and return a pointer to the Creature in the popped Node
        ListNode* popped = front;
        Creature* poppedCreature = front->getCreature();
        front = front->getNext();
        back->setNext(front);
        front->setPrev(back);
        delete popped;

        queueSize--;
        return poppedCreature;
    }
}

// advanceQueue()
// advanceQueue will shift the current top of the Queue to the back of the
// Queue. The Queue is a circular ADT.
void LineupQueue::advanceQueue()
{
    if (queueSize != 0)
    {
        back = front;
        front = front->getNext();
    }
}

// getCreature()
// getCreature() returns a pointer to the top of the Queue without popping it
// off of the Queue.
Creature* LineupQueue::getCreature()
{
    if (queueSize == 0)
    {
        return nullptr;
    }
    else
    {
        return front->getCreature();
    }
}

// getSize()
// getSize() returns the size of the Queue.
int LineupQueue::getSize()
{
    return queueSize;
}
