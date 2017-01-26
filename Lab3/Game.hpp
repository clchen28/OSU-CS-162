/******************************************************************************
** Program name: Game.hpp
** Author: Charles Chen
** Date: 01/23/2017
** Description:
Game.hpp contains the specification for the Game class. This class is used to
store Die objects for two players in a Die game, and provides utilities to
run the game.
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
