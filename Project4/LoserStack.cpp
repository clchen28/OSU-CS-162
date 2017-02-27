/******************************************************************************
** Program name: LoserStack.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:
Implementation of LoserStack, a stack-like ADT to contain Losers.
******************************************************************************/

#include <iostream>
#include "LoserStack.hpp"
#include "ListNode.hpp"

/*
LoserStack()
Constructor creates a new LoserStack with a size of 0.
*/
LoserStack::LoserStack()
{
    stackSize = 0;
    bottom = nullptr;
    top = nullptr;
}

/*
~LoserStack()
Destructor deallocates memory for every ListNode that was allocated for this
Stack.
*/
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

/*
addCreature(Creature*)
addCreature takes a pointer to a Creature, and adds it to the top of the
stack.
*/
void LoserStack::addCreature(Creature* creature)
{
    ListNode* newNode = new ListNode(creature);
    // If this is the first Node, then have the bottom and top of the stack
    // be the new Node
    if (stackSize == 0)
    {
        bottom = newNode;
        top = newNode;
    }
    else
    {
        // Otherwise, the top of the stack should be the Node that was just
        // added, as this is a First In - Last Out ADT.
        top->setNext(newNode);
        newNode->setPrev(top);
        top = newNode;
    }
    stackSize++;
}

/*
printLosers()
Prints the name and nickname of the losers, in the order of top to bottom of
stack.
*/
void LoserStack::printLosers()
{
    if (stackSize == 0)
    {
        std::cout << "No creatures in the loser stack" << std::endl;
    }
    else
    {
        ListNode* cur = top;
        for (int i = 0; i < stackSize; i++)
        {
            std::cout << cur->getName() << " '" << cur->getNickname();
            std::cout << "' " << std::endl;
            cur = cur->getPrev();
        }
    }
}

// getSize()
// getSize() returns the size of the Stack.
int LoserStack::getSize()
{
    return stackSize;
}

/*
popCreature()
popCreature will pop off the top of the Stack. It returns a pointer to the
Creature currently at the top of the Stack, and removes it from the Stack.
*/
Creature* LoserStack::popCreature()
{
    // If there is nothing at the top of the Stack, then return null
    if (stackSize == 0)
    {
        return nullptr;
    }
    else
    {
        ListNode* popped = top;
        Creature* poppedCreature = top->getCreature();
        if (top->getPrev() != nullptr)
        {
            top = top->getPrev();
            top->setNext(nullptr);
        }
        delete popped;
        stackSize--;
        return poppedCreature;
    }
}
