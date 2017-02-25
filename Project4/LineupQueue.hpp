/******************************************************************************
** Program name: LineupQueue.hpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:

******************************************************************************/

#include "ListNode.hpp"
#include "Creature.hpp"

#ifndef LINEUPQUEUE_HPP
#define LINEUPQUEUE_HPP

class LineupQueue
{
protected:
    int stackSize;
    ListNode* front;
    ListNode* back;
public:
    LineupQueue();
    ~LineupQueue();
    void addCreature(Creature* newCreature);
    Creature* popCreature();
    void advanceQueue();
    Creature* getCreature();
};

#endif
