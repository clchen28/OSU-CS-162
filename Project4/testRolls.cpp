/******************************************************************************
** Program name: testRolls.cpp
** Author: Charles Chen
** Date: 02/09/2017
** Description:
test contains a utility for testing every Creature's rollAttack and rollDefense
methods, checking to ensure that rolls are within the correct bounds, and
checking that the rolls are reasonably random. This is done by rolling each
Creature's attack die and defense die 1000 times each, and printing the number
of times that each result comes up.

To compile:
make testRolls

To run:
./testRolls
******************************************************************************/

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "menu.hpp"
#include "Game.hpp"

/*
creatureRoll(Creature* creature, std::vector<int> &rolls,
        std::vector<int> &results, std::string atkDef)
creatureRoll takes a pointer to a creature, a vector "rolls" containing the
possible results of rolling either the Attack or Defense die, a vector
"results" which corresponds to the frequencies that each roll occurs, and a
string "atkDef" which is set to either attack or defense. Based on the value
of "atkDef", the function will roll the specified die 1000 times, and then
store the frequency of each roll in the results vector.
*/
void creatureRoll(Creature* creature, std::vector<int> &rolls,
        std::vector<int> &results, std::string atkDef)
{
    int curRoll;
    for (int i = 1; i <= 1000; i++)
    {
        if (atkDef == "attack")
        {
            curRoll = creature->rollAttack();
        }
        if (atkDef == "defense")
        {
            curRoll = creature->rollDefense();
        }
        for (int j = 0; j < results.size(); j++)
        {
            if (rolls[j] == curRoll)
            {
                results[j] += 1;
            }
        }
    }
}

/*
printRollResults(std::vector<int> &rolls, std::vector<int> &results)
printRollResults takes a vector "rolls" containing the
possible results of rolling either the Attack or Defense die, and a vector
"results" which corresponds to the frequencies that each roll occurs. The
frequency of each roll is printed to standard output.
*/
void printRollResults(std::vector<int> &rolls, std::vector<int> &results)
{
    for (int i = 0; i < rolls.size(); i++)
    {
        std::cout << "Roll " << rolls[i] << ": ";
        std::cout << results[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Warning - this will take a few seconds to start displaying ";
    std::cout << "outputs on flip" << std::endl;
    Creature* barbarian = new Barbarian;
    Creature* medusa = new Medusa;
    Creature* harryPotter = new HarryPotter;
    Creature* vampire = new Vampire;
    Creature* blueMen = new BlueMen;

    // Vectors containing possible attack and defense rolls
    std::vector<int> barbarianAttackRolls =
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<int> barbarianDefenseRolls =
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<int> medusaAttackRolls =
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 9999};
    std::vector<int> medusaDefenseRolls =
        {1, 2, 3, 4, 5, 6};
    std::vector<int> blueMenAttackRolls =
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::vector<int> blueMenDefenseRolls =
        {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    std::vector<int> vampireAttackRolls =
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<int> vampireDefenseRolls =
        {1, 2, 3, 4, 5, 6, 8888};
    std::vector<int> harryPotterAttackRolls =
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<int> harryPotterDefenseRolls =
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Vectors containing the frequency of each roll
    std::vector<int> barbarianAttackResults(barbarianAttackRolls.size(),0);
    std::vector<int> barbarianDefenseResults(barbarianDefenseRolls.size(), 0);
    std::vector<int> medusaAttackResults(medusaAttackRolls.size(), 0);
    std::vector<int> medusaDefenseResults(medusaDefenseRolls.size(), 0);
    std::vector<int> blueMenAttackResults(blueMenAttackRolls.size(), 0);
    std::vector<int> blueMenDefenseResults(blueMenDefenseRolls.size(), 0);
    std::vector<int> vampireAttackResults(vampireAttackRolls.size(), 0);
    std::vector<int> vampireDefenseResults(vampireDefenseRolls.size(), 0);
    std::vector<int> harryPotterAttackResults(harryPotterAttackRolls.size(), 0);
    std::vector<int> harryPotterDefenseResults(harryPotterDefenseRolls.size()
        ,0);

    // Suppresses output of the roll methods
    std::cout.setstate(std::ios_base::failbit);

    // Rolls attack and defense die of each Creature
    creatureRoll(barbarian, barbarianAttackRolls, barbarianAttackResults,
        "attack");
    creatureRoll(barbarian, barbarianDefenseRolls, barbarianDefenseResults,
        "defense");
    creatureRoll(medusa, medusaAttackRolls, medusaAttackResults,
        "attack");
    creatureRoll(medusa, medusaDefenseRolls, medusaDefenseResults,
        "defense");
    creatureRoll(blueMen, blueMenAttackRolls, blueMenAttackResults,
        "attack");
    creatureRoll(blueMen, blueMenDefenseRolls, blueMenDefenseResults,
        "defense");
    creatureRoll(vampire, vampireAttackRolls, vampireAttackResults,
        "attack");
    creatureRoll(vampire, vampireDefenseRolls, vampireDefenseResults,
        "defense");
    creatureRoll(harryPotter, harryPotterAttackRolls,
        harryPotterAttackResults, "attack");
    creatureRoll(harryPotter, harryPotterDefenseRolls,
        harryPotterDefenseResults, "defense");

    // Unsuppresses printing
    std::cout.clear();

    // Prints results of rolls for each Creature
    std::cout << "Barbarian attack rolls" << std::endl;
    printRollResults(barbarianAttackRolls, barbarianAttackResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Barbarian defense rolls" << std::endl;
    printRollResults(barbarianDefenseRolls, barbarianDefenseResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Medusa attack rolls" << std::endl;
    printRollResults(medusaAttackRolls, medusaAttackResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Medusa defense rolls" << std::endl;
    printRollResults(medusaDefenseRolls, medusaDefenseResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Blue Men attack rolls" << std::endl;
    printRollResults(blueMenAttackRolls, blueMenAttackResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Blue Men defense rolls" << std::endl;
    printRollResults(blueMenDefenseRolls, blueMenDefenseResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Vampire attack rolls" << std::endl;
    printRollResults(vampireAttackRolls, vampireAttackResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Vampire defense rolls" << std::endl;
    printRollResults(vampireDefenseRolls, vampireDefenseResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Harry Potter attack rolls" << std::endl;
    printRollResults(harryPotterAttackRolls, harryPotterAttackResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Harry Potter defense rolls" << std::endl;
    printRollResults(harryPotterDefenseRolls, harryPotterDefenseResults);
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout << "Attacking Blue Men multiple times with vampire";
    std::cout << std::endl;
    std::cout << "Checking to see that Blue Men's number of Defense die ";
    std::cout << "reduces appropriately" << std::endl;
    std::cout << " every time 4 Strength is lost" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));

    while (!blueMen->isDead())
    {
        attackCreature(vampire, blueMen);
    }

    delete barbarian;
    delete medusa;
    delete harryPotter;
    delete vampire;
    delete blueMen;
}
