/******************************************************************************
** Program name: ListNode.hpp
** Author: Charles Chen
** Date: 02/24/2017
** Description:

******************************************************************************/

#include <string>
#include "Creature.hpp"

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

class ListNode
{
protected:
    Creature* creature;
    ListNode* next;
    ListNode* prev;
public:
    ListNode();
    ListNode(Creature* creature);
    std::string getName();
    void setNext(ListNode* nextCeature);
    void setPrev(ListNode* prevCreature);
    ListNode* getPrev();
    ListNode* getNext();
    Creature* getCreature();
};

#endif
