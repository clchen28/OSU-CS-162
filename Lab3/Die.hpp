/******************************************************************************
** Program name: Die.hpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:

******************************************************************************/

#include <string>

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
	public:
		Die();
		Die(int sides);
		virtual int rollDie();
		std::string getType();
	protected:
		int sides;
		std::string dieType;
};

#endif