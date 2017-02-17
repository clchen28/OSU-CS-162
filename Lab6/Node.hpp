/******************************************************************************
** Program name: Node.hpp
** Author: Charles Chen
** Date: 02/16/2017
** Description:
Specification of the Node structure.
******************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

struct Node
{
private:
    int data;
    Node* nextNode;

public:
    Node(int value);
    int getData();
    Node* getNextNode();
    void setNextNode(Node* newNode);
};

#endif
