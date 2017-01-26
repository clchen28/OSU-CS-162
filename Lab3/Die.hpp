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
		virtual std::string getType();
		virtual int getSides();
	protected:
		int sides;
		std::string dieType;
};

#endif