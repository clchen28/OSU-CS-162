/******************************************************************************
** Program name: LoadedDie.hpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:

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
