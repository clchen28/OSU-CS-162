/******************************************************************************
** Program name: Queue.cpp
** Author: Charles Chen
** Date: 03/05/2017
** Description:
Provides functions for implementing a buffer.
******************************************************************************/

#include <iostream>
#include <queue>
#include <random>
#include "Queue.hpp"

/*
randNum(int n)
Takes an integer n and returns integers between 0 and n, inclusive
*/
int randNum(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,n);
    return dist(gen);
}

/*
bool randNum(int n)
Takes an integer n. If n is between 0 and 100, then this function will return
true approximately n percent of the time
*/
bool randBool(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,100);
    return (dist(gen) <= n);
}

/*
addToBuffer(std::queue<int> &bufferQueue, int num, int prob)
addToBuffer takes in a queue of integers, an integer number, and an integer
representing probability. prob is an integer between 0 and 100 - there is a prob
percent chance that integer num will be added to the queue
*/
void addToBuffer(std::queue<int> &bufferQueue, int num, int prob)
{
    // Randomly determine if number should be added to buffer
    if (randBool(prob))
    {
        bufferQueue.push(num);
        std::cout << "Pushed to buffer" << std::endl;
    }
    else
    {
        std::cout << "Did not push to buffer" << std::endl;
    }
}

/*
removeFromBuffer(std::queue<int> &bufferQueue, int prob)
removeFromBuffer takes a queue of integers, and an integer representing
probability. There is prob chance that the first top element in the queue
will be removed.
*/
void removeFromBuffer(std::queue<int> &bufferQueue, int prob)
{
    // Randomly determine if number should be removed from buffer
    if (randBool(prob))
    {
        bufferQueue.pop();
        std::cout << "Popped from buffer" << std::endl;
    }
    else
    {
        std::cout << "Did not pop from buffer" << std::endl;
    }
}

/*
runSimulation(std::queue<int> &bufferQueue, int rounds, int addProb, int remProb)
runSimulation takes a queue, integer number of rounds, integer probability
for adding elements, and integer number of removing elements. Each round, it
will randomly determine if a number is to be added, and if a number is to be
removed.
*/
void runSimulation(std::queue<int> &bufferQueue, int rounds, int addProb, int remProb)
{
    // Start avg length to be the initial size of the queue
    float curAvgLength = bufferQueue.size();
    float prevAvgLength = bufferQueue.size();

    for (int i = 1; i <= rounds; i++)
    {
        std::cout << "Current Round: " << i << std::endl;

        addToBuffer(bufferQueue, randNum(100), addProb);

        // Will not attempt to remove from queue if it is empty
        if (bufferQueue.size() > 0)
        {
            removeFromBuffer(bufferQueue, remProb);
        }

        // Prints results
        curAvgLength = (prevAvgLength * (i - 1) + bufferQueue.size()) / i;
        prevAvgLength = curAvgLength;
        std::cout << "Average buffer size: " << curAvgLength << std::endl;
    }
}
