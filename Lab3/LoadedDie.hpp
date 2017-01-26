/******************************************************************************
** Program name: LoadedDie.hpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:
LoadedDie.hpp contains the specification of the LoadedDie class. This class is
designed to create a die with a certain number of sides, and provides a utility
for rolling the die.
******************************************************************************/

#include <string>

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie : public Die
{
    public:
        LoadedDie();
        LoadedDie(int sides);
        ~LoadedDie();
        int rollDie();
        std::string getType();
		int getSides();
    private:
        std::string dieType;
};

#endif
