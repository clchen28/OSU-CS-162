/******************************************************************************
** Program name: Game.cpp
** Author: Charles Chen
** Date: 01/23/2017
** Description:

******************************************************************************/

#include <memory>
#include <iostream>
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

Game::Game(int rounds, std::string die1Type, int die1Sides,
            std::string die2Type, int die2Sides)
{
    this->rounds = rounds;
    this->currentRound = 1;
    this->player1RoundsWon = 0;
    this->player2RoundsWon = 0;
    this->draws = 0;

    // Technically, we should create a copy constructor, destructor, copy
    // constructor, move constructor, copy assignment operator, and move
    // assignment operator, since we are allocating memory.
    if (die1Type == "normal")
    {
        Die1.reset(new Die(die1Sides));
    }
    else if (die1Type == "loaded")
    {
        Die1.reset(new LoadedDie(die1Sides));
    }

    if (die2Type == "normal")
    {
        Die2.reset(new Die(die2Sides));
    }
    else if (die2Type == "loaded")
    {
        Die2.reset(new LoadedDie(die2Sides));
    }
}

void Game::playGame()
{
    std::cout << "Player 1 has a " << Die1->getSides() << "-sided ";
    std::cout << Die1->getType() << " die." << std::endl;
    std::cout << "Player 2 has a " << Die2->getSides() << "-sided ";
    std::cout << Die2->getType() << " die." << std::endl;
    int Die1Roll;
    int Die2Roll;
    while (currentRound <= rounds)
    {
        Die1Roll = Die1->rollDie();
        Die2Roll = Die2->rollDie();
        
        std::cout << "This is Round " << currentRound << ":" << std::endl;
        std::cout << "Player 1 rolled " << Die1Roll << ", ";
        std::cout << "Player 2 rolled " << Die2Roll << std::endl;
        
        if (Die1Roll > Die2Roll)
        {
            std::cout << "Player 1 wins Round " << currentRound << std::endl;
            player1RoundsWon++;
        }
        else if (Die2Roll > Die1Roll)
        {
            std::cout << "Player 1 wins Round " << currentRound << std::endl;
            player2RoundsWon++;
        }
        else
        {
            std::cout << "Round " << currentRound << " is a draw" << std::endl;
            draws++;
        }

        std::cout << std::endl;
        currentRound++;
    }

    std::cout << "Player 1 won " << player1RoundsWon << " rounds" << std::endl;
    std::cout << "Player 2 won " << player2RoundsWon << " rounds" << std::endl;
    std::cout << "Draws: " << draws << std::endl;

    if (player1RoundsWon > player2RoundsWon)
    {
        std::cout << "Player 1 won the game!" << std::endl;
    }
    else if (player2RoundsWon > player1RoundsWon)
    {
        std::cout << "Player 2 won the game!" << std::endl;
    }
    else
    {
        std::cout << "The game is a draw!" << std::endl;
    }
}