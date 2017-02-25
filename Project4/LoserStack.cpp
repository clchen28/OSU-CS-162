/******************************************************************************
** Program name: LoserStack.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:

******************************************************************************/

#include <iostream>
#include "LoserStack.hpp"
#include "ListNode.hpp"

LoserStack::LoserStack()
{
    stackSize = 0;
    bottom = nullptr;
    top = nullptr;
}

LoserStack::~LoserStack()
{
    if (stackSize == 0)
    {
        return;
    }
    else
    {
        ListNode* cur = top;
        while (cur->getPrev() != nullptr)
        {
            cur = cur->getPrev();
            delete cur->getNext();
        }
        delete cur;
    }
}

void LoserStack::addCreature(Creature* creature)
{
    ListNode* newNode = new ListNode(creature);
    if (stackSize == 0)
    {
        bottom = newNode;
        top = newNode;
    }
    else
    {
        top->setNext(newNode);
        newNode->setPrev(top);
        top = newNode;
    }
    stackSize++;
}

void LoserStack::printLosers()
{
    if (stackSize == 0)
    {
        std::cout << "No creatures in the loser stack" << std::endl;
    }
    else
    {
        ListNode* cur = top;
        std::cout << "Losers:" << std::endl;
        for (int i = 0; i < stackSize; i++)
        {
            std::cout << cur->getName() << std::endl;
            cur = cur->getPrev();
        }
    }
}
