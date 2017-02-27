/******************************************************************************
** Program name: ListNode.hpp
** Author: Charles Chen
** Date: 02/24/2017
** Description:
Specification of ListNode class.
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
    std::string getNickname();
    void setNext(ListNode* nextCreature);
    void setPrev(ListNode* prevCreature);
    ListNode* getPrev();
    ListNode* getNext();
    Creature* getCreature();
};

#endif
