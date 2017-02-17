/******************************************************************************
** Program name: Node.cpp
** Author: Charles Chen
** Date: 02/16/2017
** Description:
Contains the implementation for the Node structure.
******************************************************************************/

#include "Node.hpp"

/*
Node(int value)
The constructor takes an integer as input, and sets it to be the data value
stored in the new node. The nextNode poitner is set to null.
*/
Node::Node(int value)
{
    data = value;
    this->nextNode = nullptr;
}

/*
getData()
Use this get method to obtain the integer data in this node.
*/
int Node::getData()
{
    return data;
}

/*
getNextNode()
Use this get method to obtain the address that the nextNode pointer points to.
*/
Node* Node::getNextNode()
{
    return nextNode;
}

/*
setNextNode(Node* newNode)
Use this set method to change the address that the nextNode pointer points to.
*/
void Node::setNextNode(Node* newNode)
{
    nextNode = newNode;
}
