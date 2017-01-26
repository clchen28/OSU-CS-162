/******************************************************************************
** Program name: dieTest.cpp
** Author: Charles Chen
** Date: 01/25/2017
** Description:
dieTest
******************************************************************************/

#include <iostream>
#include <string>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "inputValidator.hpp"

int main()
{
    int dieSides;
    std::string dieType;
    int trials;
    Die *Die1 = nullptr;
    int *results = nullptr;

    auto inputPositive = [](int input) -> bool {return input >= 1;};
    auto dieTypeCheck = [](std::string input) -> bool
    {
        return((input == "normal") || (input == "loaded"));
    };

    inputValidator(dieSides, inputPositive, "Enter number of die sides",
                "Must enter a positive integer number of sides");
    inputValidator(dieType, dieTypeCheck,
                "Enter die type",
                "Die types must be normal or loaded");
    inputValidator(trials, inputPositive,
                "Enter number of trials",
                "Must enter a positive integer number of trials");

    if (dieType == "normal")
    {
        Die1 = new Die(dieSides);
    }
    else if (dieType == "loaded")
    {
        Die1 = new LoadedDie(dieSides);
    }

    results = new int[dieSides];
    for (int i = 0; i < dieSides; i++)
    {
        results[i] = 0;
    }

    for (int i = 0; i < trials; i++)
    {
        results[(Die1->rollDie()) - 1] += 1;
    }

    for (int i = 0; i < dieSides; i++)
    {
        std::cout << "Side " << i + 1 << ": " << results[i] << std::endl;
    }
    
    delete Die1;
    delete [] results;
    return 0;
}