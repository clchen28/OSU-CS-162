/******************************************************************************
** Program name: Game.cpp
** Author: Charles Chen
** Date: 03/13/2017
** Description:

******************************************************************************/

#include "Game.hpp"
#include "Room.hpp"
#include "ItemRoom.hpp"
#include "Player.hpp"
#include "TeleporterRoom.hpp"
#include "MonsterRoom.hpp"
#include "ExitRoom.hpp"
#include <iostream>

Game::Game()
{
    startRoom = new ItemRoom;
    Room* tempRoom1 = startRoom;
    Room* tempRoom2 = nullptr;
    Room* tempRoom3 = nullptr;
    Room* tempRoom4 = nullptr;

    roomRow1 = startRoom;
    roomRow2 = nullptr;
    roomRow3 = nullptr;
    roomRow4 = nullptr;
    for (int i = 0; i < 4; i++)
    {
        tempRoom1->setRight(new ItemRoom);
        tempRoom1->getRight()->setLeft(tempRoom1);
        tempRoom1 = tempRoom1->getRight();
    }

    tempRoom1 = roomRow1;
    roomRow2 = new ItemRoom;
    roomRow2->setUp(roomRow1);
    roomRow1->setDown(roomRow2);
    tempRoom2 = roomRow2;
    for (int i = 0; i < 4; i++)
    {
        tempRoom2->setRight(new ItemRoom);
        tempRoom2->getRight()->setLeft(tempRoom2);
        tempRoom2->getRight()->setUp(tempRoom1->getRight());
        tempRoom1->getRight()->setDown(tempRoom2->getRight());
        tempRoom1 = tempRoom1->getRight();
        tempRoom2 = tempRoom2->getRight();
    }

    tempRoom2 = roomRow2;
    roomRow3 = new ItemRoom;
    roomRow3->setUp(roomRow2);
    roomRow2->setDown(roomRow3);
    tempRoom3 = roomRow3;
    for (int i = 0; i < 4; i++)
    {
        tempRoom3->setRight(new ItemRoom);
        tempRoom3->getRight()->setLeft(tempRoom3);
        tempRoom3->getRight()->setUp(tempRoom2->getRight());
        tempRoom2->getRight()->setDown(tempRoom3->getRight());
        tempRoom2 = tempRoom2->getRight();
        tempRoom3 = tempRoom3->getRight();
    }

    tempRoom3 = roomRow3;
    roomRow4 = new ItemRoom;
    roomRow4->setUp(roomRow3);
    roomRow3->setDown(roomRow4);
    tempRoom4 = roomRow4;
    for (int i = 0; i < 4; i++)
    {
        tempRoom4->setRight(new ItemRoom);
        tempRoom4->getRight()->setLeft(tempRoom4);
        tempRoom4->getRight()->setUp(tempRoom3->getRight());
        tempRoom3->getRight()->setDown(tempRoom4->getRight());
        tempRoom3 = tempRoom3->getRight();
        tempRoom4 = tempRoom4->getRight();
    }

    Room* tempRoom = nullptr;
    Room* newRoom = nullptr;
    tempRoom = roomRow2->getRight()->getRight();
    newRoom = new MonsterRoom(tempRoom->getUp(), tempRoom->getDown(),
        tempRoom->getLeft(), tempRoom->getRight());
    newRoom->getRight()->setLeft(newRoom);
    newRoom->getUp()->setDown(newRoom);
    newRoom->getLeft()->setRight(newRoom);
    newRoom->getDown()->setUp(newRoom);
    delete tempRoom;
}

Game::~Game()
{
    Room* tempRoom1 = roomRow1;
    Room* tempRoom2 = roomRow2;
    Room* tempRoom3 = roomRow3;
    Room* tempRoom4 = roomRow4;

    while (tempRoom1->getRight() != nullptr)
    {
        tempRoom1 = tempRoom1->getRight();
        delete tempRoom1->getLeft();
    }
    delete tempRoom1;

    while (tempRoom2->getRight() != nullptr)
    {
        tempRoom2 = tempRoom2->getRight();
        delete tempRoom2->getLeft();
    }
    delete tempRoom2;

    while (tempRoom3->getRight() != nullptr)
    {
        tempRoom3 = tempRoom3->getRight();
        delete tempRoom3->getLeft();
    }
    delete tempRoom3;

    while (tempRoom4->getRight() != nullptr)
    {
        tempRoom4 = tempRoom4->getRight();
        delete tempRoom4->getLeft();
    }
    delete tempRoom4;
}

void Game::printRow(Room* row)
{
    Room* tempRoom = row;
    while (tempRoom != nullptr)
    {
        if (!tempRoom->isFound())
        {
            std::cout << "X";
        }
        else if (player->getPlayerPosition() == tempRoom)
        {
            std::cout << "P";
        }
        else if (tempRoom->getType() == "Teleporter")
        {
            std::cout << "T";
        }
        else if (tempRoom->getType() == "Item")
        {
            std::cout << "I";
        }
        else if (tempRoom->getType() == "Empty")
        {
            std::cout << "O";
        }
        else if (tempRoom->getType() == "Monster")
        {
            std::cout << "M";
        }
        else if (tempRoom->getType() == "MonsterDead")
        {
            std::cout << "D";
        }
        else if (tempRoom->getType() == "Exit")
        {
            std::cout << "E";
        }
        tempRoom = tempRoom->getRight();
    }
    std::cout << std::endl;
}

void Game::printMap()
{
    std::cout << "Map: P is your location, X is unknown, ";
    std::cout << "O is an empty room, M has a monster, " << std::endl;
    std::cout << "E is the exit, I has items" << std::endl;

    printRow(roomRow1);
    printRow(roomRow2);
    printRow(roomRow3);
    printRow(roomRow4);
}
