/******************************************************************************
** Program name: LineupQueue.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:

******************************************************************************/

#include "LineupQueue.hpp"
#include "ListNode.hpp"
#include "Creature.hpp"

LineupQueue::LineupQueue()
{
    stackSize = 0;
    front = nullptr;
    back = nullptr;
}

LineupQueue::~LineupQueue()
{
    if (stackSize == 0)
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

void LineupQueue::addCreature(Creature* newCreature)
{
    ListNode* newNode = new ListNode(newCreature);
    if (stackSize == 0)
    {
        front = newNode;
        back = newNode;
        front->setNext(front);
        front->setPrev(front);
    }
    else
    {
        newNode->setPrev(back);
        newNode->setNext(front);
        back->setNext(newNode);
        front->setPrev(newNode);
        back = newNode;
    }
    stackSize++;
}

Creature* LineupQueue::popCreature()
{
    if (stackSize == 0)
    {
        return nullptr;
    }
    else
    {
        ListNode* popped = front;
        Creature* poppedCreature = front->getCreature();
        front = front->getNext();
        back->setNext(front);
        front->setPrev(back);
        delete popped;

        stackSize--;
        return poppedCreature;
    }
}

void LineupQueue::advanceQueue()
{
    if (stackSize != 0)
    {
        back = front;
        front = front->getNext();
    }
}

Creature* LineupQueue::getCreature()
{
    if (stackSize == 0)
    {
        return nullptr;
    }
    else
    {
        return front->getCreature();
    }
}
