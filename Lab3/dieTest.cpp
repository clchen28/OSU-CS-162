/******************************************************************************
** Program name: dieTest.cpp
** Author: Charles Chen
** Date: 01/25/2017
** Description:
dieTest provides a function for testing the rollDie functionality of both die.
Additionally, it is useful for verifying that the normal die is relatively
evenly distributed, and for verifying that the loaded die is more likely to
roll higher numbers.

The user is prompted for the number of trials (recommended to use a high
number), the die type, and die sides. The die is then rolled for the specified
number of trials, and the frequency of each die roll is presented to the user.
For normal die, the distribution should be relatively even. For loaded die,
it should be roughly 4 times more likely to roll larger numbers.

To compile, type:
make dietest

To run, type:
./dieTest
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

    // Lambda functions for input validation
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

    // Allocates memory for specified die type, and creates new object
    if (dieType == "normal")
    {
        Die1 = new Die(dieSides);
    }
    else if (dieType == "loaded")
    {
        Die1 = new LoadedDie(dieSides);
    }

    // Creates a results array. Each element represents one side of the die.
    // The number in each element represents the frequency for that side being
    // rolled.
    // First, we need to set all members of the array to 0.
    results = new int[dieSides];
    for (int i = 0; i < dieSides; i++)
    {
        results[i] = 0;
    }

    // Roll the die for the number of trials there are, and increment the
    // appropriate element of the results array for each trial.
    for (int i = 1; i <= trials; i++)
    {
        results[(Die1->rollDie()) - 1] += 1;
    }

    // Outputs results to the user
    for (int i = 0; i < dieSides; i++)
    {
        std::cout << "Side " << i + 1 << ": " << results[i] << std::endl;
    }
    
    delete Die1;
    delete [] results;
    return 0;
}