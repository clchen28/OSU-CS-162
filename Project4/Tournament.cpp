/******************************************************************************
** Program name: Tournament.cpp
** Author: Charles Chen
** Date: 02/26/2017
** Description:
Implementation of Tournament class.
******************************************************************************/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include "Tournament.hpp"
#include "LineupQueue.hpp"
#include "LoserStack.hpp"
#include "inputValidator.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

/*
Tournament(int creatures)
Tournament constructor creates a new Tournament, with the specified number
of creatures for both teams.
*/
Tournament::Tournament(int creatures)
{
    numCreatures = creatures;
    roundNum = 1;
    scoreA = 0;
    scoreB = 0;
}

/*
~Tournament()

*/
Tournament::~Tournament()
{
    while (lineupA.getSize() > 0)
    {
        delete lineupA.popCreature();
    }
    while (loserA.getSize() > 0)
    {
        delete loserA.popCreature();
    }
    while (lineupB.getSize() > 0)
    {
        delete lineupB.popCreature();
    }
    while (loserB.getSize() > 0)
    {
        delete loserB.popCreature();
    }
}

/*
setLineup()
setLineup provides a prompt for the user to define the lineups for both teams,
based on the number of characters each side has.
*/
void Tournament::setLineup()
{
    std::string prompt;
    std::string nicknamePrompt;
    std::string creatureType;
    std::string nickname;

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
    // Prompts user for creature type and creature nicknames for both teams
    for (int i = 1; i <= numCreatures; i++)
    {
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
}


/*
attackCreature(Creature* Attacker, Creature* Defender)
attackCreature takes the pointers to an attacker Creature and Defender
Creature. It rolls the attack die for the Attacker, the Defense Die for the
defender, and calls the Defender's takeDamage method.
*/
void Tournament::attackCreature(Creature* Attacker, Creature* Defender)
{
    Defender->takeDamage(Attacker->rollAttack(), Defender->rollDefense());
    return;
}

/*
playRound(Creature* Creature1, Creature* Creature2)
playRound takes pointers to two Creature objects, and sets the first one to
attack first, and has them attack each other until one of them dies.
*/
void Tournament::playRound(Creature* Creature1, Creature* Creature2, int roundN)
{
    // Sets a random first attacker for each round
    int curAttacker = randNum(2);

    std::cout << "Round " << roundN << ": ";
    std::cout << "Team A " << Creature1->getName() << " '";
    std::cout << Creature1->getNickname() << "' vs. ";
    std::cout << "Team B " << Creature2->getName() << " '";
    std::cout << Creature2->getNickname() << "'";
    std::cout << std::endl;
    while (!Creature1->isDead() && !Creature2->isDead())
    {
        // Attack the other Creature
        if (curAttacker == 1)
        {
            attackCreature(Creature1, Creature2);
        }
        else if (curAttacker == 2)
        {
            attackCreature(Creature2, Creature1);
        }

        // With this move complete, swap attackers
        if (curAttacker == 1)
        {
            curAttacker = 2;
        }
        else if (curAttacker == 2)
        {
            curAttacker = 1;
        }
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    // Determine which Creature is dead, print who won
    if (Creature1->isDead() && !Creature2->isDead())
    {
        std::cout << "Team A " << Creature1->getName();
        std::cout << " '" << Creature1->getNickname() << "' is dead!";
        std::cout << std::endl;

        std::cout << "Team B " << Creature2->getName();
        std::cout << " '" << Creature2->getNickname() << "' is the ";
        std::cout << "winner!" << std::endl;
    }
    else if (Creature2->isDead() && !Creature1->isDead())
    {
        std::cout << "Team B " << Creature2->getName();
        std::cout << " '" << Creature2->getNickname() << "' is dead!";
        std::cout << std::endl;

        std::cout << "Team A " << Creature1->getName();
        std::cout << " '" << Creature1->getNickname() << "' is the ";
        std::cout << "winner!" << std::endl;
    }
    return;
}

/*
randNum(int n)
randNum takes in a number n of integers, and will return a random integer
between 1 and n, inclusive. Similar functionality as Die object, bundled into
a function instead.
*/
int Tournament::randNum(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,n);
    return dist(gen);
}

/*
playGame()
playGame runs through the Tournament until one team has no more characters
left.
*/
void Tournament::playGame()
{
    // Runs fights until one team runs out of characters in the lineup
    while (lineupA.getSize() > 0 && lineupB.getSize() > 0)
    {
        playRound(lineupA.getCreature(), lineupB.getCreature(), roundNum);
        if (lineupA.getCreature()->isDead())
        {
            // Removes dead character from lineup, and moves it to the loser
            // stack
            loserA.addCreature(lineupA.popCreature());
            lineupB.getCreature()->restoreStrength();
            lineupB.advanceQueue();
            scoreB++;
        }
        else if (lineupB.getCreature()->isDead())
        {
            loserB.addCreature(lineupB.popCreature());
            lineupA.getCreature()->restoreStrength();
            lineupA.advanceQueue();
            scoreA++;
        }
        roundNum++;
    }
    printLosers();
    printScore();
}


/*
printScore()
Prints the current score of the Tournament
*/
void Tournament::printScore()
{
    std::cout << "Score - Team A: " << scoreA;
    std::cout << ", Team B: " << scoreB << std::endl;
    printWinner();
}

/*
printLosers()
Prints the characters in each team's loser stack
*/
void Tournament::printLosers()
{
    std::cout << "Losers:" << std::endl;
    std::cout << "Team A:" << std::endl;
    loserA.printLosers();
    std::cout << "Team B:" << std::endl;
    loserB.printLosers();
}

/*
printWinner()
Determines which team has a higher score, and prints a message to declare
which team won the Tournament
*/
void Tournament::printWinner()
{
    if ( !(lineupA.getSize() > 0 && lineupB.getSize() > 0) )
    {
        if (scoreA > scoreB)
        {
            std::cout << "Team A is the winner!" << std::endl;
        }
        else if (scoreB > scoreA)
        {
            std::cout << "Team B is the winner!" << std::endl;
        }
        else if (scoreB == scoreA)
        {
            std::cout << "It's a tie!" << std::endl;
        }
    }
    else
    {
        std::cout << "Tournament is not over yet!" << std::endl;
    }
}
