/******************************************************************************
** Program name: Queue.hpp
** Author: Charles Chen
** Date: 03/05/2017
** Description:

******************************************************************************/

#include <queue>

#ifndef QUEUE_HPP
#define QUEUE_HPP

int randNum(int n);
bool randBool(int n);
void addToBuffer(std::queue<int> &bufferQueue, int num, int prob);
void removeFromBuffer(std::queue<int> &bufferQueue, int prob);
void runSimulation(std::queue<int> &bufferQueue, int rounds, int addProb, int remProb);

#endif
