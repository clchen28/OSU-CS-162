/******************************************************************************
** Program name: Project4.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:

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
#include "Round.hpp"
#include "Vampire.hpp"
#include "inputValidator.hpp"

int main()
{
    int numCreatures;
    std::string creatureType;
    LineupQueue lineupA;
    LineupQueue lineupB;

    auto intInputPositive = [](int input) -> bool {return input >= 1;};
    auto allowedCreatureTypes = [](std::string input) -> bool
                {
                    return (input == "Barbarian")
                        || (input == "Blue Men")
                        || (input == "Harry Potter")
                        || (input == "Medusa")
                        || (input == "Vampire");
                };

    inputValidator(numCreatures, intInputPositive,
        "How many characters should each player have?",
        "Invalid creature type");

    for (int i = 1; i <= numCreatures; i++)
    {
        std::string prompt;
        prompt  = "Enter creature type for creature " + std::to_string(i);
        prompt += " for team A:";
        inputValidator(creatureType, intInputPositive,
            prompt,
            "Invalid creature type");
    }
}
