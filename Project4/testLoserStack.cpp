#include <iostream>

#include "ListNode.hpp"
#include "LineupQueue.hpp"
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
    LineupQueue lineup;
    lineup.addCreature(creature5);
    lineup.addCreature(creature4);
    lineup.popCreature();
    lineup.addCreature(creature3);
    lineup.addCreature(creature2);
    lineup.addCreature(creature1);
    std::cout << lineup.popCreature()->getName() << std::endl;
    std::cout << lineup.popCreature()->getName() << std::endl;
    std::cout << lineup.popCreature()->getName() << std::endl;
    std::cout << lineup.popCreature()->getName() << std::endl;
    std::cout << "done" << std::endl;
    delete creature1;
    delete creature2;
    delete creature3;
    delete creature4;
    delete creature5;
}
