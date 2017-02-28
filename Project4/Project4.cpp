/******************************************************************************
** Program name: Project4.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:
Project 4 is an implementation of a Tournament-style battle between multiple
characters, with Creatures that the user can select.

To compile:
make

To run:
./Project4
******************************************************************************/

#include <string>
#include <iostream>
#include <functional>
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "Die.hpp"
#include "HarryPotter.hpp"
#include "ListNode.hpp"
#include "LineupQueue.hpp"
#include "LoserStack.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "inputValidator.hpp"
#include "Tournament.hpp"

int main()
{
    int numCreatures;
    std::string creatureType;
    std::string nickname;

    auto intInputPositive = [](int input) -> bool {return input >= 1;};
    inputValidator(numCreatures, intInputPositive,
        "How many characters should each player have?",
        "Must be a positive integer");

    Tournament tournament(numCreatures);
    tournament.setLineup();
    tournament.playGame();
}
