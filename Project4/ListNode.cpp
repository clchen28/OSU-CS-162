/******************************************************************************
** Program name: ListNode.cpp
** Author: Charles Chen
** Date: 02/24/2017
** Description:
Implementation of ListNode class. ListNode is used as a node in Queue and
Stack like ADTs. It is doubly-linked (has previous and next Nodes), and contains
a pointer to a Creature as its data member.
******************************************************************************/

#include <string>
#include "Creature.hpp"
#include "ListNode.hpp"

/*
ListNode()
ListNode constructor sets next and previous pointers to null.
*/
ListNode::ListNode()
{
    next = nullptr;
    prev = nullptr;
    creature = nullptr;
}

/*
ListNode(Creature*)
ListNode constructor takes in a pointer to a Creature, and creates a new Node
with the specified pointer as its data member.
*/
ListNode::ListNode(Creature* thisCreature)
{
    next = nullptr;
    prev = nullptr;
    creature = thisCreature;
}

/*
setNext(ListNode*)
setNext sets the next pointer in the Node to the specified ListNode pointer
*/
void ListNode::setNext(ListNode* nextCreature)
{
    next = nextCreature;
}

/*
setPrev(ListNode*)
setPrev sets the previous pointer in the Node to the specified ListNode pointer
*/
void ListNode::setPrev(ListNode* prevCreature)
{
    prev = prevCreature;
}

/*
getName()
getName returns the name of the Creature pointed to by its data member
*/
std::string ListNode::getName()
{
    return creature->getName();
}

/*
getNickname()
getNickname returns the nickname of the Creature pointed to by its data member
*/
std::string ListNode::getNickname()
{
    return creature->getNickname();
}

/*
getPrev()
getPrev returns the pointer to its previous Node
*/
ListNode* ListNode::getPrev()
{
    return prev;
}

/*
getNext()
getNext returns the pointer to its next Node
*/
ListNode* ListNode::getNext()
{
    return next;
}

/*
getCreature()
getCreature returns this Node's data member, a pointer to a Creature.
*/
Creature* ListNode::getCreature()
{
    return creature;
}
