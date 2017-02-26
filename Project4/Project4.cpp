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
    std::string nickname;
    LineupQueue lineupA;
    LineupQueue lineupB;
    LoserStack loserA;
    LoserStack loserB;

    auto intInputPositive = [](int input) -> bool {return input >= 1;};
    auto allowedCreatureTypes = [](std::string input) -> bool
                {
                    return (input == "Barbarian")
                        || (input == "Blue Men")
                        || (input == "Harry Potter")
                        || (input == "Medusa")
                        || (input == "Vampire");
                };
    auto notEmpty = [](std::string input) -> bool
                {
                    bool allSpaces = true;
                    for (int i = 0; i < input.length(); i++)
                    {
                        if (!isspace(input[i]))
                        {
                            allSpaces = false;
                        }
                    }
                    return (input != "" && !allSpaces);
                };

    inputValidator(numCreatures, intInputPositive,
        "How many characters should each player have?",
        "Must be a positive integer");

    for (int i = 1; i <= numCreatures; i++)
    {
        std::string prompt;
        std::string nicknamePrompt;
        prompt = "Enter creature type for creature " + std::to_string(i);
        prompt += " for team A:";
        inputValidator(creatureType, allowedCreatureTypes,
            prompt,
            "Must be Barbarian, Blue Men, Harry Potter, Medusa, or Vampire");

        nicknamePrompt = "Enter a name for the " + creatureType;
        inputValidator(nickname, notEmpty,
            nicknamePrompt,
            "Nickname can not be an empty string");

        if (creatureType == "Barbarian")
        {
            lineupA.addCreature(new Barbarian(nickname));
        }
        else if (creatureType == "Blue Men")
        {
            lineupA.addCreature(new BlueMen(nickname));
        }
        else if (creatureType == "Harry Potter")
        {
            lineupA.addCreature(new HarryPotter(nickname));
        }
        else if (creatureType == "Medusa")
        {
            lineupA.addCreature(new Medusa(nickname));
        }
        else if (creatureType == "Vampire")
        {
            lineupA.addCreature(new Vampire(nickname));
        }
    }

    for (int i = 1; i <= numCreatures; i++)
    {
        std::string prompt;
        std::string nicknamePrompt;
        prompt = "Enter creature type for creature " + std::to_string(i);
        prompt += " for team B:";
        inputValidator(creatureType, allowedCreatureTypes,
            prompt,
            "Must be Barbarian, Blue Men, Harry Potter, Medusa, or Vampire");

        nicknamePrompt = "Enter a name for the " + creatureType;
        inputValidator(nickname, notEmpty,
            nicknamePrompt,
            "Nickname can not be an empty string");

        if (creatureType == "Barbarian")
        {
            lineupB.addCreature(new Barbarian(nickname));
        }
        else if (creatureType == "Blue Men")
        {
            lineupB.addCreature(new BlueMen(nickname));
        }
        else if (creatureType == "Harry Potter")
        {
            lineupB.addCreature(new HarryPotter(nickname));
        }
        else if (creatureType == "Medusa")
        {
            lineupB.addCreature(new Medusa(nickname));
        }
        else if (creatureType == "Vampire")
        {
            lineupB.addCreature(new Vampire(nickname));
        }
    }

    int roundNum = 1;
    while (lineupA.getSize() > 0 && lineupB.getSize() > 0)
    {
        playRound(lineupA.getCreature(), lineupB.getCreature(), roundNum);
        if (lineupA.getCreature()->isDead())
        {
            loserA.addCreature(lineupA.popCreature());
            lineupB.getCreature()->restoreStrength();
            lineupB.advanceQueue();
        }
        else if (lineupB.getCreature()->isDead())
        {
            loserB.addCreature(lineupB.popCreature());
            lineupA.getCreature()->restoreStrength();
            lineupA.advanceQueue();
        }
        std::cout << "Team A losers:" << std::endl;
        loserA.printLosers();
        std::cout << "Team B losers:" << std::endl;
        loserB.printLosers();
        roundNum++;
    }
}
