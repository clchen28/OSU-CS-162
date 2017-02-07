/******************************************************************************
** Program name: Die.hpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:
Die.hpp contains the specification of the Die class. This class is designed
to create a die with a certain number of sides, and provides a utility for
rolling the die.
******************************************************************************/

#include <string>

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
	public:
		Die();
		Die(int sides);
		virtual ~Die();
		virtual int rollDie();
		virtual std::string getType();
		virtual int getSides();
		virtual void setSides(int sides);
	protected:
		int sides;
		std::string dieType;
};

#endif
