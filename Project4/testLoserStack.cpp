#include <iostream>

#include "ListNode.hpp"
#include "LoserStack.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Die.hpp"

int main()
{
    Creature* creature1 = new Medusa;
    Creature* creature2 = new Barbarian;
    Creature* creature3 = new BlueMen;
    Creature* creature4 = new HarryPotter;
    Creature* creature5 = new Vampire;
    LoserStack losers;
    losers.printLosers();
    losers.addCreature(creature5);
    losers.addCreature(creature4);
    losers.addCreature(creature3);
    losers.addCreature(creature2);
    losers.addCreature(creature1);
    losers.printLosers();
    delete creature1;
    delete creature2;
    delete creature3;
    delete creature4;
    delete creature5;
}
