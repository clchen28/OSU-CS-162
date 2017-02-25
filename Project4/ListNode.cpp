/******************************************************************************
** Program name: ListNode.cpp
** Author: Charles Chen
** Date: 02/24/2017
** Description:

******************************************************************************/

#include <string>
#include "Creature.hpp"
#include "ListNode.hpp"

ListNode::ListNode()
{
    next = nullptr;
    prev = nullptr;
    creature = nullptr;
}

ListNode::ListNode(Creature* thisCreature)
{
    next = nullptr;
    prev = nullptr;
    creature = thisCreature;
}


void ListNode::setNext(ListNode* nextCreature)
{
    next = nextCreature;
}

void ListNode::setPrev(ListNode* prevCreature)
{
    prev = prevCreature;
}

std::string ListNode::getName()
{
    return creature->getName();
}

ListNode* ListNode::getPrev()
{
    return prev;
}

ListNode* ListNode::getNext()
{
    return next;
}
