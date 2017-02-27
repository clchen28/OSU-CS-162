/******************************************************************************
** Program name: LineupQueue.hpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:
Specification of LineupQueue class. The LineupQueue represents a Queue-like
ADT for Creature lineups - it is a First In - First Out ADT. Because the
Tournament is intended to be run until one team has no more characters alive,
the lineup has to rotate. Therefore, the LineupQueue is also a doubly-linked
circular Queue.
******************************************************************************/

#include "ListNode.hpp"
#include "Creature.hpp"

#ifndef LINEUPQUEUE_HPP
#define LINEUPQUEUE_HPP

class LineupQueue
{
protected:
    int queueSize;
    ListNode* front;
    ListNode* back;
public:
    LineupQueue();
    ~LineupQueue();
    void addCreature(Creature* newCreature);
    Creature* popCreature();
    void advanceQueue();
    Creature* getCreature();
    int getSize();
};

#endif
