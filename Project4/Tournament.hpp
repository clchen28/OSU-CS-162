/******************************************************************************
** Program name: Tournament.hpp
** Author: Charles Chen
** Date: 02/26/2017
** Description:

******************************************************************************/

#include "LineupQueue.hpp"
#include "LoserStack.hpp"
#include "Creature.hpp"

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

class Tournament
{
private:
    int numCreatures;
    int roundNum;
    LineupQueue lineupA;
    LineupQueue lineupB;
    LoserStack loserA;
    LoserStack loserB;
    int scoreA;
    int scoreB;
    void attackCreature(Creature* Attacker, Creature* Defender);
    int randNum(int n);
public:
    Tournament(int creatures);
    ~Tournament();
    void playRound(Creature* Creature1, Creature* Creature2, int roundN);
    void playGame();
    void setLineup();
    void printScore();
    void printLosers();
};

#endif
