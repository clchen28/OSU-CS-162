/******************************************************************************
** Program name: Lab7.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:

******************************************************************************/

#include <iostream>
#include "Queue.hpp"

int main()
{
    Queue queue;
    queue.addBack(5);
    queue.addBack(6);
    queue.addBack(7);
    queue.addBack(8);
    queue.addBack(9);
    queue.addBack(10);
    std::cout << queue.getFront() << std::endl;
    queue.addBack(11);
    std::cout << queue.removeFront() << std::endl;
    std::cout << queue.removeFront() << std::endl;
    std::cout << queue.removeFront() << std::endl;
    std::cout << queue.removeFront() << std::endl;
    std::cout << queue.removeFront() << std::endl;
    std::cout << queue.removeFront() << std::endl;
    return 0;
}
