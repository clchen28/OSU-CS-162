/******************************************************************************
** Program name: Die.hpp
** Author: Charles Chen
** Date: 01/22/2017
** Description:

******************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
	public:
		Die();
		Die(int sides);
		int rollDie();
	protected:
		int sides;
};

#endif