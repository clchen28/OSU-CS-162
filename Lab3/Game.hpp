/******************************************************************************
** Program name: Game.hpp
** Author: Charles Chen
** Date: 01/23/2017
** Description:

******************************************************************************/

#include <memory>
#include <string>
#include "Die.hpp"
#include "LoadedDie.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
    public:
        Game(int rounds, std::string die1Type, int die1Sides,
            std::string die2Type, int die2Sides);
        ~Game();
        void playGame();

    private:
        int rounds;
        int currentRound;
        int player1RoundsWon;
        int player2RoundsWon;
        int draws;
        Die *Die1;
        Die *Die2;
};


#endif
