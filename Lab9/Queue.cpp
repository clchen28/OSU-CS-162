/******************************************************************************
** Program name: Queue.cpp
** Author: Charles Chen
** Date: 03/05/2017
** Description:

******************************************************************************/

#include <iostream>
#include <queue>
#include <random>
#include "Queue.hpp"

int randNum(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,n);
    return dist(gen);
}

bool randBool(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,100);
    return (dist(gen) <= n);
}

void addToBuffer(std::queue<int> &bufferQueue, int num, int prob)
{
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

void removeFromBuffer(std::queue<int> &bufferQueue, int prob)
{
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

void runSimulation(std::queue<int> &bufferQueue, int rounds, int addProb, int remProb)
{
    float curAvgLength = bufferQueue.size();
    float prevAvgLength = bufferQueue.size();

    for (int i = 1; i <= rounds; i++)
    {
        std::cout << "Current Round: " << i << std::endl;
        addToBuffer(bufferQueue, randNum(100), addProb);
        if (bufferQueue.size() > 0)
        {
            removeFromBuffer(bufferQueue, remProb);
        }
        curAvgLength = (prevAvgLength * (i - 1) + bufferQueue.size()) / i;
        prevAvgLength = curAvgLength;
        std::cout << "Average buffer size: " << curAvgLength << std::endl;
    }
}
